
 
kompilator=g++
standard=-std=c++14
optymalizacja=-O3
# optymalizacja=
# debug=-g
debug=
profilowanie=-pg


__ : main
	./main   -i plik_wejsciowy -o plik_wyjsciowy -s miasto_startowe
	./main    -o plik_wyjsciowy -s miasto_startowe -i plik_wejsciowy
	./main     -s miasto_startowe -i plik_wejsciowy -o plik_wyjsciowy
	./main     -s miasto_startowe -i  -o plik_wyjsciowy
	./main     -s miasto_startowe -i plik_wejsciowy -o  
	             
main : ConsoleApplication1.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors -o $@ $^ 
		
	
 
	
	
	

