#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

int main() {
    struct Contact contacts[100];
    int count = 0;
    int choice;
    char searchName[50];

    do {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (count < 100) {
                    printf("\nEnter Name: ");
                    scanf(" %[^\n]", contacts[count].name);

                    printf("Enter Phone Number: ");
                    scanf(" %[^\n]", contacts[count].phone);

                    printf("Enter Email: ");
                    scanf(" %[^\n]", contacts[count].email);

                    count++;

                    printf("Contact Added Successfully!\n");
                } else {
                    printf("Contact List is Full!\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No Contacts Found!\n");
                } else {
                    printf("\n===== CONTACT LIST =====\n");

                    for (int i = 0; i < count; i++) {
                        printf("\nContact %d\n", i + 1);
                        printf("Name  : %s\n", contacts[i].name);
                        printf("Phone : %s\n", contacts[i].phone);
                        printf("Email : %s\n", contacts[i].email);
                    }
                }
                break;

            case 3:
                printf("\nEnter Name to Search: ");
                scanf(" %[^\n]", searchName);

                {
                    int found = 0;

                    for (int i = 0; i < count; i++) {
                        if (strcmp(contacts[i].name, searchName) == 0) {
                            printf("\nContact Found!\n");
                            printf("Name  : %s\n", contacts[i].name);
                            printf("Phone : %s\n", contacts[i].phone);
                            printf("Email : %s\n", contacts[i].email);

                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Contact Not Found!\n");
                    }
                }
                break;

            case 4:
                printf("\nThank you for using Contact Management System!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}
