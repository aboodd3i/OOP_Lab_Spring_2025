#include "iostream"
#include "Book.h"
using namespace std;

int main() {
    Book book("1984", "Goerge Orwell", "123456789");
    cout << "displaying details of the Book: " << endl << "Author: " << Book::getAuthor() << endl << "Book Name: " << Book::getTitle() << endl << "ISBN: " << Book::getISBN() << endl;

}
