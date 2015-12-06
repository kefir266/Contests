package com.gorbatko;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws FileNotFoundException {

        int masI[] = new int[51];
        int N, i;

        Scanner scanner = new Scanner(new File(args[0]));
        while (scanner.hasNext()){
            String s = scanner.nextLine();
            N =0;
            int masN[] = new int[100];
            for(String ss : s.split(" "))
            {

                i = Integer.parseInt(ss);
                masI[N++] = i;
                masN[i]++;
            }
            for (i =0 ; i <= N; i++) {
                if (masN[masI[i]] == 0) continue;
                int di = ((int)(N-i)/masN[masI[i]]);
                int dl = di*masN[masI[i]] ;
                if (dl == (N - i) && di < (N - i) / 2){

                    boolean f = true;
                    for (int j = i; j < N-di; j++){
                        if (masI[j] != masI[j+di]){
                            f = false;
                            break;
                        }
                    }
                    if (f) {
                        for (int j = i; j<i + di ;j++)
                            System.out.print(masI[j]+ " ");
                        System.out.println();
                        break;
                    }
                }
                masN[masI[i]]--;
            }

        }
    }
}
