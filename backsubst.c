#include "backsubst.h" 
#include <stdio.h>



/*
	Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
	Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
	Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
*/

int  backsubst(Matrix *x, Matrix *mat, Matrix *b) { 

	// Zmienne pomocnicze
	int columns = mat->c;
	int rows = mat->r;
	double temporarySum = 0.0;

	// Sprawdzenie czy rozmiary macierzy sa prawidlowe
	if(columns != rows) {
		return 2;
	}

	// Przechpdzenie przez kazdy rzad
	for(int i = rows-1; i >= 0; i--) {
		temporarySum = b->data[i][0];

		// Sprawdzenie, czy mat->data[i][i] nie jest rowne 0
		// Oznaczaloby to, ze macierz jest osobliwa 
		if(mat->data[i][i] == 0){
			printf("\nProba dzielenia przez 0 podczas algorytmu podstawiania wstecznego\nMacierz nie posiada rozwiazania\n");
			return 1;
		}

		// Przechodzenie przez kolumny, ktore sa wieksze badz rowne od rzedu
		for(int j = columns-1; j >= i; j--){

			// Dla kazdej kolumny wiekszej niz rzad, odejmujemy odpowiednia liczbe
			// Dziala to na podobnej zasadzie co obustronne odejmowanie w ukladach rownan
			if(i != j){
				temporarySum -= mat->data[i][j]*x->data[j][0];
			} 
		}
		
		// Przypisanie wartosci do odpowiedniej zmiennej
		if(temporarySum == -0.0){
			x->data[i][0] = 0.00;
		} else {
			x->data[i][0] = temporarySum;
		}
		
	}

	

	return 0;
}


