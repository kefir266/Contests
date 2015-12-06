#include <QCoreApplication>
//#include <math.h>
//#include <stdio.h>
//#include <stdint.h>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    int n, d3,d5, tt;
    string s;
    stringstream res;
    cin >> n;


    for (int i = 0; i < n; i++){

        //tt = cin.get();
        cin >> tt;
        //scanf("%d",&tt);

        for (int j = 1; j <= tt ; j++){

            d3 = ((int) j/3) * 3 - j;
            d5 = ((int) j/5) * 5 - j;
            s="";
            if (d3 == 0)
                s = "Fizz";
            if (d5 == 0)
                s.append("Buzz");
            if (s.length() != 0) res << s ;
                else res << j;
            res << endl;

        }
    }



    cout << res.str();



    cout << res.out;
    return a.exec();
}

