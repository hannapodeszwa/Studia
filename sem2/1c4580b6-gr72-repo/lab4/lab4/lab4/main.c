#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include "states.h"

//tablica wskaznikow na funkcje
state (*tab[NUMBER])(state, coffee_s *) = {do_turn_off, do_small_coffee, do_large_coffee, do_espresso, do_cappucino,do_milk,
do_change_power, do_change_water, do_menu, do_add_coffee, do_add_water, do_add_milk, do_init, stop };

state run_state(state state_cur, coffee_s *data)
{
	return tab[state_cur](state_cur, data);
};

int main()
{
	coffee_s data;
	state state_cur = INIT; //stan poczatkowy
		
		while (state_cur!=STOP) //warunek konca
		{
			state_cur = run_state(state_cur, &data);
		}
	return 0;
}