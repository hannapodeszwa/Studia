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
    
   for (int i : { 5, 2, 8, 1, 0, 6, 3 } /* { 1,2,3,4,5,6,7,8,9}*/)
      dodajDoDrzewaRekurencyjnie(pKorzen, i);
      
   wypisz (pKorzen);   
   std::cout << std::endl;
    
   wypisz (pKorzen, 0); 
    
   usunDrzewo(pKorzen);
   usunDrzewo(pKorzen);
   
    for (int i : { 5, 2, 8, 1, 0, 6, 3, 11, 9, 10 } )
       dodajDoDrzewaIteracyjnie(pKorzen, i);
 
    wypisz (pKorzen, 0); 
    
    
   std::cout << "rekurencyjnie" << std::endl;
   for (int i : { 5, 2, 8, 1, 0, 6, 3, 4, 10, 11, -3, 12, -1, 7, 9 } )
   {
       auto p = znajdzRekurencynie(pKorzen, i);
       if (p)
           std::cout << "szukana wartosc: " << i << ", wartosc w znalezionym wezle: " << p->wartosc << std::endl;
       else
           std::cout << "szukana wartosc " << i << " nie wystepuje w drzewie" << std::endl;
   }

   std::cout << "iteracyjnie" << std::endl;
   for (int i : { 5, 2, 8, 1, 0, 6, 3, 4, 10, 11, -3, 12, -1, 7, 9 } )
   {
       auto p = znajdzIteracyjnie(pKorzen, i);
       if (p)
           std::cout << "szukana wartosc: " << i << ", wartosc w znalezionym wezle: " << p->wartosc << std::endl;
       else
           std::cout << "szukana wartosc " << i << " nie wystepuje w drzewie" << std::endl;
           
   }
   
   std::cout << pKorzen << std::endl;  // użycie operatora << własnoręcznie zdefiniowanego
 
   std::cout << std::endl;
   wypisz(pKorzen, 0);
   std::cout << std::endl;
    
   std::cout << "liczba wezlow w drzewie: ";
   std::cout << policzWezly(pKorzen) << std::endl;
    
   std::cout << "suma wartosci w drzewie: ";
   std::cout << zsumujWartosci(pKorzen) << std::endl;
    
   std::cout << "liczba lisci w drzewie: ";
   std::cout << policzLiscie(pKorzen) << std::endl;
    
   std::cout << "maksymalna wysokosc drzewa: ";
   std::cout << maksymalnaWysokoscDrzewa(pKorzen) << std::endl;

   std::cout << "minimalna wartosc w drzewie: ";
   auto pMini = minimalny(pKorzen);
   if (pMini)
       std::cout << pMini->wartosc << std::endl;
   else 
       std::cout << "drzewo puste" << std::endl;

   std::vector<int> liczby { 5, 2, 8, 1, 0, 6, 3, 4, 10, 11, -3, 12, -1, 7, 9 };
   for (int i : liczby)
   //for (int i : { 5, 2, 8, 1, 0, 6, 3, 4, 10, 11, -3, 12, -1, 7, 9 } ) // krócej, a efekt ten sam
   {
      auto p = znajdzIteracyjnie(pKorzen, i);
      if (p)
      {
         auto rodzic = znajdzRodzic(pKorzen, p);
         if (rodzic)
            std::cout << "Rodzicem wezla " << p->wartosc << " jest wezel " << rodzic->wartosc << std::endl;
         else
            std::cout << "Wezel " << p->wartosc << " nie ma rodzica!" << std::endl;
      }
   }

  
   std::cout << "przejscie drzewa w glab i wypisanie:" << std::endl;
   std::cout << pKorzen << std::endl;  // użycie operatora << własnoręcznie zdefiniowanego
    
   std::cout << "przejscie drzewa wszerz i wypisanie:" << std::endl;
   wypiszDrzewoWszerz(pKorzen);
   std::cout << std::endl;
    
   usunDrzewo(pKorzen);
   usunDrzewo(pKorzen);  // na wszelki wypadek próbuję usunąć drzewo jeszcze raz
   
