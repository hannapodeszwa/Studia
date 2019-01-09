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

	// wycinamy 1.



	// while (.....)
	//   p = p->pNext;

	// znalezlismy --> wycinamy

	while (p)
	{
		while (p->nazwisko != nazwisko && p!=nullptr)
		{
			poprzedni = p;
			p = p->pNext;
		}

		pwynik = p;
		poprzedni->pNext = p->pNext;
		return pwynik;
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
	kandydat * poprzedni = nullptr;
	kandydat * p = pHead;
	poprzedni->pNext = pHead;
	while (p)
	{
		if (pK->nGlosy < p->nGlosy)
		{
			poprzedni->pNext = pK;
			pK->pNext = p;
		}
		else
		{
			poprzedni->pNext = p->pNext;
			pK = pK->pNext;
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

