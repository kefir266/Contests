// SolveMeFirst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main() {
  int N;
  

	scanf("%d",&N);
	//int** mas = (int**) malloc(sizeof(int*)*N);
	int iN;
	int sum = 0;
  for (int i = 0; i < N ; i++){
	  //mas[i] = (int*) malloc(sizeof(int)*N);
	  int j = N;
	  while(j--){
		  scanf("%d", &iN);//&mas[i][j]);
		  if (i == j) sum += iN;
		  if (i == N - j - 1) sum -= iN;
  }
  }		  

  
 // for (int i = 0; i <N ; i++)
	//sum += mas[i][i] - mas[i][N-i-1];

  printf("%d",abs(sum));
  return 0;
}
