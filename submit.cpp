/*
Homework 5 : The Game of Life.
Team member 1 : John Doe 
Team member 2 : Jane Doe
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

int countNeighbours(int *a, unsigned int n, int i, int j){
	int neighbours = 0;

	if(a[(i)*n + (j-1+n)%n] == 1){
		neighbours++;
	}
	
	if(a[(i)*n + (j+1)%n] == 1){
		neighbours++;
	}

	if(a[((i+1+n)%n)*n + j%n] == 1){
		neighbours++;
	}

	if(a[((i-1+n)%n)*n + j%n] == 1){
		neighbours++;
	}

	if(a[((i+1+n)%n)*n + (j-1+n)%n] == 1){
		neighbours++;
	}

	if(a[((i+1+n)%n)*n + (j+1)%n] == 1){
		neighbours++;
	}

	if(a[((i-1+n)%n)*n + (j-1+n)%n] == 1){
		neighbours++;
	}

	if(a[((i-1+n)%n)*n + (j+1)%n] == 1){
		neighbours++;
	}


	return neighbours;
}

//Life function
void life(int *a, unsigned int n, unsigned int iter){

	int *b;
	b = (int *)malloc(sizeof(int)*n*n);
	size = n;
	array =a;

	printGame(n,a);

	for (int k = 0; k < iter; ++k){
		for (int i = 0; i < n; ++i)	{
			for (int j = 0; j < n; ++j){
				if(countNeighbours(a,n,i,j) > 3){
					b[i*n+j] = 0;
				}else if(countNeighbours(a,n,i,j) < 2){
					b[i*n+j] = 0;

				}else if(countNeighbours(a,n,i,j) == 3){
					b[i*n+j] = 1;
				}else if(countNeighbours(a,n,i,j) ==2){
					b[i*n +j] = a[i*n+j];
				}
			}

		}
		memcpy(a,b,sizeof(int)*n*n);
		printf("\n");
		printGame(n,a);
	}

	// You need to store the total number of livecounts for every 1/0th of the total iterations into the livecount array. 
	// For example, if there are 50 iterations in your code, you need to store the livecount for iteration number 5 10 15 
	// 20 ... 50. The countlive function is defined in life.cpp, which you can use. Note that you can
	// do the debugging only if the number of iterations is a multiple of 10.
	// Furthermore, you will need to wrap your counting code inside the wrapper #if DEBUG == 1 .. #endif to remove
	// it during performance evaluation.
	// For example, your code in this function could look like - 
	//
	//
	//	for(each iteration)
	//      {
	//			
	//		Calculate_next_life();
	//		
	//		#if DEBUG == 1
	//		  if_current_iteration == debug_iteration
	//		  total_lives = countlive();
	//		  Store_into_livecount(total_lives);
	//		#ENDIF
	//		
	//	}
}

