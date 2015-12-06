// Sonya and string shifts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <sstream>

using namespace std;


char* S;
char* S2;
int smallestPos;
int N;
int* resMas;

//int getSmallest(int circ) {
//	if (circ > smallestPos) return smallestPos;
//	return circ;
//}

//void getSmallestPos(int NN) {
//
//	
//	int smallest = 0;
//	//int sm = 0;
//	for (int i = 1 ; i <= NN; i++){
//		for (int j = 0; j < N ; j++) { 
//			if (S2[smallest+j] > S2[i+j]) {
//				smallest = i;
//				//sm = i - 1;
//				break;}
//			else if (S2[smallest+j] < S2[i+j])
//				break;
//		}
//		resMas[i] = smallest;
//	}
//	return ;
//}
int main(int argc, char* argv[])
{
	int Q, circ;
	stringstream res;

	cin >> N;
	
	//S = new char[N+N];
	S2 = new char[N+N];
	resMas = new int [N];

	cin >> S2;

	//for (int i = 0; i < N; i++) {
	//	S2[i] = S2[i];}
	for (int i = 0; i < N; i++) {
		S2[N+i] = S2[i];}

	cin >> Q;

	int smallest = 0;
	for (int i = 1 ; i <= N - 1; i++){
		for (int j = 0; j < N ; j++) { 
			if (S2[smallest+j] > S2[i+j]) {
				smallest = i;
				break;}
			else if (S2[smallest+j] < S2[i+j])
				break;
		}
		resMas[i] = smallest;
	}
	

	for (int i = 0; i < Q; i++) {
		cin >> circ;
		smallest = (circ > resMas[circ]) ? resMas[circ]: circ;
		res << smallest<<endl;
	}
	cout << res.str();
	return 0;
}

