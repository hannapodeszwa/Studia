#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "string.h"
#include "pch.h"
#include "struktury.h"
//#include "funkcje.h"   // Pliki funkcje.h funkcje.cpp trzeba dodac do repozytorium!
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
    std::string wejscie;
	std::string wyjscie;
	std::string start;
    //bool params_ok = sprawdz_argumenty (ile, params, wejscie, wyjscie, start);
    
    
    for (int i = 0; i < ile; i++)
        debug(params[i]);
    
    
    
    const std::string WEJSCIE ("-i");
	/*
	ile = 6;
	params[1] = "-i";
	params[2] = "wejscie";
	params[3] = "-o";
	params[4] = "wyjscie";
	params[5] = "-s";
	params[6] = "start";
	*/

	while (ile > 1)
	{
		if (strcmp(params[1], "-i") == 0)    // if (std::string (params[1]) == WEJSCIE)  { // .... 
		{
			wejscie = params[2];
            debug(wejscie);
				ile -= 2;
				params += 2;
				continue;
		}
		if (strcmp(params[1], "-o") == 0)
		{
			wyjscie = params[2];
			ile -= 2;
			params += 2;
			continue;
		}
		if (strcmp(params[1], "-s") == 0)
		{
			start = params[2];
			ile -= 2;
			params += 2;
			continue;
		}
	}   
	std::cout << wejscie << std::endl;
	std::cout << wyjscie << std::endl;
	std::cout << start << std::endl;
	//wypisanie danych z pliku
	std::string miasto1;
	std::string miasto2;
	int odleglosc;
	int licznik_miast = 0;

	miasto * pGlowa = nullptr;
    
    debug(wejscie);

	std::ifstream plik (wejscie);//("miasta.txt");//(wejscie);
	if (plik)
	{
        
        std::cout << "plik otwarty" << std::endl;
        /*
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
			std::cout << miasto1<<" " <<miasto2<<" "<<odleglosc<< std::endl; //dane wypisane

			if (miasto1 == "" || miasto2 == "" || odleglosc <= 0)
			{
				std::cout << "blad w wierszu " << licznik << std::endl;
				continue; //powrot do while
			}
			stworz_miasto(pGlowa, miasto1, licznik_miast);
			stworz_miasto(pGlowa, miasto2, licznik_miast);

			droga * pGlowa_droga = nullptr;
			stworz_droga(pGlowa, odleglosc, miasto1, miasto2); // stworzenie grafu (listy list)
		}
	    */
		plik.close();
		
	}
	/*else
	{
		throw std::system_error(errno, std::system_category());

	}*/
    /*
	std::cout << "/////////////////////////////////////////////////////" << std::endl;
	wypisz_miasto(pGlowa);

	//algorytm Dijkstry
	const int rozmiar = licznik_miast;
	std::cout << rozmiar;
	*/
    //int koszt_dojscia[rozmiar];
	//std::string trasa_miasta[rozmiar];
	//algorytm(start, pGlowa);

 return 0;
}

