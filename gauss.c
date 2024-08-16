#include "gauss.h" 
#include <stdio.h>



/*
	Zwraca 0 - elimnacja zakonczona sukcesem
	Zwraca 1 - macierz osobliwa - dzielenie przez 0
*/

int eliminate(Matrix *mat, Matrix *b){

	// Zmienne pomocnicze
	double devideMatrixValue;
	double mainNumber;
	double checkNumber;
	int columns = mat->c;
	int rows = mat->r;

	// Sprawdzanie czy macierz jest osobliwa (czy liczb akolumn i rzedow sie zgadza)
	if(columns < rows) {
		return 1;
	}

	// Przechodzenie przez kazdy rzad
	for(int i = 0; i < rows; i++) {
		mainNumber = mat->data[i][i];

		// Sprawdzenie, czy mainNumber nie jest rowne 0
		// Oznaczaloby to, ze macierz jest osobliwa 
		if(mainNumber == 0){
			printf("\nProba dzielenia przez 0 podczas algorytmu Gaussa\nMacierz nie posiada rozwiazania\n");
			return 1;
		}

		// Przechodzenie przez kazda kolumne, ktora jest wieksza od numeru rzedu
		for(int j = i + 1; j < rows; j++) {

			// Zmienne mainNumber oraz checkNumber pozwalaja zidentyfikowac przez jaka liczbe (devideMatrixValue) nalezy pomnozyc caly rzad, 
			// aby po odjeciu gornego rzedu pierwszy wyraz byl rowny 0
			checkNumber = mat->data[j][i];
			devideMatrixValue = checkNumber / mainNumber;
			
			// Zmieniamy wszystkie liczby w rzedzie j 
			for(int k = i; k < rows; k++) {
				mat->data[j][k] = mat->data[j][k] - (mat->data[i][k] * devideMatrixValue);
			}
			b->data[j][0] = b->data[j][0] - (b->data[i][0] * devideMatrixValue);
		}
	}

	// Zmiana macierzy, aby ta na przekatnej miala same 1
	for(int i = 0; i < rows; i++) {
		devideMatrixValue = mat->data[i][i];
		for(int j = i; j < rows; j++) {
			mat->data[i][j] = mat->data[i][j] / devideMatrixValue;
		}
		b->data[i][0] = b->data[i][0] / devideMatrixValue;
	}



	return 0;
}





