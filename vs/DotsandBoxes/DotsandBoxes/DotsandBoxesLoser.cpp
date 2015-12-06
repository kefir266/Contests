// DotsandBoxes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>


#define N 5
#define num(x) (((x & 1) && 1) + ((x & 2) && 2) + ((x & 4) && 4) + ((x & 8) && 8))

using namespace std;


int mas[N][N];

int mx,my;
int num01;


struct Sell;

struct Move {
		int isMade;
		int code;
		int cost;
		int x,y;
		Sell *neighbour;
		Sell *sell;
	} *allMoves[4*N*N],*aux[4*N*N];


int numAllMoves;

struct Sell {
	int state;
	int x,y;
	int numTurns;
	//Sell* neighbour[4];
	Move moves[4];
	//Sell* next;
	//Sell* prev;
} sells[N][N];

void setMoves(Sell& sell) {
	int bit;
	for (int i = 0 ; i < 4 ; i++){
		int p = (int) pow( (double) 2, (double) i);
		bit = sell.state & p;
		sell.moves[i].isMade = bit;
		if (!bit) {
			sell.moves[i].code = i;
			sell.moves[i].x = sell.x;
			sell.moves[i].y = sell.y;
			allMoves[numAllMoves] = &sell.moves[i];
			allMoves[numAllMoves]->sell = &sell;
			
			numAllMoves++;

		}
	}
	
}




void merge(int lo, int mid, int hi){

	for (int k = lo; k <= hi; k++) {
            aux[k] = allMoves[k]; 
        }

        
        int i = lo, j = mid+1;
        for (int k = lo; k <= hi; k++) {
            if      (i > mid)              allMoves[k] = aux[j++];
            else if (j > hi)               allMoves[k] = aux[i++];
            else if ((aux[j]->cost > aux[i]->cost)) allMoves[k] = aux[j++];
            else                           allMoves[k] = aux[i++];
        }
}

void sort(int lo, int hi){
	if (hi <= lo) return;
        int mid = lo + (hi - lo) / 2;
        sort(lo, mid);
        sort(mid + 1, hi);
		merge(lo, mid, hi);
}
void sortMoves() {
	
	sort( 0, numAllMoves-1);
}


int getCostSell(int cost){
	switch (cost) {
	case 0: return -10;
	case 1: return 10;
	case 2: return -60;
	case 3: return 90;
	}
	return 0;
}

int getCostSellRivel(int cost){
	switch (cost) {
	case 0: return 1;
	case 1: return -1;
	case 2: return 6;
	case 3: return -9;
	}
	return 0;
}

int calculateRivel(Move *moves) {
	
	int cost = 0;

	int i = numAllMoves;
	while (i--){

		switch (allMoves[i]->code){
		case 0:if (allMoves[i]->y > 0)
			allMoves[i]->neighbour =  &sells[allMoves[i]->y - 1][allMoves[i]->x];
			  
			   

			break;
		case 3:if (allMoves[i]->x > 0)
					allMoves[i]->neighbour =  &sells[allMoves[i]->y][allMoves[i]->x - 1];
			break;
		case 2:if (allMoves[i]->y < N - 1)
					allMoves[i]->neighbour =  &sells[allMoves[i]->y + 1][allMoves[i]->x];
			break;
		case 1:if (allMoves[i]->x < N - 1)
					allMoves[i]->neighbour =  &sells[allMoves[i]->y][allMoves[i]->x + 1];
			break;
		default: allMoves[i]->neighbour = NULL;
			continue;

		}
		cost =  (allMoves[i]->neighbour == NULL ? 0: getCostSell(allMoves[i]->neighbour->numTurns))
										+ getCostSell(allMoves[i]->sell->numTurns);
	}
	
}

void calculate() {

	int i = numAllMoves;
	while (i--){

		switch (allMoves[i]->code){
		case 0:if (allMoves[i]->y > 0)
			allMoves[i]->neighbour =  &sells[allMoves[i]->y - 1][allMoves[i]->x];
			  
			   

			break;
		case 3:if (allMoves[i]->x > 0)
					allMoves[i]->neighbour =  &sells[allMoves[i]->y][allMoves[i]->x - 1];
			break;
		case 2:if (allMoves[i]->y < N - 1)
					allMoves[i]->neighbour =  &sells[allMoves[i]->y + 1][allMoves[i]->x];
			break;
		case 1:if (allMoves[i]->x < N - 1)
					allMoves[i]->neighbour =  &sells[allMoves[i]->y][allMoves[i]->x + 1];
			break;
		default: allMoves[i]->neighbour = NULL;
			continue;

		}
		allMoves[i]->cost =  (allMoves[i]->neighbour == NULL ? 0: getCostSell(allMoves[i]->neighbour->numTurns))
										+ getCostSell(allMoves[i]->sell->numTurns) + calculateRivel(allMoves);
	}
	sortMoves();
}

int read(bool zero) {
	

	numAllMoves = 0;
	num01 = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) {
			
			cin >> mas[y][x];
			sells[y][x].x = x;
			sells[y][x].y = y;
			sells[y][x].state = mas[y][x];
			sells[y][x].numTurns = num(mas[y][x]);

			if (sells[y][x].numTurns < 2) num01++;
			
			setMoves(sells[y][x]);

		}
		int pl;
		cin >> pl;

		calculate();
		return pl;
		
}

void put(int turn) {

	cout << my << " "<< mx << " "<< turn << endl;

}



int getTurn(Sell sell){

	for (int i = 0; i < 4; i++){
		if (!sell.moves[i].isMade)
			return sell.moves[i].code;
	}

	return 0;
}

int nextMove() {
	
	if (allMoves[0] != NULL) {
		my = allMoves[0]->y;
		mx = allMoves[0]->x;
		return allMoves[0]->code;
	}

	
	return 0;
}

int main(int argc, char* argv[])
{
	


	int player = 1; 

	player = read(false);

	put(nextMove());



	return 0;
}
