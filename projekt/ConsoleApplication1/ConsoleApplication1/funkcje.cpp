#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "pch.h"
#include "struktury.h"
#include "funkcje.h"

//funkcja do wpisania nowych nazw miast glownych
miasto * stworz_miasto(miasto * &pHead_miasto, std::string nowanazwa, int &licznik)
{
	miasto * p = pHead_miasto;
	while (p)
	{
		if (nowanazwa == p->nazwamiasta)//jesli miasto jest juz w liscie
			return p;
		p = p->pmiasto;
	}
	//jesli miasto nie jest jeszcze w liscie
	miasto * pNowy = new miasto{ nowanazwa, pHead_miasto, nullptr, 0 };
	pHead_miasto = pNowy;
	licznik++;
	return pNowy;
}

void stworz_droga(miasto * &pHead_miasto, int kilometry, /*std::string*/ miasto * &nowe_miasto1, /*std::string*/ miasto * &nowe_miasto2)
{/*
	miasto * p = pHead_miasto;
	while (p) //znalezienie miejsca, w którym bedzie tworzona nowa lista
	{
		if (nowe_miasto1 == p->nazwamiasta)
			break; // miasto zawsze jest na liscie
		p = p->pmiasto; 
	} //p jest wskaznikiem na miasto poczatkowe
	miasto * r = pHead_miasto; //znalezienie miasta, do którego prowadzi trasa
	while (r)
	{
		if (nowe_miasto2 == r->nazwamiasta)
			break; // miasto zawsze jest na liscie
		r = r->pmiasto;
	} // r jest wskaznikiem na miasto docelowe
	*/
	droga * pHead_droga = /*p*/nowe_miasto1->miastaobok; //pierwszy element listy droga
	
		droga * pNowy = new droga{ kilometry, pHead_droga, /*r*/ nowe_miasto2 };
		/*p*/nowe_miasto1->miastaobok = pNowy;
	
		pHead_droga = /*r*/nowe_miasto2->miastaobok; //pierwszy element listy droga
		pNowy = new droga{ kilometry, pHead_droga, /*p*/ nowe_miasto1 };
		/*r*/ nowe_miasto2->miastaobok = pNowy;
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
void algorytm(std::string startowy, miasto* &pHead, wynik * &pHead_wynik)
{
	int Najkrotsza_droga = INT_MAX;
	miasto * p = pHead;
	miasto * najblizsze_miasto = nullptr;
	while (p) 
	{
		if (startowy == p->nazwamiasta) //CO JESLI STARTOWEGO NIE MA?
			break; 
		p = p->pmiasto;
	}
	if (p)  //jesli miasta startowego nie ma w liscie to p=0?
	{
		while (p->odwiedzony == 0)
		{
			p->odwiedzony = 1;
			miasto * poprzednie = p;
			droga * nastepny = p->miastaobok;
			while (nastepny)
			{
				if (Najkrotsza_droga > nastepny->trasa)
				{
					nastepny->trasa = Najkrotsza_droga;
					najblizsze_miasto = nastepny->pmiasto; //wskaznik na miasto, do ktorego jest najblizej
				}
				nastepny = nastepny->pdroga;
				nastepny = p->miastaobok;
			}
			dodajDoListyWynik(pHead_wynik, Najkrotsza_droga, najblizsze_miasto, poprzednie); // zapisanie wyniku do listy
		}
	}

}

void dodajDoListyWynik(wynik * &pHead, int odleglosc,miasto * &aktualne, miasto * &poprzednik)
{
	wynik * pNowy = new wynik{ odleglosc,poprzednik,aktualne,nullptr };
	pHead = pNowy;
}
void wypisz_wynik(wynik * pHead)
{
	while (pHead)
	{
		std::cout << std::endl;
		std::cout << pHead->poprzednik << "  ->  "<<pHead->aktualne<<":  "<<pHead->odleglosc<<" " << std::endl;
		pHead = pHead->pwynik;
	}
}

bool sprawdz_argumenty(int ile, char ** params , std::string & wejscie, std::string & wyjscie,std::string & start)
{
	const std::string Wejscie("-i");
 	const std::string Wyjscie("-o");
 	const std::string Start("-s");
    
	if (ile <= 1)
		return false;
	if (ile > 7)
		return false;
	while (ile > 1)
	{
		//if (strcmp(params[1], "-i") == 0) 
		if (std::string (params[1]) == Wejscie) 
		{
			wejscie = params[2];
			std::cout << wejscie << std::endl;
			ile -= 2;
			params += 2;
			continue;
		}
		//if (strcmp(params[1], "-o") == 0)
		if (std::string(params[1]) == Wyjscie)
		{
			wyjscie = params[2];
			std::cout << wyjscie << std::endl;
			ile -= 2;
			params += 2;
			continue;
		}
		//if (strcmp(params[1], "-s") == 0)
		if (std::string(params[1]) == Start)
		{
			start = params[2];
			std::cout << start << std::endl;
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
	std::ifstream plik("miasta.txt");//plik(wejscie); //("miasta.txt");
	if (plik)
	{
		int odleglosc = INT_MAX;
		int licznik_miast = 0;
		std::cout << "plik otwarty" << std::endl;
		std::string linia,miasto1,miasto2;
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
			//std::cout << miasto1 << " " << miasto2 << " " << odleglosc << std::endl; //dane wypisane

			if (miasto1 == "" || miasto2 == "" || odleglosc <= 0)
			{
				std::cout << "blad w wierszu " << licznik << std::endl;
				continue; //powrot do while
			}
			
			//stworz_miasto(pGlowa, miasto1, licznik_miast);
			//stworz_miasto(pGlowa, miasto2, licznik_miast);

			miasto* pGlowa1 = stworz_miasto(pGlowa, miasto1, licznik_miast);
			miasto* pGlowa2 =stworz_miasto(pGlowa, miasto2, licznik_miast);
			droga * pGlowa_droga = nullptr;
			stworz_droga(pGlowa, odleglosc, pGlowa1, pGlowa2);// stworzenie grafu (listy list)
		}

		plik.close();

	}
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
			void usun_wynik(wynik * &pHead)
			{
				while (pHead)
				{
					wynik * pNastepnik = pHead->pwynik;
					delete pHead;
					pHead = pNastepnik;
				}
			}

			void usun(miasto * glowa_miasta, wynik * glowa_wynik )
			{
				usun_droge(glowa_miasta);
				usun_miasta(glowa_miasta);
				usun_wynik(glowa_wynik);
			}
