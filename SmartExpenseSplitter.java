import java.util.Scanner;

public class SmartExpenseSplitter {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("======================================");
        System.out.println("       💰 SMART EXPENSE SPLITTER");
        System.out.println("======================================");

        System.out.print("Enter total expense: ₹");
        double totalExpense = sc.nextDouble();

        System.out.print("Enter number of people: ");
        int people = sc.nextInt();

        if (totalExpense < 0 || people <= 0) {
            System.out.println("Invalid input!");
            sc.close();
            return;
        }

        double perPerson = totalExpense / people;

        System.out.println("\n----------- EXPENSE SUMMARY -----------");
        System.out.printf("Total Expense : ₹%.2f%n", totalExpense);
        System.out.println("People        : " + people);
        System.out.printf("Each Person   : ₹%.2f%n", perPerson);

        System.out.println("---------------------------------------");
        System.out.println("Everyone should pay ₹"
                + String.format("%.2f", perPerson));

        System.out.println("\n✅ Expense successfully divided!");

        sc.close();
    }
}
