import java.util.Scanner;

public class BusReservation {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int totalSeats = 30;
        int bookedSeats = 0;
        double ticketPrice = 250.0;
        int choice;

        System.out.println("===== BUS RESERVATION SYSTEM =====");

        do {
            System.out.println("\n1. Book Ticket");
            System.out.println("2. Check Available Seats");
            System.out.println("3. Booking Summary");
            System.out.println("4. Exit");

            System.out.print("Enter Choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("Enter Number of Tickets: ");
                    int tickets = sc.nextInt();

                    if (tickets <= 0) {
                        System.out.println("Invalid number of tickets!");
                    } else if (bookedSeats + tickets > totalSeats) {
                        System.out.println("Not enough seats available!");
                    } else {
                        bookedSeats += tickets;

                        double amount = tickets * ticketPrice;

                        System.out.println("\nBooking Successful!");
                        System.out.println("Tickets Booked: " + tickets);
                        System.out.printf("Total Amount: Rs. %.2f%n", amount);
                    }
                    break;

                case 2:
                    System.out.println(
                        "Available Seats: " +
                        (totalSeats - bookedSeats)
                    );
                    break;

                case 3:
                    System.out.println("\n===== BOOKING SUMMARY =====");
                    System.out.println("Total Seats   : " + totalSeats);
                    System.out.println("Booked Seats  : " + bookedSeats);
                    System.out.println(
                        "Available     : " +
                        (totalSeats - bookedSeats)
                    );
                    System.out.printf(
                        "Ticket Price  : Rs. %.2f%n",
                        ticketPrice
                    );
                    break;

                case 4:
                    System.out.println("Thank you for using the system!");
                    break;

                default:
                    System.out.println("Invalid Choice!");
            }

        } while (choice != 4);

        sc.close();
    }
}
