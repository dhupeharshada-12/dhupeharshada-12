import java.util.Scanner;

public class BankTransactionAnalyzer {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        double balance = 0;
        double totalDeposit = 0;
        double totalWithdrawal = 0;

        System.out.println("======================================");
        System.out.println("      🏦 BANK TRANSACTION ANALYZER");
        System.out.println("======================================");

        System.out.print("Enter number of transactions: ");
        int n = sc.nextInt();

        if (n <= 0) {
            System.out.println("Invalid number of transactions!");
            sc.close();
            return;
        }

        for (int i = 1; i <= n; i++) {

            System.out.println("\nTransaction " + i);
            System.out.println("1. Deposit");
            System.out.println("2. Withdrawal");

            System.out.print("Choose transaction type: ");
            int type = sc.nextInt();

            System.out.print("Enter amount: ₹");
            double amount = sc.nextDouble();

            if (amount <= 0) {
                System.out.println("Invalid amount!");
                continue;
            }

            if (type == 1) {

                balance += amount;
                totalDeposit += amount;

                System.out.println("✅ Deposit successful.");

            } else if (type == 2) {

                if (amount > balance) {
                    System.out.println("❌ Insufficient balance.");
                } else {
                    balance -= amount;
                    totalWithdrawal += amount;

                    System.out.println("✅ Withdrawal successful.");
                }

            } else {
                System.out.println("❌ Invalid transaction type.");
            }
        }

        System.out.println("\n======================================");
        System.out.println("          📊 ACCOUNT SUMMARY");
        System.out.println("======================================");

        System.out.printf("Total Deposits    : ₹%.2f%n", totalDeposit);
        System.out.printf("Total Withdrawals : ₹%.2f%n", totalWithdrawal);
        System.out.printf("Final Balance     : ₹%.2f%n", balance);

        System.out.println("--------------------------------------");
        System.out.println("✅ Transaction analysis completed!");

        sc.close();
    }
}
