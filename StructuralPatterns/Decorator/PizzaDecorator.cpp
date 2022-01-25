/**
 * @file PizzaDecorator.cpp
 * @author Haramohan Sahu (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-25
 *
 * @copyright Copyright (c) 2022
 *
 */
#include<iostream>
using namespace std;

/*
Component — Interface for objects that can have responsibilities added to them dynamically.
*/
//! Component
class Pizza
{
public:
    virtual void back() = 0;
};

//ConcreteComponent — Defines an object to which additional responsibilities( in this case toppings) can be added.
//! This is normal pizza , we can add some topping on it
class PlainPizza : public Pizza
{
public:
    virtual void back()
    {
        cout << " Plai Pizza ordered!!! " << endl;
    }

};

//! Decorator — Maintains a reference to a Component object and defines an interface that conforms to 
//! Component’s interface.
class PizzaDecorator : public Pizza
{
    Pizza* pizza;
public:
    PizzaDecorator(Pizza* p) :pizza(p) {

    }
    virtual void back()
    {
        pizza->back();
        // blank
    }

};

//! Concrete Decorators — Concrete Decorators extend the functionality of the component 
//! by adding state or adding behavior
class VeggiePizzaDecorator : public PizzaDecorator
{

public:
    VeggiePizzaDecorator(Pizza* p) :PizzaDecorator(p) {

    }
    virtual void back()
    {
        PizzaDecorator::back();
        cout << " Veggie topping is added tp Plain Pizza!!!\n";

    }

};
//! Concrete Decorators — Concrete Decorators extend the functionality of the component 
//! by adding state or adding behavior
class CheesePizzaDecorator : public PizzaDecorator
{

public:
    CheesePizzaDecorator(Pizza* p) :PizzaDecorator(p) {

    }
    virtual void back()
    {
        PizzaDecorator::back();
        cout << " Cheese topping is added tp Plain Pizza!!!\n";

    }

};


//! Now test decorator pattern

int main()
{
    // Pizza* p = new PlainPizza();
    // p->back();
    // //! Now we can add some toppoing to my plain pizza
    // Pizza* veggiePizza = new VeggiePizzaDecorator(new PlainPizza());
    // veggiePizza->back();

  //! Now we can add some toppoing to my plain pizza
    Pizza* veggiePizza = new CheesePizzaDecorator(new VeggiePizzaDecorator(new PlainPizza()));
    veggiePizza->back();
    return 0;
}