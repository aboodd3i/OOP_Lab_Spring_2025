// Muhammad Abdullah 24K0977 - OOP Lab 05 Question 06

#include <iostream>
#include <string>

using namespace std;

class Film
{
private:
    string filmTitle;
    string filmmaker;
    int runtime; // in minutes

public:
    Film()
    {
        filmTitle = "Untitled";
        filmmaker = "Unknown";
        runtime = 0;
    }

    Film(string title, string director, int duration)
    {
        filmTitle = title;
        filmmaker = director;
        runtime = duration;
    }

    void showDetails() const
    {
        cout << "Movie Name: " << filmTitle << endl;
        cout << "Directed by: " << filmmaker << endl;
        cout << "Duration: " << runtime << " minutes" << endl;
    }
};

class Theatre
{
private:
    Film *screenings;
    string theatreName;
    int currentCount;
    int capacity;

public:
    Theatre()
    {
        screenings = nullptr;
        theatreName = "Unnamed Theatre";
        currentCount = 0;
        capacity = 0;
    }

    Theatre(string name, int totalSeats)
    {
        theatreName = name;
        capacity = totalSeats;
        currentCount = 0;
        screenings = new Film[capacity];
    }

    void addFilm(const Film &f)
    {
        if (currentCount < capacity)
        {
            screenings[currentCount] = f;
            currentCount++;
        }
        else
        {
            cout << "Screening schedule full! Cannot add more movies." << endl;
        }
    }

    void showScreenings() const
    {
        cout << "Theatre: " << theatreName << endl;
        cout << "Number of Movies Currently Showing: " << currentCount << endl;
        cout << "Now Playing: " << endl;
        for (int i = 0; i < currentCount; i++)
        {
            screenings[i].showDetails();
        }
    }

    ~Theatre()
    {
        delete[] screenings;
    }
};

int main()
{
    Theatre cinema("Cineplex Grand", 4);

    Film film1("Interstellar", "Christopher Nolan", 169);
    Film film2("Inception", "Christopher Nolan", 148);
    Film film3("The Dark Knight", "Christopher Nolan", 152);
    Film film4("Dune: Part Two", "Denis Villeneuve", 166);

    cinema.addFilm(film1);
    cinema.addFilm(film2);
    cinema.addFilm(film3);
    cinema.addFilm(film4);

    cinema.showScreenings();

    return 0;
}
