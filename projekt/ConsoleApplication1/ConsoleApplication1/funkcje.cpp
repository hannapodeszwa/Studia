#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "pch.h"
#include "struktury.h"
#include "funkcje.h"

//funkcja do wpisania nowych nazw miast glownych
void stworz_miasto(miasto * &pHead_miasto, std::string nowanazwa, int &licznik)
{
	miasto * p = pHead_miasto;
	while (p)
	{
		if (nowanazwa == p->nazwamiasta)//jesli miasto jest juz w liscie
			return;
		p = p->pmiasto;
	}
	//jesli miasto nie jest jeszcze w liscie
	miasto * pNowy = new miasto{ nowanazwa, pHead_miasto, nullptr, 0 };
	pHead_miasto = pNowy;
	licznik++;
}

void stworz_droga(miasto * pHead_miasto, int kilometry, std::string nowe_miasto1, std::string nowe_miasto2)
{
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
	droga * pHead_droga = p->miastaobok; //pierwszy element listy droga
	
		droga * pNowy = new droga{ kilometry, pHead_droga, r };
		p->miastaobok = pNowy;
	
		pHead_droga = r->miastaobok; //pierwszy element listy droga
		pNowy = new droga{ kilometry, pHead_droga, p };
		r->miastaobok = pNowy;
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
void algorytm(std::string startowy, miasto* pHead, miasto* pGlowa_wynik)
{
	int Najkrotsza_droga = INT_MAX;
	miasto * p = pHead;
	
	miasto * najblizsze_miasto = nullptr;
	while (p) 
	{
		if (startowy == p->nazwamiasta)
			break; 
	//	p->odwiedzony == 0;
		p = p->pmiasto;
	}

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
		dodajDoListyWynik(pGlowa_wynik, Najkrotsza_droga, najblizsze_miasto, poprzednie); // zapisanie wyniku do listy
	}

}

void dodajDoListyWynik(wynik * &pHead, int odleglosc,miasto * aktualne, miasto * poprzednik)
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

bool sprawdz_argumenty(int ile, char ** params , std::string wejscie, std::string wyjscie,std::string start)
{
	if (ile <= 1)
		return false;
	while (ile > 1)
	{
		//if (strcmp(params[1], "-i") == 0) 
		if (std::string (params[1]) == wejscie) 
		{
			wejscie = params[2];
			std::cout << wejscie << std::endl;
			ile -= 2;
			params += 2;
			continue;
		}
		//if (strcmp(params[1], "-o") == 0)
		if (std::string(params[1]) == wyjscie)
		{
			wyjscie = params[2];
			std::cout << wyjscie << std::endl;
			ile -= 2;
			params += 2;
			continue;
		}
		//if (strcmp(params[1], "-s") == 0)
		if (std::string(params[1]) == start)
		{
			start = params[2];
			std::cout << start << std::endl;
			ile -= 2;
			params += 2;
			continue;
		}
		if (wejscie == "" || wyjscie == "" || start == "")
			return false;
	}
	return true;
}
/*

			//usuwanie grafu
			void usunmiastasasiednie(miasta_sasiednie * &pHead)
			{
				while (pHead)
				{
					miasta_sasiednie * pNastepnik = pHead->
				}

			}
			*/