import java.util.ArrayList;
import java.util.Scanner;

class Student {
    int studentId;
    String name;
    double percentage;
    double annualIncome;
    String scholarshipStatus;

    Student(int studentId, String name, double percentage,
            double annualIncome) {
        this.studentId = studentId;
        this.name = name;
        this.percentage = percentage;
        this.annualIncome = annualIncome;
        this.scholarshipStatus = "Not Evaluated";
    }
}

public class ScholarshipEligibilityManager {

    static Scanner sc = new Scanner(System.in);
    static ArrayList<Student> students = new ArrayList<>();

    static void addStudent() {
        System.out.print("\nEnter Student ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        for (Student s : students) {
            if (s.studentId == id) {
                System.out.println("Student ID already exists!");
                return;
            }
        }

        System.out.print("Enter Student Name: ");
        String name = sc.nextLine().trim();

        if (name.isEmpty()) {
            System.out.println("Name cannot be empty!");
            return;
        }

        System.out.print("Enter Percentage: ");
        double percentage = sc.nextDouble();

        System.out.print("Enter Annual Family Income: ");
        double income = sc.nextDouble();

        if (percentage < 0 || percentage > 100 || income < 0) {
            System.out.println("Invalid academic or income details!");
            return;
        }

        students.add(new Student(id, name, percentage, income));

        System.out.println("\nStudent registered successfully!");
    }

    static void checkEligibility() {
        System.out.print("\nEnter Student ID: ");
        int id = sc.nextInt();

        for (Student s : students) {
            if (s.studentId == id) {

                if (s.percentage >= 75 && s.annualIncome <= 250000) {
                    s.scholarshipStatus = "Eligible";
                } else {
                    s.scholarshipStatus = "Not Eligible";
                }

                System.out.println("\nScholarship Result");
                System.out.println("Student: " + s.name);
                System.out.println("Percentage: " + s.percentage);
                System.out.println("Annual Income: " + s.annualIncome);
                System.out.println("Status: " + s.scholarshipStatus);

                System.out.println("\nNote: This is a sample eligibility rule.");
                return;
            }
        }

        System.out.println("Student not found!");
    }

    static void displayStudents() {
        if (students.isEmpty()) {
            System.out.println("\nNo student records available.");
            return;
        }

        System.out.println("\n====== STUDENT RECORDS ======");

        for (Student s : students) {
            System.out.println("\nID: " + s.studentId);
            System.out.println("Name: " + s.name);
            System.out.println("Percentage: " + s.percentage);
            System.out.println("Annual Income: " + s.annualIncome);
            System.out.println("Scholarship Status: " + s.scholarshipStatus);
        }
    }

    static void searchStudent() {
        System.out.print("\nEnter Student ID to search: ");
        int id = sc.nextInt();

        for (Student s : students) {
            if (s.studentId == id) {
                System.out.println("\nStudent Found!");
                System.out.println("Name: " + s.name);
                System.out.println("Percentage: " + s.percentage);
                System.out.println("Status: " + s.scholarshipStatus);
                return;
            }
        }

        System.out.println("Student not found!");
    }

    static void showSummary() {
        int eligible = 0;
        int notEligible = 0;
        int notEvaluated = 0;

        for (Student s : students) {
            if (s.scholarshipStatus.equals("Eligible")) {
                eligible++;
            } else if (s.scholarshipStatus.equals("Not Eligible")) {
                notEligible++;
            } else {
                notEvaluated++;
            }
        }

        System.out.println("\n====== SCHOLARSHIP SUMMARY ======");
        System.out.println("Total Students: " + students.size());
        System.out.println("Eligible: " + eligible);
        System.out.println("Not Eligible: " + notEligible);
        System.out.println("Not Evaluated: " + notEvaluated);
    }

    public static void main(String[] args) {

        while (true) {
            System.out.println("\n===== SCHOLARSHIP ELIGIBILITY MANAGER =====");
            System.out.println("1. Register Student");
            System.out.println("2. Check Scholarship Eligibility");
            System.out.println("3. Display All Students");
            System.out.println("4. Search Student");
            System.out.println("5. View Scholarship Summary");
            System.out.println("6. Exit");

            System.out.print("\nEnter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addStudent();
                    break;

                case 2:
                    checkEligibility();
                    break;

                case 3:
                    displayStudents();
                    break;

                case 4:
                    searchStudent();
                    break;

                case 5:
                    showSummary();
                    break;

                case 6:
                    System.out.println("Thank you for using Scholarship Manager!");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice! Try again.");
            }
        }
    }
}
