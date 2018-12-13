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
@param pHead wskaznik na pierwszy element listy
@param nowanazwa nazwa miasta dodawanego do listy
@param licznik zmienna, w ktorej przechowywana jest ilosc miast 
@return Funkcja nie zwraca niczego.
*/
void stworz_miasto(miasto * &pHead, std::string nowanazwa, int &licznik);

/*Funkcja dodaje do listy miasta polaczone z 
@param pHead wskaznik na pierwszy element listy
@param kilometry odlegosc pomiedzy miastami
@param nowe_miasto1 nazwa miasta poczatkowego
@param nowe_miasto2 nazwa miasta docelowego
@return Funkcja nie zwraca niczego.
*/
void stworz_droga(miasto * pHead_miasto, int kilometry, std::string nowe_miasto1, std::string nowe_miasto2);

/*Funkcja wypisuje liste miast
@param pHead wskaznik na pierwszy element listy
@return Funkcja nie zwraca niczego.
*/
void wypisz_miasto(miasto * pHead);

/*Funkcja znajduje najkrotsza droge z miasta startowego do pozostalych miast
@param startowy miasto, od ktorego beda rozpoczynac sie wszystkie trasy
@param pHead wskaznik na pierwszy element listy
@return Funkcja nie zwraca niczego.
*/
void algorytm(std::string startowy, miasto* pHead, miasto*pGlowa_wynik);

/*Funkcja dodaje wynik do listy
@param pHead wskaznik na pierwszy element listy
@param odleglosc najkrotsza odleglosc z miasta poczatkowego do kolejnego miasta
@param aktualne wskaznik na miasto aktualne
@param poprzednik wskaznik na miasto poprzednie
@return Funkcja nie zwraca niczego.
*/
void dodajDoListyWynik(wynik * & pHead, int odleglosc, miasto * aktualne, miasto * poprzednik);

/*Funkcja wypisuje liste z wynikami
@param pHead wskaznik na pierwszy element listy
@return Funkcja nie zwraca niczego.
*/
void wypisz_wynik(wynik * pHead);

bool sprawdz_argumenty(int ile, char ** params, std::string wejscie, std::string wyjscie, std::string start);

#endif