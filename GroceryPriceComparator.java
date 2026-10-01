import java.util.Scanner;

public class GroceryPriceComparator {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("===== GROCERY PRICE COMPARATOR =====");

        System.out.print("Enter product name: ");
        String product = sc.nextLine();

        System.out.print("Enter price at Store A: ");
        double storeA = sc.nextDouble();

        System.out.print("Enter price at Store B: ");
        double storeB = sc.nextDouble();

        System.out.print("Enter price at Store C: ");
        double storeC = sc.nextDouble();

        double lowestPrice = Math.min(storeA, Math.min(storeB, storeC));

        System.out.println("\nProduct: " + product);
        System.out.println("Store A: ₹" + storeA);
        System.out.println("Store B: ₹" + storeB);
        System.out.println("Store C: ₹" + storeC);

        System.out.println("\nLowest Price: ₹" + lowestPrice);

        if (lowestPrice == storeA) {
            System.out.println("Best price found at Store A.");
        } else if (lowestPrice == storeB) {
            System.out.println("Best price found at Store B.");
        } else {
            System.out.println("Best price found at Store C.");
        }

        sc.close();
    }
}
