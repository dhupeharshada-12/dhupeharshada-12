import java.util.Scanner;

public class TextAnalyzer {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("===== TEXT ANALYZER =====");

        System.out.print("Enter a sentence: ");
        String text = sc.nextLine();

        int characters = text.length();
        int words = 0;
        int vowels = 0;
        int digits = 0;

        if (!text.trim().isEmpty()) {
            words = text.trim().split("\\s+").length;
        }

        for (int i = 0; i < text.length(); i++) {

            char ch = Character.toLowerCase(text.charAt(i));

            if (ch == 'a' || ch == 'e' ||
                ch == 'i' || ch == 'o' ||
                ch == 'u') {
                vowels++;
            }

            if (Character.isDigit(ch)) {
                digits++;
            }
        }

        System.out.println("\n========== ANALYSIS ==========");
        System.out.println("Characters : " + characters);
        System.out.println("Words      : " + words);
        System.out.println("Vowels     : " + vowels);
        System.out.println("Digits     : " + digits);

        sc.close();
    }
}