//    return 0;
   
   /////////////////////////////////////////////////////
   // KONTENERY  (to już na zasadzie ciekawostki)
   /////////////////////////////////////////////////////
   
   /* Kontenery są tak implementowane, żeby sposób użycia był maksymalnie podobny. Ale różnią się własnościami. Zobaczmy, jak. */
   
   {
      /* vector: 
       * tablica z zmiennym rozmiarze
       * Kolejne elementy umieszczone obok siebie w pamięci – łatwy dostęp przez indeks (jak w tablicy).
       * Dodawanie i usuwanie elementów zwykle kosztowe (szczególnie dodawanie w środku i usuwanie ze środka).
       * Specjalnie optymalizowanie dodawanie na końcu i usuwanie z końca (capacity >= size), chociaż problem przy dodawanie dużej liczby elementów – konieczność realokacji pamięci.
       * Kontener pierwszego wyboru.
       */
      std::vector<double> tablica;
      
      for (auto d : tablica)
         std::cout << d << " ";
      std::cout << std::endl;
      
      for (auto d : {4.5, 6.3, 1.5, 9.8, 4.6, 3.1, 2.6, 8.9 } )
         tablica.push_back(d);
         
      for (auto d : tablica)
         std::cout << d << " ";
      std::cout << std::endl;
   
      // Wektor ma zaimplementowany operator indeksowania – dostęp do elementu o zadanym indeksie jest szybki i niezależny od liczby elementów. 
      for (std::size_t i = 0; i < tablica.size(); i++)
         std::cout << tablica[i] << " ";
      std::cout << std::endl;
      
      std::sort(tablica.begin(), tablica.end());  // tablica.begin() zwraca iterator do pierwszego elementu
                                                  // tablica.end()   zwraca iterator do elementu ZA ostatnim elementem
      // Iterator to coś w rodzaju „wskaźnika” do elementu, ale NIE jest to prawdziwy wskaźnik. 
      for (auto d : tablica)
         std::cout << d << " ";
      std::cout << std::endl;
      
      for (auto iter = tablica.begin(); iter != tablica.end(); iter++)  // inkrementacja iteratora iter++ oznacza przejścia na następny element w sąsiedniej komórce w pamięci (jak w tablicy)
         std::cout << *iter << " ";  // Specjalnie zaimplementowany operator * dla iteratora, żeby *iter oznaczało element „wskazywany” przez iterator.
      std::cout << std::endl;
         
   }
   
//    return 0;
   {
      /* lista jednokierunkowa
       * Kolejne elementy NIE są umieszczone obok siebie w pamięci – brak operatora indeksowania.
       * Dodawanie i usuwanie elementów mało kosztowe.
       * Odnalezienie elementów – liniowe, wymaga przejścia przez wszystkie elementy.
       */ 
      std::list<double>   lista;
      
      for (auto d : lista)
         std::cout << d << " ";
      std::cout << std::endl;
      
      for (auto d : {4.5, 6.3, 1.5, 9.8, 4.6, 3.1, 2.6, 8.9 } )
         lista.push_back(d);
         
      for (auto d : lista)
         std::cout << d << " ";
      std::cout << std::endl;
      
      // BRAK OPERATORA INDEKSOWANIA
//             for (std::size_t i = 0; i < lista.size(); i++)
//                std::cout << lista[i] << " ";
//             std::cout << std::endl;
      
//       std::sort(lista.begin(), lista.end());   // tak się nie da :-( bo nie ma operatora [ ] indeksowania
      
      lista.sort(); // specjalnie zaimplementowane sortowanie listy, bo nie da się tak jak wyżej
      
      for (auto d : lista)
         std::cout << d << " ";
      std::cout << std::endl;
      
      // iteratora używa się dokładnie tak, jak w przypadku wektora, chociaż tak naprawdę inaczej to działa
      for (auto iter = lista.begin(); iter != lista.end(); iter++) // inkrementacja iteratora iter++ oznacza przejście na następny element listy, coś w stylu p = p->pNext
         std::cout << *iter << " "; 
      std::cout << std::endl;
      
   }
   
