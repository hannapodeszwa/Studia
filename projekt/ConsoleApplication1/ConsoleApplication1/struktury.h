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
    miasto * pmiasto;
    droga *miastaobok;
	bool odwiedzony;
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
};

#endif
