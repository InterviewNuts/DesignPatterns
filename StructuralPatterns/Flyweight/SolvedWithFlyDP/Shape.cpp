#include<string>
#include<iostream>
using namespace std;

class Shape
{
private:
    int radius;
    string lineColor;
    string fillColor;
    int length;
    int breadth;
    string fillStyle;
public:
    virtual void draw(int length, int breadth, string fillStyle) {}
    virtual void draw(int radius, string lineColor, string fillColor) {}
};

class Circle :public Shape
{
    string label;

public:

    Circle() :label("Circle") {}
    void draw(int radius, string lineColor, string fillColor)
    {
        cout << " Label = " << label << " Radius = " << radius << " Line Color = " << lineColor << \
            " Fill Color =" << fillColor << endl;
    }
};
class Rectangle :public Shape
{
    string label;

public:
    Rectangle() :label("Rectangle") {}

    void draw(int length, int breadth, string fillStyle)
    {
        cout << " Label = " << label << " Length = " << length << " Breadth  = " << breadth << \
            " Fill Style =" << fillStyle << endl;
    }
};

// int main()
// {
//     Shape* s = new Circle();
//     s->draw(11, "red", "white");
// }