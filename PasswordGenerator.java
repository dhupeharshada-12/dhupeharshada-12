import java.util.Random;
import java.util.Scanner;

public class PasswordGenerator {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Random random = new Random();

        String characters =
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ" +
                "abcdefghijklmnopqrstuvwxyz" +
                "0123456789" +
                "!@#$%^&*";

        System.out.println("===== PASSWORD GENERATOR =====");

        System.out.print("Enter password length: ");
        int length = sc.nextInt();

        if (length <= 0) {
            System.out.println("Invalid length!");
        } else {

            StringBuilder password = new StringBuilder();

            for (int i = 0; i < length; i++) {
                int index = random.nextInt(characters.length());
                password.append(characters.charAt(index));
            }

            System.out.println("\nGenerated Password:");
            System.out.println(password);
        }

        sc.close();
    }
}
