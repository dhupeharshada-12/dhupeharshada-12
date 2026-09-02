import java.util.Scanner;

public class SimpleChatbot {

    public static String getReply(String message) {

        message = message.toLowerCase();

        if (message.contains("hello") || message.contains("hi")) {
            return "Hello! 😊 How can I help you?";
        }
        else if (message.contains("name")) {
            return "My name is JavaBot 🤖";
        }
        else if (message.contains("how are you")) {
            return "I am doing great! Thanks for asking 😄";
        }
        else if (message.contains("study")) {
            return "Keep studying consistently. Small progress every day! 📚";
        }
        else if (message.contains("java")) {
            return "Java is a powerful object-oriented programming language ☕";
        }
        else if (message.contains("bye")) {
            return "Goodbye! Keep coding 🚀";
        }
        else {
            return "Sorry, I don't understand that yet 🤔";
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("================================");
        System.out.println("       🤖 JAVA CHATBOT");
        System.out.println("================================");
        System.out.println("Type 'bye' to exit.\n");

        while (true) {

            System.out.print("You: ");
            String message = sc.nextLine();

            String reply = getReply(message);

            System.out.println("Bot: " + reply);

            if (message.toLowerCase().contains("bye")) {
                break;
            }
        }

        sc.close();
    }
}
