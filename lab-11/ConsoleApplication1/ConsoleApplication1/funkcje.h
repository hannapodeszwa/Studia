/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 9 i 10: drzewo poszukiwań binarnych

 */

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream> 
#include "stdafx.h"

/** Typ użyty w drzewie poszukiwań binarnych. */
typedef int typ;  // będziemy mogli łatwo zmienić typ przechowywany w liście

/** węzeł drzewa poszukiwań binarnych */
struct wezel
{
   typ wartosc;     ///< wartość przechowywana w węźle   
   wezel * pLewy,   ///< wskaźnik na lewy potomek
         * pPrawy;  ///< wskaźnik na prawy potemek
};  // <--- średnik jest niezbędny

/** Funkcja dodaje rekurencyjnie do drzewa element.
 @param pRoot korzeń drzewa
 @param wartosc wartość do dodania
 */
void dodajDoDrzewaRekurencyjnie (wezel * & pRoot, const typ & wartosc);

/** Funkcja dodaje iteracyjnie do drzewa element.
 @param pRoot korzeń drzewa
 @param wartosc wartość do dodania
 */
void dodajDoDrzewaIteracyjnie (wezel * & pRoot, typ & wartosc);

/** Funkcja wypisuje w porządku wartości przechowywane w elementach drzewa.
 * Przechodzi drzewo w głąb.
 @param pRoot korzeń drzewa
 */
void wypisz (wezel * pRoot);

/** Funkcja wypisuje w porządku wartości przechowywane w elementach drzewa. Kolejne warstwy drzewa są wypisywane coraz większym wcięciem.
 @param pRoot korzeń drzewa
 @param wciecie początkowe wcięcie
 */
void wypisz (wezel * pRoot, int wciecie);

/** Funkcja usuwa całe drzewo z pamięci.
@param pRoot korzeń drzewa do usunięcia, po usunięciu ma wartość nullptr */
void usunDrzewo (wezel * & pRoot);

/** Funkcja wyszukuje (rekurencyjnie) element o podanej wartości w drzewie o podanym korzeniu. 
@param pRoot korzeń drzewa
@param wartosc wartość do wyszukania
@return adres węzła przechowujący szukaną wartość, gdy nie ma takiego węzła, funkcja zwraca nullptr.
*/
wezel * znajdzRekurencynie (wezel * pRoot, const typ & wartosc);

/** Funkcja wyszukuje (iteracyjnie) element o podanej wartości w drzewie o podanym korzeniu. 
@param pRoot korzeń drzewa
@param wartosc wartość do wyszukania
@return adres węzła przechowujący szukaną wartość, gdy nie ma takiego węzła, funkcja zwraca nullptr.
*/
wezel * znajdzIteracyjnie (wezel * pRoot, const typ & wartosc);

/** Operator do latwego wypisywania drzewa.
@param ss strumień do zapisu
@param pRoot korzeń drzewa
@return zmodyfikowany strumień */
std::ostream & operator << (std::ostream & ss, wezel * pRoot);

/** Funkcja sumuje wartości wszystkich elementów w drzewie.
@param pRoot korzeń drzewa
@return suma wartości wszystkich elementów w drzewie
*/
typ zsumujWartosci (wezel * pRoot);

/** Funkcja zlicza elementy w drzewie
@param pRoot korzeń drzewa                
@return liczba wszystkich elementów w drzewie */
int policzWezly (wezel * pRoot);

/** Funkcja wyznacza maksymalną wysokość w drzewie. Drzewo puste ma wysokość zerową.
@param pRoot korzeń drzewa                
@return maksymalna wysokość drzewa */
int maksymalnaWysokoscDrzewa (wezel * pRoot);

/** Funkcja zlicza liście drzewa.
@param pRoot korzeń drzewa                
@return liczba wszystkich liści w drzewie */
int policzLiscie (wezel * pRoot);

/** Funkcja wyszukuje rodzic wezla.
@param pRoot korzeń drzewa
@param pPotomek wezel, ktorego rodzica wyszukuje funkcja
@return adres rodzica pPotomka, jeżeli rodzica nie ma (pRoot) zwraca nullptr.
*/
wezel * znajdzRodzic (wezel * pRoot, wezel * pPotomek);

/** Funkcja zwraca wezel o minimalnej wartosci w drzewie
@param pRoot korzeń drzewa
@return adres wezla zawierajacego minimalną wartosc
*/
wezel * minimalny (wezel * pRoot);

/** Funkcja przechodzi drzewo wszerz i wypisuje (na standardowe wyjście) wartości przechowywane w węzłach.
@param pRoot korzeń drzewa */
void wypiszDrzewoWszerz (wezel * pRoot);

//Funkcja wyszukuje nastepnik wezla p
wezel * znajdzNastepnik(wezel *pRoot, wezel *p);
void usun(wezel * &pRoot, wezel * p);
#endif
