#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include "string.h"
#include "pch.h"
#include "struktury.h"
#include "funkcje.h"   
//#include "vld.h""

#define debug(x) std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl;

// sprawdzanie argumentow wywolania programu
// wczytac dane do struktury danych
// alg. Dijkstry
// wypisanie wyniku
// zwolnienie pamieci
// return 0;

// VS: solution explorer , prawym klawiszem na nazwe projetku -> properties -> debug -> command line parameters (?) 

int main(int ile, char ** params)
{	
	std::string wejscie = "", wyjscie = "", start = "";
  // bool params_ok = sprawdz_argumenty (ile, params, wejscie, wyjscie, start);
	bool params_ok = true; //TEST
	start = "Poznan"; //TEST 
	if (params_ok)
	{
		for (int i = 0; i < ile; i++)
			debug(params[i]);

		//wypisanie danych z pliku
		miasto * pGlowa = nullptr;
		wczytajzPliku(wejscie, pGlowa);
			
		std::cout << "/////////////////////////////////////////////////////" << std::endl;
//		wypisz_miasto(pGlowa);
		//algorytm Dijkstry
		wynik * pGlowa_wynik = nullptr;
		std::cout << "/////////////////////////////////////////////////////" << std::endl;
		algorytm(start, pGlowa, pGlowa_wynik);
		wypisz_wynik(pGlowa); // wypisanie wyniku

		usun(pGlowa, pGlowa_wynik);

	}
	else
		std::cout << "Bledne argumenty" << std::endl; // wyswietl help
 return 0;
}

