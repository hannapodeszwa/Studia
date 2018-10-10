// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{

	double a, b, c;

	a = 1;
	b = 2;
	c = 3;

	if (b*b - 4 * a*c < 0)
		std::cout << "brak rozwi¹zania" << std::endl;

	else if (b*b - 4 * a*c == 0)
	{
		std::cout << "x=-b/2a" << std::endl;

		double wynik1 = -b / (2 * a);
		std::cout << wynik1 << std::endl;
	}
	else
	{

		double delta = b*b - 4 * a*c;
		std::cout << delta << std::endl;
		double wynik2 = (-b - sqrt(delta)) / (2 * a);
		double wynik3 = (-b + sqrt(delta)) / (2 * a);
		std::cout << wynik2 << std::endl;
		std::cout << wynik3 << std::endl;
	}


		double delta2 = b*b - 4 * a*c;
	double wynik4 = (-b - sqrt(delta2)) / (2 * a);

	std::cout << wynik4
		std::cout << i
		<< std::endl;


	; return 0;
}

