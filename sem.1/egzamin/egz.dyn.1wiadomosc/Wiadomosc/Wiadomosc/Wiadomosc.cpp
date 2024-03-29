#include "pch.h"
#include <iostream>

struct Wiadomosc
{
	std::string tresc;
	int czas;
	Wiadomosc*next;
};

struct Osoba
{
	std::string imie;
	Wiadomosc * wiadomosci;
	Osoba * prev, *next;
};

void dodaj(Osoba * &pHead, std::string &tresc, int czas, std::string &imie)
{
	Wiadomosc * nowaWiadomosc = new Wiadomosc{ tresc, czas,nullptr };
		if (!pHead)
		{
			Osoba * pNowy = new Osoba{ imie, nowaWiadomosc, nullptr,nullptr };
			return;
		}
	Osoba* p = pHead;
	while (p&&p->imie != imie)
		p = p->next;
	if(p==nullptr)
		Osoba * pNowy = new Osoba{ imie, nowaWiadomosc, nullptr,nullptr };
	else
	{
		Wiadomosc * r = p->wiadomosci;
		if (!r)
		{
			p->wiadomosci = nowaWiadomosc;
			return;
		}
		while (r->czas<czas)
			r = r->next;
		nowaWiadomosc->next = r->next;
		r->next = nowaWiadomosc;
	}
}

void usun(Osoba*&pHead,std::string imie, int czas)
{
	if (!pHead)
		return;
	Osoba * p = pHead;
	while (p&&p->imie != imie)
		p = p->next;
	if (!p)
		return;
	else
	{
		Wiadomosc * r = p->wiadomosci;
		if (!r)
		{
			return;
		}
		while (r->czas != czas)
			r = r->next;
		Wiadomosc * nastepny = r->next;
		delete r;
		r = nastepny;

	}

	
}

int main()
{
    std::cout << "Hello World!\n"; 
}
