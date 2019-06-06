#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void board(int a, int b, int **tab){ //funkcja rysuj¹ca planszê (wraz z ¿ywymi komórkami).
	system("cls");
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
	printf("Press \"e\" key, to stop.\n");
}



int state(int **tab, int a, int b){
	int c, i, j, x, y, count=0, stop=0, diff1=0, diff2=0;
	int **prev, **res;
	
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
	
	//Pomocnicza tablica z wynikami
	res = calloc(a+2, sizeof(int*));
	for (c=0; c<a+2; c++){
		res[c] = calloc(b+2, sizeof(int*));
	}

	
	for (i=1; i<=a; i++){
		for (j=1; j<=b; j++){
			count = 0;
			for (y=i-1; y<=i+1; y++){
				for (x=j-1; x<=j+1; x++){
	//				printf("%i ", tab[y][x]);
					if (tab[y][x]==1){
						count++;
					}
				}
	//			printf("\n");
			}
//			printf("%i -----------------\n", count); //dot¹d jest ok
			if (count == 3 && tab[i][j] == 1){
				res[i][j] = 1;
			} else if (count == 4 && tab[i][j] == 1){
				res[i][j] = 1;
			} else if (count == 3 && tab[i][j] == 0){
				res[i][j] = 1;
			} else {
				res[i][j] = 0;
			}
			//////////////////////////
		}
	}
	
	for (i=1; i<=a; i++){
		for (j=1; j<=b; j++){
			tab[i][j] = res[i][j];
		}
	}
	/*
	for (i=1; i<=a; i++){
		for (j=1; j<=b; j++){
			printf("%i ", res[i][j]);
		}
		printf("\n");
	}
//	printf("--------------------------\n");
	for (i=1; i<=a; i++){
		for (j=1; j<=b; j++){
			printf("%i ", tab[i][j]);
		}
		printf("\n");
	}
	*/
	
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



			
int cont(int m){ //contigent, bo random siê gryzie
	int seed, r;
	time_t tt;
//	seed = time(NULL);
//	srand(seed);
	r = (rand()%m)+1;
	return r;
}
	
	

int main(){
	//zmienne, których czêœæ ma byæ potem wczytywana z pliku
	int a = 25, b = 25, hm = 200, x, y, c, i, j, count=0, halt=0, alive=0, dead=0, end=0;
	int **place;
	char com = 'g';
	
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
		x = cont(a);
		y = cont(b);
		if (place[y][x] == 0){
			place[y][x] = 1;
			i++;
		}
	}	


//	place[1][2] = 1;
//	place[2][2] = 1;
//	place[3][2] = 1;
	
	for (i=1; i<=a; i++){
		for(j=1; j<=b; j++){
			printf("%i ", place[i][j]);
		}
		printf("\n");
	}
	
//	sleep(1);
//	system("cls");
	
	
	FILE *data = NULL;
	FILE *output = NULL;
	data = fopen("config.dat", "r");
	output = fopen("data.dat", "w+");
	
	//inna metoda
	if(data == NULL || output == NULL) {
	perror("File opening error!\n"); //funkcja wywalajaca komentarz o bledzie
	return 1; //wyjscie z programu cokolwiek innego w return niz zero, zeby bylo wiadomo w ktorym momencie wyszlo z programu
	}
	

	board(a,b,place);
	sleep(1);

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
		com = getchar();
		if (com == 'e'){
			break;
		}
		if (end != 0 && count == end){
			break;
		}
		sleep(1);
	//	system("pause");
	} while (halt != 1);
	
	printf("Game ended in %i steps.\n", count);	
	
	fclose(data);
	fclose(output);
	
	return 0;
}
	
