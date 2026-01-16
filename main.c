#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    int issued;
};

int main() {
    struct Book b[4] = {
        {110, "Structure Programming Language", "Edsger W. Dijkstra", 0},
        {111, "General Knowledge", "Al Mamun", 0},
        {112, "Bangla", "Ishwar Chondro Vidyasagar", 0},
        {113, "ICT", "Mahbubur Rahman", 0}
    };

    int choice, i, bid, days, fine;

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Books\n");
        printf("2. View Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Books are already added in the system.\n");
        }

        else if (choice == 2) {
            for (i = 0; i < 4; i++) {
                printf("\nBook ID: %d", b[i].id);
                printf("\nBook Name: %s", b[i].name);
                printf("\nAuthor Name: %s", b[i].author);
                printf("\nStatus: %s\n", b[i].issued ? "Issued" : "Available");
            }
        }

        else if (choice == 3) {
            printf("Enter Book ID to issue: ");
            scanf("%d", &bid);
            for (i = 0; i < 4; i++) {
                if (b[i].id == bid && b[i].issued == 0) {
                    b[i].issued = 1;
                    printf("Book issued successfully.\n");
                    break;
                }
            }
        }

        else if (choice == 4) {
            printf("Enter Book ID to return: ");
            scanf("%d", &bid);
            printf("Enter number of days taken: ");
            scanf("%d", &days);

            for (i = 0; i < 4; i++) {
                if (b[i].id == bid && b[i].issued == 1) {
                    b[i].issued = 0;

                    if (days > 7) {
                        fine = (days - 7) * 20;
                        printf("Late return! Fine = %d TK\n", fine);
                    } else {
                        printf("Returned on time. No fine.\n");
                    }
                    break;
                }
            }
        }

        else if (choice == 5) {
            break;
        }

        else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
