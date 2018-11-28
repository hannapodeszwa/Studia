#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <math.h>
#include <time.h>

/*
Napisaæ klasê Wektor która dziedziczy z klasy Punkt(æw. 3) .
Klasa Wektor ma dodatkowe pola : dlugosc(sqrt(x*x + y*y)) oraz kierunek(k¹t równy atan(y / x)).
Zaimplementowaæ odpowiednie konstruktory.Przedefiniowaæ metody i operator ==.
Napisaæ klasê TablicaWektorów(na podstawie klasy Wektor z æw. 2).
Zaimplementowaæ klasê TabWektorowSort, która dziedziczy z klasy TablicaWektorów i przechowuje wektory posortowane wg.d³ugoœci .
Napisaæ metodê wstaw(Wektor &), która wstawia wektor w sposób uporz¹dkowany.
Przedefiniowaæ operator = (klasa TabWektorowSort) tak aby przy zapisywaniu wstawia³ obiekt Wektor na odpowiednie miejsce(nie koniecznie na i - t¹ pozycjê)
*/
class Punkt
{
protected : 
	float x;
	float y;
public:
	Punkt(Punkt &p)
	{
		x = p.x;
		y = p.y;
	}
	Punkt(float x_ = 0, float y_ = 0)
	{
		x = x_;
		y = y_;
	}
	void dodaj(Punkt &p)//dodaje do siebie wspó³rzêdne punktu p (dodawanie wektorów w przestrzeni 2d )
	{
		x = p.x + x;
		y = p.y + y;
	}

	void ObliczParametryPocz()
	{
		// bedzie nadpisana w klasie wektor
	}


	void dodaj(Punkt *p)
	{
		x = p->x + x;
		y = p->y + y;

		
	}
	void drukuj()// drukuje swoje wspó³rzêdne
	{
		std::cout << "Oto wspolrzedne : " << x << " , " << y << std::endl;
	}
	void wstaw(float x_, float y_)
	{
		x = x_;
		y = y_;
	}
	void wstawX(float x_)
	{
		x = x_;
	}
	void wstawY(float y_)
	{
		y = y_;
	}
	float podajX()
	{
		return this->x;

	}
	float podajY()
	{
		return this->y;
	}

	Punkt operator+=(const Punkt& punkt_dod)
	{
		Punkt pun;
		pun.x = punkt_dod.x + this->x;
		pun.y = punkt_dod.y + this->y;
		this->x = pun.x;
		this->y = pun.y;
		return pun;
	}
	Punkt operator=(const Punkt& punkt_przyp)
	{
		this->x = punkt_przyp.x;
		this->y = punkt_przyp.y;
		return 0;
	}
	bool operator==(const Punkt& punkt_por)
	{
		if (this->x == punkt_por.x && this->y == punkt_por.y)
		{
			std::cout << "True" << std::endl;
			return true;
		}
		else
		{
			std::cout << "False" << std::endl;
			return false;
		}

	}
	Punkt operator+(const Punkt& punkt_dod)
	{

		Punkt pun;
		pun.x = punkt_dod.x + this->x;
		pun.y = punkt_dod.y + this->y;
		this->x = pun.x;
		this->y = pun.y;
		return pun;

	}
	friend std::ostream & operator <<(std::ostream &stream, const Punkt &punkt_wypisz)
	{
		stream << '(' << punkt_wypisz.x << ',' << punkt_wypisz.y << ')';
		return stream;
	}
};

class Wektor : public Punkt 
{
	float dlugosc;
	float kierunek; 

public : 

	Wektor()
	{
		this->wstaw(rand()%9+1, rand() % 9 + 1);

		ObliczParametryPocz();
	}

	Wektor(float x_, float y_)
	{
		this->wstaw(x_, y_);

		ObliczParametryPocz();
		
	}

	Wektor(Wektor &p)
	{
		this->wstaw(p.podajX(), p.podajY());
		this->ObliczParametryPocz();
	}

	Wektor(Punkt &p)
	{
		this->wstaw(p.podajX(), p.podajY());
		this->ObliczParametryPocz();
	}

	void dodaj(Wektor &p)//dodaje do siebie wspó³rzêdne punktu p (dodawanie wektorów w przestrzeni 2d )
	{
		this->wstaw(this->podajX() + p.podajX(), this->podajY() + p.podajY());
		this->ObliczParametryPocz();
	}

	void dodaj(Wektor *p)
	{
		this->wstaw(this->podajX() + p->podajX(), this->podajY() + p->podajY());
		this->ObliczParametryPocz();
	}

	void dodaj(Punkt &p)//dodaje do siebie wspó³rzêdne punktu p (dodawanie wektorów w przestrzeni 2d )
	{
		this->wstaw(this->podajX() + p.podajX(), this->podajY() + p.podajY());
		this->ObliczParametryPocz();
	}

