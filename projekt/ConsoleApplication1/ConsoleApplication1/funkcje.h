#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#ifndef funkcje_H  
#define funkcje_H

#include "struktury.h"

/**Funkcja dodaje nowe miasto do listy
@param pHead wskaznik na pierwszy element listy
@param nowanazwa nazwa miasta dodawanego do listy
@param licznik zmienna, w ktorej przechowywana jest ilosc miast 
@return Funkcja nie zwraca niczego.
@warning Czy nie byloby lepiej, gdyby funkcja zwracala adres stworzonego miasta?
*/
miasto * stworz_miasto(miasto * &pHead, std::string nowanazwa, int &licznik);

/**Funkcja dodaje do listy miasta polaczone z 
@param pHead wskaznik na pierwszy element listy
@param kilometry odlegosc pomiedzy miastami
@param nowe_miasto1 nazwa miasta poczatkowego // przekazywalby tutaj adres, a nie nazwe
@param nowe_miasto2 nazwa miasta docelowego
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
void algorytm(std::string startowy, miasto* &pHead, wynik *&pHead_wynik);

/**Funkcja dodaje wynik do listy
@param pHead wskaznik na pierwszy element listy
@param odleglosc najkrotsza odleglosc z miasta poczatkowego do kolejnego miasta
@param aktualne wskaznik na miasto aktualne
@param poprzednik wskaznik na miasto poprzednie
@return Funkcja nie zwraca niczego.
*/
void wypisz_wynik(miasto * pHead);

void wypisz_miasta(miasto * pHead);

/**Funkcja wypisuje liste z wynikami
@param pHead wskaznik na pierwszy element listy
@return Funkcja nie zwraca niczego.
*/


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
@param wejscie
@param miasto
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

/**Funkcja usuwa liste wyników
@param pHead wskaznik na pierwszy element listy
@return Funkcja nie zwraca niczego.
*/
void usun_wynik(wynik * &pHead);

/**Funkcja usuwa liste miast,drog i wynikow
@param glowa_miasta wskaznik na pierwszy element listy miast
@param glowa_wynik wskaznik na pierwszy element listy wynikow
@return Funkcja nie zwraca niczego.
*/
void usun(miasto * glowa_miasta, wynik * glowa_wynik);

#endif
