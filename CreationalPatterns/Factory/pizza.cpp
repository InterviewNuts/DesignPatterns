
#include<iostream>
using namespace std;
class Pizza
{
public:
    virtual void prepare() = 0;
    virtual void back() = 0;
    virtual void cut() = 0;
};
class VeggiPizza :public Pizza
{
public:
    void prepare() {
        std::cout << " Preparing Veggi Pizza\n ";
    }
    void back() {
        std::cout << " Backing Veggi Pizza\n ";
    }
    void cut() {
        std::cout << " Cutting Veggi Pizza\n ";
    }
};
class CheesePizza :public Pizza
{
public:
    void prepare() {
        std::cout << " Preparing Cheese Pizza\n ";
    }
    void back() {
        std::cout << " Backing Cheese Pizza\n ";
    }
    void cut() {
        std::cout << " Cutting Cheese Pizza\n ";
    }
};