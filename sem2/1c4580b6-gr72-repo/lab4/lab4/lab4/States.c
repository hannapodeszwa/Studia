#include <stdio.h>>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include "states.h"

 state do_init(state state_cur, coffee_s *data)
{
	FILE * file = NULL;
	fopen_s(&file, "plik.txt", "r"); //stala nazwa pliku

	if (file)
	{
		fscanf_s(file, "%d%d%d%d%d", &(*data).coffee, &(*data).water, &(*data).milk, &(*data).power, &(*data).size, sizeof(int)); //wczytanie danych poczatkowych
		fclose(file);

		return MENU;
	}
	else
		printf("Blad otwarcia pliku.");
	return STOP;
}

 state do_menu(state state_cur, coffee_s *data) //zwraca nr wybranego stanu
 {
	 int choice = -1;
	 printf("\n\n******************\n*      MENU      *\n******************\n\n");
	 printf("Dostepne zasoby:\nkawa: %d\nwoda: %d\nmleko: %d\n\n", (*data).coffee, (*data).water, (*data).milk);
	 printf("Wybierz napoj:\n1. Mala kawa\n2. Duza kawa\n3. Espresso\n4. Cappucino\n5. Mleko\n\n0. Wylacz ekspres.\n\n");
	 printf("Moc kawy: %d\nRozmiar: %d\n\nZmien ustawienia:\n6.Mocy\n7.Rozmiaru napoju\n\n", (*data).power, (*data).size);
	 scanf_s("%d", &choice, sizeof(int));
	 while (getchar() != '\n'); //czyszczenie bufora
	 if (choice < 0 || choice > 7)
	 {
		 system("cls"); //czyszczenie konsoli
		 printf("Niepoprawna wartosc.\n");
		 return MENU;
	 }
	 return choice;
 }

state check(state state_cur, int coffee, int  water, int milk, coffee_s *data) //sprawdza czy wystarczy zasobow do przygotowania napoju
{
	// jezeli zasobow jest za malo, to idz do stanu odpowiedzialnego za dodanie kawy, wody lub mleka
	if ((*data).coffee - coffee < 0)
			return ADD_COFFEE;
	if ((*data).milk - milk < 0)
			return ADD_MILK;
	if ((*data).water - water < 0)
			return ADD_WATER;
	return state_cur;  // znacznik, ze mozna wykonac realizacje zamowienia
}

state do_add_coffee(state state_cur, coffee_s *data)
{
	int n = -1;
	printf("Za malo kawy.\nIle dodac kawy? Podaj wartosc od 1 do 1000. Jesli chcesz przerwac uzupelnianie wybierz 0\n");
	scanf_s("%d", &n, sizeof(int));
	while (getchar() != '\n'); //czyszczenie bufora
	system("cls"); //czyszczenie konsoli
	printf("%d\n",n);
	if (n == 0)
	{
		printf("Przerwanie uzupelniania.\n");
	}
	else if (n <0 ||n>1000)
	{
		printf("Niepoprawna wartosc.\n");
	}
	else
	{
		printf("Dodawanie zakonczone.\n");
		(*data).coffee = (*data).coffee + n;
	}
	return MENU;
}

state do_add_water(state state_cur, coffee_s *data)
{
	int n = -1;
	printf("Za malo wody.\nIle dodac wody? Podaj wartosc od 1 do 1000. Jesli chcesz przerwac uzupelnianie wybierz 0\n");
	scanf_s("%d", &n, sizeof(int));
	while (getchar() != '\n'); //czyszczenie bufora
	system("cls"); //czyszczenie konsoli
	if (n == 0)
	{
		printf("Przerwanie uzupelniania.\n");
	}
	else if (n < 0 || n > 1000)
	{
		printf("Niepoprawna wartosc.\n");
	}
	else
	{
		printf("Dodawanie zakonczone.\n");
		(*data).water = (*data).water + n;
	}
	return MENU;
}
state do_add_milk(state state_cur, coffee_s *data)
{
	int n = -1;
	printf("Za malo mleka.\nIle dodac mleka? Podaj wartosc od 1 do 1000. Jesli chcesz przerwac uzupelnianie wybierz 0\n");
	scanf_s("%d", &n, sizeof(int));
	while (getchar() != '\n'); //czyszczenie bufora
	system("cls"); //czyszczenie konsoli
	if (n == 0)
	{
		printf("Przerwanie uzupelniania.\n");
	}
	else if (n < 0 || n > 1000)
	{
		printf("Niepoprawna wartosc.\n");
	}
	else
	{
		printf("Dodawanie zakonczone.\n");
		(*data).milk = (*data).milk + n;
	}
	return MENU;
}

