import java.util.Scanner;

public class PasswordStrengthChecker {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("===== PASSWORD STRENGTH CHECKER =====");

        System.out.print("Enter Password: ");
        String password = sc.nextLine();

        int score = 0;

        if (password.length() >= 8) {
            score++;
        }

        if (password.matches(".*[A-Z].*")) {
            score++;
        }

        if (password.matches(".*[a-z].*")) {
            score++;
        }

        if (password.matches(".*[0-9].*")) {
            score++;
        }

        if (password.matches(".*[^a-zA-Z0-9].*")) {
            score++;
        }

        System.out.println("\n===== RESULT =====");

        if (score <= 2) {
            System.out.println("Password Strength: Weak");
        } 
        else if (score <= 4) {
            System.out.println("Password Strength: Medium");
        } 
        else {
            System.out.println("Password Strength: Strong");
        }

        System.out.println("Strength Score: " + score + "/5");

        sc.close();
    }
}
