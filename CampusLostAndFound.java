
import java.util.ArrayList;
import java.util.Scanner;

class LostItem {
    String itemName;
    String description;
    String location;
    String status;

    LostItem(String itemName, String description,
             String location, String status) {
        this.itemName = itemName;
        this.description = description;
        this.location = location;
        this.status = status;
    }

    void display() {
        System.out.println("\nItem: " + itemName);
        System.out.println("Description: " + description);
        System.out.println("Location: " + location);
        System.out.println("Status: " + status);
        System.out.println("--------------------------");
    }
}

public class CampusLostAndFound {
    static ArrayList<LostItem> items = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);

    static void addItem() {
        System.out.print("Enter item name: ");
        String name = sc.nextLine();

        System.out.print("Enter item description: ");
        String description = sc.nextLine();

        System.out.print("Enter location: ");
        String location = sc.nextLine();

        System.out.println("1. Lost");
        System.out.println("2. Found");
        System.out.print("Choose status: ");
        String choice = sc.nextLine();

        String status;

        if (choice.equals("1")) {
            status = "Lost";
        } else if (choice.equals("2")) {
            status = "Found";
        } else {
            System.out.println("Invalid status. Report not added.");
            return;
        }

        items.add(new LostItem(name, description, location, status));
        System.out.println("Item report added successfully!");
    }

    static void showItems() {
        if (items.isEmpty()) {
            System.out.println("No item reports available.");
            return;
        }

        System.out.println("\n===== ALL ITEM REPORTS =====");

        for (LostItem item : items) {
            item.display();
        }
    }

    static void searchItem() {
        System.out.print("Enter item name to search: ");
        String search = sc.nextLine();

        boolean found = false;

        for (LostItem item : items) {
            if (item.itemName.toLowerCase()
                    .contains(search.toLowerCase())) {
                item.display();
                found = true;
            }
        }

        if (!found) {
            System.out.println("No matching item found.");
        }
    }

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== CAMPUS LOST & FOUND =====");
            System.out.println("1. Report Lost/Found Item");
            System.out.println("2. View All Reports");
            System.out.println("3. Search Item");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            String input = sc.nextLine();

            try {
                choice = Integer.parseInt(input);
            } catch (NumberFormatException e) {
                System.out.println("Please enter a valid number.");
                continue;
            }

            switch (choice) {
                case 1:
                    addItem();
                    break;

                case 2:
                    showItems();
                    break;

                case 3:
                    searchItem();
                    break;

                case 4:
                    System.out.println("Thank you for using the app!");
                    break;

                default:
                    System.out.println("Invalid choice. Try again.");
            }

        } while (choice != 4);

        sc.close();
    }
}
