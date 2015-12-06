// FizzBuzz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
//#include <sstream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	
	if (argc < 2) return 0;
	int X,Y, dX, dY, tt;

    ifstream stream(argv[1],ios::in);
	while (!stream.eof()) {
    
        stream >> X >> Y >> tt ;
		dX = X;
		dY = Y;
        for (int j = 1; j <= tt ; j++){

            //dX = ((int) j/X) * X - j;
            //dY = ((int) j/Y) * Y - j;
            bool f = true;
            if (dX == j) {
                cout << 'F';
				f = false;
				dX += X;
			}
            if (dY == j) {
				cout << 'B';
				f = false;
				dY += Y;
			}
            if (f) cout << j ;
			cout << ' ';

        }
		cout << endl;
    }
	//stream.close();
    return 0;
}

