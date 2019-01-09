#ifndef STRUKTURY_H  
#define STRUKTURY_H


#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <ios>
#include<limits.h>

struct droga;
struct miasto 
{
    std::string nazwamiasta;
    miasto * pmiasto;   // nastepne miasto na li�cie miast
    droga *miastaobok;  // lista dr�g z danego miasta
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

#endif
