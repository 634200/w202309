public class TestMin {
    public static void main(String[] args) {
        int min = Integer.MIN_VALUE; // -2147483648
        System.out.println(min); // -2147483648
        System.out.println(1 - min); // 2147483649 ? -2147483647
    }

}
