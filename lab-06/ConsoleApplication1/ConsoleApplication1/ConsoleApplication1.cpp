#include "stdafx.h"
#include<iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include<fstream>
#include<sstream>
#include<string>

void zapisz(std::ostream &strumien)
{
	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());

	std::uniform_int_distribution<int>rozkladw(15, 20);
	std::uniform_int_distribution<int>rozkladk(3, 12);
	std::normal_distribution<double>rozkladl(0, 5);


	
	int wiersz = rozkladw(silnik);
	for (int i = 0; i < wiersz; i++)
	{
		
		int kolumna = rozkladk(silnik);
		for (int j = 0; j < kolumna; j++)
		{
			double x = rozkladl(silnik);
			std::cout << std::setw(5) << std::setprecision(2) << x;
			strumien << std::setw(5) << std::setprecision(2) << x;
			
		}
		std::cout<<std::endl;
		strumien << std::endl;
	}


}

void srednia(std::istream &wejscie, std::ostream &wyjscie)
{
	double suma = 0;
	int liczba = 0;

	double n;
	while (wejscie >> n)
	{
		suma += n;
		liczba++;
	}

	wyjscie << suma / liczba;

}

void srednia2(std::istream &wejscie, std::ostream &wyjscie)
{


	std::string linia;
	while (std::getline(wejscie, linia))
	{
		double suma = 0;
		int licznik = 0;
		std::stringstream liczby;
		liczby << linia;
		double liczba;
		while (liczby >> liczba)
		{
			suma += liczba;
			licznik++;
		}

		wyjscie << suma / licznik << std::endl;
	}
}


int main()
{
	//zapisz(std::cout);
	std::ofstream lab("losowe");
	if (lab)
	{
		zapisz(lab);
		lab.close();
	}
	std::ifstream lab1("losowe");
	if (lab1)
	{

		srednia(lab1, std::cout);
		lab1.close();
	}
	std::cout<<std::endl;
	std::cout << "***************************" << std::endl;
	std::ifstream lab2("losowe");
	if (lab2)
	{

		srednia2(lab2, std::cout);
		lab2.close();
	}


	return 0;
}