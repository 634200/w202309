import java.util.Scanner;

public class D_Default_Price_xg {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int i = 0, j, Total = 0, p = 0;
        int N = input.nextInt();
        int M = input.nextInt();
        int[] Price = new int[M + 1];
        String[] C = new String[N];
        String[] D = new String[M];
        while (i < N) {
            C[i] = input.next();
            i = i + 1;
        }
        i = 0;
        while (i < M) {
            D[i] = input.next();
            i = i + 1;
        }
        i = 0;
        // while (i < N) {
        while (i < M + 1) {

            Price[i] = input.nextInt();
            i = i + 1;
        }
        i = 0;
        while (i < N) {
            j = 0;
            while (j < M) {
                if (C[i].equals(D[j])) {
                    Total = Total + Price[j + 1];
                    break;
                }
                j = j + 1;
                if (j == M) {
                    Total = Total + Price[0];
                }
            }
            i = i + 1;
        }
        System.out.println(Total);
    }
}
