import java.util.Scanner;

public class StudentGradeAnalyzer {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("===== STUDENT GRADE ANALYZER =====");

        System.out.print("Enter Student Name: ");
        String name = sc.nextLine();

        System.out.print("Enter marks for Subject 1: ");
        double m1 = sc.nextDouble();

        System.out.print("Enter marks for Subject 2: ");
        double m2 = sc.nextDouble();

        System.out.print("Enter marks for Subject 3: ");
        double m3 = sc.nextDouble();

        System.out.print("Enter marks for Subject 4: ");
        double m4 = sc.nextDouble();

        System.out.print("Enter marks for Subject 5: ");
        double m5 = sc.nextDouble();

        double total = m1 + m2 + m3 + m4 + m5;
        double percentage = total / 5;

        char grade;

        if (percentage >= 90)
            grade = 'A';
        else if (percentage >= 80)
            grade = 'B';
        else if (percentage >= 70)
            grade = 'C';
        else if (percentage >= 60)
            grade = 'D';
        else if (percentage >= 40)
            grade = 'E';
        else
            grade = 'F';

        System.out.println("\n========== RESULT ==========");
        System.out.println("Student Name : " + name);
        System.out.println("Total Marks  : " + total + " / 500");
        System.out.printf("Percentage   : %.2f%%%n", percentage);
        System.out.println("Grade        : " + grade);

        if (grade == 'F')
            System.out.println("Result       : FAIL");
        else
            System.out.println("Result       : PASS");

        sc.close();
    }
}
