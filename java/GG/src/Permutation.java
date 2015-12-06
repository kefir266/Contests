/**
 * Created by dmitrij on 24.11.2015.
 */


import java.util.ArrayList;

import java.util.Scanner;


public class Permutation {

    private ArrayList<Integer> list;
    private int[] arr;
    private int N;
    private long counter;
    private int sumPos, sumNeg;

    Permutation(int N, String S) {
        this.N = N;
        list = new ArrayList<Integer>();
        for (Integer i = 0; i < N; i++){
            list.add(i);
        }
        arr = new int[N];
        sumPos = 1;
        sumNeg = -1;
        for (int i = 0; i < N - 1; i++){
            if (S.charAt(i) == 'G'){
                sumPos++;
                arr[i] = 1;}
            else {
                sumNeg--;
                arr[i] = -1;
            }
        }

    }
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        long M = scanner.nextLong();
        scanner.nextLine();
        String S = scanner.nextLine();



        Permutation permutation = new Permutation(N, S);

        long pn = permutation.calcNumPerm();
        int i =(int)  (Math.log10(pn) / Math.log10(M)) + 1;
//        int i = 0;
//        do {
//            i++;
//            pn = pn / M;
//        } while (pn != 0);


        System.out.println(i);
    }

    public long calcNumPerm(){
        counter = 0;
        for (int i = 0; i < N; i++){
            Integer cur = list.get(i);
            list.remove(i);
            permute(0, cur, arr[i], list, sumPos, sumNeg);
            list.add(i,cur);
        }
        return counter;
    }

    private void permute(int n, Integer prev, int sign, ArrayList<Integer> auxList, int pos, int neg){
        if ( n == N - 1) {
            counter++;
            return;
        }
        int sPos = pos;
        int sNeg = neg;

        for (int i = 0; i < auxList.size(); i++){
            Integer cur = auxList.get(i);
            if ((prev >  cur && sign == 1 && sPos > 0
                    || prev <  cur && sign == -1 && sNeg < 0) || n == 0) {
                auxList.remove(i);
                if (arr[n] < 0)
                    sNeg++;
                else
                    sPos--;
                permute(n + 1, cur, arr[n], auxList, sPos, sNeg);
                if (arr[n] < 0)
                    sNeg--;
                else
                    sPos++;
                auxList.add(i,cur);
            }


        }
    }
}
