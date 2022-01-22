#ifndef CLASS_CAR_FACTORY_H
#define CLASS_CAR_FACTORY_H
#include"Tyre.h"
#include"Body.h"
#include"Car.h"
#include"Tyre.h"


class CarFactory
{
protected:
    virtual Tyre* buildTyre() = 0;
    virtual Body* buildBody() = 0;

public:
    virtual Car* buildWholeCar() = 0;
};

class SimpleCarFactory : public CarFactory
{
protected:
    Tyre* buildTyre()
    {
        return new SimpleTyre();
    }
    Body* buildBody()
    {
        return new SimpleBody();
    }
public:
    Car* buildWholeCar()
    {
        return new Car(buildBody(), buildTyre());
    }
};
class LuxuryCarFactory : public CarFactory
{
public:
    LuxuryCarFactory() = default;
protected:
    Tyre* buildTyre()
    {
        return new LuxuryTyre();
    }
    Body* buildBody()
    {
        return new LuxuryBody();
    }
public:
    Car* buildWholeCar()
    {
        return new Car(buildBody(), buildTyre());
    }
};

#endif