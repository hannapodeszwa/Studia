#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#ifndef STRUKTURY_H  
#define STRUKTURY_H

struct droga;
struct miasto 
{
    std::string nazwamiasta;
    miasto * pmiasto;   // nastepne miasto na liœcie miast
    droga *miastaobok;  // lista dróg z danego miasta
	bool odwiedzony;    // 
	int odleglosc_od_centrali;
	miasto * pMiastoPoprzednie;
};

struct droga   
{
        int trasa;
        droga * pdroga;
        miasto * pmiasto;
};

struct wynik
{
	int odleglosc;
	miasto * poprzednik;
	miasto * aktualne;
	wynik * pwynik;
};

#endif
