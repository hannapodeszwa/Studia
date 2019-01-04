// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<sstream>
#include<fstream>



char tablica(std::istream & wejscie, char tab[8][8])
 {
	 std::ifstream wejscie("plik");
	std::string szachowinca;
	while(wejscie >> szachowinca)
	//while (std::getline(wejscie, szachownica))
	{
		std::stringstream znak;
		znak << szachownica;
		for (int i = 0; i < 8;i++)
		{
			for (j = 0;j < 8;j++)
				tab[i][j] = znak;
		}
	}
	return tab;
}

bool funkcja(tab)
{
	const int M = 8;
	if (H)
	{
		for (int w = 0; w < M; w++)  // dla kazdego wiersza
		{
			int liczba_hetmanow = 0;
			for (int k = 0; k < M; k++) // dla kazdego pola w wierszu
			{
				if (tab[w][k] == 'H')
					liczba_hetmanow++;
			}
		}
		if (liczba_hetmanow >1)
			return false;

		// sprawdzenie kolumn
		for (int k = 0; k < M; k++)
		{
			int liczba=0;
			for (int w = 0; w < M; w++)
			{
				if (tab[w][k] == 'H')
					liczba++;
			}
			if (liczba >1)
				return false;
		}

		// sprawdzenie przekatnych

		for (int w = 0; w < M; w++)  // dla kazdego wiersza
		{
			int liczba_hetmanow = 0;
			for (int k = 0; k < M; k++) // dla kazdego pola w wierszu
			{
				if (tab[w][k] == 'H')
					liczba_hetmanow++;
			}
		}
		if (liczba_hetmanow >= 1)
			return false;

	/*	for (int i = 0; i < 8;i++)
		{
			for (j = 0;j < 8;j++)
			{
				int a = i;
				int b = j;
				if (tab[i][j] = tab[a][j])
					return false;
				if (tab[i][j] = tab[a][b])
					return false;
				if (tab[i][j] = tab[i + 1][j + 1])
					return false;
				else
					return true;
			}
		}
	}
}
*/
int main()
{
    return 0;
}

/*

#include "stdafx.h"
#include <fstream>
#include <string>
#include <cmath>

bool f(const string &nazwa)
{
	//jak struktura danych
	bool tab[8][8] = { 0 };
	//wczytanie szachownicy ze strumienia
	std::ifstream nazwa("szachownica")
		if (nazwa)
		{
			string linia;
			int wiersz = 0;
			while (std::getline(wejscie, linia))
			{
				for (int i = 0; i < 8; i++)
					if (linia[i] == 'H')
						tab[wiersz][i] = true;
				wiersz++;
			}
			nazwa.close()
			/// konczymy wczytywanie danych z pliku
		}
		// rozpoczynay weryfikacje

	/*

				if (H)
					int licznik = 0;
					for (int i = 0; i < 8; i++)
						for (int j = 0; i < 8; i++)
					{
						if (tab[i][j] == 'H')
							licznik++;
						if (licznik > 1)
							return false;
					}
				for (int i = 0; i < 8; i++)
					for (int j = 0; i < 8; i++)
					{
						if (tab[i][j] == 'H')
							licznik++;
						if (licznik > 1)
							return false;
					}
				/*for (int i = 8; i < 0; i--)
					for (int j = 8; i < 0; i--)
					{
						if (tab[i][j] == 'H')
							licznik++;
						if (licznik > 1)
							return false;
					}
				else return true;
				if (.)
			}

			nazwa.close();
		}
		//sprawdzenie wierszy
		*/
/*
return true; // na razie zwraca zawsze true;

	}
	int main()
	{
		f(std::cout)
			return 0;
	}
*/
