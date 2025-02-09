// In this question, i have assumed each month to consist of 30 days.
// I have made a 2d array of 13x31 (12 months, with 30 days each month)

#include <iostream>
#include <string>
using namespace std;

class Planner
{
private:
    int rows = 31, cols = 13;

    string **calendar;

public:
    Planner()
    {
        calendar = new string *[rows];
        for (int i = 0; i < rows; i++)
        {
            calendar[i] = new string[cols];
        }
    }

    void initialise()
    {
        string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for (int j = 1; j <= 12; j++)
        {
            calendar[0][j] = months[j - 1]; // filing the top most row with month names
        }

        for (int i = 1; i < rows; i++)
        {
            calendar[i][0] = to_string(i); // filling the left most column with dates
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                calendar[i][j] = "No Task"; // filling the rest of the array
            }
        }
    }

    void addTask(int date, int month, string task)
    {
        if (date < 1 || date > 30 || month < 1 || month > 12)
        {
            cout << "\nInvalid date and/or month. Exiting the program.\n";
            return;
        }
        calendar[month][date] = task;
        cout << "Task Added Successfully!" << endl
             << "Task Name: " << task << " Task Date: " << date << "/" << month << endl;
    }

    void removeTask(int date, int month)
    {
        if (date < 1 || date > 30 || month < 1 || month > 12)
        {
            cout << "\nInvalid date and/or month. Exiting the program.\n";
            return;
        }
        calendar[date][month] = "-";
        cout << "Task Removed Succesfully! " << date << "/" << month << " is now free.";
    }

    void displayTasks()
    {

        cout << "\nHere are all the tasks you have scheduled: \n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (calendar[i][j] != "-")
                {
                    cout << "Task Date: " << j << "/" << i << " - Task Name: " << calendar[i][j] << endl;
                }
            }
        }
    }
};

int main()
{

    cout << "\n\n--- TASK CALENDAR RECORDER ---\n\n";

    Planner myPlanner;
    myPlanner.initialise();
    while (true)
    {
        cout << "\n- Main Menu -\n";
        cout << "1. Add A Task" << endl
             << "2. Remove A Task" << endl
             << "3. Display Calendar" << endl
             << "4. Exit" << endl;
        cout << "Please enter your choice: ";
        int choice, date, month;
        string task;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nPlease enter the month number: ";
            cin >> month;
            cout << "\nPlease enter the date: ";
            cin >> date;
            cout << "\nPlease enter the task: ";
            cin.ignore();
            getline(cin, task);
            myPlanner.addTask(date, month, task);
            break;

        case 2:
            cout << "\nPlease enter the month number: ";
            cin >> month;
            cout << "\nPlease enter the date: ";
            cin >> date;
            myPlanner.removeTask(date, month);
            break;

        case 3:
            myPlanner.displayTasks();
            break;

        case 4:
            cout << "\nExiting the program. Thank You.";
            return 0;

        default:
            cout << "\nPlease enter the right choice.";
        }
    }

    return 0;
}
