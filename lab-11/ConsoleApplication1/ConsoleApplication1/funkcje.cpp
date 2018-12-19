/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 9: drzewo poszukiwań binarnych
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl
#define and &&
#define or ||
#define not !

#include <iostream>
#include <vector>
#include <climits>
#include <random>
#include <chrono>
#include <string>
#include <iomanip>
#include <deque>
#include <algorithm>

#include "funkcje.h"
//#include "struktury.h"

 
wezel * znajdzIteracyjnie (wezel * pRoot, const typ & wartosc)
{
    if (not pRoot or pRoot->wartosc == wartosc)
        return pRoot;
    else
    {
        auto p = pRoot;
        while (p)
        {
            if (wartosc == p->wartosc)
                return p;
            if (wartosc < p->wartosc)
                p = p->pLewy;
            else
                p = p->pPrawy;
        }
        // nie znaleźliśmy
        return nullptr;
    }
}

wezel * znajdzRekurencynie (wezel * pRoot, const typ & wartosc)
{
    if (not pRoot or pRoot->wartosc == wartosc)
        return pRoot;
    else // w drzewie cos jest
    {
        if (wartosc < pRoot->wartosc) // idziemy w lewo
            return znajdzRekurencynie(pRoot->pLewy, wartosc);
        else
            return znajdzRekurencynie(pRoot->pPrawy, wartosc);
    }
}

void dodajDoDrzewaIteracyjnie (wezel * & pRoot, typ & wartosc)
{
    if (not pRoot)
        pRoot = new wezel { wartosc, 0, 0 };
    else // w drzewie juz cos jest 
    {
        auto p = pRoot;
        
        while (p)
        {
            if (wartosc < p->wartosc) // idziemy w lewo
            {
                if (p->pLewy)  // jezeli istnieje pLewy
                    p = p->pLewy; 
                else 
                {
                    p->pLewy = new wezel { wartosc, 0, 0 };
                    p = nullptr; // można dać return;
//                     return;
                }        
            }
            else  // idziemy w prawo
            {
                if (p->pPrawy)
                    p = p->pPrawy;
                else
                {
                    p->pPrawy = new wezel { wartosc, 0, 0 };
                    p = nullptr; // można dać return;
//                     return;
                }
            }
        }
    }
    
}

void usunDrzewo (wezel * & pRoot)
{
    if (pRoot)
    {
        usunDrzewo(pRoot->pLewy);
        usunDrzewo(pRoot->pPrawy);
        
        delete pRoot;
        pRoot = nullptr;
    }
}
 
 
void dodajDoDrzewaRekurencyjnie (wezel * & pRoot, const typ & wartosc)
{
    if (not pRoot) // drzewo puste
        pRoot = new wezel { wartosc, nullptr, nullptr };
    else  // w drzewie juz co jest
    {
        if (wartosc < pRoot->wartosc) // idziemy w lewo
            dodajDoDrzewaRekurencyjnie(pRoot->pLewy, wartosc);
        else // idziemy w prawo
            dodajDoDrzewaRekurencyjnie(pRoot->pPrawy, wartosc);
    }
}


void wypisz (wezel * pRoot)
{
    if (pRoot)  // jezeli drzewo jest niepuste
    {
        wypisz(pRoot->pLewy);
        std::cout << pRoot->wartosc << std::endl;
        wypisz(pRoot->pPrawy);
    }
}

void wypisz (wezel * pRoot, int wciecie)
{
    const int MNOZNIK = 4; 
    if (pRoot)  // jezeli drzewo jest niepuste
    {
        wypisz(pRoot->pLewy, wciecie + 1);
        std::cout << std::setw (wciecie * MNOZNIK) << pRoot->wartosc << std::endl;
        wypisz(pRoot->pPrawy, wciecie + 1);
    }
}

std::ostream & operator << (std::ostream & ss, wezel * pRoot)
{
    const int SZEROKOSC = 4;
    if (pRoot)
    {
        ss << pRoot->pLewy;
        ss << std::setw(SZEROKOSC) << pRoot->wartosc;
        ss << pRoot->pPrawy;
    }
    return ss;
}

int policzWezly (wezel * pRoot)
{
    if (not pRoot)  // drzewo puste
        return 0;
    return 1 + policzWezly(pRoot->pLewy) + policzWezly(pRoot->pPrawy);    
}

typ zsumujWartosci (wezel * pRoot)
{
    typ suma {} ; // inicjalizacja wartością domyślną, bo możemy sobie zmienić typ na inny operatorem typedef
    if (not pRoot)
        return suma;
    return pRoot->wartosc + zsumujWartosci(pRoot->pLewy) + zsumujWartosci(pRoot->pPrawy);
}


