#include "iostream"
#include "Book.h"
using namespace std;

Book::Book(string title, string author, string ISBN) : title(title), author(author), ISBN(ISBN) {}

cout << "displaying details of the Book: " << endl << "Author: " << Book::getAuthor() << endl << "Book Name: " << Book::getTitle() << endl << "ISBN: " << Book::getISBN() << endl;

string getTitle() { return title; }
string getAuthor() { return author; }
string getISBN() { return ISBN; }

