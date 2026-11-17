import java.util.ArrayList;
import java.util.Scanner;

class Seat {
    int seatNumber;
    boolean isBooked;
    String studentName;

    Seat(int seatNumber) {
        this.seatNumber = seatNumber;
        this.isBooked = false;
        this.studentName = "";
    }
}

public class LibrarySeatReservation {

    static ArrayList<Seat> seats = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);

    static void initializeSeats() {
        for (int i = 1; i <= 20; i++) {
            seats.add(new Seat(i));
        }
    }

    static void displaySeats() {
        System.out.println("\n===== LIBRARY SEAT STATUS =====");

        for (Seat seat : seats) {
            System.out.println(
                "Seat " + seat.seatNumber + " : " +
                (seat.isBooked ? "Booked" : "Available")
            );
        }
    }

    static void bookSeat() {
        System.out.print("\nEnter Student Name: ");
        String name = sc.nextLine().trim();

        if (name.isEmpty()) {
            System.out.println("Student name cannot be empty!");
            return;
        }

        System.out.print("Enter Seat Number (1-20): ");

        int number;

        try {
            number = Integer.parseInt(sc.nextLine());
        } catch (NumberFormatException e) {
            System.out.println("Please enter a valid number!");
            return;
        }

        for (Seat seat : seats) {
            if (seat.seatNumber == number) {

                if (seat.isBooked) {
                    System.out.println("This seat is already booked!");
                } else {
                    seat.isBooked = true;
                    seat.studentName = name;

                    System.out.println("Seat booked successfully!");
                }

                return;
            }
        }

        System.out.println("Invalid seat number!");
    }

    static void viewBookings() {
        System.out.println("\n===== BOOKING DETAILS =====");

        boolean found = false;

        for (Seat seat : seats) {
            if (seat.isBooked) {
                System.out.println(
                    "Seat: " + seat.seatNumber +
                    " | Student: " + seat.studentName
                );

                found = true;
            }
        }

        if (!found) {
            System.out.println("No bookings available.");
        }
    }

    static void cancelBooking() {
        System.out.print("\nEnter Seat Number to Cancel: ");

        int number;

        try {
            number = Integer.parseInt(sc.nextLine());
        } catch (NumberFormatException e) {
            System.out.println("Invalid input!");
            return;
        }

        for (Seat seat : seats) {
            if (seat.seatNumber == number) {

                if (seat.isBooked) {
                    seat.isBooked = false;
                    seat.studentName = "";

                    System.out.println("Booking cancelled successfully!");
                } else {
                    System.out.println("This seat is not booked!");
                }

                return;
            }
        }

        System.out.println("Invalid seat number!");
    }

    public static void main(String[] args) {

        initializeSeats();

        while (true) {

            System.out.println("\n===== SMART LIBRARY MANAGEMENT =====");
            System.out.println("1. Display Available Seats");
            System.out.println("2. Book a Seat");
            System.out.println("3. View All Bookings");
            System.out.println("4. Cancel Booking");
            System.out.println("5. Exit");

            System.out.print("Enter Your Choice: ");

            String input = sc.nextLine();

            switch (input) {

                case "1":
                    displaySeats();
                    break;

                case "2":
                    bookSeat();
                    break;

                case "3":
                    viewBookings();
                    break;

                case "4":
                    cancelBooking();
                    break;

                case "5":
                    System.out.println("Thank you for using the system!");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice! Try again.");
            }
        }
    }
}
