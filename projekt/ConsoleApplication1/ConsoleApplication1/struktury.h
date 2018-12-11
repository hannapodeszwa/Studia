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
/*
			struct miastaglowne
			{
				std::string nazwamiasta;
				miastaglowne * kolejnemiasto;
				struct  miasta_sasiednie
				{
					int trasa;
					miasta_sasiednie * miastokolejne;
					miastaglowne * nastepnemiasto;
					bool odwiedzony;
				} *miastaobok;
			};
			*/

#endif
