#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for books and users
typedef struct Book {
    int id;
    char title[100];
    char author[100];
    int available;
    struct Book* next;
} Book;

typedef struct User {
    int id;
    char name[100];
    struct User* next;
} User;

// Global head pointers
Book* bookHead = NULL;
User* userHead = NULL;

// Function to create a new book
Book* createBook(int id, char* title, char* author, int available) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->available = available;
    newBook->next = NULL;
    return newBook;
}

// Function to add a book to the list
void addBook(int id, char* title, char* author, int available) {
    Book* newBook = createBook(id, title, author, available);
    newBook->next = bookHead;
    bookHead = newBook;
    printf("Book added successfully.\n");
}

// Function to display all books
void displayBooks() {
    Book* temp = bookHead;
    if (!temp) {
        printf("No books available.\n");
        return;
    }
    printf("\nBooks in the Library:\n");
    while (temp) {
        printf("ID: %d, Title: %s, Author: %s, Available: %d\n", temp->id, temp->title, temp->author, temp->available);
        temp = temp->next;
    }
}

// Function to create a new user
User* createUser(int id, char* name) {
    User* newUser = (User*)malloc(sizeof(User));
    newUser->id = id;
    strcpy(newUser->name, name);
    newUser->next = NULL;
    return newUser;
}

// Function to add a user to the list
void addUser(int id, char* name) {
    User* newUser = createUser(id, name);
    newUser->next = userHead;
    userHead = newUser;
    printf("User added successfully.\n");
}

// Function to display all users
void displayUsers() {
    User* temp = userHead;
    if (!temp) {
        printf("No users registered.\n");
        return;
    }
    printf("\nRegistered Users:\n");
    while (temp) {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

// Function to borrow a book
void borrowBook(int bookId) {
    Book* temp = bookHead;
    while (temp) {
        if (temp->id == bookId) {
            if (temp->available > 0) {
                temp->available--;
                printf("Book borrowed successfully.\n");
                return;
            } else {
                printf("Book not available.\n");
                return;
            }
        }
        temp = temp->next;
    }
    printf("Book not found.\n");
}

// Function to return a book
void returnBook(int bookId) {
    Book* temp = bookHead;
    while (temp) {
        if (temp->id == bookId) {
            temp->available++;
            printf("Book returned successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Book not found.\n");
}

// Main function
int main() {
    int choice, id, available;
    char title[100], author[100], name[100];

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Add User\n");
        printf("4. Display Users\n");
        printf("5. Borrow Book\n");
        printf("6. Return Book\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book ID, title, author, and availability: ");
                scanf("%d", &id);
                getchar(); // Clear newline from buffer
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                fgets(author, 100, stdin);
                author[strcspn(author, "\n")] = 0;
                scanf("%d", &available);
                addBook(id, title, author, available);
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                printf("Enter user ID and name: ");
                scanf("%d", &id);
                getchar(); // Clear newline from buffer
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0;
                addUser(id, name);
                break;

            case 4:
                displayUsers();
                break;

            case 5:
                printf("Enter book ID to borrow: ");
                scanf("%d", &id);
                borrowBook(id);
                break;

            case 6:
                printf("Enter book ID to return: ");
                scanf("%d", &id);
                returnBook(id);
                break;

            case 7:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
