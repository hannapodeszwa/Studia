#include "pch.h"
#include <iostream>

struct Zadanie
{
	int piorytet;
	std::string tresc_zadania;
	Zadanie * pLewy, *pPrawy;
};

struct Pracownik
{
	std::string nazwisko;
	Pracownik * pPrev, *pNext;
	Zadanie * pZadania;
};

Pracownik *znajdzLubDodajPracownika(Pracownik * &pHead,Pracownik * &pTail, std::string nazwisko)
{
	if (!pHead)
	{
		Pracownik * pNowy = new Pracownik{nazwisko,nullptr, nullptr, nullptr};
		pHead = pNowy;
		pTail = pNowy;
		return pHead;
	}
	Pracownik * p = pHead;
	while (p&& p->nazwisko != nazwisko)
		p = p->pNext;
	if (p->nazwisko == nazwisko)
		return p;
	else
	{
		p = pHead;
		Pracownik * poprzedni = nullptr;
		while (p->nazwisko < nazwisko)
			poprzedni = p;
			p = p->pNext;
		Pracownik * pNowy = new Pracownik{ nazwisko,poprzedni, p,nullptr };
		poprzedni->pNext = pNowy;
		p->pPrev = pNowy;
		if (pTail == p)
			pTail = pNowy;
		return pNowy;
	}
}
void dodajZadanie(Zadanie * &pRoot, std::string &tresc, int piorytet)
{
	Zadanie * p = pRoot;
	if (!pRoot)
		Zadanie * pNowy = new Zadanie{ piorytet, tresc, nullptr, nullptr };
	else
	{
		
			if (p->piorytet > piorytet)
				dodajZadanie(p->pLewy, tresc, piorytet);
			else 
				dodajZadanie(p->pPrawy, tresc, piorytet);
		
	}
}

void dodajZadaniePracownikowi(Pracownik * &pHead, Pracownik * &pTail, std::string nazwisko, std::string tresc, int piorytet)
{
	if (!pHead)
	{
		dodajZadanie(znajdzLubDodajPracownika(pHead, pTail,nazwisko)->pZadania,tresc, piorytet);
	}
	Pracownik * p = pHead;
	while (p&&p->nazwisko != nazwisko)
		p = p->pNext;
	if(!p)
		dodajZadanie(znajdzLubDodajPracownika(pHead, pTail, nazwisko)->pZadania, tresc, piorytet);
	else
	{
		dodajZadanie(p->pZadania, tresc, piorytet);
	}
}

void usunPracownikowBezZadan(Pracownik * &pHead)
{
	if (!pHead)
		return;
	Pracownik * p = pHead;
	if (!p->pZadania)
	{
		Pracownik * nastepny = p->pNext;
		Pracownik * poprzedni = p->pPrev;
		delete p;
		p = nastepny; // p->pPrev->pNext = nastepny;
		p->pNext->pPrev = poprzedni;

	}
}

void odwrocKolejnoscPracownikow(Pracownik * pHead, Pracownik * pTail)
{
	if (!pHead)
		return;
	Pracownik * p = pHead;

	while (p)
	{
		Pracownik * nowyPoprzedni = p->pNext;
		Pracownik * nowyNastepny = p->pPrev;
		p->pNext = nowyNastepny;
		p->pPrev = nowyPoprzedni;
		p = p->pPrev; //
	}
	
	pTail = p;
	pTail = pHead; 
	pHead = p; 

}
int cos()
{
	int tab[1][2];

	return tab[1][1];
}
int main()
{ 

}
