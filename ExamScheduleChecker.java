import java.time.LocalDate;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

class Exam {
    String subject;
    LocalDate date;
    String time;

    Exam(String subject, LocalDate date, String time) {
        this.subject = subject;
        this.date = date;
        this.time = time;
    }

    void display() {
        System.out.println(
            "Subject: " + subject +
            " | Date: " + date +
            " | Time: " + time
        );
    }
}

public class ExamScheduleChecker {

    static ArrayList<Exam> exams = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);

    static void addExam() {
        System.out.print("Enter subject name: ");
        String subject = sc.nextLine().trim();

        if (subject.isEmpty()) {
            System.out.println("Subject cannot be empty.");
            return;
        }

        try {
            System.out.print("Enter exam date (YYYY-MM-DD): ");
            LocalDate date = LocalDate.parse(sc.nextLine().trim());

            System.out.print("Enter exam time (e.g. 10:00 AM): ");
            String time = sc.nextLine().trim();

            if (time.isEmpty()) {
                System.out.println("Time cannot be empty.");
                return;
            }

            exams.add(new Exam(subject, date, time));
            System.out.println("Exam added successfully!");

            checkConflicts();

        } catch (DateTimeParseException e) {
            System.out.println("Invalid date! Use YYYY-MM-DD.");
        }
    }

    static void displayExams() {
        if (exams.isEmpty()) {
            System.out.println("No exams scheduled.");
            return;
        }

        exams.sort(Comparator.comparing(e -> e.date));

        System.out.println("\n===== EXAM SCHEDULE =====");

        for (Exam exam : exams) {
            exam.display();
        }
    }

    static void checkConflicts() {
        boolean conflictFound = false;

        for (int i = 0; i < exams.size(); i++) {
            for (int j = i + 1; j < exams.size(); j++) {
                if (exams.get(i).date.equals(exams.get(j).date)) {
                    if (!conflictFound) {
                        System.out.println("\n⚠️ Same-date exam warning:");
                    }

                    System.out.println(
                        exams.get(i).subject + " and " +
                        exams.get(j).subject + " are on " +
                        exams.get(i).date
                    );

                    conflictFound = true;
                }
            }
        }

        if (!conflictFound) {
            System.out.println("No same-date conflicts found.");
        }
    }

    static void searchExam() {
        System.out.print("Enter subject to search: ");
        String keyword = sc.nextLine().trim();

        boolean found = false;

        for (Exam exam : exams) {
            if (exam.subject.toLowerCase()
                    .contains(keyword.toLowerCase())) {
                exam.display();
                found = true;
            }
        }

        if (!found) {
            System.out.println("No matching subject found.");
        }
    }

    public static void main(String[] args) {
        while (true) {
            System.out.println("\n===== EXAM SCHEDULE CHECKER =====");
            System.out.println("1. Add Exam");
            System.out.println("2. Display Schedule");
            System.out.println("3. Check Same-Date Conflicts");
            System.out.println("4. Search Exam");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");

            String choice = sc.nextLine().trim();

            switch (choice) {
                case "1":
                    addExam();
                    break;

                case "2":
                    displayExams();
                    break;

                case "3":
                    checkConflicts();
                    break;

                case "4":
                    searchExam();
                    break;

                case "5":
                    System.out.println("Thank you for using the app!");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice. Try again.");
            }
        }
    }
}
