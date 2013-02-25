#include<cilk.h>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<numeric>
#include<sys/time.h>


void readlife(unsigned char *a,unsigned int n);
void genlife(unsigned char *a,unsigned int n, int whichstart);
void life(unsigned char *a,unsigned int n, unsigned int iter, int* livecount);
void printGame(unsigned int n, int age);
int countlive(unsigned char *a, unsigned int n, int age);
