
#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>

#define N 5
#define num(x) (((x & 1) && 1) + ((x & 2) && 2) + ((x & 4) && 4) + ((x & 8) && 8))

using namespace std;


int mas[N][N];

//int read(bool zero) {
//	
//
//	numAllMoves = 0;
//	num01 = 0;
//	for (int y = 0; y < N; y++)
//		for (int x = 0; x < N; x++) {
//			
//			cin >> mas[y][x];
//			sells[y][x].x = x;
//			sells[y][x].y = y;
//			sells[y][x].state = mas[y][x];
//			sells[y][x].numTurns = num(mas[y][x]);
//
//			if (sells[y][x].numTurns < 2) num01++;
//			
//			setMoves(sells[y][x]);
//
//		}
//		int pl;
//		cin >> pl;
//
//		calculate();
//		return pl;
//		
//}
//
void outStep(ofstream os) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			os << mas[y][x];
		}
		os << endl;
	}
	os << 1;
}

void initField() {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) mas[y][x] = 0;
}

int main(int argc, char* argv[])
{
	
	//char tmp_tmpfn[L_tmpnam];
	//	if(!std::tmpnam(tmp_tmpfn))
	//	{
	//		//throw whatever;
	//	}

	//	std::string tmpfn = tmp_tmpfn;
	
	int step = N*N;

	initField();

	ifstream fin;
	ofstream fout, field;
	
	
	outStep(field);

	fout << std::system("DotsandBox.exe") << field;

		//std::ifstream output(tmpfn.c_str());

	//int player = 0; 

	//player = read(false);

	//put(nextMove());



	return 0;
}