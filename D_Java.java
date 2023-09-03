import java.util.Scanner;

public class D_Java {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // 吃了 N 盘地三鲜
        int M = sc.nextInt(); // 盘子的颜色数目

        // dishes[i]表示第 i 盘地三鲜的颜色
        String[] dishes = new String[N];
        for (int i = 0; i < N; i++) {
            dishes[i] = sc.next();

        }
        // pricesColor
        String[] pricesColor = new String[M];
        for (int i = 0; i < M; i++) {
            pricesColor[i] = sc.next();
        }
        // prices
        int[] prices = new int[M + 1];
        for (int i = 0; i < M + 1; i++) {
            prices[i] = sc.nextInt();
        }
        sc.close();

        // 遍历dishes，计算总价格
        int total = 0;
        for (int i = 0; i < N; i++) {
            String dish = dishes[i];
            // 遍历pricesColor，找到dish对应的价格
            int price = 0;
            for (int j = 0; j < M; j++) {
                String priceColor = pricesColor[j];
                if (dish.equals(priceColor)) {
                    price = prices[j + 1];
                    break;
                }
            }
            // 没找到
            if (price == 0) {
                price = prices[0];
            }
            total += price;
        }
        System.out.println(total);

    }
}
