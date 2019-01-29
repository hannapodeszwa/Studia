#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <vector>

#define N 100;
struct obiekt
{
	double x;
	double y;
	 int e;
};
int wczytajObiekty(const std::string& wejscie, obiekt obiekty[])
{
	int liczbaObiektow = 0;
	int rozmiar = N;
	std::ifstream plik(wejscie);
	if (plik)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			std::string linia;
			if (std::getline(plik, linia))
			{
				std::stringstream ss;
				double x = 0;
				double y = 0;
				int e = 0;
				ss << linia;
				ss << x << y << e;
				obiekty[i]= { x,y,e };
				liczbaObiektow++;
			}
		}
		plik.close();
		return liczbaObiektow;
	}
	return -1;
}

double odleglosc(const obiekt &obiekt1, const obiekt &obiekt2)
{
	double odleglosc = 0;
	return odleglosc = sqrt((obiekt1.x - obiekt2.x)*(obiekt1.x - obiekt2.x)+ (obiekt1.y - obiekt2.y)*(obiekt1.y - obiekt2.y));
}

void knn(const obiekt treningowy[], int n, obiekt& Q, int k)
{
	std::vector<double> odleglosci(n);
	std::vector<int> etykiety(k);
	std::vector<int> najczestsza(k); 
	for (int i = 0; i < n ;i++)			//odleglosci do wszystkich
		odleglosci[i]=odleglosc(treningowy[i], Q);
	for (int i = 0; i < k; i++) // znalezienie k najblizszych
	{
		double najblizsza_odleglosc = INT_MAX;
		int j;
		for ( j = 0; j < n; j++)
		{
			if (najblizsza_odleglosc > odleglosci[j])
				najblizsza_odleglosc = odleglosci[j];
		}
		for (j = 0; j < n; j++)
		{
			if(odleglosci[j]==najblizsza_odleglosc)
			odleglosci[j] = INT_MAX;
		}
	}
	for (int i = 0; i < n; i++) // etykiety k najblizszych
	{
		if (odleglosci[i] = INT_MAX)
			etykiety[i] = treningowy[i].e;
	}
	for (int i = 0; i < k; i++) //ilosc wystapien etykiet
	{
		int licznik = 1;
		for (int j = 1; j < k; j++)
		{
			if (etykiety[i] == etykiety[j])
				licznik++;
		}
		najczestsza[i] = licznik;
	}
	int etykieta = 0;
	for (int i = 0; i < k; i++)
	{		
		if (najczestsza[i] > etykieta)
			etykieta = najczestsza[i];
	}
	Q.e = etykieta;
}
int main()
{
	
}
