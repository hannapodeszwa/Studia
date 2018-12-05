
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "pch.h"
#include "struktury.h"

//funkcja do wpisania nowych nazw miast glownych

void wypisz_miastaglowne(miastaglowne * &pHead, std::string nowanazwa)
{
	miastaglowne * pNowy = new miastaglowne;
	pNowy->nazwamiasta = nowanazwa;
	pNowy->kolejnemiasto = pHead;
	pNowy->miastaobok = nullptr;
	pHead = pNowy;
}

void wypisz_miastasasiednie(miasta_sasiednie * &pHead, int kilometry)
{

}
/*
			//usuwanie grafu
			void usunmiastasasiednie(miasta_sasiednie * &pHead)
			{
				while (pHead)
				{
					miasta_sasiednie * pNastepnik = pHead->
				}

			}
			*/


int main(int ile, char ** params)
{
    
    // sprawdzanie argumentow wywolania programu
    
    // wczytac dane do struktury danych
    
    // alg. Dijkstry
    
    // wypisanie wyniku
    
    // zwolnienie pamieci
    
    // return 0;
    
	//wypisanie danych z pliku
	std::string miasto1;
	std::string miasto2;
	int odleglosc;

	std::ifstream plik("miasta.txt");
	if (plik)
	{
		std::string linia;

		while (std::getline(plik, linia))
		{
			std::stringstream ss;

			ss << linia;

			ss >> miasto1 >> miasto2 >> odleglosc;  //dane wypisane
            // KS: Co z nieprawid�owymi danymi?
            
			// stworzenie grafu (listy list)	
			

			
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
			miastaglowne * pGlowa = nullptr;
			//funkcja do wpisania nowych nazw miast glownych
		
			wypisz_miastaglowne(pGlowa, miasto1);
		}

		plik.close();
	}
	

	/*
	struct listamiastglownych
{
  listamiastglownych * next;
  int v;
};

int main()
{
  int n,m,i,v1,v2;                     //ilosc miast (wierzcholki), lini pliku (krawedzie), punkt poczatkowy i koncowy
  listamiastglownych ** A;             // A jest wskaznikiem na wskaznik listamiastglownych (czyli next?)?
  listamiastglownych *p,*r;            //p i r sa wskaznikiem na listamiastglownych

  cin >> n >> m;         // Czytamy liczb? wierzcho?k�w i kraw?dzi //ilosc miast i ilosc lini w pliku

  A = new listamiastglownych * [n]; // Tworzymy tablic? list s?siedztwa  // zamienic tablice na liste?

  // Tablic? wype?niamy pustymi listami

  for(i = 0; i < n; i++) A[i] = NULL;         

  // Odczytujemy kolejne definicje kraw?dzi

  for(i = 0; i < m; i++)
  {
    cin >> v1 >> v2;    // Wierzcho?ek startowy i ko?cowy kraw?dzi
    p = new listamiastglownych;    // Tworzymy nowy element
    p->v = v2;          // Numerujemy go jako v2
    p->next = A[v1];    // Dodajemy go na pocz?tek listy A[v1]
    A[v1] = p;
  }

  cout << endl;

  // Wypisujemy zawarto?? tablicy list s?siedztwa

  for(i = 0; i < n; i++)
  {
    cout << "A[" << i << "] =";
    p = A[i];
    while(p)
    {
      cout << setw(3) << p->v;
      p = p->next;
    }
    cout << endl;
  }

  // Usuwamy tablic? list s?siedztwa

  for(i = 0; i < n; i++)
  {
    p = A[i];
    while(p)
    {
      r = p;
      p = p->next;
      delete r;
    }
  }
  delete [] A;

  cout << endl;
	*/
	
return 0;
}

