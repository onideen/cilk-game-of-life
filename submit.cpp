/*
Homework 5 : The Game of Life.
Team member 1 : Vegar Engen 
Team member 2 : Arne Bjune
*/

#include "life.h"
unsigned int size;
int *array;



//Generate the life matrix any way you want. We would highly recommend that you print the generated
//matrix into a file, so that you can share it with other teams for checking correctness.
void printGame(unsigned int n, int* a){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%i ", a[i* n + j]);
		}
		printf("\n");
	}
}

int getElement(int x, int y, int age){	
	return array[y*size+x];
}

void setElement(int x, int y, int age, int value){
	array[y*size+x]=value;

}

void genlife(int *a, unsigned int n){
	//int i, j;	

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i*n +j] = 1;
		}
	}	
}

//Read the life matrix from a file
void readlife(int *a, unsigned int n){
	
	FILE *file;
	int i,j;
	char *line;
	line = (char *)malloc(2*n+2);

	file = fopen("input","rt");

	if(file == NULL){
		printf("Input file not found\n");
		exit(-1);
	}
	for(i = 0; i < n; i++){
		fgets(line, 2*n+2, file);
		for(j =0; j < n; j++){
			a[j +i*n] = atoi(&line[2 * j]);
		}
	}
}

int countNeighbours(int *a, unsigned int n, int x, int y){

	int neighbours = 0;
	
	neighbours += getElement(x,(y+1+size)%size, 0);
	neighbours += getElement(x,(y-1+size)%size, 0);
	neighbours += getElement((x+1+size)%size,y, 0);
	neighbours += getElement((x-1+size)%size,y, 0);
	neighbours += getElement((x+1+size)%size,(y+1+size)%size, 0);
	neighbours += getElement((x+1+size)%size,(y-1+size)%size, 0);
	neighbours += getElement((x-1+size)%size,(y+1+size)%size, 0);
	neighbours += getElement((x-1+size)%size,(y-1+size)%size, 0);

	return neighbours;
}


void Calculate_next_life(int *a, int *b, unsigned int n) {
	cilk_for (int i = 0; i < n; ++i)	{
		cilk_for (int j = 0; j < n; ++j){
			unsigned int neighbours = countNeighbours(a,n,j,i);
			if(neighbours > 3){
				b[i*n+j] = 0;
			}else if(neighbours < 2){
				b[i*n+j] = 0;

			}else if(neighbours == 3){
				b[i*n+j] = 1;
			}else if(neighbours ==2){
				b[i*n +j] = a[i*n+j];
			}
		}

	}
	memcpy(a,b,sizeof(int)*n*n);
	printf("\n");
	printGame(n,a);


}


void Store_into_livecount(int total_lives) {

}

//Life function
void life(int *a, unsigned int n, unsigned int iter, int* livecount){

	int *b;
	b = (int *)malloc(sizeof(int)*n*n);
	size = n;
	array = a;

	printGame(n,a);

	for (int current_it = 0; current_it < iter; ++current_it){
		Calculate_next_life(a,b,n);

		#if DEBUG == 1
			if(iter%10 == 0) {
				if(current_it%(iter/10) == 0) {
					printf("HERE\n");
					int total_lives = countlive(a, n);
					
					livecount[current_it/(iter/10)] = total_lives;
				}
			}
		#endif
	}
}

