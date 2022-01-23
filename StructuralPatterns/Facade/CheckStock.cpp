#include<iostream>

using namespace std;
class ChekStock
{
private:
    int quantity = 20;
public:
    ChekStock(int qty) :quantity(qty)
    {
    }
    int generateOrdId()
    {
        return std::rand();
    }
    ChekStock() = default;
    ~ChekStock() = default;
    int getQty()const { return this->quantity; }
    void setQty(int qty) { this->quantity = qty; }
    bool ChekOrderedStock(int q)
    {
        return (q < this->quantity) ? true : false;
    }
};

//Unit test code
// int main()
// {
//     ChekStock ch;
//     //cout << ch.getQty() << "\n";
//     cout << std::rand() << "\n";
// }