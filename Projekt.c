#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void board(int a, int b, int **tab){ //Function which draws current state of the game and counts number living and dead cells.
	system("cls");
	printf("	GAME OF LIFE\n\n");
	int i, j;
	for (i=1; i<=a; i++){
		for (j=1; j<=b; j++){
			if (tab[i][j] == 0){
				printf("  ");
			} else {
				printf("o ", tab[i][j]);
			}
		}
		printf("\n");
	}
}

void VarFromFile(int *p1, int *p2, int *p3, int *p4, int *p5){ //Function responsible for reading variables from config.txt file.
	
	FILE *variables = fopen("config.txt", "r");
	if(variables == NULL){
		perror("File opening error!\n");
		return;
	}
	char ch[300]={'\0'}, vars[5][7] = {'\0'};
	int i=0, n=0, o=0;
	
	while (feof(variables)==0){
		ch[i] = fgetc(variables);
		
		if (isdigit(ch[i])){
			vars[n][o] = ch[i];
			o++;
		} else if (iscntrl(ch[i])!=0){
			n++;
			o=0;
		}
		i++;
	}
	
	*p1 = atoi(vars[0]);
	*p2 = atoi(vars[1]);
	*p3 = atoi(vars[2]);
	*p4 = atoi(vars[3]);
	*p5 = atoi(vars[4]);

	fclose(variables);	
}



int state(int **tab, int a, int b){ //Function responsible for whole system's evolution.
	int c, i, j, x, y, count=0, stop=0, diff1=0, diff2=0;
	int **prev, **res;
	
	prev = calloc(a+2, sizeof(int*));
	for (c=0; c<a+2; c++){
		prev[c] = calloc(b+2, sizeof(int*));
	}
	/*Copying actual game's state to other two-dimensional array,
	which will represent previous step's status.*/
	for (i=0; i<a+2; i++){
		for (j=0; j<b+2; j++){
			prev[i][j] = tab[i][j];
		}
	}
	
	//Additional array with results.
	res = calloc(a+2, sizeof(int*));
	for (c=0; c<a+2; c++){
		res[c] = calloc(b+2, sizeof(int*));
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
			if (count == 3 && tab[i][j] == 1){
				res[i][j] = 1;
			} else if (count == 4 && tab[i][j] == 1){
				res[i][j] = 1;
			} else if (count == 3 && tab[i][j] == 0){
				res[i][j] = 1;
			} else {
				res[i][j] = 0;
			}
		}
	}
	
	for (i=1; i<=a; i++){
		for (j=1; j<=b; j++){
			tab[i][j] = res[i][j];
		}
	}
	
	/*Comparing previous step with current one.
	If they're identical, then diff2 won't change*/
	for (i=1; i<=a; i++){
		for (j=1; j<=b; j++){
			if (tab[i][j] != prev[i][j]){
				diff2++;
			}
		}
	}
	
	//If diff1 and diff2 are the same, that means, that current and previous step are the same.
	if (diff1 == diff2){
		stop = 1;
	} else {
		stop = 0;
	}
	
	return stop;
}
			
int cont(int m){ //cont (contigent), because "random" makes problems with some compilators.
	int r;
	r = (rand()%m)+1;
	return r;
}	

int main(){
	int a = 25, b = 25, hm = 300, x, y, c, i, j, count=0, halt=0, alive=0, dead=0, end=0, exit=0, step=0;
	int **place;
	char comm = 'g';
	srand(time(0));
	
	FILE *data = NULL;
	FILE *output = NULL;
	data = fopen("config.txt", "r");
	output = fopen("data.dat", "w+");
	

	if(data == NULL || output == NULL) {
	perror("File opening error!\n");
	return 1;
	}	
	
	VarFromFile(&a, &b, &hm, &end, &exit);
	
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
		x = cont(b);
		y = cont(a);
		if (place[y][x] == 0){
			place[y][x] = 1;
			i++;
		}
	}	
		
	board(a, b, place);
	printf("Step: %i	Dead: %i	Alive: %i\n", count, a*b-hm, hm);
	sleep(1);
	count++;
	do{
		fprintf(output, "%i %i %i\n", count, dead, alive); //Saving to files in 3 columns, separated by space.
		halt = state(place, a, b);
		board(a, b, place);
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
		printf("Step: %i	Dead: %i	Alive: %i\n", count, dead, alive);
		count++;
		step++;
		if (step == exit && exit != 0){
			step = 0;
			printf("Do you want to stop the game?\n\
Type \"e\" and press \"Enter\" to stop or press \"Enter\" to continue.\n");
			comm = getchar();
			if (comm == 'e'){
				break;
			}
		}
		if (end != 0 && count == end){
			break;
		}
		sleep(1);
	} while (halt != 1);
	
	printf("Game ended in %i steps.\n", count-1);	
		
	fclose(data);
	fclose(output);
	
	return 0;
}	
