#include "stdafx.h"
#include <iostream>
#include <limits>
#include<cmath>
#include<vector>
#include<chrono>
#include<random>
#include <iomanip>


struct stGenom
{
	double gen;
	stGenom * pNast;
};
struct stBakteria
{
	std::string nazwa;
	stBakteria * pNast;
	stGenom * pGenom;
};
/*
std::default_random_engine silnik;
silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
std::normal_distribution<double>rozklad(0, 5);
std::uniform_int_distribution<int>rozklad_int(15, 20);
*/


void dodaj(stGenom *&pGenom, stGenom * pFragment)
{
	if (pFragment == nullptr)
		return;
	stGenom *ostatniFragment = pFragment;
	// 
	while (ostatniFragment->pNast != nullptr)
		ostatniFragment = ostatniFragment->pNast;

	if (pGenom == nullptr)
	{
		pGenom = pFragment;
		ostatniFragment->pNast = pFragment;
	}
	else
	{
		stGenom*p = pGenom;
		stGenom *ostatniGenom = p;
		while (ostatniGenom->pNast != pGenom)
			ostatniGenom = ostatniGenom->pNast;

		ostatniFragment->pNast = pGenom;
		ostatniGenom->pNast = pFragment;

		pGenom = pFragment;
	}
}

stGenom * wytnij(stGenom *&pGenom, int ile)
{
	if (ile <= 0 || pGenom == nullptr)
		return nullptr;
	else
	{
		stGenom *ostatniGenom = pGenom;
		while (ostatniGenom->pNast != pGenom)
			ostatniGenom = ostatniGenom->pNast;
		stGenom * pFragment = pGenom;
		stGenom * p = pGenom;
		while (ile > 0)
		{
			p = p->pNast;
			ile--;
		}
		
		ostatniGenom->pNast = p;
		pGenom = p;
		return pFragment;
	}
	
}

double ocen(stGenom * pGenom)
{
	return 0;
}

void znajdz(stBakteria * pGlowa, stBakteria *&pNajgorsza, stBakteria *&pNajlepsza)
{
	stBakteria*p = pGlowa;
	double najgorsza = INT_MAX;
	double najlepsza = -INT_MAX;
	while (p)
	{
		double ocena =ocen(p->pGenom);
		if (ocena > najlepsza)
		{
			najlepsza = ocena;
			pNajlepsza = p;
		}
		if (ocena < najgorsza)
			pNajgorsza=p; //...............
		p = p->pNast;
	}
}
int ile(stGenom * pGenom)
{
	return 0;
}
void krzyzuj(stBakteria * pGronkowiec, stBakteria * pPaciorkowiec)
{
	if (ile(pGronkowiec->pGenom) <= 1 || ile(pPaciorkowiec->pGenom) <= 1)
	{
		//std::cout << "Brak mozliwosci krzyzowania." << std::endl;
		return;
	}
	stGenom *pFragmentGronkowice = wytnij(pGronkowiec->pGenom, ile(pGronkowiec->pGenom) / 2);// -(ile(pGronkowiec->pGenom) % 2) / 2);

	stGenom *pFragmentPaciorkowiec = wytnij(pPaciorkowiec->pGenom, ile(pPaciorkowiec->pGenom) / 2 - (ile(pPaciorkowiec->pGenom)%2)/2);

	dodaj(pGronkowiec->pGenom, pFragmentPaciorkowiec);
	dodaj(pPaciorkowiec->pGenom, pFragmentGronkowice);
}



int main()
{
	stGenom *pGenom = nullptr;
	
    return 0;
}

