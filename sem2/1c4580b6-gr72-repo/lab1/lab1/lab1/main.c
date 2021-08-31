#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool pesel_good(char pesel[]) //funkcja sprawdza poprawnosc peselu
{
	int ok = 0;
	int sum = 0;
	char k[] = "1379137913"; 
	for (int i = 0;i < 11;i++) 
	{
		if (pesel[i] >= '0' || pesel[i] <= '9')
			ok++;
		if (i != 10)
			sum += (pesel[i] - '0')*(k[i] - '0') % 10;
	}
	sum = sum % 10;
	sum = (10 - sum) % 10;
	if (ok == 11 && sum == (pesel[10] - '0'))
		return true;
	return false;
}

void date(int *month, int *year, char pesel[]) //znalezienie miesiaca i roku urodzenia
{
	switch (pesel[2])
	{
	case '0':
	case '1':
		(*month) = pesel[2];
		(*year) = 19;
		break;
	case '8':
	case '9':
		(*month) = pesel[2]-8;
		(*year) = 18;
		break;
	case '2':
	case '3':
		(*month) = pesel[2] - 2;
		(*year) = 20;
		break;
	case '4':
	case '5':
		(*month) = pesel[2] - 4;
		(*year) = 21;
		break;
	case '6':
	case '7':
		(*month) = pesel[2] - 6;
		(*year) = 22;
		break;

	default:
		break;
	}
}
bool gender(char pesel[]) //funkcja wyczytujaca plec
{
	if (pesel[9] % 2 == 1)
		return true;
	else
		return false;
}

int main()
{
	printf("Program sprawdzajacy poprawnosc peselu\n\nWpisanie znaku - zatrzymuje program.\n");
	char pesel[12];
	while (1)
{
	printf("\nPodaj PESEL\n");
	pesel[0]=0;
	scanf_s("%11s", &pesel, sizeof pesel);
	while (getchar() != '\n'); //czyszczenie bufora klawiatury
	if (pesel[0] == '-') //warunek zakonczenie wczytywania peseli
		break;
	if (pesel_good(pesel)) //sprawdzenie poprawnosci peselu
	{
		printf("\nPesel poprawny.\n");
		int month=0;
		int year=0;
		int *pmonth = &month;
		int *pyear = &year;

		date(pmonth, pyear, pesel); //znalezienie daty urodzenia
		printf("\nData urodzenia: %c%c.%c%c.%d%c%cr.\n", pesel[4], pesel[5], month, pesel[3], year, pesel[0], pesel[1]);
		
		if(gender(pesel)) 
		printf("\nmezczyzna\n");
			else
		printf("\nkobieta\n");
	}
	else
		printf("\nPesel niepoprawny.\n");
}
	return 0;
}
