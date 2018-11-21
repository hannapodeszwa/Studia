// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

double funkcja(double x)
{
	double wynik = x;
	return wynik;
}

double calkuj(double a, double b, int n)
{
	double suma = 0;
	double dx = (b - a) / n;
	for (double x = a;x < b;x+=dx)
	{
		double poletko = funkcja(x)*dx;
		suma += poletko;
	}
	return suma;
}



double calkuj(double a, double b, int n,double(*pfunkcja)(double x))
{
	double suma = 0;
	double dx = (b - a) / n;
	for (double x = a;x < b;x += dx)
	{
		double poletko = pfunkcja(x)*dx;
		suma += poletko;
	}
	return suma;
}



int main()
{
	funkcja(5);
	std::cout<<calkuj(0, 5, 100)<<std::endl;
	double(*pfunkcja)(double x);
	//std::cout << calkuj(0, 5, 100, (*pfunkcja)) << std::endl;
	std::cout << calkuj(0, acos(-1), 1000, sin) << std::endl;

	double(*tab[])(double x) = { funkcja, sin,cos,sqrt };

	int rozmiar = 4;
	for (int i = 0; i < rozmiar;i++)
	{
		std::cout << calkuj(0, acos(-1), 1000, tab[i]) << std::endl;
	}
    return 0;
}

