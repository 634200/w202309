import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringJoiner;

public class Main2 {
    public static void main(String[] args) {
        // 计算100-999之间的水仙花数
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i = 100; i < 1000; i++) {
            if (isNarcissisticNumber(i)) {
                list.add(i);
            }
        }
        int[] arr = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            arr[i] = list.get(i).intValue();
        }
        System.out.println(Arrays.toString(arr));
        // Arrays.sort(arr);

        Scanner sc = new Scanner(System.in);

        String nextLine = null;
        while ((nextLine = sc.nextLine()) != null) {
            String[] splited = nextLine.split(" ");
            int m = Integer.parseInt(splited[0]);
            int n = Integer.parseInt(splited[1]);
            int mI = -Arrays.binarySearch(arr, m) - 1;
            int nI = -Arrays.binarySearch(arr, n) - 1;
            if (nI - mI > 0) {
                StringJoiner sj = new StringJoiner(" ");
                for (int i = mI; i < nI; i++) {
                    sj.add(String.valueOf(arr[i]));
                }
                System.out.println(sj.toString());
            } else {
                System.out.println("no");
            }
        }
        sc.close();
    }

    private static boolean isNarcissisticNumber(int n) {
        int bai = n / 100;
        int shi = n / 10 % 10;
        int ge = n % 10;
        return n == bai * bai * bai + shi * shi * shi + ge * ge * ge;
    }

}
