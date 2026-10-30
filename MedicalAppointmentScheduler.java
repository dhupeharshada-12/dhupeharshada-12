import java.util.ArrayList;
import java.util.Scanner;

class Appointment {
    int id;
    String patientName;
    String doctorName;
    String date;
    String time;

    Appointment(int id, String patientName, String doctorName,
                String date, String time) {
        this.id = id;
        this.patientName = patientName;
        this.doctorName = doctorName;
        this.date = date;
        this.time = time;
    }

    void display() {
        System.out.println("\nAppointment ID: " + id);
        System.out.println("Patient: " + patientName);
        System.out.println("Doctor: " + doctorName);
        System.out.println("Date: " + date);
        System.out.println("Time: " + time);
        System.out.println("----------------------------");
    }
}

public class MedicalAppointmentScheduler {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        ArrayList<Appointment> appointments = new ArrayList<>();

        int nextId = 1001;
        int choice;

        do {
            System.out.println("\n===== MEDICAL APPOINTMENT SCHEDULER =====");
            System.out.println("1. Book Appointment");
            System.out.println("2. View All Appointments");
            System.out.println("3. Search Appointment");
            System.out.println("4. Cancel Appointment");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            while (!sc.hasNextInt()) {
                System.out.print("Enter a valid number: ");
                sc.next();
            }

            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {

                case 1:
                    System.out.print("Enter patient name: ");
                    String patient = sc.nextLine().trim();

                    System.out.print("Enter doctor name: ");
                    String doctor = sc.nextLine().trim();

                    System.out.print("Enter date (DD-MM-YYYY): ");
                    String date = sc.nextLine().trim();

                    System.out.print("Enter time: ");
                    String time = sc.nextLine().trim();

                    if (patient.isEmpty() || doctor.isEmpty()
                            || date.isEmpty() || time.isEmpty()) {
                        System.out.println("All fields are required!");
                        break;
                    }

                    Appointment appointment = new Appointment(
                            nextId++, patient, doctor, date, time
                    );

                    appointments.add(appointment);

                    System.out.println("\nAppointment booked successfully!");
                    System.out.println("Appointment ID: " + appointment.id);
                    break;

                case 2:
                    if (appointments.isEmpty()) {
                        System.out.println("No appointments available.");
                    } else {
                        for (Appointment a : appointments) {
                            a.display();
                        }
                    }
                    break;

                case 3:
                    System.out.print("Enter appointment ID: ");

                    while (!sc.hasNextInt()) {
                        System.out.print("Enter a valid ID: ");
                        sc.next();
                    }

                    int searchId = sc.nextInt();
                    sc.nextLine();

                    boolean found = false;

                    for (Appointment a : appointments) {
                        if (a.id == searchId) {
                            a.display();
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        System.out.println("Appointment not found!");
                    }
                    break;

                case 4:
                    System.out.print("Enter appointment ID to cancel: ");

                    while (!sc.hasNextInt()) {
                        System.out.print("Enter a valid ID: ");
                        sc.next();
                    }

                    int cancelId = sc.nextInt();
                    sc.nextLine();

                    boolean removed = appointments.removeIf(
                            a -> a.id == cancelId
                    );

                    if (removed) {
                        System.out.println("Appointment cancelled successfully!");
                    } else {
                        System.out.println("Appointment not found!");
                    }
                    break;

                case 5:
                    System.out.println("Thank you for using the Scheduler!");
                    break;

                default:
                    System.out.println("Invalid choice! Try again.");
            }

        } while (choice != 5);

        sc.close();
    }
}
