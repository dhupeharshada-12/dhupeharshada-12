import java.util.ArrayList;
import java.util.Scanner;

class Event {
    int eventId;
    String eventName;
    String eventDate;
    int maxParticipants;
    ArrayList<String> participants;

    Event(int eventId, String eventName, String eventDate,
          int maxParticipants) {
        this.eventId = eventId;
        this.eventName = eventName;
        this.eventDate = eventDate;
        this.maxParticipants = maxParticipants;
        this.participants = new ArrayList<>();
    }

    void displayEvent() {
        System.out.println("\nEvent ID: " + eventId);
        System.out.println("Event Name: " + eventName);
        System.out.println("Date: " + eventDate);
        System.out.println("Participants: " +
                participants.size() + "/" + maxParticipants);
    }
}

public class CollegeEventManager {

    static Scanner sc = new Scanner(System.in);
    static ArrayList<Event> events = new ArrayList<>();

    static void addEvent() {
        System.out.print("\nEnter Event ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        for (Event event : events) {
            if (event.eventId == id) {
                System.out.println("Event ID already exists!");
                return;
            }
        }

        System.out.print("Enter Event Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Event Date: ");
        String date = sc.nextLine();

        System.out.print("Enter Maximum Participants: ");
        int max = sc.nextInt();
        sc.nextLine();

        if (max <= 0) {
            System.out.println("Maximum participants must be positive!");
            return;
        }

        events.add(new Event(id, name, date, max));
        System.out.println("Event added successfully!");
    }

    static void viewEvents() {
        if (events.isEmpty()) {
            System.out.println("\nNo events available.");
            return;
        }

        System.out.println("\n===== COLLEGE EVENTS =====");

        for (Event event : events) {
            event.displayEvent();
        }
    }

    static void registerStudent() {
        System.out.print("\nEnter Event ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        for (Event event : events) {
            if (event.eventId == id) {

                if (event.participants.size() >= event.maxParticipants) {
                    System.out.println("Event is full!");
                    return;
                }

                System.out.print("Enter Student Name: ");
                String name = sc.nextLine().trim();

                if (name.isEmpty()) {
                    System.out.println("Name cannot be empty!");
                    return;
                }

                if (event.participants.contains(name)) {
                    System.out.println("Student already registered!");
                    return;
                }

                event.participants.add(name);
                System.out.println("Registration successful!");
                return;
            }
        }

        System.out.println("Event not found!");
    }

    static void searchEvent() {
        System.out.print("\nEnter Event ID to search: ");
        int id = sc.nextInt();

        for (Event event : events) {
            if (event.eventId == id) {
                event.displayEvent();
                return;
            }
        }

        System.out.println("Event not found!");
    }

    static void viewParticipants() {
        System.out.print("\nEnter Event ID: ");
        int id = sc.nextInt();

        for (Event event : events) {
            if (event.eventId == id) {

                System.out.println("\nParticipants of " +
                        event.eventName + ":");

                if (event.participants.isEmpty()) {
                    System.out.println("No registrations yet.");
                } else {
                    for (String name : event.participants) {
                        System.out.println("- " + name);
                    }
                }
                return;
            }
        }

        System.out.println("Event not found!");
    }

    public static void main(String[] args) {

        while (true) {
            System.out.println("\n===== COLLEGE EVENT MANAGER =====");
            System.out.println("1. Add New Event");
            System.out.println("2. View All Events");
            System.out.println("3. Register Student");
            System.out.println("4. Search Event");
            System.out.println("5. View Participants");
            System.out.println("6. Exit");

            System.out.print("\nEnter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    addEvent();
                    break;

                case 2:
                    viewEvents();
                    break;

                case 3:
                    registerStudent();
                    break;

                case 4:
                    searchEvent();
                    break;

                case 5:
                    viewParticipants();
                    break;

                case 6:
                    System.out.println("Thank you for using College Event Manager!");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice! Try again.");
            }
        }
    }
}
