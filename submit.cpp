/*
Homework 5 : The Game of Life.
Team member 1 : John Doe 
Team member 2 : Jane Doe
*/

#include "life.h"
#include "math.h"

unsigned int size;
int *array;
int *array2;

//Generate the life matrix any way you want. We would highly recommend that you print the generated
//matrix into a file, so that you can share it with other teams for checking correctness.

int getElement(int x, int y, int age){
	if(age == 0){
		return array[y*size + x];
	}else{
		return array2[y*size + x];
	}
}

int setElement(int x, int y, int age, int value){
	if(age == 0){
		array[y*size +x] = value;
	}else{
		array2[y*size +x] = value;
	}
}
/*
int getElement(int x, int y, int age){
	int currentVal = array[(y*size)/4+x/4];
//	printf("Getting %i %i %i\n", (int) array[(y*size)/4+x/4] , (int)pow(2,(x%4)*2+age),(int) array[(y*size)/4+x/4] & (int)pow(2,(x%4)*2+age));

	if((currentVal  & (int)pow(2,(x%4)*2+age)) == (int)pow(2,(x%4)*2+age)){
	//	printf("Fant 1\n");
		return 1;
	}else if((currentVal & (int)pow(2,(x%4)*2+age)) == 0){
	//	printf("Fant 0\n");
		return 0;
	}else{
	//	printf("---------------error!----------------\n");
	}
}

void setElement(int x, int y, int age, int value){
	int currentVal = getElement(x,y,age);
	//printf("%i & %i = %i \n", currentVal, pow(2,(x%4)*2+age),currentVal & (int)pow(2,(x%4)*2+age));
	if((currentVal & (int)pow(2,(x%4)*2+age)) == 0 && value == 1){
		array[(y*size)/4+x/4] += (int)pow(2,(x%4)*2+age);
	//	printf("Setting 1\n");

	
	} else if((currentVal & (int)pow(2,(x%4)*2+age)) == pow(2,(x%4)*2+age) && value == 0){
		array[(y*size)/4+x/4] -= pow(2,(x%4)*2+age);
	//	printf("Setting 0\n");
	}
}
*/
void printGame(unsigned int n, int age){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%i ", getElement(j,i,age));
		}
		printf("\n");
	}
}

void genlife(int *a, unsigned int n){
	array = a;
	size = n;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			setElement(i,j,0,1);
		}
	}	
}

//Read the life matrix from a file
void readlife(int *a, unsigned int n){
	FILE *file;
	int i,j;
	char *line;
	array = a;
	size = n;

	line = (char *)malloc(2*n+2);

	file = fopen("input","rt");

	if(file == NULL){
		printf("Input file not found\n");
		exit(-1);
	}
	for(i = 0; i < n; i++){
		fgets(line, 2*n+2, file);
		for(j =0; j < n; j++){
			setElement(j,i,0,atoi(&line[2 * j]));
		}
	}
}

int countNeighbours(int x, int y, int age){

	int neighbours = 0;
	
	neighbours += getElement(x,(y+1+size)%size, age);
	neighbours += getElement(x,(y-1+size)%size, age);
	neighbours += getElement((x+1+size)%size,y, age);
	neighbours += getElement((x-1+size)%size,y, age);
	neighbours += getElement((x+1+size)%size,(y+1+size)%size, age);
	neighbours += getElement((x+1+size)%size,(y-1+size)%size, age);
	neighbours += getElement((x-1+size)%size,(y+1+size)%size, age);
	neighbours += getElement((x-1+size)%size,(y-1+size)%size, age);
	printf("%i ", getElement((x-1+size)%size,(y-1+size)%size, age));
	return neighbours;
}


void inIteration(int *a, int k) {
	printf("\nDEBUG med age %i\n",k%2);
	for (int i = 0; i < size; ++i)	{
		for (int j = 0; j < size; ++j){
			unsigned int neighbours = countNeighbours(j,i,k%2);
	//		printf("%i ",neighbours );
			if(neighbours > 3){
				setElement(j,i,(k+1)%2,0);
				//b[i*n+j] = 0;
			}else if(neighbours < 2){
				setElement(j,i,(k+1)%2,0);
				
				//b[i*n+j] = 0;

			}else if(neighbours == 3){
				setElement(j,i,(k+1)%2,1);
				
				//b[i*n+j] = 1;
			}else if(neighbours ==2){
				setElement(j,i,(k+1)%2,getElement(j,i,k%2));
				
				//b[i*n +j] = a[i*n+j];
			}
		}
		printf("\n");
	}
	//memcpy(a,b,sizeof(int)*n*n);
	printf("\nITER\n");
	printGame(size,(k+1)%2);


}
//Life function
void life(int *a, unsigned int n, unsigned int iter){

	array2 = (int *)malloc(sizeof(int)*n*n);
	size = n;
	array = a;

	printGame(n,0);

	for (int k = 0; k < iter; ++k){
		inIteration(a,k);
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