int policzLiscie (wezel * pRoot)
{
    if (not pRoot)
        return 0;
    
//     if (not pRoot->pLewy and not pRoot->pPrawy) // to jest liść!
//         return 1;
//     return policzLiscie(pRoot->pLewy) + policzLiscie(pRoot->pPrawy); 
    
// ufikuśnienie kodu:    
    
    return not pRoot->pLewy and not pRoot->pPrawy ? 1 : policzLiscie(pRoot->pLewy) + policzLiscie(pRoot->pPrawy); 
}

int maksymalnaWysokoscDrzewa (wezel * pRoot)
{
    if (not pRoot)
        return 0;
    return std::max (maksymalnaWysokoscDrzewa(pRoot->pLewy), maksymalnaWysokoscDrzewa(pRoot->pPrawy)) + 1;
}

wezel * minimalny (wezel * pRoot)
{
	if (not pRoot)
		return nullptr;
	if (pRoot->pLewy)
		return minimalny(pRoot->pLewy);
	return pRoot;
}


wezel * znajdzRodzic (wezel * pRoot, wezel * pPotomek)
{
    if (not pRoot or not pPotomek)
        return nullptr;
    
    if (pRoot->pLewy == pPotomek or pRoot->pPrawy == pPotomek)
        return pRoot;
    if (pPotomek->wartosc < pRoot->wartosc)
        return znajdzRodzic(pRoot->pLewy, pPotomek);
    else 
        return znajdzRodzic(pRoot->pPrawy, pPotomek);
    
}

void wypiszDrzewoWszerz (wezel * pRoot)
{
    if (not pRoot)
        return;
    
    std::deque<wezel *> kolejka;  // kolejka FIFO do zapamiętania wskaźników do potomków
    
    kolejka.push_front(pRoot);    // na początku zapisujemy wskaźnik na korzeń
    
    while (not kolejka.empty())   // dopóki jest co wypisywać
    {
        auto p = kolejka.back();  // pobierz wartość ostatniego elementu w kolejce
        kolejka.pop_back();       // usuń ostatni element z kolejki
        
        std::cout << p->wartosc << " ";  // wypisujemy wartość
        
        if (p->pLewy)                      // jeżeli istnieje lewy potomek, ...
            kolejka.push_front(p->pLewy);  // ... to jego adres umieszczamy w kolejce
        if (p->pPrawy)                     // analogicznie jak wyżej
            kolejka.push_front(p->pPrawy);
    }
}


 wezel * znajdzNastepnik(wezel *pRoot, wezel *p)
{
	
	if (not pRoot or not p)
		return nullptr;

	if (p->pPrawy)
		return minimalny(p->pPrawy);
	else
		/*
		while (pRoot->pPrawy != p)
			pRoot = pRoot->pLewy;
		*/
		while ( pRoot->wartosc<p->wartosc)
			
		{
			znajdzRodzic(pRoot, p);
			p = pRoot->pPrawy;
		}
	return pRoot;
	
}

 void usun(wezel * &pRoot, wezel * p)
 {
	 if (p == nullptr)
		 return;
	 if (p->pLewy == nullptr && p->pPrawy ==nullptr)
	 {
		 wezel *pRodzic = znajdzRodzic(pRoot, p);
		 if (pRodzic->pPrawy == p)
			 pRodzic->pPrawy = nullptr;
		 if (pRodzic->pLewy == p)
			 pRodzic->pLewy = nullptr;
		 delete p;
	 }
	 
	 if (p->pPrawy && p->pLewy == nullptr)
	 {
		 wezel* pNastepny = p->pPrawy;
		 wezel *pRodzic =znajdzRodzic(pRoot, p); 
		 if (pRodzic->pPrawy == p)
			 pRodzic->pPrawy = pNastepny;
		 if (pRodzic->pLewy == p)
			 pRodzic->pLewy = pNastepny;
		 p->pPrawy = nullptr;
		 delete p;
	 }
	 if (p->pLewy && p->pPrawy == nullptr)
	 {
		 wezel* pNastepny = p->pLewy;
		 wezel *pRodzic = znajdzRodzic(pRoot, p);
		 if (pRodzic->pPrawy == p)
			 pRodzic->pPrawy = pNastepny;
		 if (pRodzic->pLewy == p)
			 pRodzic->pLewy = pNastepny;
		 p->pLewy = nullptr;
		 delete p;
	 }
	 
	 /*
	 if (p->pLewy && p->pPrawy)
		p->wartosc= znajdzNastepnik(pRoot, p)->wartosc;
		*/
 }