import java.util.Scanner;

public class SmartParkingCalculator {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("======================================");
        System.out.println("      🚗 SMART PARKING CALCULATOR");
        System.out.println("======================================");

        System.out.print("Enter vehicle number: ");
        String vehicleNumber = sc.nextLine();

        System.out.print("Enter vehicle type (1-Car, 2-Bike): ");
        int type = sc.nextInt();

        System.out.print("Enter parking hours: ");
        int hours = sc.nextInt();

        if (hours <= 0) {
            System.out.println("❌ Invalid parking hours!");
            sc.close();
            return;
        }

        double rate;

        if (type == 1) {
            rate = 30;
        } else if (type == 2) {
            rate = 15;
        } else {
            System.out.println("❌ Invalid vehicle type!");
            sc.close();
            return;
        }

        double totalFee = rate * hours;

        // Discount for parking 5 hours or more
        double discount = 0;

        if (hours >= 5) {
            discount = totalFee * 0.10;
        }

        double finalFee = totalFee - discount;

        System.out.println("\n======================================");
        System.out.println("          🅿️ PARKING RECEIPT");
        System.out.println("======================================");

        System.out.println("Vehicle Number : " + vehicleNumber);
        System.out.println("Vehicle Type   : "
                + (type == 1 ? "Car" : "Bike"));
        System.out.println("Parking Hours  : " + hours);

        System.out.printf("Base Fee       : ₹%.2f%n", totalFee);
        System.out.printf("Discount       : ₹%.2f%n", discount);
        System.out.printf("Final Fee      : ₹%.2f%n", finalFee);

        System.out.println("--------------------------------------");
        System.out.println("✅ Parking fee calculated successfully!");

        sc.close();
    }
}
