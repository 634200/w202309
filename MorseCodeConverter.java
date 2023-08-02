import java.util.HashMap;
import java.util.Map;

public class MorseCodeConverter {
    private static final Map<String, String> MORSE_CODE_MAP = new HashMap<>();

    static {
        MORSE_CODE_MAP.put("A", ".-");
        MORSE_CODE_MAP.put("B", "-...");
        MORSE_CODE_MAP.put("C", "-.-.");
        MORSE_CODE_MAP.put("D", "-..");
        MORSE_CODE_MAP.put("E", ".");
        MORSE_CODE_MAP.put("F", "..-.");
        MORSE_CODE_MAP.put("G", "--.");
        MORSE_CODE_MAP.put("H", "....");
        MORSE_CODE_MAP.put("I", "..");
        MORSE_CODE_MAP.put("J", ".---");
        MORSE_CODE_MAP.put("K", "-.-");
        MORSE_CODE_MAP.put("L", ".-..");
        MORSE_CODE_MAP.put("M", "--");
        MORSE_CODE_MAP.put("N", "-.");
        MORSE_CODE_MAP.put("O", "---");
        MORSE_CODE_MAP.put("P", ".--.");
        MORSE_CODE_MAP.put("Q", "--.-");
        MORSE_CODE_MAP.put("R", ".-.");
        MORSE_CODE_MAP.put("S", "...");
        MORSE_CODE_MAP.put("T", "-");
        MORSE_CODE_MAP.put("U", "..-");
        MORSE_CODE_MAP.put("V", "...-");
        MORSE_CODE_MAP.put("W", ".--");
        MORSE_CODE_MAP.put("X", "-..-");
        MORSE_CODE_MAP.put("Y", "-.--");
        MORSE_CODE_MAP.put("Z", "--..");
        MORSE_CODE_MAP.put("0", "-----");
        MORSE_CODE_MAP.put("1", ".----");
        MORSE_CODE_MAP.put("2", "..---");
        MORSE_CODE_MAP.put("3", "...--");
        MORSE_CODE_MAP.put("4", "....-");
        MORSE_CODE_MAP.put("5", ".....");
        MORSE_CODE_MAP.put("6", "-....");
        MORSE_CODE_MAP.put("7", "--...");
        MORSE_CODE_MAP.put("8", "---..");
        MORSE_CODE_MAP.put("9", "----.");
        MORSE_CODE_MAP.put(".", ".-.-.-");
        MORSE_CODE_MAP.put(",", "--..--");
        MORSE_CODE_MAP.put("?", "..--..");
        MORSE_CODE_MAP.put("!", "-.-.--");
        MORSE_CODE_MAP.put("/", "-..-.");
        MORSE_CODE_MAP.put("-", "-....-");
        MORSE_CODE_MAP.put("(", "-.--.");
        MORSE_CODE_MAP.put(")", "-.--.-");
        MORSE_CODE_MAP.put("&", ".-...");
        MORSE_CODE_MAP.put(":", "---...");
        MORSE_CODE_MAP.put(";", "-.-.-.");
        MORSE_CODE_MAP.put("=", "-...-");
        MORSE_CODE_MAP.put("+", ".-.-.");
        MORSE_CODE_MAP.put("_", "..--.-");
        MORSE_CODE_MAP.put("\"", ".-..-.");
        MORSE_CODE_MAP.put("$", "...-..-");
        MORSE_CODE_MAP.put("@", ".--.-.");
    }

    public static String toMorseCode(String text) {
        StringBuilder morseCode = new StringBuilder();
        for (char c : text.toUpperCase().toCharArray()) {
            String code = MORSE_CODE_MAP.get(String.valueOf(c));
            if (code != null) {
                morseCode.append(code).append(" ");
            }
        }
        return morseCode.toString().trim();
    }

    public static String toPlainText(String morseCode) {
        StringBuilder plainText = new StringBuilder();
        String[] words = morseCode.split(" / ");
        for (String word : words) {
            String[] letters = word.split(" ");
            for (String letter : letters) {
                String text = getKeyByValue(MORSE_CODE_MAP, letter);
                if (text != null) {
                    plainText.append(text);
                }
            }
            plainText.append(" ");
        }
        return plainText.toString().trim();
    }

    private static String getKeyByValue(Map<String, String> map, String value) {
        for (Map.Entry<String, String> entry : map.entrySet()) {
            if (entry.getValue().equals(value)) {
                return entry.getKey();
            }
        }
        return null;
    }
}
