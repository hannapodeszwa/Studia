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
	while (ostatniFragment->pNast !=nullptr)
	{
		ostatniFragment = ostatniFragment->pNast;
	}
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
			pFragment->pNast = pGenom;
			pGenom = pFragment;
			
			ostatniFragment->pNast = pFragment;
		
	}
}
int main()
{
	stGenom *pGenom = nullptr;

    return 0;
}

