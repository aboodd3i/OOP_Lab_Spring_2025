#include <iostream>
using namespace std;

class Professor;
class Student;

class Course {
    public:
    string courseId, courseName;
    int credits;
    Professor* instructor;

    Course(string id, string name, int cr, Professor* prof)
        : courseId(id), courseName(name), credits(cr), instructor(prof) {}

    void registerStudent(Student& student);

    void displayCourseInfo();

    void CalculateGrades () {
        cout << "Calculating grades\n";
    }
};

class Person {
    public:
    string name, address, phoneNumber, email;
    int id;

    Person(string n, int i, string addr, string phone, string mail): name(n), id(i), address(addr), 
    phoneNumber(phone), email(mail) {}

    virtual void displayInfo() {
        cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address 
        << "\nPhone: " << phoneNumber << "\nEmail: " << email << "\n";
    }

    void updateInfo(string addr, string phone, string mail) {
        address = addr;
        phoneNumber = phone;
        email = mail;
    }
};

class Student : public Person {
    public:
    Course** coursesEnrolled;
    int numOfCourses;
    float GPA;
    int enrollmentYear;

    Student(string n, int i, string addr, string phone, string mail, float gpa, int year): Person(n, i, addr, phone, mail), 
    GPA(gpa), enrollmentYear(year), numOfCourses(0) {
        coursesEnrolled = nullptr;
    }

    ~Student () {
        delete [] coursesEnrolled;
    }

    void enrollCourse (Course* c) {
        Course** temp = new Course*[numOfCourses+1];
        temp[numOfCourses] = c;
        for (int i = 0; i < numOfCourses; i++) {
            temp[i] = coursesEnrolled[i];
        }
        delete [] coursesEnrolled;
        coursesEnrolled = temp;
        numOfCourses++;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "GPA: " << GPA << "\nEnrollment Year: " << enrollmentYear << endl;
        cout << "Courses Enrolled:\n";
        for (int i = 0; i < numOfCourses; i++) {
            cout << coursesEnrolled[i]->courseName << endl;
        }
    }
};

void Course::registerStudent(Student& student) {
    student.enrollCourse(this);
}

class Professor : public Person {
    public:
    string department;
    Course** coursesTaught;
    int numOfCourses;
    double salary;

    Professor(string n, int i, string addr, string phone, string mail, string dept, double sal)
    : Person(n, i, addr, phone, mail), department(dept), salary(sal), numOfCourses(0) {
        coursesTaught = nullptr;
    }

    ~Professor () {
        delete [] coursesTaught;
    }


    void assignCourse(Course* c) {
        Course** temp = new Course*[numOfCourses+1];
        temp[numOfCourses] = c;
        for (int i = 0; i < numOfCourses; i++) {
            temp[i] = coursesTaught[i];
        }
        delete [] coursesTaught;
        coursesTaught = temp;
        numOfCourses++;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: " << salary << endl;
        cout << "Courses Assigned:\n";
        for (int i = 0; i < numOfCourses; i++) {
            cout << coursesTaught[i]->courseName << endl;
        }
    }
};

class Staff : public Person {
    public:
    string department, position;
    double salary;
    Staff(string n, int i, string addr, string phone, string mail, string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: " << salary << "\n";
    }
};

void Course::displayCourseInfo () {
    cout << "Course: " << courseName << " (" << courseId << ")\nCredits: " << credits 
    << "\nInstructor: " << instructor->name << "\n";
}

int main() {
    Professor prof("Dr. Smith", 101, "123 Uni Ave", "1234567890", "smith@uni.edu", "CS", 80000);
    Student stud("Alice Johnson", 201, "456 Dorm St", "9876543210", "alice@uni.edu", 3.8, 2023);
    Staff staff("John Doe", 301, "789 Admin Blvd", "5551234567", "john@uni.edu", "Admin", "Manager", 50000);

    Course course("CS101", "Intro to Programming", 3, &prof);
    prof.assignCourse(&course);
    course.registerStudent(stud);

    cout << "--- Professor Info ---\n";
    prof.displayInfo();

    cout << "\n--- Student Info ---\n";
    stud.displayInfo();

    cout << "\n--- Staff Info ---\n";
    staff.displayInfo();

    cout << "\n--- Course Info ---\n";
    course.displayCourseInfo();
}