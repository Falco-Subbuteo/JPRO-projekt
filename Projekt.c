#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void board(int a, int b, int **tab){ //funkcja rysuj¹ca planszê (wraz z ¿ywymi komórkami).
	system("cls");
	int i, j;
	for (i=0; i<a; i++){
		for (j=0; j<b; j++){
			if (tab[i][j] == 0){
				printf("  ");
			} else {
				printf("o ", tab[i][j]);
			}
		}
		printf("\n");
	}
}

int state(int **tab, int a, int b){
	int i, j, x, y count=0, res;
//	for (i=y-1; i<=y+1 && i<b; i++){
//		for (j=x-1; j<=x+1 && j<a; j++){
	for (i=0; i<a; i++){
		for (j=0; j<b; j++){
			if (tab[i][j]==1){
				count--;
				for (y=i-1; y<=i+1; y++){
					for (x=j-1; x<=j+1; x++){
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
				for (y=i-1; y<=i+1; y++){
					for (x=j-1; x<=j+1; x++){
						if (tab[y][x]==1){
							count++;
						}
					}
				}
				if (count == 3){
					res = 1;
				} else if (count == 0){
					res = 0;
				}
			}
		}
	}
	return res;
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
		if (place[y][x] == 0){
			place[y][x] = 1;
			i++;
		}
	}
	
	board(a, b, place);
	
	
	return 0;
}
	
