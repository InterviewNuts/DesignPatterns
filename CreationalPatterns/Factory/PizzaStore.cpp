#include"pizzaFactory.cpp"

int main()
{

    Pizza* p = pizzaFactory::OrderPizza("veggi");
    p->prepare();
    p->back();
    p->cut();
    return 0;
}