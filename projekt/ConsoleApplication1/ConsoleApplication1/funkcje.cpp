#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#include <ios>
#include<limits.h>
#include "pch.h"
#include "struktury.h"
#include "funkcje.h"

//funkcja do wpisania nowych nazw miast glownych
miasto * stworz_miasto(miasto * &pHead_miasto, std::string nowanazwa )
{
	miasto * p = pHead_miasto;
	while (p)
	{
		if (nowanazwa == p->nazwamiasta)//jesli miasto jest juz w liscie
			return p;
		p = p->pmiasto;  // nastêpne miasto
	}
	//jesli miasto nie jest jeszcze w liscie, tworzymy nowe
	miasto * pNowy = new miasto{ nowanazwa, pHead_miasto, nullptr, 0, INT_MAX, nullptr};
	pHead_miasto = pNowy;
	return pNowy;
}

void stworz_droga(miasto * &pHead_miasto, int kilometry,  miasto * &nowe_miasto1,  miasto * &nowe_miasto2)
{
	droga * pHead_droga = nowe_miasto1->miastaobok; //pierwszy element listy droga
	
		droga * pNowy = new droga{ kilometry, pHead_droga,  nowe_miasto2 };
		nowe_miasto1->miastaobok = pNowy;
	
		pHead_droga = nowe_miasto2->miastaobok; //pierwszy element listy droga
		pNowy = new droga{ kilometry, pHead_droga, nowe_miasto1 };
		nowe_miasto2->miastaobok = pNowy;
}

void wypisz_droga(droga * pHead_droga)
{
	while (pHead_droga)
	{
		std::cout << pHead_droga->pmiasto->nazwamiasta << " " << pHead_droga->trasa<< std::endl;
		pHead_droga = pHead_droga->pdroga;
	}
}

void wypisz_miasto(miasto * pHead)
{
	while (pHead)
	{
		std::cout << std::endl;
		std::cout << pHead->nazwamiasta << " "<< std::endl;
		wypisz_droga(pHead->miastaobok);
		pHead = pHead->pmiasto;
	}
}
 //algorytm Dijkstry
void algorytm(std::string startowy, miasto* &pHead)
{
	miasto * p = pHead;
	while (p) 
	{
		if (startowy == p->nazwamiasta) //CO JESLI STARTOWEGO NIE MA?
			break; 
		p = p->pmiasto;
	}
	if (p)  //jesli miasta startowego nie ma w liscie to p=0?
	{
		p->odleglosc_od_centrali = 0;
		while (p)
		{
			p->odwiedzony = 1;
			miasto * poprzednie = p;
			droga * nastepny = p->miastaobok;
			while (nastepny)
			{
				if(nastepny->pmiasto->odleglosc_od_centrali > poprzednie->odleglosc_od_centrali + nastepny->trasa)
				{
					nastepny->pmiasto->odleglosc_od_centrali = poprzednie->odleglosc_od_centrali + nastepny->trasa;
		
					nastepny->pmiasto->pMiastoPoprzednie = poprzednie; //wskaznik na miasto, z ktorego jest najblizej 
				}
				nastepny = nastepny->pdroga;
			}
			p = pHead;
			int Najkrotsza_droga = INT_MAX;
			miasto * najblizsze_miasto = nullptr;
			while (p)
			{
				if (p->odwiedzony == 0 && Najkrotsza_droga > p->odleglosc_od_centrali)
				{
					Najkrotsza_droga =p->odleglosc_od_centrali;
					najblizsze_miasto = p; //wskaznik na miasto, do ktorego jest najblizej
				}
				p = p->pmiasto;
			}
			p = najblizsze_miasto;
		}
		return;
	}
	std::cout << "Brak miasta startowego" << std::endl;
}

void wypisz_miasta(miasto * pHead, std::ostream &wyjscie)
{
	if (pHead->pMiastoPoprzednie)
	{
		wypisz_miasta(pHead->pMiastoPoprzednie, wyjscie);
		wyjscie << " -> ";		
	}
	wyjscie << pHead->nazwamiasta;
}

