// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <limits>
#include<cmath>
#include<vector>
#include<chrono>
#include<random>
#include <iomanip>

struct kandydat
{
	std::string nazwisko;
	int nGlosy;
	kandydat * pNext;
};

struct komisja
{
	int numer;
	kandydat * pKandydaci;
	komisja * pLewa, *pPrawa;
};

kandydat * wytnij(kandydat * &pKandydaci, const std::string &nazwisko)
{
	kandydat * p = pKandydaci;
	kandydat * pwynik = nullptr;
	kandydat * poprzedni= nullptr;
	poprzedni->pNext = pKandydaci;
	if (pKandydaci == nullptr)
		return nullptr;
	while (p)
	{
		if (p->nazwisko != nazwisko)
		{
			poprzedni = p;
			p = p->pNext;
		}
		else
		{
			pwynik = p;
			poprzedni->pNext = p->pNext;
			return pwynik;
		}
	}
	return nullptr;
}

void dodaj(kandydat * &pHead, kandydat *pK)
{
	if (pHead == nullptr)
	{
		pHead = pK;
		return;
	}
	kandydat * p = pHead;
	while (p)
	{
		if (pK->nGlosy >= p->nGlosy)
			pK = pK->pNext;
		else
		{
			kandydat * nastepny=p->pNext;
			p->pNext = pK;
			pK->pNext = nastepny;
		}
	}
}

void aktualizuj(kandydat * &pListaUporzadkowana, kandydat * &pKandydaciDoDodania)
{

}


int main()
{
    return 0;
}

