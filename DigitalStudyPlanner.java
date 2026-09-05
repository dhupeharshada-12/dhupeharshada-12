import java.util.Scanner;

public class DigitalStudyPlanner {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("======================================");
        System.out.println("        📚 DIGITAL STUDY PLANNER");
        System.out.println("======================================");

        System.out.print("Enter your name: ");
        String name = sc.nextLine();

        System.out.print("How many subjects do you want to plan? ");
        int n = sc.nextInt();
        sc.nextLine();

        if (n <= 0) {
            System.out.println("Invalid number of subjects!");
            sc.close();
            return;
        }

        String[] subjects = new String[n];
        double[] hours = new double[n];

        double totalHours = 0;
        int highestIndex = 0;

        for (int i = 0; i < n; i++) {

            System.out.print("\nEnter subject " + (i + 1) + ": ");
            subjects[i] = sc.nextLine();

            System.out.print("Enter study hours for " + subjects[i] + ": ");
            hours[i] = sc.nextDouble();
            sc.nextLine();

            if (hours[i] < 0) {
                System.out.println("Hours cannot be negative.");
                hours[i] = 0;
            }

            totalHours += hours[i];

            if (hours[i] > hours[highestIndex]) {
                highestIndex = i;
            }
        }

        System.out.println("\n======================================");
        System.out.println("           📋 STUDY PLAN");
        System.out.println("======================================");

        System.out.println("Student: " + name);

        for (int i = 0; i < n; i++) {
            System.out.printf("%-20s : %.2f hours%n",
                    subjects[i], hours[i]);
        }

        System.out.println("--------------------------------------");
        System.out.printf("Total Study Hours    : %.2f hours%n", totalHours);
        System.out.println("Priority Subject     : " + subjects[highestIndex]);

        System.out.println("\n💡 Keep studying consistently. Good luck! 🚀");

        sc.close();
    }
}
