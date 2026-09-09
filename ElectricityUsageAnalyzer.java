import java.util.Scanner;

public class ElectricityUsageAnalyzer {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("======================================");
        System.out.println("      ⚡ ELECTRICITY USAGE ANALYZER");
        System.out.println("======================================");

        System.out.print("Enter consumer name: ");
        String name = sc.nextLine();

        System.out.print("Enter number of months: ");
        int months = sc.nextInt();

        if (months <= 0) {
            System.out.println("Invalid number of months!");
            sc.close();
            return;
        }

        double totalUnits = 0;
        double highestUsage = 0;
        int highestMonth = 0;

        for (int i = 1; i <= months; i++) {

            System.out.print("Enter units used in month " + i + ": ");
            double units = sc.nextDouble();

            if (units < 0) {
                System.out.println("Units cannot be negative!");
                i--;
                continue;
            }

            totalUnits += units;

            if (units > highestUsage) {
                highestUsage = units;
                highestMonth = i;
            }
        }

        double averageUsage = totalUnits / months;

        String category;

        if (averageUsage <= 100) {
            category = "Low Usage 🟢";
        } else if (averageUsage <= 250) {
            category = "Moderate Usage 🟡";
        } else {
            category = "High Usage 🔴";
        }

        System.out.println("\n======================================");
        System.out.println("           📊 USAGE REPORT");
        System.out.println("======================================");

        System.out.println("Consumer Name : " + name);
        System.out.println("Months        : " + months);

        System.out.printf("Total Units   : %.2f%n", totalUnits);
        System.out.printf("Average Units : %.2f%n", averageUsage);

        System.out.println("Highest Usage : Month " + highestMonth);
        System.out.printf("Highest Units : %.2f%n", highestUsage);

        System.out.println("Usage Category: " + category);

        System.out.println("--------------------------------------");
        System.out.println("💡 Track your electricity usage regularly!");

        sc.close();
    }
}
