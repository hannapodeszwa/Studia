
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "pch.h"
#include "struktury.h"



int main()
{
	std::string str1;
	std::string str2;
	int str3;
	int licznik=0;
	
//	trasa droga;
	std::ifstream plik("miasta.txt");
	if (plik)
	{
		std::string linia;
		
		while (std::getline(plik, linia))
		{
			std::stringstream ss;
			
			ss << linia;
			
			ss >> str1 >> str2 >> str3;
			/*
			std::cout << str1 << std::endl;
			std::cout << str2 << std::endl;
			std::cout << str3 << std::endl;
			*/
			licznik++;

			struct trasa
			{
				/*
				std::string tab[];
				if (str1 != tab[licznik-1] )
						tab[licznik] = str1;
				
				*/
				/*
				element * pierwszy = nullptr;
				void dodaj(element * & pierwszy)
				{
					pierwszy = new element{ pierwszy };

				}
		*/

				push_front(str1);
			};
			
		}

		plik.close();
	}
	
	
return 0;
}

