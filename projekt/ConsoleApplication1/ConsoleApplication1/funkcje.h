#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#ifndef funkcje_H  
#define funkcje_H

#include "struktury.h"

/*Funkcja dodaje nowe miasto do listy
@param pHead
@param nowanazwa
@return Funkcja nie zwraca niczego.
*/
void stworz_miasto(miasto * &pHead, std::string nowanazwa, int &licznik);

/*Funkcja dodaje do listy miasta polaczone z 
@param pHead
@param kilometry 
@param nowe_miasto1
@param nowe_miasto2
@return Funkcja nie zwraca niczego.
*/
void stworz_droga(miasto * pHead_miasto, int kilometry, std::string nowe_miasto1, std::string nowe_miasto2);

/*Funkcja wypisuje liste miast
@param pHead
@return Funkcja nie zwraca niczego.
*/
void wypisz_miasto(miasto * pHead);
/*Funkcja znajduje najkrotsza droge z miasta startowego do pozostalych miast
@param startowy
@param pHead
@return Funkcja nie zwraca niczego.
*/
void algorytm(std::string startowy, miasto* pHead);

#endif