#include<iostream>
#include<memory>
#include <stdexcept>
#include"CheckStock.cpp"
#include"PlaceOrder.cpp"
#include"ShipOrder.cpp"

class OrderFacade
{
    std::unique_ptr <ChekStock> chkStock = std::make_unique<ChekStock>(25);;
    std::unique_ptr <PlaceOrder> placeOrd = std::make_unique<PlaceOrder>();
    std::unique_ptr <ShipOrder> shipOrd = std::make_unique<ShipOrder>();
public:
    OrderFacade() = default;
    void processOrder(int ordQty)
    {
        if (this->chkStock->ChekOrderedStock(ordQty))
        {
            int ordId = this->chkStock->generateOrdId();
            this->placeOrd->placeMyOrder(ordId);
            this->shipOrd->shipMyOrder(ordId);
        }
        else {
            //cout << " Please reduce the ord qty as we dont have sufficint stock available\n";
            throw std::invalid_argument("ord qty is Higher, pleas order less qty");;
        }

    }
};
