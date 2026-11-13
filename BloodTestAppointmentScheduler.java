import java.util.ArrayList;
import java.util.Scanner;

class Appointment {
    int appointmentId;
    String patientName;
    String testName;
    String appointmentDate;
    String status;

    Appointment(int id, String name, String test, String date) {
        appointmentId = id;
        patientName = name;
        testName = test;
        appointmentDate = date;
        status = "Scheduled";
    }

    void display() {
        System.out.println("\nAppointment ID: " + appointmentId);
        System.out.println("Patient Name: " + patientName);
        System.out.println("Test Name: " + testName);
        System.out.println("Appointment Date: " + appointmentDate);
        System.out.println("Status: " + status);
    }
}

public class BloodTestAppointmentScheduler {

    static ArrayList<Appointment> appointments = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);
    static int nextId = 1;

    static void bookAppointment() {
        System.out.print("Enter Patient Name: ");
        String name = sc.nextLine();

        System.out.println("\nAvailable Tests:");
        System.out.println("1. CBC");
        System.out.println("2. Blood Sugar");
        System.out.println("3. Thyroid");
        System.out.println("4. Lipid Profile");

        System.out.print("Choose Test: ");
        int choice = Integer.parseInt(sc.nextLine());

        String test;

        switch (choice) {
            case 1: test = "CBC"; break;
            case 2: test = "Blood Sugar"; break;
            case 3: test = "Thyroid"; break;
            case 4: test = "Lipid Profile"; break;
            default:
                System.out.println("Invalid test selection!");
                return;
        }

        System.out.print("Enter Appointment Date (DD-MM-YYYY): ");
        String date = sc.nextLine();

        Appointment appointment =
            new Appointment(nextId++, name, test, date);

        appointments.add(appointment);

        System.out.println("\nAppointment booked successfully!");
        System.out.println("Your Appointment ID: "
                + appointment.appointmentId);
    }

    static void viewAppointments() {
        if (appointments.isEmpty()) {
            System.out.println("\nNo appointments found.");
            return;
        }

        for (Appointment a : appointments) {
            a.display();
        }
    }

    static void searchAppointment() {
        System.out.print("Enter Appointment ID: ");
        int id = Integer.parseInt(sc.nextLine());

        for (Appointment a : appointments) {
            if (a.appointmentId == id) {
                a.display();
                return;
            }
        }

        System.out.println("Appointment not found!");
    }

    static void cancelAppointment() {
        System.out.print("Enter Appointment ID: ");
        int id = Integer.parseInt(sc.nextLine());

        for (Appointment a : appointments) {
            if (a.appointmentId == id) {
                a.status = "Cancelled";
                System.out.println("Appointment cancelled.");
                return;
            }
        }

        System.out.println("Appointment not found!");
    }

    public static void main(String[] args) {

        while (true) {
            System.out.println("\n===== BLOOD TEST APPOINTMENT SCHEDULER =====");
            System.out.println("1. Book Appointment");
            System.out.println("2. View Appointments");
            System.out.println("3. Search Appointment");
            System.out.println("4. Cancel Appointment");
            System.out.println("5. Exit");

            System.out.print("Enter Choice: ");

            try {
                int choice = Integer.parseInt(sc.nextLine());

                switch (choice) {
                    case 1:
                        bookAppointment();
                        break;

                    case 2:
                        viewAppointments();
                        break;

                    case 3:
                        searchAppointment();
                        break;

                    case 4:
                        cancelAppointment();
                        break;

                    case 5:
                        System.out.println("Thank you!");
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
