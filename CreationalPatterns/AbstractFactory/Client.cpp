#include <iostream>
//#include"Car.h"
#include"CarFactory.h"
using namespace std;

#define SIMPLE_CAR 1
//#define LUXURY_CAR 1
/*#ifdef SIMPLE_CAR
    CarFactory* factory = new SimpleCarFactory();

#elif LUXURY_CAR
    CarFactory* factory = new LuxuryCarFactory();

#endif
*/
//! This class is the factory of factory. I should have made a separate class file ( .cpp file) for it.
class CarFactoryProducer
{
public:
    static CarFactory* produceCarFactory(string typeOfCarFactory)
    {
        if (typeOfCarFactory.compare("SIMPLE_CAR") == 0)
            return  new SimpleCarFactory();
        else if (typeOfCarFactory.compare("LUXURY_CAR") == 0)
            return new LuxuryCarFactory();
        else
            return  new SimpleCarFactory();
    }
};


int main()
{

    CarFactory* factory = CarFactoryProducer::produceCarFactory("SIMPLE_CAR");

    Car* car = factory->buildWholeCar();
    car->printDetails();

    factory = CarFactoryProducer::produceCarFactory("LUXURY_CAR");

    car = factory->buildWholeCar();
    car->printDetails();

    return 0;
}