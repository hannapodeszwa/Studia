// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl
#define and &&
#define or ||
#define not !
#include <iostream>   
#include <fstream> 
#include <sstream> 
#include <string.h>
#include <iomanip>
#include <ios>
#include <algorithm>
typedef int typ;  // b�dziemy mogli �atwo zmieni� typ przechowywany w li�cie

				  /** w�ze� drzewa poszukiwa� binarnych */
struct wezel
{
	typ wartosc;     ///< warto�� przechowywana w w�le   
	wezel * pLewy,   ///< wska�nik na lewy potomek
		*pPrawy;  ///< wska�nik na prawy potemek
};
int main()
{
	for (int i : { 5, 2, 8, 1, 0, 6, 3 })
		dodajDoDrzewaRekurencyjnie(pKorzen, i);

	wypisz(pKorzen);
	std::cout << std::endl;
	//znajdzNastepnik(pKorzen, 17)
    return 0;
}

