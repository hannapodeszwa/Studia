#include "pch.h"
#include <iostream>
#include <fstream>
int main() 
{
	int liczba = 9890809; //107597858
	std::ofstream plik("wyjscie.bin", std::ios::binary);
	if (plik)
	{
			plik.write(reinterpret_cast<char*>(&liczba),sizeof(int));
			plik.close();
	}		
	
	int zmienna=0;
	std::ifstream plik2("wejscie.bin", std::ios::binary);
	if (plik2)
	{
		plik2.read(reinterpret_cast<char*>(&zmienna), sizeof(int));
		plik2.close();
	}
	std::cout << zmienna;
}