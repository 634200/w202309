import java.util.Scanner;
import java.util.StringJoiner;

public class Main22 {
    public static void main(String[] args) {
        int[] arr = { 153, 370, 371, 407 };
        Scanner sc = new Scanner(System.in);
        String nextLine = null;
        while ((nextLine = sc.nextLine()) != null) {
            String[] splited = nextLine.split(" ");
            int m = Integer.parseInt(splited[0]);
            int n = Integer.parseInt(splited[1]);
            if (n < 153 || m > 407) {
                System.out.println("no");
                continue;
            }
            StringJoiner sj = new StringJoiner(" ");
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] >= m && arr[i] <= n) {
                    sj.add(String.valueOf(arr[i]));
                }
            }
            if (sj.length() > 0) {
                System.out.println(sj.toString());
            } else {
                System.out.println("no");
            }
        }
        sc.close();
    }
}
