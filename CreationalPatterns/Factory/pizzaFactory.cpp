#include"pizza.cpp"


class pizzaFactory
{
private:

public:
    static Pizza* OrderPizza(string type);
    pizzaFactory();
    ~pizzaFactory();
};

pizzaFactory::pizzaFactory()
{
}

pizzaFactory::~pizzaFactory()
{
}
Pizza* pizzaFactory::OrderPizza(string type)
{
    Pizza* pizza = nullptr;

    if (type.compare("veggi") == 0)
    {
        pizza = new VeggiPizza();
    }
    else if (type.compare("Cheese") == 0)
    {
        pizza = new CheesePizza();
    }
    /*
    //! this <=> is 3 way comparison introduced in c++20
    //! to run this code , while compiling use -std=c++20
    if (type <=> "veggi" == 0)
        pizza = new VeggiPizza();
    else if (type <=> "Cheese" == 0)
        pizza = new CheesePizza();
        */
    return pizza;


}