import java.util.ArrayList;
import java.util.Scanner;

class Certificate {
    int id;
    String studentName;
    String course;
    String status;

    Certificate(int id, String studentName, String course) {
        this.id = id;
        this.studentName = studentName;
        this.course = course;
        this.status = "Pending";
    }
}

public class DigitalCertificateVerifier {

    static Scanner sc = new Scanner(System.in);
    static ArrayList<Certificate> certificates = new ArrayList<>();
    static int nextId = 1001;

    static void addCertificate() {
        System.out.print("Enter student name: ");
        String name = sc.nextLine();

        System.out.print("Enter course name: ");
        String course = sc.nextLine();

        certificates.add(new Certificate(nextId++, name, course));
        System.out.println("Certificate added successfully!");
    }

    static void displayCertificates() {
        if (certificates.isEmpty()) {
            System.out.println("No certificate records available.");
            return;
        }

        for (Certificate c : certificates) {
            System.out.println("\nCertificate ID: " + c.id);
            System.out.println("Student: " + c.studentName);
            System.out.println("Course: " + c.course);
            System.out.println("Status: " + c.status);
        }
    }

    static void verifyCertificate() {
        System.out.print("Enter Certificate ID: ");

        try {
            int id = Integer.parseInt(sc.nextLine());
            boolean found = false;

            for (Certificate c : certificates) {
                if (c.id == id) {
                    found = true;

                    System.out.println("\nCertificate Details:");
                    System.out.println("Student: " + c.studentName);
                    System.out.println("Course: " + c.course);
                    System.out.println("Status: " + c.status);

                    System.out.print("Mark as Verified? (yes/no): ");
                    String answer = sc.nextLine();

                    if (answer.equalsIgnoreCase("yes")) {
                        c.status = "Verified";
                        System.out.println("Certificate verified successfully!");
                    } else {
                        System.out.println("Verification cancelled.");
                    }
                    break;
                }
            }

            if (!found) {
                System.out.println("Certificate ID not found.");
            }

        } catch (NumberFormatException e) {
            System.out.println("Invalid ID. Please enter a number.");
        }
    }

    static void searchCertificate() {
        System.out.print("Enter student name: ");
        String name = sc.nextLine();

        boolean found = false;

        for (Certificate c : certificates) {
            if (c.studentName.toLowerCase().contains(name.toLowerCase())) {
                System.out.println("\nID: " + c.id);
                System.out.println("Student: " + c.studentName);
                System.out.println("Course: " + c.course);
                System.out.println("Status: " + c.status);
                found = true;
            }
        }

        if (!found) {
            System.out.println("No matching certificate found.");
        }
    }

    public static void main(String[] args) {

        while (true) {
            System.out.println("\n===== Certificate Verification System =====");
            System.out.println("1. Add Certificate");
            System.out.println("2. Display Certificates");
            System.out.println("3. Verify Certificate");
            System.out.println("4. Search Certificate");
            System.out.println("5. Exit");

            System.out.print("Enter choice: ");
            String choice = sc.nextLine();

            switch (choice) {
                case "1":
                    addCertificate();
                    break;
                case "2":
                    displayCertificates();
                    break;
                case "3":
                    verifyCertificate();
                    break;
                case "4":
                    searchCertificate();
                    break;
                case "5":
                    System.out.println("System closed.");
                    return;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
