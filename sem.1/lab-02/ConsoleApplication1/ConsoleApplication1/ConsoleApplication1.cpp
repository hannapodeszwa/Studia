// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;


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
//A11*x1+A12*x2=B1
//A21*x1+A22*x2=B2

double A11,A12, A21,A22, B1, B2;
A11=7;
A12=2;
A21=3;
A22=4;
B1=99;
B2=26;
//std::cout<< "B2="; std::cin >>B2;

double W =A11*A22-A21*A12;
double Wx1=B1*A22-B2*A12;
double Wx2=A11*B2-A21*B1;
if (W != 0)
{
std::cout << "x1=" << Wx1/W<< std::endl;
std::cout << "x2=" << Wx2/W<< std::endl;
}
else
{
std::cout <<"sprzeczne lub nieokreślone" << std::endl;
}




/*
double l,m, n,o,p,r;
l=11;
m=-2;
n=9;
o=8;
p=6;
r=4;

char x;

std::cout << "py=lx+m"<< std::endl;
std::cout << "ry=nx+o"<< std::endl;

std:: cout << "y=" <<(l*x+m)/p << std::endl;
double y = ((l*x+m)/p);

if (n=0)
    std:: cout << "brak x" << std::endl;
else
  {std:: cout << "x=y*r/n-o" << std::endl;
std:: cout << "x=" << y*r/n-o << std::endl;
}
*/

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

//pole trójkąta

/*
//ciąg Fibbonaciego
double k;
int fib (int k);
if (k<3)

      return 1;
else
return fib (k-2) + fib (k-1);


//tabele
/*

double rozmiar = 5;
double tablica;
tablica [0] = 1;
tablica [rozmiar - 1] = 50;
 //petla

 double z=0;
 while (z<rozmiar);
 {
     tablica [z]=z;
     std::cout<<z<< std:: endl;
     std::cout << tablica [z] << std::endl;
     z++ }

*/



/*

double l,m,n,o,p,r;
	std :: cout << "wypisz współczynniki funkcji: " << std :: endl;
	std :: cout << "l= " << std :: endl;
	std :: cin >> l;
	std :: cout << "m=  " << std :: endl;
	std :: cin >> m;
	std :: cout << "n= " << std :: endl;
	std :: cin >> n;
	std :: cout << "o= " << std :: endl;
	std :: cin >> o;
	std :: cout << "p= " << std :: endl;
	std :: cin >> p;
	std :: cout << "r= " << std :: endl;
	std :: cin >> r;
	char x;
	std :: cout << "py = lx + m " <<  std::endl;
	std::cout << "ry = nx + o " << std::endl;
	std::cout << "y= " << (l*x*+m)/p << std::endl;
	double y = ((l*x + m) / p);
		if (n > 0)
		{ std::cout << "x=y*r/n-o" << std::endl;
	std::cout << "x= " << y * r / n - o << std::endl;
		}
		else
			std::cout << "brak x" << std::endl;
			*/
	; return 0;
}
