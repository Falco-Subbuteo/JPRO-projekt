#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void board(int a, int b, int **tab){ //funkcja rysuj¹ca planszê (wraz z ¿ywymi komórkami).
	system("cls");
	int i, j;
	for (i=0; i<a; i++){
		for (j=0; j<b; j++){
//			if (tab[i][j] == 0){
//				printf("%i");
//			} else {
				printf("%i ", tab[i][j]);
		//	}
		}
		printf("\n");
	}
}

int random(int m){
	int seed, r;
	time_t tt;
//	seed = time(&tt);
//	srand(seed);
	r = rand()%m;
	return r;
}
	
	

int main(){
	//zmienne, które bêd¹ potem wczytywane z pliku
	int a = 20, b = 20, hm = 32, x, y, c, i, j, count=0;
	int **place;
	
	place = calloc(a, sizeof(int*));
	for (c=0; c<a; c++){
		place[c] = calloc(b, sizeof(int));
	}
//
//	place = (int*) calloc(a, sizeof(int));
//	for (c=0; c<a; c++){
//		place[c] = (int*) calloc(b, sizeof(int));
//	}
	
	for (i=0; i<a; i++){
		for(j=0; j<b; j++){ 
			place[i][j] = (int) 0;
		//	printf("%i", place[i][j]);
		}
	//	printf("\n");
	}
	
	for (i=0; i<hm;){
		x = random(a);
		y = random(b);
		if (place[x][y] == 0){
			place[x][y] = 1;
			i++;
		}
	}
		
	
//	place[9][13] = 1;
//	place[2][5] = 1;
	
	board(a, b, place);
	

	
	
	
	return 0;
}
	
