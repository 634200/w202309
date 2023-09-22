import java.util.Scanner;

public class Main1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String nextLine = null;
        while ((nextLine = sc.nextLine()) != null) {
            String[] splited = nextLine.split(" ");
            double n = Integer.parseInt(splited[0]);
            int m = Integer.parseInt(splited[1]);
            double res = 0;
            for (int i = 0; i < m; i++) {
                res += n;
                n = Math.sqrt(n);
            }
            System.out.println(String.format("%.2f", res));
        }

        sc.close();
    }
}
