import java.util.Scanner;

public class DigitalWallet {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        double balance = 1000.00;
        int choice;

        System.out.println("===== DIGITAL WALLET =====");

        do {
            System.out.println("\n1. Check Balance");
            System.out.println("2. Add Money");
            System.out.println("3. Pay Money");
            System.out.println("4. Exit");

            System.out.print("Enter Choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.printf(
                        "Current Balance: Rs. %.2f%n",
                        balance
                    );
                    break;

                case 2:
                    System.out.print("Enter Amount: Rs. ");
                    double addMoney = sc.nextDouble();

                    if (addMoney > 0) {
                        balance += addMoney;
                        System.out.printf(
                            "Money Added! New Balance: Rs. %.2f%n",
                            balance
                        );
                    } else {
                        System.out.println("Invalid Amount!");
                    }
                    break;

                case 3:
                    System.out.print("Enter Payment Amount: Rs. ");
                    double payment = sc.nextDouble();

                    if (payment <= 0) {
                        System.out.println("Invalid Amount!");
                    } else if (payment > balance) {
                        System.out.println("Insufficient Balance!");
                    } else {
                        balance -= payment;
                        System.out.printf(
                            "Payment Successful! Remaining Balance: Rs. %.2f%n",
                            balance
                        );
                    }
                    break;

                case 4:
                    System.out.println("Thank you for using Digital Wallet!");
                    break;

                default:
                    System.out.println("Invalid Choice!");
            }

        } while (choice != 4);

        sc.close();
    }
}
