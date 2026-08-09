#include <stdio.h>

int main() {
    int answer;
    int score = 0;

    printf("====================================\n");
    printf("          C QUIZ GAME               \n");
    printf("====================================\n");

    printf("\n1. Which language is used to create C programs?\n");
    printf("1. HTML\n2. C\n3. Python\n4. Java\n");
    printf("Enter answer: ");
    scanf("%d", &answer);

    if (answer == 2) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong!\n");
    }

    printf("\n2. Which symbol is used to end a statement in C?\n");
    printf("1. .\n2. :\n3. ;\n4. ,\n");
    printf("Enter answer: ");
    scanf("%d", &answer);

    if (answer == 3) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong!\n");
    }

    printf("\n3. Which function is the starting point of a C program?\n");
    printf("1. start()\n2. main()\n3. begin()\n4. run()\n");
    printf("Enter answer: ");
    scanf("%d", &answer);

    if (answer == 2) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong!\n");
    }

    printf("\n4. Which header file is used for printf()?\n");
    printf("1. stdio.h\n2. math.h\n3. string.h\n4. time.h\n");
    printf("Enter answer: ");
    scanf("%d", &answer);

    if (answer == 1) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong!\n");
    }

    printf("\n5. Which data type stores decimal numbers?\n");
    printf("1. int\n2. char\n3. float\n4. void\n");
    printf("Enter answer: ");
    scanf("%d", &answer);

    if (answer == 3) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong!\n");
    }

    printf("\n========== RESULT ==========\n");
    printf("Your Score: %d / 5\n", score);

    if (score == 5)
        printf("Excellent! 🎉\n");
    else if (score >= 3)
        printf("Good Job! 👍\n");
    else
        printf("Keep Practicing! 💪\n");

    return 0;
}
