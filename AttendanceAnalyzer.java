import java.util.Scanner;

public class AttendanceAnalyzer {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("====================================");
        System.out.println("     STUDENT ATTENDANCE ANALYZER");
        System.out.println("====================================");

        System.out.print("Enter student name: ");
        String name = sc.nextLine();

        System.out.print("Enter total working days: ");
        int totalDays = sc.nextInt();

        System.out.print("Enter days attended: ");
        int attendedDays = sc.nextInt();

        if (totalDays <= 0 || attendedDays < 0 || attendedDays > totalDays) {
            System.out.println("Invalid attendance data!");
            sc.close();
            return;
        }

        double percentage = (attendedDays * 100.0) / totalDays;

        System.out.println("\n----------- ATTENDANCE REPORT -----------");
        System.out.println("Student Name : " + name);
        System.out.println("Total Days   : " + totalDays);
        System.out.println("Present Days : " + attendedDays);
        System.out.printf("Attendance   : %.2f%%\n", percentage);

        if (percentage >= 75) {
            System.out.println("Status       : Eligible ✅");
        } else {
            System.out.println("Status       : Not Eligible ❌");
        }

        sc.close();
    }
}
