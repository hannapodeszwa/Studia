#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

#include<limits.h>
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
    bool params_ok = sprawdz_argumenty (ile, params, wejscie, wyjscie, start);
	
	if (params_ok)
	{
		//wypisanie danych z pliku
		miasto * pGlowa = nullptr;
		wczytajzPliku(wejscie, pGlowa);

		//algorytm Dijkstry
		Dijkstra(start, pGlowa);
		wypisz_wynik(pGlowa, wyjscie); // wypisanie wyniku
		usun(pGlowa); 
	}
	else
	{
        ///@todo do funkcji help
		if (ile >= 2)
			if (std::string(params[1]) == std::string("-h")) // wyswietl help
			{
				std::cout << std::endl;
				std::cout <<"SPEDYCJA"<< std::endl;
				std::cout << std::string(params[0]) << " -i <plik_wejsciowy> -s miasto -o <plik_wyjsciowy>" << std::endl;
				std::cout << std::endl;
				std::cout << "Program tworzy najkrotsze mozliwe trasy pomiedzy miastem startowym a wszystkimi innymi miastami" << std::endl;
				std::cout << std::endl;
				std::cout << " -i: plik z danymi wejsciowymi" << std::endl;
				std::cout << " -o: plik, w ktorym bedzie zapisany wynik" << std::endl;
				std::cout << " -s: miasto startowe" << std::endl;
				return false;
			}
		std::cout << std::endl;
		std::cout << "Bledne argumenty" << std::endl;
	}
 return 0;
}

