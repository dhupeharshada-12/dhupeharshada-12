import java.util.Scanner;

public class MovieRatingAnalyzer {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String[] movies = new String[5];
        double[] ratings = new double[5];

        System.out.println("===== MOVIE RATING ANALYZER =====");

        for (int i = 0; i < 5; i++) {
            System.out.print("\nEnter Movie " + (i + 1) + " Name: ");
            movies[i] = sc.nextLine();

            System.out.print("Enter Rating (0-10): ");
            ratings[i] = sc.nextDouble();
            sc.nextLine();

            if (ratings[i] < 0 || ratings[i] > 10) {
                System.out.println("Invalid rating! Enter between 0 and 10.");
                i--;
            }
        }

        double total = 0;
        int highestIndex = 0;

        for (int i = 0; i < ratings.length; i++) {
            total += ratings[i];

            if (ratings[i] > ratings[highestIndex]) {
                highestIndex = i;
            }
        }

        double average = total / ratings.length;

        System.out.println("\n========== RESULT ==========");

        for (int i = 0; i < movies.length; i++) {
            System.out.printf(
                "%s : %.1f/10%n",
                movies[i],
                ratings[i]
            );
        }

        System.out.printf("\nAverage Rating : %.2f/10%n", average);

        System.out.println(
            "Highest Rated  : " +
            movies[highestIndex] +
            " (" +
            ratings[highestIndex] +
            "/10)"
        );

        sc.close();
    }
}
