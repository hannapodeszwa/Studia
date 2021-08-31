#include <stdio.h>
#include <stdlib.h>


typedef struct
{
	int id;
	char* imie; //alokowane dynamicznie
} DaneOsobowe;

char* f_name( )  // wczytywanie imienia do dynamicznie alokowanej tablicy znaków
{
	char* name;  // bufor na zwracany string
	char tab_name[101]; //tablica przechowujaca imie
	printf("Podaj imie: \n");
	scanf_s("%100s", &tab_name, sizeof tab_name); //wpisanie imienia do tablicy
	while (getchar() != '\n'); //czyszczenie bufora

	int n=0; //ilosc znakow imienia
	for (; tab_name[n] != '\n' && tab_name[n] != 0; n++);

	//przepisanie imienia do dynamicznej tablicy
	
	name = (char*)malloc(n + 1);  
	for (int i = 0; i < n; i++)
		name[i] = tab_name[i];
	name[n] = 0;  //dodanie znacznika koñca 
	return name;
}

DaneOsobowe (*tab_struct(int size))[] //tworzenie tablicy struktur
{
	 DaneOsobowe(*tab)[];
	tab = (DaneOsobowe*)calloc(size, sizeof(DaneOsobowe));//zarezerwowanie miejsca w pamieci
	for (int i = 0; i < size; i++)
	{
		(*tab)[i].imie = f_name();  //wczytanie imienia
		(*tab)[i].id = i + 1;
	}	
	return tab;
}


int sort_id (const void * a, const void * b) //funkcja porownuje elementy po id
{
	return (*(DaneOsobowe*)a).id - (*(DaneOsobowe*)b).id;
}

int sort_name(const void * a, const void * b) //funkcja porownuje elementy po imieniu
{
	return (strcmp((*(DaneOsobowe*)a).imie,(*(DaneOsobowe*)b).imie));
}

void write(DaneOsobowe(*tab)[], int size)  
{
	while(1)
	{
		int x = -1;
		printf("\n\nW jaki sposob posortowac tablice?\n\n1 - po id\n2 - po imieniu\n0- zakoncz wypisywanie\n");
		scanf_s("%i", &x, sizeof x);
		while (getchar() != '\n');
<<<<<<< HEAD
		int n;
		for (int j = 0;j < 101;j++)
		while (namec != '\n') //liczenie ilosci znakow w tablicy 
			n++;
		int *name = (int*)malloc(n + 1);
		for (int j = 0;j < n;j++) //przepisanie imienia do dynamicznej tablicy
			name[j] = namec[j];
				
		tab[i] = new DaneOsobowe{ i + 1,name };
		
=======
		switch (x)
		{

		case 1:  // sortowanie wg id
			qsort(tab, size, sizeof(DaneOsobowe), sort_id);
			printf("\nTablica posortowana po id\n");
			for (int i = 0; i < size; i++)
			{
				printf("\n%d\t%s\n",(*tab)[i].id, (*tab)[i].imie);
			}
			break;
		case 2:  //sortowanie wg imienia
			printf("\nTablica posortowana po imieniu\n");
			qsort(tab, size, sizeof(DaneOsobowe), sort_name);
			for (int i = 0; i < size; i++)
			{
				printf("\n%s\t%d\n", (*tab)[i].imie, (*tab)[i].id);
			}
			break;
		case 0:
			return ;
		default:
			printf("Niepoprawna wartosc");
			break;
		}
>>>>>>> bea74b70ff902222d1c01372b96c20cfb6d4551a
	}
	return ;
}

void release(DaneOsobowe(**tab)[], int size)  // zwolnienie pamieci
{
	for (int i = 0; i < size; i++)
	{
		free((**tab)[i].imie);  
	}
	free(*tab);
	*tab = NULL;
}

int main()
{	
	int size; //ilosc elementow tablicy
	printf("Podaj ilosc elementow tablicy\n");
	scanf_s("%i", &size); 

	DaneOsobowe(*tab) []= tab_struct(size); //deklaracja tablicy
	write(tab, size);//wypisanie posortowanej tablicy
	release(&(tab), size); //zwolnienie pamieci

<<<<<<< HEAD
	qsort(tab,size, sizeof(size), int(*compare)(void *)(void*))
	//free(tab); //zwolnienie pamieci
=======
>>>>>>> bea74b70ff902222d1c01372b96c20cfb6d4551a
	return 0;
}