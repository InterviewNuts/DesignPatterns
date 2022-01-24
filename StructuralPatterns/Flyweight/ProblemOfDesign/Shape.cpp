#include<string>
#include<iostream>
using namespace std;

class Shape
{
private:

public:
    virtual void draw() = 0;
};

class Circle :public Shape
{
    string label;
    int radius;
    string lineColor;
    string fillColor;
public:

    void setRadius(int l) { radius = l; }
    int getRadius() { return radius; }

    void setlineColor(string l) { lineColor = l; }
    string getBreadth() { return lineColor; }

    void setfillColor(string l) { fillColor = l; }
    string getfillColor() { return fillColor; }


    Circle() :label("Circle") {}
    void draw()
    {
        cout << " Label = " << label << " Radius = " << radius << " Line Color = " << lineColor << \
            " Fill Color =" << fillColor << endl;
    }
};
class Rectangle :public Shape
{
    string label;
    int length;
    int breadth;
    string fillStyle;
public:
    Rectangle() :label("Rectangle") {}
    void setLength(int l) { length = l; }
    int getLength() { return length; }

    void setBreadth(int l) { breadth = l; }
    int getBreadth() { return breadth; }

    void setfillStyle(string l) { fillStyle = l; }
    string getfillStyle() { return fillStyle; }

    void draw()
    {
        cout << " Label = " << label << " Length = " << length << " Breadth  = " << breadth << \
            " Fill Style =" << fillStyle << endl;
    }
};