	void dodaj(Punkt *p)
	{
		this->wstaw(this->podajX() + p->podajX(), this->podajY() + p->podajY());
		this->ObliczParametryPocz();
	}

	void ObliczParametryPocz()
	{
		dlugosc = sqrt(std::pow(this->podajX(), 2) + std::pow(this->podajY(), 2));
		kierunek = atan(this->podajX() / this->podajY());
	}

	void WstawParametry(float dlugosc_, float kierunek_)
	{
		dlugosc = dlugosc_;
		kierunek = kierunek_;
	}

	float podajDl()
	{
		return dlugosc;
	}

	float podajKier()
	{
		return kierunek;
	}

	void drukuj()
	{
		std::cout << "x : " << this->podajX() << " y : " << this->podajY() << " dlugosc  : " << dlugosc << " kierunek : " << kierunek << std::endl;
	}

	bool operator==(const Wektor &w_)
	{
		if (w_.x == this->podajX() && w_.y == this->podajY())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
};

class TablicaWektorow
{
	Wektor *w;
	 int dl;

public :
	TablicaWektorow(const int dl_ = 0)
	{
		dl = dl_;
		w = new Wektor[dl];

	}

	void drukuj()
	{
		for (int i = 0; i < dl; i++)
		{
			std::cout << "Wektor nr " << i << " : (" << w[i].podajX() << ", " << w[i].podajY() << ")" <<" dlugosc : "<<w[i].podajDl()<<" kierunek : "<<w[i].podajKier()<< std::endl;
		}
	}


	
};

class Tablica
{
	Punkt * w;
	int dl; // dlugoœæ Tablicy
public:
	Tablica(const int dl_ = 0)// tworzy Tablice o zadanej d³ugoœci i wype³nia punktami (0,0)
	{
		dl = dl_;
		w = new Punkt[dl];

		for (int i = 0; i < dl; i++)
		{
			w[i].wstaw(0, 0);
		}

	}
	Tablica(Tablica w_, int dl_) //inicjalizacja za pomoc¹ Tablicy w_
	{
		dl = dl_;
		w = new Punkt[w_.dl];
		for (int i = 0; i < dl; i++)
		{
			w[i].wstaw(w_.w[i].podajX(), w_.w[i].podajY());
		}
	}
	Tablica(float *x, float *y, int dl_) // inicjalizacja tablicy punktów tablicami x -ów i y -ów
	{
		dl = dl_;
		w = new Punkt[dl];
		//Zakladam ze skoro dostaje 'dl' to znaczy ze sa one rowne i zgodne  z tym dl
		for (int i = 0; i < dl; i++)
		{
			w[i].wstaw(x[i], y[i]);
		}

	}
	Tablica(std::string sciezka) //do wczytywania z pliku tekstowego , pierwsza liczba w pliku oznacza liczbê lini tekstu ( nie wliczaj¹c tej pierwszej ) 
	{
		std::ifstream plik;
		plik.open("X.txt");
		/* Przykladowy rozstaw :
		6    <---- Ta liczba okresla liczbe nastepujacych lini tekstu, nie moze byc ujemna itp.
		3
		3
		4
		4
		5
		5
		*/
		if (!plik.good())
		{
			std::cout << "ERROR!!! Cos poszlo nie tak z wczytywaniem ..." << std::endl;
			return;
		}
		std::cout << "Wczytano plik" << std::endl;
		std::string tmp = "8";


		getline(plik, tmp);
		dl = stoi(tmp);
		dl = dl / 2;

		std::cout << "Dlugosc tablicy :" << dl << std::endl;
		w = new Punkt[dl];
		float tmpFlt = 0;
		int licznik = 0;
		for (int i = 0; i < (dl * 2); i++)
		{
			getline(plik, tmp);
			tmpFlt = std::stof(tmp);
			if (i % 2 == 0)
			{
				w[licznik].wstawX(tmpFlt);

			}
			else
			{
				w[licznik].wstawY(tmpFlt);
				licznik++;
			}

		}
		plik.close();
	}

	~Tablica()
	{
		delete[] w;
	}

	void dodaj(Tablica &w_)// dodaje do siebie Tablice w_
	{
		Punkt * w_temp;
		int dl_temp = w_.dl + dl;
		w_temp = new Punkt[dl_temp];
		for (int i = 0; i < dl; i++)
		{
			w_temp[i].wstaw(w[i].podajX(), w[i].podajY());
		}

		for (int i = dl; i < dl_temp; i++)
		{
			w_temp[i].wstaw(w_.w[i - dl].podajX(), w_.w[i - dl].podajY());
		}
		w = w_temp;
		dl = dl_temp;
	}

