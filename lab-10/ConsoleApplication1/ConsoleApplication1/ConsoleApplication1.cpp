// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

typedef int typ;
struct element
{
	typ wartosc;
	element * pNext;
	element * pPrev;
};

void dodajNaPoczatek (element *&pHead, element *&pTail, const typ &liczba)
{
	if (pHead == nullptr)
	{
		
		pHead = pTail = new element{ liczba,nullptr,nullptr }; 

	}
	else
	{
		element * pNowy = new element{ liczba,pHead,nullptr };
		pNowy->pNext = pHead;
		pNowy->pPrev=nullptr;
		pHead->pPrev = pNowy;
		pHead = pNowy;

		
	}
}
void wypisz(element *pHead, element *pTail)
{
	while (pHead)
	{
		std::cout << pHead->wartosc << " ";
		pHead = pHead->pNext;
	}
	std::cout << std::endl;
}

void dodajDoListyPosortowanej(element *&pHead, element *&pTail, const typ &liczba)
{
	if (pHead==nullptr)
		dodajNaPoczatek(pHead, pTail, liczba);

	if (liczba < pHead->wartosc)
	{
		element * pNowy = new element{ liczba,pHead,nullptr };
		pNowy->pNext = pHead;
		pNowy->pPrev = nullptr;
		pHead->pPrev = pNowy;
		pHead = pNowy;
	}
	if (liczba > pTail->wartosc)
	{
		element * pNowy = new element{ liczba,nullptr,pHead->pPrev };
		pNowy->pNext = nullptr;
		pNowy->pPrev = pHead;
		pHead->pNext = pNowy;
		pTail = pNowy;
	}
	else
	{
		element * pNowy = new element{ liczba,pHead,pHead->pPrev };
		while (liczba < pHead->wartosc)
			pHead = pHead->pNext;

		pNowy->pNext = pHead;
		pNowy->pPrev = pHead->pPrev;
		pHead->pPrev = pNowy;
		pHead = pNowy;
	}
	
}
void usun(element *&pHead, element *&pTail)
{
	while (pHead)
	{
		element * pNastepnik = pHead->pNext;
		delete pHead;
		pHead = pNastepnik;
	}
	pTail = pHead;
}

int main()
{
	element * pGlowa = nullptr;
		element * pKoniec = nullptr;
		for (int i : {1, 5, 6, 34, 7, 4, 67, 43, 9})
			dodajNaPoczatek(pGlowa, pKoniec, i);
		wypisz(pGlowa, pKoniec);
		usun(pGlowa, pKoniec);
		wypisz(pGlowa, pKoniec);
<<<<<<< HEAD
		for (int i : {3,2,4,1,5})
		dodajDoListyPosortowanej(pGlowa, pKoniec, i);
=======
		for (int i : {9,7,6,4,3,2})
			dodajDoListyPosortowanej(pGlowa, pKoniec, i);
>>>>>>> c4626064dd32c774f8057d8d11ab738592e0525f
		wypisz(pGlowa, pKoniec);
		usun(pGlowa, pKoniec);
    return 0;
}

