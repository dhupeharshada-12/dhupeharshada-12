import java.util.Scanner;

public class StudentGradeCalculator {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("=================================");
        System.out.println("      STUDENT GRADE CALCULATOR");
        System.out.println("=================================");

        System.out.print("Enter student name: ");
        String name = sc.nextLine();

        System.out.print("Enter marks for English: ");
        double english = sc.nextDouble();

        System.out.print("Enter marks for Mathematics: ");
        double maths = sc.nextDouble();

        System.out.print("Enter marks for Science: ");
        double science = sc.nextDouble();

        System.out.print("Enter marks for Computer: ");
        double computer = sc.nextDouble();

        System.out.print("Enter marks for Hindi: ");
        double hindi = sc.nextDouble();

        double total = english + maths + science + computer + hindi;
        double percentage = total / 5;

        String grade;

        if (percentage >= 90) {
            grade = "A+";
        } else if (percentage >= 80) {
            grade = "A";
        } else if (percentage >= 70) {
            grade = "B";
        } else if (percentage >= 60) {
            grade = "C";
        } else if (percentage >= 50) {
            grade = "D";
        } else {
            grade = "F";
        }

        System.out.println("\n=================================");
        System.out.println("          RESULT");
        System.out.println("=================================");
        System.out.println("Student Name : " + name);
        System.out.println("Total Marks  : " + total + " / 500");
        System.out.printf("Percentage   : %.2f%%\n", percentage);
        System.out.println("Grade        : " + grade);

        if (percentage >= 40) {
            System.out.println("Result       : PASS 🎉");
        } else {
            System.out.println("Result       : FAIL");
        }

        System.out.println("=================================");

        sc.close();
    }
}