coffee_s new_data(int coffee, int water, int milk, coffee_s data) 
//aktualizacja ilosci zasobow
{
	data.coffee -= coffee;
	data.water -= water;
	data.milk -= milk;
	return data;
}

state do_small_coffee(state state_cur, coffee_s *data) //przygotowanie malej kawy
{
	int coffee_need = ((*data).power * 2);
	int water_need = ((*data).size * 4);
	int milk_need = (10);

	state state_a = check (state_cur, coffee_need, water_need, milk_need, (*&data));
	if (state_cur != state_a)
		return state_a;
	(*data) = new_data(coffee_need, water_need, milk_need, (*data));
	system("cls"); //czyszczenie konsoli
	printf("Mala kawa gotowa.\n");
	return MENU;
}

state do_large_coffee(state state_cur, coffee_s *data) //przygotowanie duzej kawy
{
	int coffee_need = (2 *(*data).power * 5);
	int water_need = (2 * (*data).size * 10);
	int milk_need = (20);

	state state_a = check(state_cur, coffee_need, water_need, milk_need, (*&data));
	if (state_cur != state_a)
		return state_a;
	(*data) = new_data(coffee_need, water_need, milk_need, (*data));
	system("cls"); //czyszczenie konsoli
	printf("Duza kawa gotowa.\n");
	return MENU;
}

state do_espresso(state state_cur, coffee_s *data) //przygotowanie espresso
{
	int coffee_need = ((*data).power * 10);
	int water_need = ((*data).size * 4);
	int milk_need = 0;

	state state_a = check(state_cur, coffee_need, water_need, milk_need, (*&data));
	if (state_cur != state_a)
		return state_a;
	(*data) = new_data(coffee_need, water_need, milk_need, (*data));
	system("cls"); //czyszczenie konsoli
	printf("Espresso gotowe.\n");
	return MENU;
}

state do_cappucino(state state_cur, coffee_s* data) //przygotowanie cappucino
{
	int coffee_need = ((*data).power * 5);
	int water_need = ((*data).size * 5);
	int milk_need = (40);

	state state_a = check(state_cur, coffee_need, water_need, milk_need, (*&data));
	if (state_cur != state_a)
		return state_a;
	(*data) = new_data(coffee_need, water_need, milk_need, (*data));
	system("cls"); //czyszczenie konsoli
	printf("Cappucino gotowe.\n");
	return MENU;
}

state do_milk(state state_cur, coffee_s* data) //przygotowanie goracego mleka
{
	int coffee_need = 0;
	int water_need = (2 * (*data).size * 10);
	int milk_need = (100);

	state state_a = check(state_cur, coffee_need, water_need, milk_need, (*&data));
	if (state_cur != state_a)
		return state_a;
	(*data) = new_data(coffee_need, water_need, milk_need, (*data));
	system("cls"); //czyszczenie konsoli
	printf("Mleko gotowe.\n");
	return MENU;
}

state do_change_power(state state_cur, coffee_s* data) //zmienia moc kawy
{
	int n = -1;
	printf("Podaj moc kawy od 1 do 100:\n");
	scanf_s("%d", &n, sizeof(int));
	while (getchar() != '\n'); //czyszczenie bufora
	system("cls"); //czyszczenie konsoli
	if(n<1||n>100)
		printf("Niepoprawna wartosc.\n");
	else
	{
		(*data).power = n;
		printf("Zmieniono moc kawy.\n");
	}
	return MENU;
}

state do_change_water(state state_cur, coffee_s* data) //zmienia ilosc dodawanej wody
{
	int n= -1;
	printf("Podaj rozmiar napoju od 1 do 100:\n");
	scanf_s("%d", &n, sizeof(int));
	while (getchar() != '\n'); //czyszczenie bufora
	system("cls"); //czyszczenie konsoli
	if (n < 1 || n>100)
		printf("Niepoprawna wartosc.\n");
	else
	{
		(*data).size = n;
		printf("Zmieniono ilosc wody.\n");
	}
	return MENU;
}

state do_turn_off(state state_cur, coffee_s* data) //wylaczenie ekspresu
{
	FILE * file = NULL;
	fopen_s(&file, "plik.txt", "w"); //stala nazwa pliku

	if (file)
	{
		fprintf(file, "%d\n%d\n%d\n%d\n%d\n", (*data).coffee, (*data).water, (*data).milk, (*data).power, (*data).size);
		
		fclose(file);
		return STOP;
	}
	else
		printf("Blad otwarcia pliku.\n");
	return MENU;
}

state stop(state state_cur, coffee_s* data)
{
	return STOP;
}
