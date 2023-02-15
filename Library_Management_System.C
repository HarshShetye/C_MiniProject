#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for book details
typedef struct {
    char title[50];
    char author[50];
    int book_id;
    int quantity;
} Book;

// Define global variables
Book books[100];
int num_books = 0;

// Function to add a book
void add_book() {
    Book new_book;

    // Get book details from user
    printf("Enter book title: ");
    scanf("%s", new_book.title);
    printf("Enter book author: ");
    scanf("%s", new_book.author);
    printf("Enter book ID: ");
    scanf("%d", &new_book.book_id);
    printf("Enter quantity: ");
    scanf("%d", &new_book.quantity);

    // Add book to library
    books[num_books] = new_book;
    num_books++;
    printf("Book added successfully.\n");
}

// Function to search for a book by title
void search_book() {
    char search_title[50];
    int found = 0;

    // Get title to search for
    printf("Enter book title to search for: ");
    scanf("%s", search_title);

    // Search for book
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, search_title) == 0) {
            found = 1;
            printf("Title: %s\nAuthor: %s\nID: %d\nQuantity: %d\n", books[i].title, books[i].author, books[i].book_id, books[i].quantity);
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to remove a book by ID
void remove_book() {
    int remove_id;
    int found = 0;

    // Get ID to remove
    printf("Enter book ID to remove: ");
    scanf("%d", &remove_id);

    // Remove book
    for (int i = 0; i < num_books; i++) {
        if (books[i].book_id == remove_id) {
            found = 1;
            for (int j = i; j < num_books - 1; j++) {
                books[j] = books[j + 1];
            }
            num_books--;
            printf("Book removed successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to display all books
void display_books() {
    if (num_books == 0) {
        printf("No books in library.\n");
    } else {
        for (int i = 0; i < num_books; i++) {
            printf("Title: %s\nAuthor: %s\nID: %d\nQuantity: %d\n\n", books[i].title, books[i].author, books[i].book_id, books[i].quantity);
        }
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        // Display menu
        printf("\nLibrary Management System\n");
        printf("1. Add book\n");
        printf("2. Search book\n");
        printf("3. Remove book\n");
        printf("4. Display all books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                search_book();
                break;
            case 3:
                remove_book();
                break;
            case 4:
                display_books();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

