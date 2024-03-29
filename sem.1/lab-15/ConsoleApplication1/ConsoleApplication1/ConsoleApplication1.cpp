// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <limits>
#include<cmath>
#include<vector>
#include<chrono>
#include<random>
#include <iomanip>
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>


int losuj()
{
	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> rozklad_int (5, 10);
	return rozklad_int(silnik);
}

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
		else
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
void wypisz_Student(Student * pHead)
{
	while (pHead)
	{
		std::cout << pHead->nazwisko << std::endl;
		pHead = pHead->pNext;
	}
}

void wypisz(Egzaminator * pHead)
{
	while (pHead)
	{
		std::cout << std::endl;
		std::cout << pHead->nazwisko << std::endl;
		wypisz_Student(pHead->pStudenci);
		pHead=pHead->pNext;
	}
}

int main()
{

	Egzaminator* pHead = nullptr;
	Student * nowyStudent = nullptr;
		srand(time(NULL));
		std::string wylosowane;
		for (int j = 0; j < 10; j++)
		{
			wylosowane = "";
			std::string los = "";
			int liczba = losuj();
			for (int i=0; i<liczba; i++)
			{
				los = ((rand() % ('z' - 'a')) + 'a');
				wylosowane = wylosowane + los;
			}
			//std::cout << wylosowane << std::endl;
			
			std::string nazwisko = wylosowane;
			dodajEgzaminatora(pHead, nazwisko);
			for (int i : { 5, 2, 8, 1, 0, 6, 3 })
			{
				
				//dodajStudentaEgzaminatorowi(nowyStudent, pHead, nazwisko, i);
			}
		}

		wypisz(pHead);
	
    return 0;
}

