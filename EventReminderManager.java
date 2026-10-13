
import java.time.LocalDate;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.Scanner;

class Event {
    String name;
    LocalDate date;
    String description;

    Event(String name, LocalDate date, String description) {
        this.name = name;
        this.date = date;
        this.description = description;
    }

    void display() {
        System.out.println("\nEvent: " + name);
        System.out.println("Date: " + date);
        System.out.println("Description: " + description);
        System.out.println("---------------------------");
    }
}

public class EventReminderManager {
    static ArrayList<Event> events = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);

    static void addEvent() {
        System.out.print("Enter event name: ");
        String name = sc.nextLine().trim();

        if (name.isEmpty()) {
            System.out.println("Event name cannot be empty.");
            return;
        }

        try {
            System.out.print("Enter date (YYYY-MM-DD): ");
            LocalDate date = LocalDate.parse(sc.nextLine().trim());

            System.out.print("Enter description: ");
            String description = sc.nextLine().trim();

            events.add(new Event(name, date, description));
            System.out.println("Event added successfully!");
        } catch (DateTimeParseException e) {
            System.out.println("Invalid date! Use YYYY-MM-DD.");
        }
    }

    static void showEvents() {
        if (events.isEmpty()) {
            System.out.println("No events available.");
            return;
        }

        events.sort((a, b) -> a.date.compareTo(b.date));

        System.out.println("\n===== ALL EVENTS =====");
        for (Event event : events) {
            event.display();
        }
    }

    static void searchByDate() {
        try {
            System.out.print("Enter date to search (YYYY-MM-DD): ");
            LocalDate searchDate = LocalDate.parse(sc.nextLine().trim());
            boolean found = false;

            for (Event event : events) {
                if (event.date.equals(searchDate)) {
                    event.display();
                    found = true;
                }
            }

            if (!found) {
                System.out.println("No events found for this date.");
            }
        } catch (DateTimeParseException e) {
            System.out.println("Invalid date format.");
        }
    }

    static void deleteEvent() {
        System.out.print("Enter exact event name to delete: ");
        String name = sc.nextLine().trim();

        boolean removed = events.removeIf(
            event -> event.name.equalsIgnoreCase(name)
        );

        if (removed) {
            System.out.println("Event deleted successfully.");
        } else {
            System.out.println("Event not found.");
        }
    }

    public static void main(String[] args) {
        while (true) {
            System.out.println("\n===== EVENT REMINDER MANAGER =====");
            System.out.println("1. Add Event");
            System.out.println("2. View Events");
            System.out.println("3. Search Events by Date");
            System.out.println("4. Delete Event");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");

            String choice = sc.nextLine().trim();

            switch (choice) {
                case "1":
                    addEvent();
                    break;
                case "2":
                    showEvents();
                    break;
                case "3":
                    searchByDate();
                    break;
                case "4":
                    deleteEvent();
                    break;
                case "5":
                    System.out.println("Goodbye!");
                    sc.close();
                    return;
                default:
                    System.out.println("Invalid choice. Enter 1 to 5.");
            }
        }
    }
}
