// VitalyAndNight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
	int N, M, a1, a2;
	int numberDontSlipe = 0;
	
	cin >> N >> M;
	for (int i = 0 ; i < N ; i++) {
		for (int j = 0; j < M ; j++) {
		cin >> a1 >> a2;
			numberDontSlipe += (a1+a2 == 0 ? 0: 1) ;
		}
	}
	cout <<numberDontSlipe;
	return 0;
}

