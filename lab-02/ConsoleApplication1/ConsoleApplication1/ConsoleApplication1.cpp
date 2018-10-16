// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <math.h>

int main()
{
//równanie kwadratowe
	double a, b, c;

	a = 1;
	b = 2;
	c = 3;

	if (b*b - 4 * a*c < 0)
		std::cout << "brak rozwi�zania" << std::endl;

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
//równanie kwadratowe (liczby zespolone)

		double delta2 = b*b - 4 * a*c;
  if (delta2 < 0)
  {
//	std::cout << "Re: " << -b/2/a <<std::endl;
	//std::cout << "Im: " << -sqrt(-delta2)/2/a <<std::endl;

	std::cout << -b/2/a << -sqrt(-delta2)/2/a <<" i"<<std::endl;

	//std::cout << "Re: " << -b/2/a <<std::endl;
//	std::cout << "Im: " << +sqrt(-delta2)/2/a <<std::endl;
	std::cout << -b/2/a <<"+"<< sqrt(-delta2)/2/a <<" i"<<std::endl;

  }

//		std::cout << i	<< std::endl;  //


//równanie liniowe

double e,f;

std::cout << "y=ax+b"<< std::endl;

e=2;
f=3;

//bmi

double masa, wzrost;
masa=20; //w kg;
wzrost =123; //w m

std::cout<< "bmi" <<masa/wzrost/wzrost << std::endl;

//trójkąt prostokątny

double h,i,j;

h=3;
i=4;

std::cout<< "c=" << sqrt(h*h+(i*i)) << std::endl;






	; return 0;
}

