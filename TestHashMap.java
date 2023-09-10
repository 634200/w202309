import java.util.HashMap;

public class TestHashMap {
    public static void main(String[] args) {
        HashMap<Integer, Boolean> map = new HashMap<>();
        map.put(1, null);
        System.out.println(map.containsKey(1));
    }
}
