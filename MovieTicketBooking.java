import java.util.Scanner;

public class MovieTicketBooking {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String[] movies = {
            "Avengers",
            "Interstellar",
            "Inception",
            "3 Idiots"
        };

        double[] prices = {
            180.0,
            200.0,
            170.0,
            150.0
        };

        System.out.println("======================================");
        System.out.println("       🎬 MOVIE TICKET BOOKING");
        System.out.println("======================================");

        System.out.println("\nAvailable Movies:");

        for (int i = 0; i < movies.length; i++) {
            System.out.printf("%d. %-15s ₹%.2f%n",
                    i + 1, movies[i], prices[i]);
        }

        System.out.print("\nChoose a movie (1-4): ");
        int choice = sc.nextInt();

        if (choice < 1 || choice > movies.length) {
            System.out.println("❌ Invalid movie choice!");
            sc.close();
            return;
        }

        System.out.print("Enter number of tickets: ");
        int tickets = sc.nextInt();

        if (tickets <= 0) {
            System.out.println("❌ Invalid number of tickets!");
            sc.close();
            return;
        }

        double total = prices[choice - 1] * tickets;

        System.out.println("\n======================================");
        System.out.println("          🎟️ BOOKING SUMMARY");
        System.out.println("======================================");

        System.out.println("Movie       : " + movies[choice - 1]);
        System.out.println("Tickets     : " + tickets);
        System.out.printf("Ticket Price: ₹%.2f%n", prices[choice - 1]);
        System.out.printf("Total Amount: ₹%.2f%n", total);

        System.out.println("--------------------------------------");
        System.out.println("✅ Booking Successful!");
        System.out.println("Enjoy the movie! 🍿🎬");

        sc.close();
    }
}
