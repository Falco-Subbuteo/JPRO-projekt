#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void board(int a, int b, int **tab){ //funkcja rysuj¹ca planszê (wraz z ¿ywymi komórkami).
	system("cls");
	int i, j;
	for (i=1; i<=a; i++){
		for (j=1; j<=b; j++){
		//	if (tab[i][j] == 0){
		//		printf("  ");
		//	} else {
				printf("%i ", tab[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
//}



int state(int **tab, int a, int b){
	int c, i, j, x, y, count=0, res, stop=0, diff1=0, diff2=0;
	int **prev;
	
	prev = calloc(a+2, sizeof(int*));
	for (c=0; c<a+2; c++){
		prev[c] = calloc(b+2, sizeof(int*));
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
			count = 0;
			for (y=i-1; y<=i+1; y++){
				for (x=j-1; x<=j+1; x++){
					if (tab[y][x]==1){
						count++;
					}
				}
			}
			if (tab[i][j] == 1) {
				if (count == 1 || count == 2){
					tab[i][j] = 1;
				} else {
					tab[i][j] = 0;
				}
			} else if (tab[i][j] == 0) {
				if (count == 3) {
					tab[i][j] = 1;
				} else {
					tab[i][j] = 0;
				}
			}
		}
	}
	/*Porownanie kroku poprzedniego z krokiem nastepnym,
	jesli sa identyczne, to parametr diff2 nie ulegnie zmianie.*/
	for (i=1; i<=a; i++){
		for (j=1; j<=b; j++){
			if (tab[i][j] != prev[i][j]){
				diff2++;
			}
		}
	}
	//Jesli diff1 i diff2 sa rowne 0, oznacza to, ze krok poprzedni i krok nastepny sa takie same.
	if (diff1 == diff2){
		stop = 1;
	} else {
		stop = 0;
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
	//zmienne, których czêœæ ma byæ potem wczytywana z pliku
	int a = 20, b = 20, hm = 100, x, y, c, i, j, count=0, halt=0, alive=0, dead=0;
	int **place;
	
	place = calloc(a+2, sizeof(int*));
	for (c=0; c<a+2; c++){
		place[c] = calloc(b+2, sizeof(int*));
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
	
	
	//FILE *data = NULL;
	FILE *output = NULL;
	//data = fopen("config.dat", "r");
	output = fopen("data.dat", "w+");
	
	//inna metoda
	if(/*data == NULL || */output == NULL) {
	perror("File opening error!\n"); //funkcja wywalajaca komentarz o bledzie
	return 1; //wyjscie z programu cokolwiek innego w return niz zero, zeby bylo wiadomo w ktorym momencie wyszlo z programu
	}
	
//	board(a, b, place);
//	sleep(1);
//	for (i=1; i<=a; i++){
//		for(j=1; j<=b; j++){
//			if (place[i][j] == 1){
//				alive++;
//			} else {
//				dead++;
//			}
//		}
//	}
//	fprintf(output, "%i %i %i\n", count, dead, alive);

	
	do{
	//	board(a, b, place);
		dead = 0;
		alive = 0;		
		for (i=1; i<=a; i++){
			for(j=1; j<=b; j++){
				if (place[i][j] == 1){
					alive++;
				} else {
					dead++;
				}
			}
		}
	//	printf("%i", count);
		fprintf(output, "%i %i %i\n", count, dead, alive);
		halt = state(place, a, b);
		board(a, b, place);
		count++;
		
	//	sleep(1);
		system("pause");
	} while (halt != 1);
	
	printf("Game ended in %i steps.\n", count);	
	
	return 0;
}
	
