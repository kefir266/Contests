// UGLY NUMBERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


int N;
int sumOfUgly;
int D[13];

void nextNum(int n, int multi, int sum) {

	if (n + 1 == N) {
		int nn = sum ;
		if (nn == 0 || (nn != 1 && ((((int) nn/2) * 2 == nn) || (((int) nn/3) * 3 == nn) || (((int) nn/5) * 5 == nn) || (((int) nn/7) * 7 == nn)))) {
			sumOfUgly++;
		}
		return;}
	if (n + 2 < N) {
		nextNum(n + 1, -1, sum + D[n+1] * multi);
		nextNum(n + 1, 1, sum + D[n+1] * multi);
	}
	nextNum(n + 1, multi * 10, sum + D[n+1] * multi);
	
	return;
}

int main(int argc, char* argv[])
{
	if (argc < 2) return 0;
	
	char strn[13];

    ifstream stream(argv[1],ios::in);
	
	while (!stream.eof()) {
		sumOfUgly = 0;
		stream>>strn;
		
		N = strlen(strn);
		for (int i = 0; i < N; i++) {
			D[N - i - 1] = (int) (strn[i] - 0x30);
		}
		if (N > 1) {
			nextNum(0,-1, D[0]);
			nextNum(0, 1, D[0]);
			nextNum(0, 10, D[0]);
		}
		else
			nextNum(0, 1, D[0]);
		
		
		cout << sumOfUgly <<  endl;

	}
	return 0;
}

