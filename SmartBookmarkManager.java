import java.util.ArrayList;
import java.util.Scanner;

class Bookmark {
    String title;
    String url;
    String category;

    Bookmark(String title, String url, String category) {
        this.title = title;
        this.url = url;
        this.category = category;
    }

    void display() {
        System.out.println("Title: " + title);
        System.out.println("URL: " + url);
        System.out.println("Category: " + category);
        System.out.println("--------------------------");
    }
}

public class SmartBookmarkManager {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Bookmark> bookmarks = new ArrayList<>();

        int choice;

        do {
            System.out.println("\n===== Smart Bookmark Manager =====");
            System.out.println("1. Add Bookmark");
            System.out.println("2. View All Bookmarks");
            System.out.println("3. Search by Category");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            while (!sc.hasNextInt()) {
                System.out.print("Please enter a valid number: ");
                sc.next();
            }

            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter website title: ");
                    String title = sc.nextLine();

                    System.out.print("Enter website URL: ");
                    String url = sc.nextLine();

                    System.out.print("Enter category: ");
                    String category = sc.nextLine();

                    bookmarks.add(new Bookmark(title, url, category));

                    System.out.println("Bookmark added successfully!");
                    break;

                case 2:
                    if (bookmarks.isEmpty()) {
                        System.out.println("No bookmarks available.");
                    } else {
                        for (Bookmark b : bookmarks) {
                            b.display();
                        }
                    }
                    break;

                case 3:
                    System.out.print("Enter category to search: ");
                    String searchCategory = sc.nextLine();

                    boolean found = false;

                    for (Bookmark b : bookmarks) {
                        if (b.category.equalsIgnoreCase(searchCategory)) {
                            b.display();
                            found = true;
                        }
                    }

                    if (!found) {
                        System.out.println("No bookmarks found in this category.");
                    }
                    break;

                case 4:
                    System.out.println("Thank you for using Bookmark Manager!");
                    break;

                default:
                    System.out.println("Invalid choice. Try again.");
            }

        } while (choice != 4);

        sc.close();
    }
}
