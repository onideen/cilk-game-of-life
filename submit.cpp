/*
Homework 5 : The Game of Life.
Team member 1 : Vegar Engen 
Team member 2 : Arne Bjune
*/

#include "life.h"
#include "math.h"

unsigned int size;
int *array;
int *array2;



//Generate the life matrix any way you want. We would highly recommend that you print the generated
//matrix into a file, so that you can share it with other teams for checking correctness.

//Gets an element with cordinates x,y 
int getElement(int x, int y, int age){
	if(age == 0){
		return array[y*size + x];
	}else{
		return array2[y*size + x];
	}
}

//Sets an element with cordinates x,y to value
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

//The countlive function to be used for calculating the number of live cells.
int countlive(int age, unsigned int n)
{
	int sum = 0;
	for(int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; ++x)
		{
			sum += getElement(x, y, age);	
		}
	}	

	return sum;
}

//Print the board
void printGame(unsigned int n, int age){
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			printf("%i ", getElement(x,y,age));
		}
		printf("\n");
	}
}

void genlife(int *a, unsigned int n, int whichstart) {
	int startX = floor(n/3);
	int startY = floor(n/5);
	size = n;
	array = a;
	
	memset(array, 0, n*n);
	switch (whichstart) {
		case 0:
			break;

		case 1:
			{
				// An interesting cell
				int cell[25] = {1,1,1,0,1, 1,0,0,0,0, 0,0,0,1,1, 0,1,1,0,1, 1,0,1,0,1};

				for (int y = 0; y < 5; y++){
					for (int x = 0; x < 5; x++) {
						setElement(x+startX, y+startY, 0, cell[y*5+x]);
					}
				}
			}
			break;

		case 2:
			{
				// Glider
				int glider[9] = {1,1,1, 1,0,0, 0,1,0};

				for (int y = 0; y < 3; y++){
					for (int x = 0; x < 3; x++) {
						setElement(x+startX, y+startY, 0, glider[y*3+x]);
					}
				}
				break;
			}
		case 3:
			{
				// Lightweight spaceship
				int blinker[25] = {0,0,0,0,0, 0,1,0,0,1, 1,0,0,0,0, 1,0,0,0,0, 1,1,1,1,0};

				for (int y = 0; y < 5; y++){
					for (int x = 0; x < 5; x++) {
						setElement(x+startX, y+startY, 0, blinker[y*5+x]);
					}
				}
				break;
			}
		case 4:
			{
				// Blinker
				int blinker[9] = {0,0,0, 1,1,1, 0,0,0};

				for (int y = 0; y < 3; y++){
					for (int x = 0; x < 3; x++) {
						setElement(x+startX, y+startY, 0, blinker[y*3+x]);
					}
				}
				break;
			}
		case 5:
			{
				// Toad
				int toad[16] = {0,0,1,0, 1,0,0,1, 1,0,0,1, 0,1,0,0};

				for (int y = 0; y < 4; y++){
					for (int x = 0; x < 4; x++) {
						setElement(x+startX, y+startY, 0, toad[y*4+x]);
					}
				}
				break;
			}

	}
}

//Read the life matrix from stdin
void readlife(int *a, unsigned int n){
	char *line;
	array = a;
	size = n;

	line = (char *)malloc(2*n+2);
	for(int y = 0; y < n; y++){
		fgets(line, 2*n+2, stdin);
		for(int x = 0; x < n; x++){
			setElement(x,y,0,atoi(&line[2 * x]));
		}
	}
}

//Count the number of living Neighbours
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
	return neighbours;
}

//Do one iteration
void Calculate_next_life(int *a, unsigned int k) {
	printGame(size,(k)%2);
	printf("\n");
	cilk_for (int y = 0; y < size; ++y)	{
		cilk_for (int x = 0; x < size; ++x){
			unsigned int neighbours = countNeighbours(x,y,k%2);

			if(neighbours > 3){
				setElement(x,y,(k+1)%2,0);
			}else if(neighbours < 2){
				setElement(x,y,(k+1)%2,0);
			}else if(neighbours == 3){
				setElement(x,y,(k+1)%2,1);
			}else if(neighbours ==2){
				setElement(x,y,(k+1)%2,getElement(x,y,k%2));
			}
		}
	}	

}


void Store_into_livecount(int total_lives) {

}

//Life function
void life(int *a, unsigned int n, unsigned int iter, int* livecount){

	array2 = (int *)malloc(sizeof(int)*n*n);
	size = n;
	array = a;



	for (int current_it = 1; current_it <= iter; ++current_it){
		Calculate_next_life(a,current_it-1);

		#if DEBUG == 1
			if(iter%10 == 0) {
				if(current_it%(iter/10) == 0) {
					int total_lives = countlive(current_it%2, n);
					livecount[(current_it/(iter/10)) -1] = total_lives;
				}
			}
		#endif
	}
	
//	printGame(n,iter%2);

}

