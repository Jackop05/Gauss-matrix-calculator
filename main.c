#include "gauss.h"
#include "backsubst.h" 
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {

	// Definiowanie zmiennych oraz odczytywanie plikow i tworzenie macierzy A, B, X
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	// Sprawdzenie czy pliki zostaly poprawnie odczytane
	if (A == NULL){ 
		return -1;
	}
	if (b == NULL){
		return -2;
	}
	// Wypisanie macierzy A oraz B
	printf("Macierz A: \n");
	printToScreen(A);
	printf("Macierz B: \n");
	printToScreen(b);
	printf("\n\n");

	// Algorytm eliminacji Gaussa 
	res = eliminate(A,b);

	// Jesli algorytm Gaussa sie powiodl
	if(res == 0){

		// Wypisanie macierzy A oraz B po tym wykonaniu algorytmu
		printf("Macierz A po zmianie: \n");
		printToScreen(A);
		printf("Macierz B po zmianie: \n");
		printToScreen(b);
		printf("\n\n");

		// Stworzenie macierzy X oraz wykonanie dla niej podstawiania wstecznego
		x = createMatrix(b->r, 1);
		if (x != NULL) {

			// Wykonanie podstawienia wstecznego
			res = backsubst(x,A,b);
			
			// Jesli algorytm podstawiania wstecznego sie powiodl wypisanie macierzy rozwiazan
			if(res == 0){
				printf("Macierz rozwiazan X: \n");
				printToScreen(x);
				freeMatrix(x);
			}
		} else {
			fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
		}
	}

	// Zwolnienie pamieci z macierzy A oraz B
	freeMatrix(A);
	freeMatrix(b);



	return 0;
}
