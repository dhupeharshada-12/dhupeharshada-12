import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.Scanner;

public class ExamCountdown {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("===== EXAM COUNTDOWN CALCULATOR =====");

        System.out.print("Enter exam name: ");
        String examName = sc.nextLine();

        System.out.print("Enter exam date (YYYY-MM-DD): ");
        String dateInput = sc.nextLine();

        LocalDate examDate = LocalDate.parse(dateInput);
        LocalDate today = LocalDate.now();

        long daysLeft = ChronoUnit.DAYS.between(today, examDate);

        System.out.println("\nExam: " + examName);
        System.out.println("Exam Date: " + examDate);

        if (daysLeft > 0) {
            System.out.println("Days remaining: " + daysLeft);
            System.out.println("Keep studying! 📚");
        } 
        else if (daysLeft == 0) {
            System.out.println("Your exam is TODAY! 📝");
        } 
        else {
            System.out.println("The exam date has already passed.");
        }

        sc.close();
    }
}
