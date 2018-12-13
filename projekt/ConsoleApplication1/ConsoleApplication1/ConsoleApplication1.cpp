#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
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
    const std::string wejscie("-i");
	const std::string wyjscie("-o");
	const std::string start("-s");

	//int params_ok = 1;
	//start == "Szczecin";
    bool params_ok = sprawdz_argumenty (ile, params, wejscie, wyjscie, start);
	if (params_ok)
	{
		for (int i = 0; i < ile; i++)
			debug(params[i]);

		//wypisanie danych z pliku
		std::string miasto1;
		std::string miasto2;
		int odleglosc=INT_MAX;
		int licznik_miast = 0;

		miasto * pGlowa = nullptr;

		//wczytajzPliku(wejscie, miasto1, miasto2, odleglosc, pGlowa, licznik_miast);
		std::ifstream plik("miasta.txt");//plik(wejscie); //("miasta.txt");
		if (plik)
		{

			std::cout << "plik otwarty" << std::endl;

			std::string linia;
			int licznik = 0;
			while (std::getline(plik, linia))
			{
				licznik++;
				std::stringstream ss;

				ss << linia;

				miasto1 = "";
				miasto2 = "";
				odleglosc = -1;
				ss >> miasto1 >> miasto2 >> odleglosc;
				//std::cout << miasto1 << " " << miasto2 << " " << odleglosc << std::endl; //dane wypisane

				if (miasto1 == "" || miasto2 == "" || odleglosc <= 0)
				{
					std::cout << "blad w wierszu " << licznik << std::endl;
					continue; //powrot do while
				}
				stworz_miasto(pGlowa, miasto1, licznik_miast);
				stworz_miasto(pGlowa, miasto2, licznik_miast);

				droga * pGlowa_droga = nullptr;
				stworz_droga(pGlowa, odleglosc, miasto1, miasto2);// stworzenie grafu (listy list)
			}

			plik.close();

		}
	
		
		std::cout << "/////////////////////////////////////////////////////" << std::endl;

		wypisz_miasto(pGlowa);
		//algorytm Dijkstry
		wynik * pGlowa_wynik = nullptr;
		algorytm(start, pGlowa, pGlowa_wynik);
		wypisz_wynik(pGlowa_wynik);

		usun(pGlowa, pGlowa_wynik);

	}
	else
		std::cout << "Bledne argumenty" << std::endl;
 return 0;
}

