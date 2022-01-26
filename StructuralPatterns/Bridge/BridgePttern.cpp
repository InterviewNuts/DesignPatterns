#include<iostream>
using namespace std;

class DrawingAPI;
//! Abstraction — Abstraction defines abstraction interface.
class Shape
{
public:
    virtual void draw() = 0;

};

//! AbstractionImp — Implements the abstraction interface using a reference to an object of type Implementor.
class CircleShape : public Shape
{
    DrawingAPI* m_drawingAPI;
public:
    CircleShape(DrawingAPI* m) :m_drawingAPI(m) {}
    virtual void draw();


};

//! Implementor — Implementor defines the interface for implementation classes. 
//! This interface does not need to correspond directly to the abstraction interface and can be very different. 
//! AbstractionImp provides an implementation in terms of operations provided by Implementor interface.

class DrawingAPI
{
public:
    DrawingAPI() = default;
    virtual void draw() = 0;

};

void CircleShape::draw()
{
    m_drawingAPI->draw();
}

//! ConcreteImplementor1, ConcreteImplementor2 — Implements the Implementor interface.
class circleDraw : public DrawingAPI
{
    int radius;
public:
    circleDraw() = default;
    circleDraw(int radius) :radius(radius)
    {

    }
    virtual void draw()
    {
        cout << " Circle drawn " << radius << "\n";
    }
};

class rectangleDraw : public DrawingAPI
{
    int length, breadth;
public:
    rectangleDraw() = default;
    rectangleDraw(int l, int b) :length(l), breadth(b) {}
    virtual void draw()
    {
        cout << " Rectangle drawn " << length << " : " << breadth << "\n";
    }

};


int main()
{

    Shape* shape = new CircleShape(new circleDraw(23));
    shape->draw();
    shape = new CircleShape(new rectangleDraw(3, 30));
    shape->draw();
}