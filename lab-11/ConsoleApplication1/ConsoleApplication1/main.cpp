/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 9 i 10: drzewo poszukiwań binarnych
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl
#define and &&
#define or ||
#define not !
#include <iostream>   
#include <fstream> 
#include <sstream> 
#include <string.h>
#include <iomanip>
#include <ios>
#include <algorithm>


// kontenery
#include <string> // napis
#include <vector> // wektor (tablica o zmiennym rozmiarze)
#include <map>    // mapa uporządkowana według wartości klucza
#include <unordered_map>  // mapa nieuporządkowana
#include <list>   // lista jednokierunkowa



#include "funkcje.h"
 
int main ()
{
   // DRZEWO POSZUKIWAŃ BINARNYCH    
   
   wezel * pKorzen = nullptr;      
    
  

   for (int i : { 5, 2, 8, 1, 0, 6, 3 })
	   dodajDoDrzewaRekurencyjnie(pKorzen, i);

   wypisz(pKorzen);
   std::cout << std::endl;

   wypisz(pKorzen,0);
   std::cout << std::endl;
   for (int i : { 5, 2, 8, 1, 0, 6, 3 })
   {
	   auto p = znajdzIteracyjnie(pKorzen, i);
	   usun(pKorzen, p);
	  
   } 
   wypisz(pKorzen);
   std::cout << std::endl;
   wypisz(pKorzen, 0);
   //znajdzNastepnik(pKorzen, 17)
   return 0; 
} 

// Cur non dicitur veritas? (TGM)
