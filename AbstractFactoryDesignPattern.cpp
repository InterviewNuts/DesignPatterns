#include <iostream>
using namespace std;

#define SIMPLE_CAR 1
//#define LUXURY_CAR 1
class Car;
class Tyre;
class Body;
class CarFactory
{
protected:
    virtual Tyre *buildTyre() = 0;
    virtual Body *buildBody() = 0;

public:
    virtual Car *buildWholeCar() = 0;
};

class SimpleCarFactory : public CarFactory
{
protected:
    Tyre *buildTyre()
    {
        return new SimpleTyre();
    }
    Body *buildBody()
    {
        return new SimpleBody();
    }
};
class LuxuryCarFactory : public CarFactory
{
};

class Car
{
public:
    void printDetails();
};

class Tyre
{
};
class Body
{
};

int main()
{

#ifdef SIMPLE_CAR
    CarFactory *factory = new SimpleCarFactory;

#elif LUXURY_CAR
    CarFactory *factory = new LuxuryCarFactory;

#endif

    Car *car = factory->buildWholeCar();
    car->printDetails();

    return 0;
}