//    return 0;
   {
      /* Wektor ma indeksy będące kolejnymi liczbami naturalnymi od 0 do size - 1. To czasem jest niewygodne. Dlatego mamy koleny kontener: mapę.
       * Mapa może mieć dowolne indeksy: kolejne liczby naturalne, niekolejne liczby naturalne, napisy lub inny tym.
       * Mapa ma operator indeksowania (bo ma indeksy).
       * Próba dostępu do nieistniejącego elementu przez indeks powoduje utworzenie tegoż elementu i zainicjowanie wartością domyślną.
       * Dostęp do elementu jest dość szybki – logarytmiczny. 
       * Wartości w mapie są posortowanie wg wartości indeksu.
       * Często na indeks mówi się klucz.
       * Zwykle implementowana jako drzewo czerwono-czarne (samorównoważące się drzewo).
       */ 
       
      std::map<std::string, unsigned int> slowniczek; // Pierwszy typ (std::string) określa typ indeksu (klucza),
                                                      // drugi typ (unsigned int) określa wartość przechowywą.
      // Policzmy, ile razy każde słowo występuje w „Panu Tadeuszu”.
      std::ifstream plik;
      plik.open ("pan-tadeusz");
      if (plik)
      {
         std::string slowo;
         
         while (plik >> slowo)
            slowniczek[slowo]++;  // slowo to indeks (klucz), slowniczek[slowo] to element przechowywany w mapie, u nas jest to zmienna typu unsigned int. Po napotkaniu słowa inkrementujemy liczbę jego wystąpień w tekscie.
         
         plik.close();
      }
      
      // Każdy element w mapie ma postać pary typu std::pair. Pierwszy element pary to indeks (klucz), drugi element pary to wartość przechowywana,
      for (const auto & s : slowniczek)
         std::cout << s.first << "   " << s.second << std::endl;
      std::cout << std::endl;
      
      // iteratora używa się dokładnie tak, jak w przypadku wektora i listy, chociaż tak naprawdę inaczej to działa
      for (auto iter = slowniczek.begin(); iter != slowniczek.end(); iter++) // inkrementacja iteratora iter++ oznacza przejście na następny element w drzewie (następnik) – wyraźnie bardziej skomplikowane niż w liście
         std::cout << iter->first << " " << iter->second << std::endl; // użycie jak wskaźnika, choć nie jest to wskaźnik 
      std::cout << std::endl;
      
      std::cout << "liczba slow: " << slowniczek.size() << std::endl;
      // Mapa przechowuje elementy posortowane wg klucza – bo jest to drzewo.    
      
   }
      
//    return 0;
   {
      /* Odmianą mapy jest mapa nieuporządkowana.
       * Mapa nieuporządkowana może mieć dowolne indeksy (jak to mapa).
       * Mapa ma operator indeksowania (bo ma indeksy).
       * Próba dostępu do nieistniejącego elementu przez indeks powoduje utworzenie tegoż elementu i zainicjowanie wartością domyślną.
       * Dostęp do elementu jest bardzo szybki – stały, niezależny od liczby elementów w mapie nieuporządkowanej. 
       * Wartości w mapie NIE są posortowanie, bo jest to mapa NIEuporządkowana.
       * Zwykle implementowana jako tablica mieszająca (haszująca).
       */  
       
      // Zróbmy to samo co wyżej, sprawdźmy, ile razy w „Panu Tadeuszu” występuje każde słowo.
      std::unordered_map<std::string, unsigned int> balagan;  // dwa typy: klucz i wartość przechowywana
      std::ifstream plik;
      plik.open ("pan-tadeusz");
      if (plik)
      {
         std::string slowo;
         
         while (plik >> slowo)
            balagan[slowo]++; // analogicznie jak w zwykłej mapie
         
         plik.close();
      }
      for (const auto & s : balagan)
         std::cout << s.first << "   " << s.second << std::endl;
      std::cout << std::endl;
      
      // iteratora używa się dokładnie tak, jak w przypadku wektora i listy, chociaż tak naprawdę inaczej to działa
      for (auto iter = balagan.begin(); iter != balagan.end(); iter++) // inkrementacja iteratora iter++ oznacza przejście na następny element w tablicy mieszającej
         std::cout << iter->first << " " << iter->second << std::endl; // użycie jak wskaźnika, choć tak naprawdę nie jest to wskaźnik 
      std::cout << std::endl;
      
      //
      std::cout << "liczba slow: " << balagan.size() << std::endl;
      // Słowa nie są uporządkowane. Mapa nieuporządkowana zapewnia szybszy dostęp do elementów niż zwykła mapa, ale ceną, jaką płacimy, jest nieuporządkowanie elementów.
   }  
   
