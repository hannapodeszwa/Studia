// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<random>
#include<chrono>

const int N = 5;

void wypelnij(double tab[N][N], const int rozmiar)
{
	
	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::normal_distribution<double>rozklad(0, 5);

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++)
		{
			tab[i][j] = rozklad(silnik);
			
		}
	} 
}


void transponuj(double tab[N][N], const int rozmiar)
{
	

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++)
		{
			int a = i;
			tab[i][j] = tab[j][a];
		}
	}
	
}
int main()
{
	double tab[N][N];
	
	wypelnij(tab, N);
	
	transponuj(tab, N);

    return 0;
}

