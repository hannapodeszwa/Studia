#include "pch.h"
#include <iostream>
#include <fstream>
#include<sstream>
#include <string>

bool funkcja(std::string nazwa)
{
	std::ifstream plik(nazwa);
	int licznik = 0;
	if (plik)
	{
		const int rozmiar = 8;
		char tab[rozmiar][rozmiar];
		for (int i = 0; i < rozmiar; i++)
		{
			std::string linia;
			if (std::getline(plik, linia))
			{
				for (int j = 0; j < rozmiar; j++)
					tab[i][j] = linia[j];
			}
		}
		//wiersze
		for (int i = 0; i < rozmiar; i++)
		{
			licznik = 0;
			for (int j = 0; j < rozmiar; j++)
			{
				if (tab[i][j] == 'H')
					licznik++;
			}
			if (licznik > 1)
				return false;
		}

		//kolumny
		for (int j = 0; j < rozmiar; j++)
		{
			licznik = 0;
			for (int i = 0; i < rozmiar; i++)
			{
				if (tab[i][j] == 'H')
					licznik++;
			}
			if (licznik > 1)
				return false;
		}

		//ukos
		//z lewej
		//srodek
		for (int i = 0; i < rozmiar; i++)
		{
			licznik = 0;
			
				if (tab[i][i] == 'H')
					licznik++;
		}
		if (licznik > 1)
			return false;
		for(int a=1; a<8; a++) //po wierszach z lewej z gory
		{
			licznik = 0;
			for (int i = a, j=0; i < rozmiar && j < rozmiar; i++, j++)
			{
				
					if (tab[i][j] == 'H')
						licznik++;
			}
			if (licznik > 1)
				return false;
		}
		for (int a = 1; a < 8; a++) //po kolumnach z lewej z gory
		{
			licznik = 0;
			for (int i = 0, j=a; i < rozmiar && j < rozmiar; i++, j++)
			{
				if (tab[i][j] == 'H')
					licznik++;
			}
			if (licznik > 1)
				return false;
		}
		//z prawej
		//srodek
		for (int i = 0, j=7; i < rozmiar && j > -1; i++, j--)
		{
			licznik = 0;
			if (tab[i][j] == 'H')
				licznik++;
		}
		if (licznik > 1)
			return false;
		for (int a = 6; a >-1; a--) //po kolumach z prawej
		{
			licznik = 0;
			for (int i = 0, j = a; i < rozmiar && j > -1; i++, j--)
			{
				if (tab[i][j] == 'H')
					licznik++;
			}
			if (licznik > 1)
				return false;
		}
		for (int a = 1; a<8; a++) // po wierszach z prawej
		{
			licznik = 0;
			for (int i = a, j = 7; i < rozmiar && j > -1; i++, j--)
			{
				if (tab[i][j] == 'H')
					licznik++;
			}
			if (licznik > 1)
				return false;
		}
		plik.close();
	}
	return true;
}
int main()
{
	std::string nazwa = "plik.txt";
		bool wynik=funkcja(nazwa);
		if (wynik == false)
			std::cout << "zle";
		std::cout << "ok";
}
