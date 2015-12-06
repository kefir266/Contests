import java.util.Scanner;

/**
 * Created by dmitrij on 23.11.2015.
 */
public class Target {

    private int[] aCirc;
    private int K;

    Target(int K){
        this.K = K;
        aCirc = new int[K];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int K = scanner.nextInt();
        int N = scanner.nextInt();

        Target target = new Target(K);


        for(int i = 0; i < K; i++){
            target.aCirc[i] = scanner.nextInt();
        }


        long score = 0;

        for (int i = 0; i < N ; i++) {
            score += (long) target.getScore(scanner.nextInt(),scanner.nextInt());
        }

        System.out.println(score);
    }


    public int getScore(int x, int y){
        double dx = (double) x;
        double dy = (double) y;
        double radius = Math.sqrt((double) (dx * dx + dy * dy));
        int iradius = (int) radius;
        if ((double) iradius != radius) iradius++;
        int pos = find(iradius);
        return pos;

    }

    private int find(int r){
        int lo =0;
        int hi = K - 1;
        int mid = (hi + lo)/2;
        if (r <= aCirc[hi]) return hi + 1;
        if (r == aCirc[lo]) return lo + 1;
        if (r > aCirc[lo]) return 0;
        do{
            if (r < aCirc[mid]){
                lo = mid ;
                mid = (lo + hi) / 2;

            }
            else if (r > aCirc[mid]){
                hi = mid ;
                mid =(lo + hi) / 2;

            }

            else break;

            if ((hi - lo) == 1) if (r == aCirc[hi]) return hi + 1;
            else return lo + 1;
        } while (hi > lo );

        return mid + 1;
    }


}