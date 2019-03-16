// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>

int main()
{

	const int W = 5;
	const int K = 3;
	double tab[W][K];

	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::normal_distribution<double>rozk³ad(0, 5);

	for (int w = 0; w < W; w++)
		for (int k = 0; k < K; k++)
			tab[w][k] = rozk³ad(silnik);

	for (int w = 0; w < W; w++)
	{
		for (int k = 0; k < K; k++)
			std::cout << std::setw(10) << std::setprecision(5) << tab[w][k];

		std::cout << std::endl;
	}
	//suma wierszy
	double sumaw[w] = {};
	double sumak[k] = {};

	for (int w = 0; w < W; w++)
	{
		for (int k = 0; k < K; k++)
		{
			sumaw[w] += tab[w][k];
			sumak[k] += tab[w][k];

		}
	}


	std::cout <<sumaw[w] << std::endl;
	std::cout << sumak[k] << std::endl;
	

		return 0;
}

