// Gomoku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <ctime>
#define ABS(a)  ((a) < 0 ? -(a) : (a))

#define N 10

clock_t starttime;

using namespace std;


/////////////////////////
struct Dir {
	int x,y;

} dir[8] = {{-1,-1},{-1,0},{-1,1},
{0,-1},{0,1},
{1,-1},{1,0},{1,1}};

struct StrNext{
	int pl; int n;

};
//////////////////////////////////
class Move {

public:
	int x,y;
	int cost;

	Move* nextLink;
	Move() {
		nextLink = this;
		cost = -7777777;
	}
	Move(int movX, int movY) {
		x = movX;
		y = movY;
	}
	Move* next() {
		return nextLink;
	}
};


///////////////////////////////
class Field {

	Move* curMove;
	Move* bestMove;
	int player;
	int recurN;

public:
	int** mas;
	int numOfMoves;
	Move* firstMove;

	Field(int** fld, int pl){ ///New Field
		recurN = 0;
		numOfMoves = N * N;
		player = pl;
		copyInit(fld);
		
	}

	Field(Field& fld, int pl, Move* move, int recur){ /// Constructor's copier

		numOfMoves = N * N;
		player = pl;
		copyInit(fld.mas);
		
		fld.mas[move->y][move->x] = pl;
		recurN = recur;
	}

	~Field(){
		delete []mas;
	}

	//////////////////////////////////////////////
	void copyInit(int** fld){
		firstMove = new Move();
		curMove = firstMove;
		mas = new int*[N];
		for (int y = 0; y < N; y++){
			mas[y] = new int[N];
			for (int x = 0; x < N; x++){
				if (fld[y][x] != 0) {
					numOfMoves--;

				}
				else{
					curMove->nextLink = new Move(x,y);
					curMove = curMove->nextLink;
					curMove->nextLink = firstMove;
					
				}
				mas[y][x] = fld[y][x];
			}
		}
	}


	////////////////////////////////
	int getCostDirect(int player, int nextToPlayer, int numbOfNeighbor) {
		
		if (player == nextToPlayer) {
			switch (numbOfNeighbor) {
			case 0: return 0;
			case 1: return 20;
			case 2: return 100;
			case 3: return 200;
			case 4: return 2000;
			default: return 99999;
			}
		}
		else
		{
			switch (numbOfNeighbor) {
			case 0: return 0;
			case 1: return 10;
			case 2: return 100;
			case 3: return 200;
			case 4: return 1000;
			default: return 10000;
			}
		}
	}

	////////////////////////////////////
	StrNext* getStonesInDirection(int dx, int dy, int x, int y, StrNext* str, bool tr ) {
		
		int n = str->n; 
		int x1 = x + dx;
		int y1 = y + dy;
		if (x1 >= 0 && y1 >= 0 && x1 < N && y1 < N){
			
			if (str->pl == 0)
				str->pl = mas[y1][x1];

			if (str->pl == 0 || (str->pl != mas[y1][x1] && mas[y1][x1] != 0) || (mas[y1][x1] == 0 && !tr) || str->n >5)
				return str;
			if ((mas[y1][x1] == 0 && mas[y][x] == str->pl) ){
				//if (n != 0) {
					if (tr) str->n++;
					//if (mas[y][x] != 0) getStonesInDirection(dx,dy,x1,y1,str);
				//}
				return str;
			}
			str->n++;
			getStonesInDirection(dx,dy,x1,y1,str, tr);
			if (n == 0)
				getStonesInDirection(-dx,-dy,x , y ,str, false);
		}

		return str;
	}
	//////////////////////////////
	Move* calcMoves(){
		
		StrNext* next = new StrNext;
		int maxCost = -9999999;
		int curCost = 0;
		curMove = firstMove->nextLink;
		bestMove = curMove;
		while (curMove != firstMove) {
			curCost = 0;
			for (int d = 0; d < 8; d++) {
				next->pl = 0;
				next->n = 0;
				next = getStonesInDirection(dir[d].x,dir[d].y,curMove->x, curMove->y,next, true);
				curCost += getCostDirect(player, next->pl, next->n);
				curMove->cost = curCost;
				// if ((curCost > 10000 ) &&  numOfMoves < 90) {
				// 	Move* nMove = nextMove(curMove, recurN, player);
				// 	curCost += nMove->cost/128;
				// }
			}

			curCost += (N - ABS(curMove->x - 5) - ABS(curMove->y - 5));
			curMove->cost = curCost;
				
			if (curMove->cost > maxCost) {
				maxCost = curMove->cost;
				bestMove = curMove;
			}
			curMove = curMove->nextLink;
		}
		return bestMove;
	}

	////////////////////////////////////////////////

	Move* getBestMove(){
		
		return bestMove;
	}

	//////////////////////////////////////////
	Move* nextMove( int recur, int player){
		

		calcMoves();



		return bestMove;
	}
	//////////////////////////////////////////
	Move* nextMove(Move* move, int recur, int player){
		if (recur > 1  || numOfMoves == 1) return move;
		Field* newField = new Field(*this, 3 - player, move, recur+1);

		newField->calcMoves();

		return newField->bestMove;
	}
};

/////////////////////////////////////////////////////

class Stones {
	int x,y;
	int player;
	int numberOfDirection[4];

public: Stones(int y, int x, int p) {
			this->x = x;
			this->y = y;
			this->player = p;
		}
		void calcNumberToDirection(){
		
		}
};


///////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	starttime = clock();

	int player;
	int** mas;
	mas = new int*[N];
	for (int y = 0; y < N ; y++) {
		mas[y] = new int[N];
		for (int x = 0; x < N ; x++) 
			cin >> mas[y][x];
	}
	cin >> player;
	Field* field = new Field(mas, player);
	Move * move = field->nextMove(0, player);

	cout << move->y << " " << move->x <<endl;
	return 0;
}
