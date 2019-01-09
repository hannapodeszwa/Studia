// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include <iostream>
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
		//wyzerowanie ostatniego el fragmnetu
		ostatniGenom->pNast = p;
		pGenom = p;
		return pFragment;
	}
	
}
void znajdz(stBakteria * pGlowa,  stBakteria *&pNajgorsza, stBakteria* pNajlepsza)
{

}

int main()
{
	stGenom *pGenom = nullptr;

    return 0;
}

