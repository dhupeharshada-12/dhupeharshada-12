import java.util.Random;
import java.util.Scanner;

public class NumberGuessingGame {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Random random = new Random();

        int secretNumber = random.nextInt(100) + 1;
        int attempts = 0;
        int guess;

        System.out.println("================================");
        System.out.println("       NUMBER GUESSING GAME");
        System.out.println("================================");
        System.out.println("Guess a number between 1 and 100.");

        do {
            System.out.print("\nEnter your guess: ");
            guess = sc.nextInt();
            attempts++;

            if (guess > secretNumber) {
                System.out.println("Too High! Try again.");
            } else if (guess < secretNumber) {
                System.out.println("Too Low! Try again.");
            } else {
                System.out.println("\n🎉 Correct Guess!");
                System.out.println("You found the number in "
                        + attempts + " attempts.");
            }

        } while (guess != secretNumber);

        System.out.println("================================");

        sc.close();
    }
}
