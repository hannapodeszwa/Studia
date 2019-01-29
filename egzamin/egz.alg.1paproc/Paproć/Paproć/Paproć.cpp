#include "pch.h"
#include <iostream>
#include <fstream>
#include<vector>
#include<chrono>
#include<random>
#include <iomanip>


void Barnsley(std::string &nazwa, int liczba_punktow)
{
	double x=0, y = 0;

	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());


	std::ofstream plik(nazwa); //zapisanie do pliku
	if (plik)
	{
		plik << "0 0" << std::endl;
//for (int i=1; i<liczba_punktow; i++)
		while(liczba_punktow-1)
		{
			std::uniform_int_distribution<int>rozklad(1, 100);
			int prawdopodobienstwo = rozklad(silnik);
			//std::cout << prawdopodobienstwo << std::endl;

			if (0 <= prawdopodobienstwo && prawdopodobienstwo < 86)
			{
			double  x1 = 0.85 * x + 0.04 * y;
				 double y1 = -0.04 * x + 0.85 * y + 1.6;
				 x = x1;
				 y = y1;
			}
			else if (86 <= prawdopodobienstwo && prawdopodobienstwo < 93)
			{
				double x1 = -0.15 * x + 0.28 * y;
				double y1 = 0.26 * x + 0.24 * y + 0.44;
				x = x1;
				y = y1;
			}

			else if (93 <= prawdopodobienstwo && prawdopodobienstwo < 100)
			{
				double x1 = 0.2 * x - 0.26 * y;
				double y1 = 0.23 * x + 0.22 * y + 1.6;
				x = x1;
				y = y1;
			}
			else
			{
				double x1 = 0;
				double y1 = 0.16 * y;
				x = x1;
				y = y1;
			}
			std::cout << x<<" "<<y << std::endl;
			plik << x << " " << y << std::endl;
			liczba_punktow--;
		}
			plik.close();
		
	}
}

int main()
{
	std::string wynik= "wynik";
	Barnsley(wynik, 100);
	return 0;
}


