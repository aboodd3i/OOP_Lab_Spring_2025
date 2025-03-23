// Muhammad Abdullah | 24K 0977 | OOP Lab 07 | Question 02
#include <iostream>
#include <math.h>
using namespace std;

class Shape
{
protected:
    string position, color, borderThickness;

public:
    Shape(string position, string color, string borderThickness) : position(position), color(color), borderThickness(borderThickness)
    {
        cout << "\nCreating Shape...\n";
    }

    virtual void draw()
    {
        cout << "Drawing Shape";
    }

    virtual void calculateArea()
    {
        cout << "\nCalculating Area..";
    }

    virtual void calculatePerimeter()
    {
        cout << "\nCalculating Perimeter..";
    }
};

class Circle : private Shape
{
private:
    int radius, centreX, centreY;

public:
    Circle(string position, string color, string borderThickness, int radius, int centreX, int centreY) : Shape(position, color, borderThickness), radius(radius), centreX(centreX), centreY(centreY)
    {
        cout << "\nCircle Created!\n";
    }

    void draw() override
    {
        cout << "Drawing a Circle!\n";
    }

    void calculateArea() override
    {
        cout << "The area of the circle is " << radius * radius * 3.14;
    }

    void calculatePerimeter() override
    {
        cout << "\nThe perimeter of the circle is " << 2 * 3.14 * radius;
    }
};

class Rectangle : private Shape
{
private:
    int height, width, topLeftPosition;

public:
    Rectangle(string position, string color, string borderThickness, int height, int width, int topLeftPosition) : Shape(position, color, borderThickness), height(height), width(width), topLeftPosition(topLeftPosition)
    {
        cout << "\nRectangle Created!\n";
    }

    void draw() override
    {
        cout << "\nDrawing a Rectangle!";
    }

    void calculateArea() override
    {
        cout << "\nThe area of the Rectangle is " << height * width;
    }

    void calculatePerimeter() override
    {
        cout << "\nThe perimeter of the Rectangle is " << (2 * height) + (2 * width);
    }
};

class Triangle : private Shape
{
private:
    int base, height, hypotenuse;

public:
    Triangle(string position, string color, string borderThickness, int height, int base) : Shape(position, color, borderThickness), height(height), base(base)
    {
        cout << "\nTriangle Created!";
    }

    void draw() override
    {
        cout << "\nDrawing a Triangle!";
    }

    void calculateArea() override
    {
        cout << "\nThe area of the Triangle is " << (height * base) / 2;
    }

    void calculatePerimeter() override
    {
        hypotenuse = sqrt((base * base) + (height * height));
        cout << "\nIn this case, we're assuming that the triangle is an eqilateral triangle." << endl
             << "It's perimeter is " << 2 * hypotenuse + base;
    }
};

int main()
{

    Circle circle1("0,0", "Blue", "2 pt", 5, 0, 0);
    Rectangle rectangle1("0,0", "Red", " 3 pt", 5, 12, 6);
    Triangle triangle1("0,0", "Yellow", "1 pt", 12, 6);

    cout << "\n\n--- TESTING FOR CIRCLE ---\n\n";
    circle1.draw();
    circle1.calculateArea();
    circle1.calculatePerimeter();

    cout << "\n\n--- TESTING FOR RECTANGLE ---\n\n";
    rectangle1.draw();
    rectangle1.calculateArea();
    rectangle1.calculatePerimeter();

    cout << "\n\n--- TESTING FOR TRIANGLE ---\n\n";
    triangle1.draw();
    triangle1.calculateArea();
    triangle1.calculatePerimeter();
}