void wypisz_wynik(miasto * pHead, std::string wyjscie)
{
	std::ofstream plik(wyjscie);
	if (plik)
	{
		plik << " ---------------- wypisanie tras -------------- " << std::endl;

		miasto * p = pHead;
		while (p)
		{
			if (p->odleglosc_od_centrali == INT_MAX)
				plik << p->nazwamiasta << ": Brak trasy z centrali " << std::endl;
			else
			{
				wypisz_miasta(p, plik);
				plik << ":  " << p->odleglosc_od_centrali << " " << std::endl;
			}
			plik << std::endl;
			p = p->pmiasto;
		}
		std::cout << std::endl;
		std::cout << "Wynik zostal zapisany do pliku" << std::endl;
		plik.close();

	}
}

bool sprawdz_argumenty(int ile, char ** params , std::string & wejscie, std::string & wyjscie,std::string & start)
{
	const std::string Wejscie("-i");
 	const std::string Wyjscie("-o");
 	const std::string Start("-s");
    

	if (ile != 7)
		return false;
	while (ile > 1)
	{
		if (std::string (params[1]) == Wejscie) 
		{
			wejscie = params[2];
			ile -= 2;
			params += 2;
			continue;
		}
		if (std::string(params[1]) == Wyjscie)
		{
			wyjscie = params[2];
			ile -= 2;
			params += 2;
			continue;
		}
		if (std::string(params[1]) == Start)
		{
			start = params[2];
			ile -= 2;
			params += 2;
			continue;
		}
		if (wejscie == "" || wyjscie == "" || start == "" || params[1]!="-i" or "-s" or "-o" || params[3] != "-i" or "-s" or "-o" || params[5] != "-i" or "-s" or "-o")
			return false;
	}
	return true;
}

void wczytajzPliku(std::string wejscie, miasto * &pGlowa)
{
	std::ifstream plik(wejscie);
	if (plik)
	{
		int odleglosc = INT_MAX;
		std::cout << "plik otwarty" << std::endl;
		std::string linia, miasto1, miasto2;
		int licznik = 0;
		while (std::getline(plik, linia))
		{
			licznik++;
			std::stringstream ss;

			ss << linia;

			miasto1 = "";
			miasto2 = "";
			odleglosc = -1;
			ss >> miasto1 >> miasto2 >> odleglosc;

			if (miasto1 == "" || miasto2 == "" || odleglosc <= 0)
			{
				std::cout << "blad w wierszu " << licznik << std::endl;
				continue; //powrot do while
			}

			miasto* pGlowa1 = stworz_miasto(pGlowa, miasto1);
			miasto* pGlowa2 = stworz_miasto(pGlowa, miasto2);
			droga * pGlowa_droga = nullptr;
			stworz_droga(pGlowa, odleglosc, pGlowa1, pGlowa2);// stworzenie grafu (listy list)
		}

		plik.close();

	}
	else
		std::cout << "NIe udalo sie otworzyc pliku." << std::endl;
}
			//usuwanie grafu
			void usun_droge(miasto*pmiasto)
			{
				while (pmiasto)
				{
					while (pmiasto->miastaobok)
					{
						droga * pNastepnik = pmiasto->miastaobok->pdroga;
						delete pmiasto->miastaobok;
						pmiasto->miastaobok = pNastepnik;
					}
					pmiasto = pmiasto->pmiasto;
				}
			}
			void usun_miasta(miasto* &pHead)
			{
				while (pHead)
				{
					miasto * pNastepnik = pHead->pmiasto;
					delete pHead;
					pHead = pNastepnik;
				}
			}
		
			void usun(miasto * glowa_miasta )
			{
				usun_droge(glowa_miasta);
				usun_miasta(glowa_miasta);
			}

		