//    return 0;
   {
      // Przykład użycia kilku map i wektora  
      std::map<std::string, std::map<int, std::map<int, std::vector<std::pair<std::string, std::string>>>>>  studenci;
      //       kierunek              rok           grupa                      imie         nazwisko         
          
      studenci["inf" /* kierunek */][3 /* rok */][1 /* grupa */].push_back ({"Jan", "Kowalski"});
      studenci["inf"][1][1].push_back ({"Ewa", "Jordanska"});
      studenci["inf"][1][5].push_back ({"Tomasz", "Chudzicki"});
      studenci["inf"][1][5].push_back ({"Grzegorz", "Matecki"});
      studenci["inf"][2][5].push_back ({"Eugeniusz", "Abacki"});
      studenci["ele"][1][4].push_back ({"Maria", "Dededzka"});
      studenci["ele"][4][8].push_back ({"Anna", "Edzka"});
      studenci["aut"][2][5].push_back ({"Eugeniusz", "Abacki"});
      studenci["aut"][1][4].push_back ({"Maria", "Hanecka"});
      studenci["inf"][1][4].push_back ({"Maria", "Hanecka"});
      studenci["inf"][1][1].push_back ({"Teresa", "Edzka"});
      studenci["inf"][1][4].push_back ({"Maria", "Dededzka"});
      studenci["inf"][4][8].push_back ({"Anna", "Edzka"});
      studenci["ele"][1][1].push_back ({"Teresa", "Edzka"});
      studenci["aut"][1][1].push_back ({"Teresa", "Edzka"});
      studenci["aut"][1][4].push_back ({"Maria", "Dededzka"});
      studenci["aut"][4][8].push_back ({"Anna", "Edzka"});
      studenci["ele"][2][5].push_back ({"Eugeniusz", "Abacki"});
      studenci["ele"][1][4].push_back ({"Maria", "Hanecka"});
      studenci["ele"][1][1].push_back ({"Teresa", "Edzka"});
      studenci["tele"][1][1].push_back ({"Teresa", "Rudzka"});
      
      // dostęp do konketnego elementu:
      std::cout << studenci["inf"][1][5][1].first << " " << studenci["inf"][1][5][1].second << std::endl;
      
      std::cout << std::endl;
      // Wypiszmy wszystkich studentów:
      std::cout << "STUDENCI" << std::endl;
      
      for (const auto & kierunek : studenci)  // dla każdego kierunku, na którym są studenci
      {
         std::cout << "KIERUNEK: " << kierunek.first << std::endl; // wypisz nazwę kierunku
         
         for (const auto & rok : kierunek.second)  // dla każdego roku na kierunku
         {
            std::cout << "   ROK: " << rok.first << std::endl; // wypisz numer roku
            for (const auto & grupa : rok.second)  // dla każdej grupy na roku
            {
               std::cout << "     grupa: " << grupa.first << std::endl;  // wypisz numer grupy
               for (const auto & student : grupa.second) // dla każdego studenta w grupie
               {
                  // wypisz                  imię             i      nazwisko studenta              
                  std::cout << "        " << student.first << " " << student.second << std::endl;
               }
            }
         }
      }
   }  // Mapy są posortowane wg kluczy, więc mamy ładny wynik :-) 
      // Wektor już nie jest posortowany.

   for (int i : { 5, 2, 8, 1, 0, 6, 3 })
	   dodajDoDrzewaRekurencyjnie(pKorzen, i);

   wypisz(pKorzen);
   std::cout << std::endl;
   //znajdzNastepnik(pKorzen, 17)
   return 0; 
} 

// Cur non dicitur veritas? (TGM)
