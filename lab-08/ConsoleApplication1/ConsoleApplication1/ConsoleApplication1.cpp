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

