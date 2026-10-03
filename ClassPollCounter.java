import java.util.Scanner;

public class ClassPollCounter {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String[] options = {
            "Sports Day",
            "Coding Competition",
            "Quiz Competition",
            "Cultural Event"
        };

        int[] votes = new int[4];

        System.out.println("===== CLASS POLL COUNTER =====");

        System.out.print("Enter number of students: ");
        int students = sc.nextInt();

        for (int i = 0; i < students; i++) {

            System.out.println("\nStudent " + (i + 1));
            
            for (int j = 0; j < options.length; j++) {
                System.out.println((j + 1) + ". " + options[j]);
            }

            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            if (choice >= 1 && choice <= options.length) {
                votes[choice - 1]++;
                System.out.println("Vote recorded!");
            } else {
                System.out.println("Invalid choice. Vote not recorded.");
            }
        }

        System.out.println("\n===== POLL RESULTS =====");

        for (int i = 0; i < options.length; i++) {
            System.out.println(options[i] + " : " + votes[i] + " votes");
        }

        sc.close();
    }
}
