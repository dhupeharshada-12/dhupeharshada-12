import java.util.Scanner;

public class DailyHabitTracker {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String[] habits = {
            "Study",
            "Exercise",
            "Reading",
            "Coding",
            "Drink Water"
        };

        boolean[] completed = new boolean[habits.length];

        System.out.println("===== DAILY HABIT TRACKER =====");

        for (int i = 0; i < habits.length; i++) {
            System.out.print(
                "\nDid you complete " + habits[i] + "? (yes/no): "
            );

            String answer = sc.nextLine();

            if (answer.equalsIgnoreCase("yes")) {
                completed[i] = true;
            }
        }

        int completedCount = 0;

        System.out.println("\n========== TODAY'S REPORT ==========");

        for (int i = 0; i < habits.length; i++) {

            if (completed[i]) {
                System.out.println("✅ " + habits[i] + " - Completed");
                completedCount++;
            } else {
                System.out.println("❌ " + habits[i] + " - Not Completed");
            }
        }

        double percentage =
            (completedCount * 100.0) / habits.length;

        System.out.println("\nCompleted Habits : "
                           + completedCount + "/" + habits.length);

        System.out.printf(
            "Daily Progress   : %.2f%%%n",
            percentage
        );

        sc.close();
    }
}
