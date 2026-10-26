import java.util.ArrayList;
import java.util.Scanner;

class Resource {
    int id;
    String name;
    String category;
    boolean available;

    Resource(int id, String name, String category) {
        this.id = id;
        this.name = name;
        this.category = category;
        this.available = true;
    }

    void display() {
        System.out.println("\nResource ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Category: " + category);
        System.out.println("Status: " +
                (available ? "Available" : "In Use"));
        System.out.println("---------------------------");
    }
}

public class ClassroomResourceManager {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Resource> resources = new ArrayList<>();

        int nextId = 101;
        int choice;

        do {
            System.out.println("\n===== CLASSROOM RESOURCE MANAGER =====");
            System.out.println("1. Add Resource");
            System.out.println("2. View All Resources");
            System.out.println("3. Search Resource");
            System.out.println("4. Update Resource Availability");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            while (!sc.hasNextInt()) {
                System.out.print("Enter a valid number: ");
                sc.next();
            }

            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {

                case 1:
                    System.out.print("Enter resource name: ");
                    String name = sc.nextLine().trim();

                    System.out.print("Enter resource category: ");
                    String category = sc.nextLine().trim();

                    if (name.isEmpty() || category.isEmpty()) {
                        System.out.println(
                                "Name and category cannot be empty!");
                        break;
                    }

                    Resource resource =
                            new Resource(nextId++, name, category);

                    resources.add(resource);

                    System.out.println("Resource added successfully!");
                    System.out.println("Resource ID: " + resource.id);
                    break;

                case 2:
                    if (resources.isEmpty()) {
                        System.out.println("No resources available.");
                    } else {
                        for (Resource r : resources) {
                            r.display();
                        }
                    }
                    break;

                case 3:
                    System.out.print("Enter resource name to search: ");
                    String searchName = sc.nextLine().trim();

                    boolean found = false;

                    for (Resource r : resources) {
                        if (r.name.equalsIgnoreCase(searchName)) {
                            r.display();
                            found = true;
                        }
                    }

                    if (!found) {
                        System.out.println("Resource not found!");
                    }
                    break;

                case 4:
                    System.out.print("Enter resource ID: ");

                    while (!sc.hasNextInt()) {
                        System.out.print("Enter a valid resource ID: ");
                        sc.next();
                    }

                    int searchId = sc.nextInt();
                    sc.nextLine();

                    Resource selected = null;

                    for (Resource r : resources) {
                        if (r.id == searchId) {
                            selected = r;
                            break;
                        }
                    }

                    if (selected == null) {
                        System.out.println("Resource not found!");
                        break;
                    }

                    System.out.println("1. Mark Available");
                    System.out.println("2. Mark In Use");
                    System.out.print("Choose new status: ");

                    if (!sc.hasNextInt()) {
                        System.out.println("Invalid input!");
                        sc.nextLine();
                        break;
                    }

                    int status = sc.nextInt();
                    sc.nextLine();

                    if (status == 1) {
                        selected.available = true;
                        System.out.println("Resource marked Available.");
                    } else if (status == 2) {
                        selected.available = false;
                        System.out.println("Resource marked In Use.");
                    } else {
                        System.out.println("Invalid status choice!");
                    }
                    break;

                case 5:
                    System.out.println(
                            "Thank you for using Resource Manager!");
                    break;

                default:
                    System.out.println("Invalid choice! Try again.");
            }

        } while (choice != 5);

        sc.close();
    }
}
