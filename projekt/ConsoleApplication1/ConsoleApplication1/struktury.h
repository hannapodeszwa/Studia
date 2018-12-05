#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#ifndef STRUKTURY_H  
#define STRUKTURY_H

struct trasa
{
	std::string miasto1, miasto2;

	double odleglosc;
};

struct miasta_sasiednie;
struct miastaglowne // miasto (?)
{
    std::string nazwamiasta;
    miastaglowne * kolejnemiasto;
    miasta_sasiednie *miastaobok;
};

struct miasta_sasiednie   // droga (?)
{
        int trasa;
        miasta_sasiednie * miastokolejne;
        miastaglowne * nastepnemiasto;
        bool odwiedzony;
};

#endif
