import java.util.Scanner;

/**
 * Created by dmitrij on 23.11.2015.
 */
public class TargetMergeSort {

    private int[] aCirc;
    private int K;

    TargetMergeSort(int K){
        this.K = K;
        aCirc = new int[K];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int K = scanner.nextInt();
        int N = scanner.nextInt();

        TargetMergeSort target = new TargetMergeSort(K);


        for(int i = 0; i <= K; i++){
            target.aCirc[i] = scanner.nextInt();
        }

        target.sort();
        int score = 0;

        for (int i = 0; i <= N; i++) {
            score += target.getScore(scanner.nextInt(),scanner.nextInt());
        }

        System.out.println(score);
    }

    public void sort(){
        int[] b = new int[K];
        sort(aCirc, b, 0, K);

    }

    private void sort(int[] a , int[] b, int lo, int hi){

        if (hi <= lo) return;
        int mid = lo + (hi - lo) / 2;
        sort(a, b, lo, mid);
        sort(a, b, mid + 1, hi);
        merge(a, b, lo, mid, hi);
    }

    private void merge(int[] a , int[] b, int lo, int mid, int hi){

        for (int k = lo; k <= hi; k++) {
            b[k] = a[k];
        }


        int i = lo, j = mid+1;
        for (int k = lo; k <= hi; k++) {
            if      (i > mid)              a[k] = b[j++];
            else if (j > hi)               a[k] = b[i++];
            else if ((b[j] > b[i])) a[k] = b[j++];
            else                           a[k] = b[i++];
        }
    }
    public int getScore(int x, int y){

        return 0;

    }
}
