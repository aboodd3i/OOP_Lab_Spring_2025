#include <iostream>
using namespace std;

class Media {
    public:
    string title, publicationDate, uniqueID, publisher;
    bool isCheckedOut;

    Media(string t, string pDate, string id, string pub)
        : title(t), publicationDate(pDate), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
        << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher
        << "\nStatus: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out.\n";
        } else {
            cout << title << " is already checked out.\n";
        }
    }

    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned.\n";
        } else {
            cout << title << " was not checked out.\n";
        }
    }

    string getTitle() {
        return title; 
    }

    string getPublicationDate() { 
        return publicationDate; 
    }

    virtual string getAuthorOrDirector() { 
        return ""; 
    } 

    virtual ~Media() {}
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;

    public:
    Book(string t, string pDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
    }

    string getAuthorOrDirector() override {
        return author; 
    }
};

class DVD : public Media {
    string director;
    int duration;
    float rating;

    public:
    DVD(string t, string pDate, string id, string pub, string dir, int dur, float rate)
        : Media(t, pDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " min\nRating: " << rating << endl;
    }

    string getAuthorOrDirector() override { 
        return director; 
    }
};


class CD : public Media {
    string artist, genre;
    int numberOfTracks;

    public:
    CD(string t, string pDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};

void searchMedia(string title, Media** items) {
    cout << "\nSearching for media with title: " << title << endl;
    for (int i = 0; i < 3; i++) {
        if (items[i]->getTitle() == title) {
            items[i]->displayInfo();
            return;
        }
    }
    cout << "No media found with the title '" << title << "'.\n";
}

void searchMediaByAuthorOrDirector(string name, Media** items) {
    cout << "\nSearching for media by: " << name << endl;
    for (int i = 0; i < 3; i++) {
        if (items[i]->getAuthorOrDirector() == name) {
            items[i]->displayInfo();
            return;
        }
    }
    cout << "No media found by '" << name << "'.\n";
}

void searchMediaByYear(string year, Media** items) {
    cout << "\nSearching for media published in year: " << year << endl;
    for (int i = 0; i < 3; i++) {
        if (items[i]->getPublicationDate() == year) {
            items[i]->displayInfo();
            return;
        }
    }
    cout << "No media found published in '" << year << "'.\n";
}


int main() {
    Book book("C++ Programming", "2022", "B001", "TechPub", "Bjarne Stroustrup", "978-0321563842", 800);
    DVD dvd("Inception", "2010", "D002", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD cd("Thriller", "1982", "C003", "Epic Records", "Michael Jackson", 9, "Pop");

    Media* items[] = {&book, &dvd, &cd};

    searchMedia("Inception", items);
    searchMediaByAuthorOrDirector("Bjarne Stroustrup", items);
    searchMediaByYear("1982", items);
}