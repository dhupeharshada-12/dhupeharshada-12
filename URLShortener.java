import java.util.HashMap;
import java.util.Scanner;

public class URLShortener {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        HashMap<String, String> urls = new HashMap<>();

        int counter = 1;
        int choice;

        do {
            System.out.println("\n===== URL SHORTENER =====");
            System.out.println("1. Add URL");
            System.out.println("2. Find Original URL");
            System.out.println("3. Show All URLs");
            System.out.println("4. Exit");

            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {

                case 1:
                    System.out.print("Enter long URL: ");
                    String longUrl = sc.nextLine();

                    String shortCode = "short" + counter;

                    urls.put(shortCode, longUrl);

                    System.out.println("Short URL Code: " + shortCode);

                    counter++;
                    break;

                case 2:
                    System.out.print("Enter short URL code: ");
                    String code = sc.nextLine();

                    if (urls.containsKey(code)) {
                        System.out.println("Original URL: " + urls.get(code));
                    } else {
                        System.out.println("URL not found!");
                    }

                    break;

                case 3:
                    if (urls.isEmpty()) {
                        System.out.println("No URLs stored.");
                    } else {
                        System.out.println("\n--- Stored URLs ---");

                        for (String key : urls.keySet()) {
                            System.out.println(key + " -> " + urls.get(key));
                        }
                    }

                    break;

                case 4:
                    System.out.println("Thank you for using URL Shortener!");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 4);

        sc.close();
    }
}
