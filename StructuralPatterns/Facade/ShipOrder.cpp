#include<iostream>
using namespace std;
class ShipOrder
{
private:
    int ordId;
public:
    explicit ShipOrder(int id) :ordId(id)
    {
    }
    ShipOrder() = default;
    ~ShipOrder() = default;
    int getQty()const { return this->ordId; }
    void setQty(int id) { this->ordId = id; }
    void shipMyOrder(int id)
    {
        std::cout << "My Order Id = " << id << " has beed place Suvv==ccessfully\n";
    }
};