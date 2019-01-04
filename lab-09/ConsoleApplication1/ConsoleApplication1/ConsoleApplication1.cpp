// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>

typedef int typ;
struct element
{
	typ wartosc;
	element*pNext;

};

void dodaj(element * & pHead, typ liczba)
{
	pHead = new element{ liczba, pHead };
}
void wypisz(element * pHead)
{
	while (pHead)
	{
		std::cout << pHead->wartosc << " ";
		pHead = pHead->pNext;
	}
	std::cout << std::endl;
}

void usunElement(element * &pHead, typ liczba)
{
	if (pHead)
	{
		if (pHead->wartosc == liczba)
		{
			auto p = pHead -> pNext;
			delete pHead;
			pHead=p;
		}
		else 
		{
			if (liczba == pNext->wartosc)
			{
				auto p = pNext;
				pHead = pNext;
				p = p->pNext;
				delete pHead;
				pHead = pNext;
			}
			else
				pHead = pNext;
		}
			
		}
}

int main()
{
	element * pGlowa = nullptr;
	for (int i : { 3, 54, 6, 5, 43, 5})
		dodaj(pGlowa, i);
		wypisz(pGlowa);

		for (int i : { 5,6})
		{
			std::cout << "usun:  " << i << std::endl;
			usunElement(pGlowa, i);
		}
		wypisz(pGlowa);
    return 0;
}

