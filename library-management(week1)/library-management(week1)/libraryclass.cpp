#include <iostream> // Include input/output stream library
#include <vector>   // Include vector library
#include <string>   // Include string library

using namespace std; // Use the standard namespace
// Define Book class
class Book {
    string title; // Title of the book
    string author; // Author of the book
    int id; // Unique identifier for the book
public:
    // Constructor to initialize the book with title, author, and id
    Book(string t, string a, int i) : title(t), author(a), id(i) {}

    // Getters to retrieve book details
    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getId() { return id; }
};

// Define Library class to manage books
class Library {
    vector<Book> books; // Vector to store Book objects
public:
    // Add book to library
    void addBook(Book b) {
        books.push_back(b); // Add the book to the vector
    }

    // Search book by title
    Book* searchBook(string title) {
        for (int i = 0; i < books.size(); ++i) { // Iterate through the books vector
            if (books[i].getTitle() == title) { // If title matches
                return &books[i]; // Return a pointer to the book
            }
        }
        return nullptr; // Book not found, return nullptr
    }

    // Other functionalities such as removing books, checking availability, etc., can be added similarly
};

int main() {
    // Test your code here

    // Create a Library object
    Library library;

    // Add some books to the library
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 2));
    // Add more books...

    // Search for a book by title
    Book* book = library.searchBook("To Kill a Mockingbird");
    if (book != nullptr) { // If book is found
        cout << "Book found: " << book->getTitle() << " by " << book->getAuthor() << endl; // Print book details
    }
    else {
        cout << "Book not found!" << endl; // Print message if book is not found
    }

    return 0;
}
