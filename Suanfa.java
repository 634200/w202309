import java.util.Scanner;

public class Suanfa {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int K, x, i, j;
        K = 0;
        int[] R = new int[2];
        int[] B = new int[2];
        i = j = x = 0;
        String S = input.next();
        while (x < 8) {
            char a = S.charAt(x);
            if (a == 'K')
                K = x + 1;
            if (a == 'R') {
                R[i] = x + 1;
                i = i + 1;
            }
            if (a == 'B') {
                B[j] = x + 1;
                j = j + 1;
            }
            x = x + 1;
        }
        if ((R[0] < K && K < R[1]) && (B[0] + B[1]) % 2 == 1)
            System.out.println("Yes");
        else
            // System.out.println("NO");
            System.out.println("No");
    }
}