import java.util.Scanner;

public class CurrencyConverter {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        double amount, converted;
        int choice;

        System.out.println("===== CURRENCY CONVERTER =====");
        System.out.println("1. INR to USD");
        System.out.println("2. USD to INR");
        System.out.println("3. INR to EUR");
        System.out.println("4. EUR to INR");

        System.out.print("Enter Choice: ");
        choice = sc.nextInt();

        System.out.print("Enter Amount: ");
        amount = sc.nextDouble();

        switch (choice) {

            case 1:
                converted = amount / 90.0;
                System.out.printf("USD: %.2f%n", converted);
                break;

            case 2:
                converted = amount * 90.0;
                System.out.printf("INR: %.2f%n", converted);
                break;

            case 3:
                converted = amount / 105.0;
                System.out.printf("EUR: %.2f%n", converted);
                break;

            case 4:
                converted = amount * 105.0;
                System.out.printf("INR: %.2f%n", converted);
                break;

            default:
                System.out.println("Invalid Choice!");
        }

        sc.close();
    }
}