	bool porownaj(Tablica &w_)// porownnaie z Tablica w_;
	{
		if (!(dl == w_.dl))
		{
			return false;

		}

		for (int i = 0; i < dl; i++)
		{
			if ((w[i].podajX() != w_.w[i].podajX()) || (w[i].podajY() != w_.w[i].podajY()))
			{
				return false;
			}


		}

		return true;
	}

	void drukuj()
	{
		for (int i = 0; i < dl; i++)
		{
			std::cout << "Punkt nr " << i << " : (" << w[i].podajX() << ", " << w[i].podajY() << ")" << std::endl;
		}
	}

	Tablica operator=(const Tablica &tab)
	{
		this->w = new Punkt[tab.dl];
		this->dl = tab.dl;

		for (int i = 0; i < (this->dl); i++)
		{
			this->w[i].wstaw(tab.w[i].podajX(), tab.w[i].podajY());
		}


		return 0;

	}

	bool operator==(const Tablica &tab)
	{
		if (!(this->dl == tab.dl))
		{
			std::cout << "False" << std::endl;
			return false;

		}

		for (int i = 0; i < this->dl; i++)
		{
			if ((this->w[i].podajX() != tab.w[i].podajX()) || (this->w[i].podajY() != tab.w[i].podajY()))
			{
				std::cout << "False" << std::endl;
				return false;
			}


		}
		std::cout << "True" << std::endl;
		return true;
	}

	friend std::ostream & operator <<(std::ostream &stream, const Tablica &tab)
	{

		for (int i = 0; i<tab.dl; i++)
		{
			stream << '(' << tab.w[i].podajX() << ',' << tab.w[i].podajY() << ')';
		}


		return stream;

	}

	void operator+=(const Tablica &tab)
	{
		Punkt * w_temp;
		int dl_temp = tab.dl + dl;
		w_temp = new Punkt[dl_temp];



		for (int i = 0; i < dl; i++)
		{
			w_temp[i].wstaw(w[i].podajX(), w[i].podajY());
		}

		for (int i = dl; i < dl_temp; i++)
		{
			w_temp[i].wstaw(tab.w[i - dl].podajX(), tab.w[i - dl].podajY());
		}
		this->w = w_temp;
		this->dl = dl_temp;

	}

	void operator[](int x)
	{
		std::string tmp;
		std::cout << "Podaj x i wcisnij enter : " << std::endl;
		getline(std::cin, tmp);
		w[x].wstawX(std::stof(tmp));
		while (_kbhit())
		{
			_getch();
		}
		std::cout << "Podaj y i wcisnij enter : " << std::endl;
		getline(std::cin, tmp);
		w[x].wstawY(std::stof(tmp));


	}


};


int main()
{   
	srand(time(NULL));
	/*
	// TESTOWANIE KLASY PUNKT
	Punkt punkcik(5, 10);
	Punkt punkt2(punkcik);
	Punkt punkt3(3, 7);
	punkcik += punkt3;
	punkcik.drukuj();
	punkcik = punkt3;
	punkcik.drukuj();
	punkcik == punkt3;
	punkcik = punkcik + punkt3;
	punkcik.drukuj();
	std::cout << "Oto wspolrzedne z uzyciem operatora '<<' : " << punkcik << std::endl;
	// TESTOWANIE KLASY TABLICA
	std::cout << std::endl << "Teraz testujemy klase TABLICA !!!" << std::endl;
	float tabliczka1[4] = { 1,5,7,9 };
	float tabliczka2[5] = { 2,6,8,10,100 };
	Tablica tab(tabliczka1, tabliczka1, 4);
	Tablica tab2(tabliczka2, tabliczka2, 5);
	tab.drukuj();
	tab2.drukuj();
	tab == tab2;
	tab = tab2;
	tab.drukuj();
	std::cout << tab << std::endl;
	tab += tab;
	std::cout << tab << std::endl;
	std::cout << "testowanie wczytywania z pliku " << std::endl;
	Tablica tab_plik("X.txt");
	tab_plik.drukuj();
	std::cout << tab_plik << std::endl;






	tab_plik[2];
	tab_plik.drukuj();
	_getch();

	tab.~Tablica();
	tab2.~Tablica();
	tab_plik.~Tablica();
	*/

	//Testowanie Klasy Wektor 
	Wektor test1(3, 4);
	test1.drukuj();
	Wektor test2(3, 4);
	test1.dodaj(test2);
	test1.drukuj();
	Punkt test3(3, 4);
	test2.drukuj();
	test2.dodaj(test3);
	test2.drukuj();
	if (test1 == test2)
	{
		std::cout << "True" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}

	//Testowanie Klasy Tablica 
	TablicaWektorow tab_test1(10);
	tab_test1.drukuj();

	
	_getch();
	return 0;
}

