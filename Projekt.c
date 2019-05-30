#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void board(int a, int b, int **tab){ //funkcja rysuj¹ca planszê (wraz z ¿ywymi komórkami).
//	system("cls");
	int i, j;
	for (i=1; i<=a; i++){
		for (j=1; j<=b; j++){
			if (tab[i][j] == 0){
				printf("  ");
			} else {
				printf("x ", tab[i][j]);
			}
		}
		printf("\n");
	}
}

int state(int **tab, int a, int b){
	int c, i, j, x, y, count=0, res, stop=0, diff1=0, diff2=0;
	int **prev;
	
	prev = calloc(a, sizeof(int*));
	for (c=0; c<a+2; c++){
		prev[c] = calloc(b+2, sizeof(int));
	}
	/*Przepisanie aktualnego stanu planszy, do drugiej tablicy tablic,
	ktora bedzie oznaczac stan poprzedniego kroku.*/
	for (i=0; i<a+2; i++){
		for (j=0; j<b+2; j++){
			prev[i][j] = tab[i][j];
		}
	}
	
	for (i=1; i<=a; i++){
		for (j=1; j<=b; j++){
			if (tab[i][j]==1){
				count--;
				for (y=i-1; y<=i+1; y++){
					for (x=j-1; x<=j+1; x++){
						printf("%i %i", i, j);
						if (tab[y][x]==1){
							count++;
						}
					}
				}
				if (count==2 || count == 3){
					res = 1;
				} else {
					res = 0;
				}
			} else if (tab[i][j]==0){
				for (y=i-1 && y>=0; y<=i+1 && y<a; y++){
					for (x=j-1 && x>=0; x<=j+1 && x<b; x++){
						if (tab[y][x]==1){
							count++;
						}
					}
				}
				if (count == 3){
					res = 1;
				} else {
					res = 0;
				}
			}
			tab[i][j] = res;
		}
	}
	/*Porownanie kroku poprzedniego z krokiem nastepnym,
	jesli sa identyczne, to parametr diff2 nie ulegnie zmianie.*/
	for (i=0; i<a; i++){
		for (j=0; j<b; j++){
			if (tab[i][j] != prev[i][j]){
				diff2++;
			}
		}
	}
	//Jesli diff1 i diff2 sa rowne 0, oznacza to, ze krok poprzedni i krok nastepny sa takie same.
	if (diff1 == diff2){
		stop = 1;
	}
	
	return stop;
}

			
int random(int m){
	int seed, r;
	time_t tt;
//	seed = time(NULL);
//	srand(seed);
	r = (rand()%m)+1;
	return r;
}
	
	

int main(){
	//zmienne, które bêd¹ potem wczytywane z pliku
	int a = 20, b = 20, hm = 2, x, y, c, i, j, count=0, halt=0;
	int **place;
	
	place = calloc(a+2, sizeof(int*));
	for (c=0; c<a+2; c++){
		place[c] = calloc(b+2, sizeof(int));
	}
	
	for (i=0; i<a+2; i++){
		for(j=0; j<b+2; j++){ 
			place[i][j] = (int) 0;
		}
	}
	
	for (i=0; i<hm;){
		x = random(a);
		y = random(b);
		if (place[y][x] == 0){
			place[y][x] = 1;
			i++;
		}
	}
	
	board(a, b, place);
	
	do{
		board(a, b, place);
		halt = state(place, a, b);
		count++;
	//	sleep(1);
		system("pause");
	} while (halt != 1);
	
	printf("Game ended in %i steps.\n", count);	
	
	return 0;
}
	
