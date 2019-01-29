#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <chrono>
#include <iomanip>

std::string nazwa_miesiaca(int n)
{
	std::string nazwa;
	if (n == 1)
		nazwa = "styczen";
	if (n == 2)
		nazwa = "luty";
	if (n == 3)
		nazwa = "marzec";
	if (n == 4)
		nazwa = "kwiecien";
	if (n == 5)
		nazwa = "maj";
	if (n == 6)
		nazwa = "czerwiec";
	if (n == 7)
		nazwa = "lipiec";
	if (n == 8)
		nazwa = "sierpien";
	if (n == 9)
		nazwa = "wrzesien";
	if (n == 10)
		nazwa = "pazdziernik";
	if (n == 11)
		nazwa = "listopad";
	if (n == 12)
		nazwa = "grudzien";
	
	return nazwa;
}

int dzien_tygodnia(int rok, int miesiac, int dzien)
{
	return miesiac%7+1;
}

void kalendarz(int rok, std::string nazwa)
{
	
	std::ofstream plik(nazwa);

	if (plik)
	{
		for (int i = 1; i < 13; i++) //kolejne miesiace
		{
			plik << nazwa_miesiaca(i) << " " << rok << std::endl;
			plik << "pn wt sr cz pt sb nd" << std::endl;
			const int rozmiar = 5;
			int tab[rozmiar][7] = { };
			int dni;
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			{
				dni = 31;
			}
			else if (i == 2)
			{
				if (przestepny(rok))
					dni = 29;
				else
					dni = 28;
			}
			else
			{
				dni = 30;
			}
			int tydzien = dzien_tygodnia(rok, i, 1);
			int a;
			for (a = 1; a < tydzien + dni; a++)
			{
				if (a < tydzien)
				{
					plik << "   ";
				}
				else
				{
					plik << std::setw(2) << a - tydzien + 1 << " ";
					if (a % 7 == 0)
						plik << std::endl;
				}

			}
			if (a % 7 != 1)
			{
				plik << std::endl;
			}
			plik << std::endl;
		}
		plik.close();
	}
}

bool przestepny(int rok)
{
	if (rok % 100 == 0)
		if (rok % 400 == 0)
			return true;
		else if (rok % 4 == 0)
			return true;
		else
			return false;
}

	
int main()
{
	std::string wynik = "wynik";
	kalendarz(2019, wynik);
}

