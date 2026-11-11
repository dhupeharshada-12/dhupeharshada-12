import java.util.ArrayList;
import java.util.Scanner;

class Complaint {
    int id;
    String studentName;
    String category;
    String description;
    String status;

    Complaint(int id, String studentName, String category, String description) {
        this.id = id;
        this.studentName = studentName;
        this.category = category;
        this.description = description;
        this.status = "Pending";
    }

    void display() {
        System.out.println("\nComplaint ID: " + id);
        System.out.println("Student Name: " + studentName);
        System.out.println("Category: " + category);
        System.out.println("Description: " + description);
        System.out.println("Status: " + status);
    }
}

public class CampusComplaintManager {

    static ArrayList<Complaint> complaints = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);
    static int nextId = 1;

    static void submitComplaint() {
        System.out.print("Enter Student Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Complaint Category: ");
        String category = sc.nextLine();

        System.out.print("Enter Description: ");
        String description = sc.nextLine();

        Complaint c = new Complaint(
            nextId++, name, category, description
        );

        complaints.add(c);

        System.out.println("\nComplaint submitted successfully!");
        System.out.println("Your Complaint ID: " + c.id);
    }

    static void viewComplaints() {
        if (complaints.isEmpty()) {
            System.out.println("\nNo complaints found.");
            return;
        }

        for (Complaint c : complaints) {
            c.display();
        }
    }

    static void searchComplaint() {
        System.out.print("Enter Complaint ID: ");
        int id = Integer.parseInt(sc.nextLine());

        for (Complaint c : complaints) {
            if (c.id == id) {
                c.display();
                return;
            }
        }

        System.out.println("Complaint not found.");
    }

    static void updateStatus() {
        System.out.print("Enter Complaint ID: ");
        int id = Integer.parseInt(sc.nextLine());

        for (Complaint c : complaints) {
            if (c.id == id) {
                System.out.print("Enter new status: ");
                c.status = sc.nextLine();

                System.out.println("Status updated successfully!");
                return;
            }
        }

        System.out.println("Complaint not found.");
    }

    public static void main(String[] args) {

        while (true) {
            System.out.println("\n===== SMART CAMPUS COMPLAINT MANAGER =====");
            System.out.println("1. Submit Complaint");
            System.out.println("2. View All Complaints");
            System.out.println("3. Search Complaint");
            System.out.println("4. Update Complaint Status");
            System.out.println("5. Exit");

            System.out.print("Enter your choice: ");

            String input = sc.nextLine();

            try {
                int choice = Integer.parseInt(input);

                switch (choice) {
                    case 1:
                        submitComplaint();
                        break;

                    case 2:
                        viewComplaints();
                        break;

                    case 3:
                        searchComplaint();
                        break;

                    case 4:
                        updateStatus();
                        break;

                    case 5:
                        System.out.println("Thank you for using the system!");
                        sc.close();
                        return;

                    default:
                        System.out.println("Invalid choice!");
                }

            } catch (NumberFormatException e) {
                System.out.println("Please enter a valid number.");
            }
        }
    }
}
