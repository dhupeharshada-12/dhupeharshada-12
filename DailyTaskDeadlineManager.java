import java.util.ArrayList;
import java.util.Scanner;

class Task {
    int id;
    String title;
    String deadline;
    String status;

    Task(int id, String title, String deadline) {
        this.id = id;
        this.title = title;
        this.deadline = deadline;
        this.status = "Pending";
    }
}

public class DailyTaskDeadlineManager {

    static ArrayList<Task> tasks = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);
    static int nextId = 1;

    static void addTask() {
        System.out.print("Enter task title: ");
        String title = sc.nextLine().trim();

        if (title.isEmpty()) {
            System.out.println("Task title cannot be empty.");
            return;
        }

        System.out.print("Enter deadline (DD-MM-YYYY): ");
        String deadline = sc.nextLine().trim();

        tasks.add(new Task(nextId++, title, deadline));
        System.out.println("Task added successfully!");
    }

    static void displayTasks() {
        if (tasks.isEmpty()) {
            System.out.println("No tasks available.");
            return;
        }

        System.out.println("\n--- Task List ---");

        for (Task t : tasks) {
            System.out.println("ID: " + t.id);
            System.out.println("Title: " + t.title);
            System.out.println("Deadline: " + t.deadline);
            System.out.println("Status: " + t.status);
            System.out.println("-----------------------");
        }
    }

    static void completeTask() {
        System.out.print("Enter task ID: ");

        try {
            int id = Integer.parseInt(sc.nextLine());

            for (Task t : tasks) {
                if (t.id == id) {
                    if (t.status.equals("Completed")) {
                        System.out.println("Task is already completed.");
                    } else {
                        t.status = "Completed";
                        System.out.println("Task marked as completed!");
                    }
                    return;
                }
            }

            System.out.println("Task ID not found.");

        } catch (NumberFormatException e) {
            System.out.println("Please enter a valid ID.");
        }
    }

    static void searchTask() {
        System.out.print("Enter task title to search: ");
        String search = sc.nextLine().trim().toLowerCase();

        boolean found = false;

        for (Task t : tasks) {
            if (t.title.toLowerCase().contains(search)) {
                System.out.println("\nID: " + t.id);
                System.out.println("Title: " + t.title);
                System.out.println("Deadline: " + t.deadline);
                System.out.println("Status: " + t.status);
                found = true;
            }
        }

        if (!found) {
            System.out.println("No matching task found.");
        }
    }

    static void displaySummary() {
        int completed = 0;
        int pending = 0;

        for (Task t : tasks) {
            if (t.status.equals("Completed"))
                completed++;
            else
                pending++;
        }

        System.out.println("\n===== Task Summary =====");
        System.out.println("Total Tasks: " + tasks.size());
        System.out.println("Completed: " + completed);
        System.out.println("Pending: " + pending);
    }

    public static void main(String[] args) {
        while (true) {
            System.out.println("\n===== Daily Task Deadline Manager =====");
            System.out.println("1. Add Task");
            System.out.println("2. View Tasks");
            System.out.println("3. Complete Task");
            System.out.println("4. Search Task");
            System.out.println("5. Task Summary");
            System.out.println("6. Exit");

            System.out.print("Enter choice: ");
            String choice = sc.nextLine();

            switch (choice) {
                case "1":
                    addTask();
                    break;
                case "2":
                    displayTasks();
                    break;
                case "3":
                    completeTask();
                    break;
                case "4":
                    searchTask();
                    break;
                case "5":
                    displaySummary();
                    break;
                case "6":
                    System.out.println("Program closed.");
                    return;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
