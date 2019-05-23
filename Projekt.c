#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void board(int a, int b, int tab[15][15]){ //funkcja rysuj¹ca planszê (wraz z ¿ywymi komórkami).
	system("cls");
	int i, j;
	for (i=0; i<a; i++){
		for (j=0; j<b; j++){
			if (tab[i][j] == 0){
				printf(" ");
			} else {
				printf("O");
			}
		}
		printf("\n");
	}
}
	
	

int main(){
	//zmienne, które bêd¹ potem wczytywane z pliku
	int a = 15, b = 15;
	
	
	
	int place[15][15]={0}; //plansza do gry
	place[9][13] = 1;
	place[2][5] = 1;
	
	board(a, b, place);
	
	
	
	
	
//	printf("Projekt.\n");
	
	
	
	return 0;
}
	
