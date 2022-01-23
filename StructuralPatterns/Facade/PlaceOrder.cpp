#include<iostream>
using namespace std;

class PlaceOrder
{
private:
    int ordQty = 0;
    int ordId = 0;
public:
    explicit PlaceOrder(int qty) :ordQty(qty)
    {
    }
    PlaceOrder() = default;
    ~PlaceOrder() = default;
    int getOrdQty()const { return this->ordQty; }
    void setOrdQty(int qty) { this->ordQty = qty; }
    int getOrdId()const { return this->ordId; }
    void setOrdId(int id) { this->ordId = id; }

    void placeMyOrder(int id)
    {
        std::cout << "My Order Id = " << id << " has beed place Successfully\n";
    }
};


//Unit test code
// int main()
// {
//     PlaceOrder ch;
//     ch.placeMyOrder(5);
// }