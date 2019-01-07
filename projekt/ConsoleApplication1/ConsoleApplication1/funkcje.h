#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <ios>
#include<limits.h>
#ifndef funkcje_H  
#define funkcje_H

#include "struktury.h"

/**Funkcja dodaje nowe miasto do listy
@param pHead wskaznik na pierwszy element listy
@param nowanazwa nazwa miasta dodawanego do listy
@return Funkcja zwraca wskaünik na nowoutworzone miasto.
*/
miasto * stworz_miasto(miasto * &pHead, std::string nowanazwa);

/**Funkcja dodaje do listy miasta polaczone z 
@param pHead_miasto wskaznik na pierwszy element listy
@param kilometry odlegosc pomiedzy miastami
@param nowe_miasto1 wskaznik na  miasto poczatkowe 
@param nowe_miasto2 wskaznik na  miasto docelowe
@return Funkcja nie zwraca niczego.
*/
void stworz_droga(miasto * &pHead_miasto, int kilometry, miasto * &nowe_miasto1, miasto * &nowe_miasto2);

/**Funkcja wypisuje liste miast
@param pHead wskaznik na pierwszy element listy
@return Funkcja nie zwraca niczego.
*/
void wypisz_miasto(miasto * pHead);

/**Funkcja znajduje najkrotsza droge z miasta startowego do pozostalych miast
@param startowy miasto, od ktorego beda rozpoczynac sie wszystkie trasy
@param pHead wskaznik na pierwszy element listy
@return Funkcja nie zwraca niczego.
*/
void algorytm(std::string startowy, miasto* &pHead);

/**Funkcja zapisuje wynik do pliku wyjsciowego							
@param pHead wskaznik na pierwszy element listy
@param wyjscie nazwa pliku wyjsciowego
@return Funkcja nie zwraca niczego.
*/
void wypisz_wynik(miasto * pHead, std::string wyjscie);

/**Funkcja zapisuje trasy do pliku wyjsciowego								
@param pHead wskaznik na pierwszy element listy
@param wyjscie nazwa pliku wyjsciowego
@return Funkcja nie zwraca niczego.
*/
void wypisz_miasta(miasto * pHead, std::ostream &wyjscie);

/**Funkcja sprawdza argumenty wywolania programu
@param ile ilosc argumentow
@param params tablica argumentow
@param[out] wejscie plik wejsciowy
@param[out] wyjscie plik wyjsciowy
@param[out] start miasto startowe
@return Funkcja nie zwraca niczego.
*/
bool sprawdz_argumenty(int ile, char ** params, std::string & wejscie, std::string & wyjscie, std::string& start);

/**Funkcja wczytuje dane z pliku
@param wejscie nazwa pliku wejsciowego
@param pGlowa wskaznik na pierwszy element listy
*/
void wczytajzPliku(std::string wejscie,miasto * &pGlowa);

/**Funkcja usuwa liste drog
@param pmiasto wskaznik na kolejne miasto
@return Funkcja nie zwraca niczego.
*/
void usun_droge( miasto*pmiasto);

/**Funkcja usuwa liste miast
@param pHead wskaznik na pierwszy element listy
@return Funkcja nie zwraca niczego.
*/
void usun_miasta(miasto* &pHead);

/**Funkcja usuwa liste miast i drog
@param glowa_miasta wskaznik na pierwszy element listy miast
@return Funkcja nie zwraca niczego.
*/
void usun(miasto * glowa_miasta);

#endif
