#include "pch.h"
#include <iostream>
#include <fstream>
#include<vector>
#include<chrono>
#include<random>
#include <iomanip>
#include <sstream>

bool sudoku(std::string nazwa)
{
	const int rozmiar = 9;
	char tab[rozmiar][rozmiar];
	std::ifstream plik(nazwa);
	if (plik)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			std::string linia;
			if (std::getline(plik, linia))
			{
				for (int j = 0; j < rozmiar; j++)
				{
					tab[i][j] = linia[j];
					std::cout << tab[i][j];
				}
				std::cout << std::endl;
			}
			
		}
		//wiersze
		for (int a = 0; a < rozmiar; a++)
		{
			for (int b = 0; b < rozmiar; b++)
			{
				for (int j = b + 1; j < rozmiar; j++)
				{
					if (tab[a][b] == tab[a][j])
					{
						std::cout << a << " " << b <<"wiersz"<< std::endl;
						return false;
					}
				}
			}
		}
		//kolumny
		for (int b = 0; b < rozmiar; b++)
		{
			for (int a = 0; a < rozmiar; a++)
			{
				for (int i = a + 1; i < rozmiar; i++)
				{
					if (tab[a][b] == tab[i][b])
					{
						std::cout << a << " " << b << "kolumna" << std::endl;
						return false;
					}
				}
			}
		}
		//kwadrat
		for (int i = 0; i < rozmiar; i += 3)
		{

			for (int j = 0; j < rozmiar; j += 3) //wieksze kwadraty
			{
				for (int c = i; c < (i + 3); c++)
				{
					for (int d = j; d < (j + 3); d++) //przesuwanie sie po elemenatch mniejszego kwadratu
					{
						for (int a = i; a < (i + 3); a++)
						{
							for (int b = j; b < (j + 3); b++)
							{
								if (c == a && d == b)
									break;
								if (tab[c][d] == tab[a][b])
								{
									std::cout << c << " " << d << "kwadrat" << std::endl;
									return false;
								}
							}
						}
					}
				}
			}

		}
	
		plik.close();
	}
	return true;
}

int main()
{
	std::string plik = "plik.txt";
	bool wynik =sudoku(plik);	
	if (wynik == false)
		std::cout << "Blad" << std::endl;
	else
		std::cout << "ok";
}

