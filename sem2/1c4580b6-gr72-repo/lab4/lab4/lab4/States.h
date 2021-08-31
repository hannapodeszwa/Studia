#ifndef states_H
#define states_H

#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

typedef struct
{
	int coffee;
	int water;
	int milk;
	int power;
	int size;
}coffee_s;

//stany ekspresu
typedef enum
{
	TURN_OFF, SMALL_COFFEE, LARGE_COFFEE, ESPRESSO, CAPPUCINO, MILK,
	CHANGE_POWER, CHANGE_WATER, MENU, ADD_COFFEE, ADD_WATER, ADD_MILK, INIT, STOP, NUMBER
} state;

state do_init(state state_cur, coffee_s data); //pobranie danych wejsciowych z pliku

state do_menu (state state_cur, coffee_s data); //wyswietlenie menu

state check(state state_cur,int coffee, int  water, int milk, coffee_s *data); //sprawdzenie dostepnosci zasobow

state do_add_coffee(state state_cur, coffee_s data); //dodanie kawy

state do_add_water(state state_cur, coffee_s data); //dodanie wody

state do_add_milk(state state_cur, coffee_s data); //dodanie mleka

coffee_s new_data(int coffee, int water, int milk, coffee_s data); //aktualizacja ilosci zasobow

state do_small_coffee(state state_cur, coffee_s *data); //przygotowanie malej kawy

state do_large_coffee(state state_cur, coffee_s *data); //przygotowanie duzej kawy

state do_espresso(state state_cur, coffee_s *data); //przygotowanie espresso

state do_cappucino(state state_cur, coffee_s* data); //przygotowanie cappucino

state do_milk(state state_cur, coffee_s* data); //przygotowanie goracego mleka

state do_change_power(state state_cur, coffee_s* data); //zmiana mocy kawy

state do_change_water(state state_cur, coffee_s* data); //zmiana ilosci dodawanej wody

state do_turn_off(state state_cur, coffee_s* data); //wylaczenie ekspresu

state stop(state state_cur, coffee_s* data); //zakonczenie dzialania programu

#endif