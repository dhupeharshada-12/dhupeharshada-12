import java.util.Scanner;

public class TicTacToe {

    static char[] board = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'
    };

    static void printBoard() {
        System.out.println();
        System.out.println(" " + board[0] + " | " + board[1] + " | " + board[2]);
        System.out.println("---+---+---");
        System.out.println(" " + board[3] + " | " + board[4] + " | " + board[5]);
        System.out.println("---+---+---");
        System.out.println(" " + board[6] + " | " + board[7] + " | " + board[8]);
        System.out.println();
    }

    static boolean checkWin(char player) {

        int[][] combinations = {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
            {0, 3, 6},
            {1, 4, 7},
            {2, 5, 8},
            {0, 4, 8},
            {2, 4, 6}
        };

        for (int[] combo : combinations) {
            if (board[combo[0]] == player &&
                board[combo[1]] == player &&
                board[combo[2]] == player) {
                return true;
            }
        }

        return false;
    }

    static boolean isDraw() {
        for (char cell : board) {
            if (cell >= '1' && cell <= '9') {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        char currentPlayer = 'X';

        System.out.println("================================");
        System.out.println("       TIC-TAC-TOE GAME");
        System.out.println("================================");

        while (true) {

            printBoard();

            System.out.print("Player " + currentPlayer +
                    ", choose a position (1-9): ");

            int position = sc.nextInt();

            if (position < 1 || position > 9) {
                System.out.println("Invalid position! Try again.");
                continue;
            }

            int index = position - 1;

            if (board[index] == 'X' || board[index] == 'O') {
                System.out.println("Position already occupied!");
                continue;
            }

            board[index] = currentPlayer;

            if (checkWin(currentPlayer)) {
                printBoard();
                System.out.println("🎉 Player " + currentPlayer + " wins!");
                break;
            }

            if (isDraw()) {
                printBoard();
                System.out.println("🤝 It's a draw!");
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        sc.close();
    }
}
