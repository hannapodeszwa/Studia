#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

bool read_file(const char * file, BITMAPFILEHEADER *bmfh, BITMAPINFOHEADER *bmih, RGBQUAD **picture) // wczytanie obrazu z pliku do tablicy
{	
	FILE *ffile = NULL;
	fopen_s((&ffile), file, "rb"); //otwarcie pliku
	if (ffile == NULL)
	{
		printf("Blad otwarcia pliku.\n");
		return false;
	}
	fread(bmfh, sizeof(*bmfh), 1, ffile); //wczytanie naglowka pliku
	if ((*bmfh).bfType != 0x4D42)  // znacznik "BM"
	{
		printf("To nie jest plik BMP.\n");
		fclose(ffile);
		return false;
	}

	fread(bmih, sizeof(*bmih), 1, ffile); // wczytanie naglowka obrazu

	if ((*bmih).biWidth <=0 || (*bmih).biHeight<=0 )  // sprawdzenie wymiarow obrazu
	{
		printf("Niepoprawne wymiary.\n");
		fclose(ffile);
		return false;
	}

	if ((*bmih).biCompression!=0)  // obraz nie moze byc skompresowany
	{
		printf("Obraz nie moze byc skompresowany.\n");
		fclose(ffile);
		return false;
	}
	fseek(ffile, (*bmfh).bfOffBits, SEEK_SET); //poczatek obrazu

	*picture = (RGBQUAD*)calloc((*bmih).biWidth*(*bmih).biHeight, sizeof(RGBQUAD)); //zaalokowanie miejsca w pamieci
	fread(*picture, sizeof(RGBQUAD), (*bmih).biWidth*(*bmih).biHeight, ffile); //wpisanie pikseli z pliku do tablicy

	fclose(ffile);
	return true;
}

void to_gray(RGBQUAD *picture, BITMAPINFOHEADER bmih) //szarzenie
{
	for (long int i = 0; i < bmih.biHeight*bmih.biWidth; i++)
	{
		//int kolor = (int)picture[i].rgbBlue + (int)picture[i].rgbGreen + (int)picture[i].rgbRed;
		//kolor /= 3;
		//rozne wspolczynniki ze wzgledu na wlasciwosci oka
		int kolor = picture[i].rgbBlue*0.11 + picture[i].rgbGreen*0.59 + picture[i].rgbRed*0.3; 
		picture[i].rgbBlue = picture[i].rgbGreen = picture[i].rgbRed = kolor;
	}
 }

void write(char * file, BITMAPFILEHEADER bmfh, BITMAPINFOHEADER bmih, RGBQUAD *picture)
{
	//zapisanie do pliku (z wykorzystaniem parametrow z pliku wejsciowego)
	FILE * ffile = NULL;
	fopen_s((&ffile), file, "wb");
	if (ffile != NULL)
	{
		fwrite(&bmfh, sizeof(bmfh), 1, ffile);
		fwrite(&bmih, sizeof(bmih), 1, ffile);
		fwrite(picture, sizeof(RGBQUAD), bmih.biWidth*bmih.biHeight, ffile);
		fclose(ffile);
	}
}

int main(int argc, char** argv)
{	
	const char * file= argv[1]; //nazwa pliku wejsciowego
	const char * file_out = "wynik.bmp"; // nazwa pliku wyjsciowego
	if (file == NULL)
		file = "plik2.bmp";
	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER bmih;
	RGBQUAD *picture;

	if (read_file(file, &bmfh, &bmih, &picture))// zapisanie obrazu z pliku do tabeli
	{
		to_gray(picture, bmih); //szarzenie

		write(file_out, bmfh, bmih, picture); //zapisanie do pliku
		free(picture);
	}
	
	return 0;
}