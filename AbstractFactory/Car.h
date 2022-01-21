#ifndef CLASS_CAR_H
#define CLASS_CAR_H
#include"Tyre.h"
#include"Body.h"
#include<iostream>
class Car
{
    Body* body;
    Tyre* tyre;
public:
    Car(Body* b, Tyre* t) :body(b), tyre(t)
    {

    }
    void printDetails()
    {
        std::cout << " Body Name :" << body->getBodyName() << " : " << "Body Strength : " << body->getBodyStrength() << "\n";
        std::cout << " Tyre Name :" << tyre->getTyreName() << " : " << "Tyre Presure : " << tyre->getTyrePresure() << "\n";
    }
};
#endif