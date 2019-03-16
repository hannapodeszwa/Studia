// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
#include<vector>
#include<chrono>
#include<random>

struct punkt
{
	double x, y, z;

};
double odleglosc(const punkt&a, const punkt&b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));

}

std::vector <punkt> losujpunkty(const int n)
{
	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::normal_distribution<double>rozklad(0, 5);

	
	std::vector<punkt> wynik(n);
	for (int i = 0; i < n; i++) {
		wynik[i].x = rozklad(silnik);
		wynik[i].y = rozklad(silnik);
		wynik[i].z = rozklad(silnik);

	}
	return wynik;
}

std::pair<punkt, punkt> znajdz(const std::vector<punkt> &chmura)
{
	auto n = chmura.size();
	double maxi = 0;
	std::pair<punkt, punkt> para;
	for (int i = 0; i < n;i++)
	{
		for (int j = i+ 1;j < n;j++)
			//odleglosc[i][j]
			while (odleglosc(chmura[i],chmura[j])<maxi)
			{
				maxi = odleglosc(chmura[i], chmura[j]);
				para.first = chmura[i];
				para.second = chmura[j];
			}
		

	}
	return para;
}

int main()
{
	punkt a, b;
	a.x = 1;
	a.y = 1;
	a.z = 1;
	b.x = 0;
	b.y = 0;
	b.z = 0;
		
	std::cout << odleglosc(a, b) << std::endl;
	
	auto punkty = losujpunkty(5);
	

	auto para = znajdz(chmura[i], chmura[j]);

    return 0;
}

