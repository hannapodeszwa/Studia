// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>




struct Student
{
	std::string nazwisko;
	Student * pNext;
	double ocena;
};

struct Egzaminator
{
	std::string nazwisko;
	Egzaminator * pNext;
	Student * pStudenci;
};

void dodajEgzaminatora(Egzaminator * &pHead, std::string &nazwisko)
{
	if (pHead == nullptr)
	{
		Egzaminator * pNowy = new Egzaminator{ nazwisko, nullptr, nullptr };
	pHead = pNowy;
}
	else
	{
		dodajEgzaminatora(pHead->pNext, nazwisko);
	}
}

int policzStudentow(Student * pHead)
{
	int licznik = 0;
	while (pHead)
	{
		licznik++;
		pHead->pNext;
	}
	return licznik;
}

void dodaj(Student * &pHead, std::string &nazwisko, double ocena)
{
	Student * p = pHead;
	Student * poprzedni = pHead;
	if (!pHead)
		Student * pNowy = new Student{ nazwisko, nullptr, ocena };
	else
	{
		while (p&&nazwisko > p->nazwisko)
		{
				poprzedni = p;
				p->pNext;
		}
		Student * pNowy = new Student{ nazwisko, p, ocena };
		if (p == pHead&&nazwisko > p->nazwisko)
			poprzedni = pNowy;
		poprzedni->pNext = pNowy;
	}
		
}
void dodajStudentaEgzaminatorowi(Student * nowyStudent, Egzaminator * pHead, std::string &nazwisko, double ocena)
{
	int liczba = 0;
	Egzaminator*p = pHead;
	Egzaminator * ten = nullptr;
	while (p)
	{
		if (int liczbaS = policzStudentow(p->pStudenci) < liczba)
		{
			liczba = liczbaS;
			ten = p;
		}
		p->pNext;
	}
	dodaj(ten->pStudenci, nazwisko, ocena);
	
}

Student * scal(Student * pHead1, Student * pHead2)
{
	Student * wynik = nullptr;
	std::string nazwisko = pHead1->nazwisko;
	double ocena = pHead1->ocena;

	dodaj(wynik, nazwisko, ocena);
	nazwisko = pHead1->nazwisko;
	ocena = pHead1->ocena;
	dodaj(wynik, nazwisko, ocena);
	return wynik;

}

int main()
{
	Egzaminator* pHead = nullptr;
	Student * nowyStudent = nullptr;
	std::string nazwisko = "fdhsfjihdsifh";
	dodajStudentaEgzaminatorowi(nowyStudent, pHead, nazwisko, 0);
	
    return 0;
}

