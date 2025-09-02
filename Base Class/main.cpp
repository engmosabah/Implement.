#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Shape
{
protected:
    string name;
    string color;
    int id;
public:
    Shape(string n, string c, int i) : name(n), color(c), id(i)
    {

}
    virtual double calculateArea() const = 0;
    virtual void displayInfo() const
    {
        cout << "Shape ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Color: " << color << "\n";
    }

    virtual ~Shape()
    {

    }
};
class Circle : public Shape {
private:
    double radius;

public:
    Circle(string c, int i, double r) : Shape("Circle", c, i), radius(r) {}

    double calculateArea() const override
    {
        return M_PI * radius * radius;
    }

    void displayInfo() const override
    {
        Shape::displayInfo();
        cout << "Radius: " << radius << "\n";
        cout << "Area: " << calculateArea() << "\n\n";
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(string c, int i, double l, double w)
        : Shape("Rectangle", c, i), length(l), width(w)
        {

        }

    double calculateArea() const override
    {
        return length * width;
    }

    void displayInfo() const override
    {
        Shape::displayInfo();
        cout << "Length: " << length << ", Width: " << width << "\n";
        cout << "Area: " << calculateArea() << "\n\n";
    }
};

class Triangle : public Shape
 {
private:
    double base, height;

public:
    Triangle(string c, int i, double b, double h)
        : Shape("Triangle", c, i), base(b), height(h)
         {

         }

    double calculateArea() const override
    {
        return 0.5 * base * height;
    }

    void displayInfo() const override
    {
        Shape::displayInfo();
        cout << "Base: " << base << ", Height: " << height << "\n";
        cout << "Area: " << calculateArea() << "\n\n";
    }
};

int main()
 {
    vector<Shape*> shapes;

    shapes.push_back(new Circle("Red", 1, 5.0));
    shapes.push_back(new Rectangle("Blue", 2, 4.0, 6.0));
    shapes.push_back(new Triangle("Green", 3, 3.0, 7.0));


    for (auto s : shapes)
    {
        s->displayInfo();
    }

    for (auto s : shapes)
    {
        delete s;
    }

    return 0;
}
