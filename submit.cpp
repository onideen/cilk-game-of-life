/*
Homework 5 : The Game of Life.
Team member 1 : John Doe 
Team member 2 : Jane Doe
*/

#include "life.h"

//Generate the life matrix any way you want. We would highly recommend that you print the generated
//matrix into a file, so that you can share it with other teams for checking correctness.
void genlife(int *a, unsigned int n){
	//int i, j;	

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			a[i*n +j] = 1;
		}
	}	
}

//Read the life matrix from a file
void readlife(int *a, unsigned int n){

}

int countNeighbours(int *a, unsigned int n){
	int neighbours = 0;
	if(a[(i*n)%n + (j-1)%n] == 1){
		neighbours++;
	}
	
	if(a[(i*n)%n + (j+1)%n] == 1){
		neighbours++;
	}

	if(a[((i-1)*n)%n + j%n] == 1){
		neighbours++;
	}

	if(a[((i+1)*n)%n + j%n] == 1){
		neighbours++;
	}

	if(a[((i+1)*n)%n + (j-1)%n] == 1){
		neighbours++;
	}

	if(a[((i+1)*n)%n + (j+1)%n] == 1){
		neighbours++;
	}

	if(a[((i-1)*n)%n + (j-1)%n] == 1){
		neighbours++;
	}

	if(a[((i-1)*n)%n + (j+1)%n] == 1){
		neighbours++;
	}

	return neighbours;
}

//Life function
void life(int *a, unsigned int n, unsigned int iter){
	int *b;
	b = malloc(sizeof(int)*n*n);

	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j){
			if(countNeighbours(a,n) > 3){
				b[i*n+j] = 0;
			}else if(countNeighbours(a,n) < 2){
				b[i*n+j] = 0;

			}else if(countNeighbours(a,n) == 3){
				b[i*n+j] = 1;
			}else if(a[i*n+j]==1 && countNeighbours(a,n) ==2){
				b[i*n +j] = 1;
			}
		}
	}

	memcpy(a,b,sizeof(int)*n*n);
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
