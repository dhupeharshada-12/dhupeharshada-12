import java.util.ArrayList;
import java.util.Scanner;

public class TodoListManager {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        ArrayList<String> tasks = new ArrayList<>();

        int choice;

        do {
            System.out.println("\n===== TO-DO LIST MANAGER =====");
            System.out.println("1. Add Task");
            System.out.println("2. View Tasks");
            System.out.println("3. Remove Task");
            System.out.println("4. Exit");

            System.out.print("Enter Choice: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {

                case 1:
                    System.out.print("Enter Task: ");
                    String task = sc.nextLine();

                    tasks.add(task);

                    System.out.println("✅ Task Added Successfully!");
                    break;

                case 2:
                    if (tasks.isEmpty()) {
                        System.out.println("No Tasks Available!");
                    } else {
                        System.out.println("\n===== YOUR TASKS =====");

                        for (int i = 0; i < tasks.size(); i++) {
                            System.out.println(
                                (i + 1) + ". " + tasks.get(i)
                            );
                        }
                    }
                    break;

                case 3:
                    if (tasks.isEmpty()) {
                        System.out.println("No Tasks to Remove!");
                    } else {
                        System.out.print("Enter Task Number: ");
                        int taskNumber = sc.nextInt();

                        if (taskNumber >= 1 &&
                            taskNumber <= tasks.size()) {

                            tasks.remove(taskNumber - 1);

                            System.out.println(
                                "✅ Task Removed Successfully!"
                            );

                        } else {
                            System.out.println("Invalid Task Number!");
                        }
                    }
                    break;

                case 4:
                    System.out.println("Thank you! 👋");
                    break;

                default:
                    System.out.println("Invalid Choice!");
            }

        } while (choice != 4);

        sc.close();
    }
}
