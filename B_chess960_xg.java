import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class B_chess960_xg {

    private static boolean test(String s) {

        int b1 = -1, b2 = -1, k = -1, r1 = -1, r2 = -1;
        char h[] = s.toCharArray();
        for (int i = 0; i < h.length; i++) {

            if (h[i] == 'B' && b1 == -1)
                b1 = i;
            else if (h[i] == 'B')
                b2 = i;

            if (h[i] == 'K')
                k = i;

            if (h[i] == 'R' && r1 == -1)
                r1 = i;
            else if (h[i] == 'R')
                r2 = i;
        }

        return (k > r1 && k < r2 && (b1 + b2) % 2 == 1);
    }

    private static boolean getRes(String S) {
        int K, x, i, j;
        K = 0;
        int[] R = new int[2];
        int[] B = new int[2];
        i = j = x = 0;
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
        // if ((R[0] < K && K < R[1]) && (B[0] + B[1]) % 2 == 1)
        // System.out.println("Yes");
        // else
        // System.out.println("NO");
        return (R[0] < K && K < R[1]) && (B[0] + B[1]) % 2 == 1;
    }

    // RNBQKBNR 随机返回排列
    private static String getStr() {
        String str = "RNBQKBNR";
        List<String> list = Arrays.asList(str.split(""));
        Collections.shuffle(list);
        return String.join("", list);
    }

    public static void main(String[] args) {
        // Scanner input = new Scanner(System.in);
        // String S = input.next();
        // System.out.println(S);
        // input.close();

        for (int i = 0; i < 1000000; i++) {
            String S = getStr();
            if (test(S) != getRes(S))
                System.err.println("！！！");
        }

    }
}