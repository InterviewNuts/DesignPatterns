/**
 * @file ProxyPattern.cpp
 * @author Haramohan Sahu (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include<iostream>
#include<vector>
using namespace std;

class Order;
//! Subject — Interface implemented by the RealSubject and representing its services. 
//! The interface must be implemented by the Proxy as well so that the Proxy can be used in any location where 
//! the RealSubject can be used.
//! This i sthe subject class
class Customer
{
public:

    virtual vector<Order> getOrders() = 0;
    virtual int getID() = 0;
    virtual void setOrders(Order& o) {}

};

class Order
{
private:
    int ordId = 0;
    string ordName = "";
    int qty = 0;
public:

    Order(int id, int q, string name) :ordId(id), qty(q), ordName(name)
    {

    }
    Order() = default;
    ~Order() = default;

    int getOrdId()
    {
        return ordId;
    }
    void setOrdId(int q)
    {
        ordId = q;
    }
    string getOrdName()
    {
        return ordName;
    }
    void setOrdName(string n)
    {
        ordName = n;
    }

    void setOrdId(string n)
    {
        ordName = n;
    }

    int getOrdQty()
    {
        return qty;
    }
    void setOrdQty(int q)
    {
        qty = q;
    }
};

//! •	RealSubject — the real object that the proxy represents.
class CustomerImpl : public Customer
{
    int CustId = 123;
    vector<Order> orders;
public:
    CustomerImpl(int id)
    {
        // Read the order from DB( ORM Frameworks comes to the picture here)
        CustId = id;
    }
    vector<Order> getOrders()
    {
        return orders;
    }
    int getID()
    {
        return CustId;
    }
    void setOrders(Order& o)
    {
        orders.push_back(o);
    }

};

/*
1. Maintains a reference that allows the Proxy to access the RealSubject.
2. Implements the same interface implemented by the RealSubject so that the Proxy can be substituted for the RealSubject.
3. Controls access to the RealSubject and may be responsible for its creation and deletion.
4. Other responsibilities depend on the kind of proxy.

*/

class CustomerImplProxy : public Customer
{
    int CustId = 123;
    vector<Order> orders;
    Customer* cust = new CustomerImpl(123);
public:
    CustomerImplProxy()
    {
        // Read the order from DB( ORM Frameworks comes to the picture here)
        CustId = cust->getID();
        setOrders();
    }
    vector<Order> getOrders()
    {
        return cust->getOrders();
    }


    void setOrders()
    {
        Order ord;
        ord.setOrdId(90);
        ord.setOrdQty(5);
        ord.setOrdName("IPONE");
        cust->setOrders(ord);

        Order o;
        o.setOrdId(190);
        o.setOrdQty(15);
        o.setOrdName("NOKIA");
        cust->setOrders(o);

    }

    int getID()
    {
        return CustId;
    }
};



int main()
{
    // Customer* cust = new CustomerImpl(123);
    // cout << " Customet Id = " << cust->getID() << "\n";
    // cout << cust->getOrders().size() << "\n";


    //! use proxy
    Customer* proxy = new CustomerImplProxy();
    cout << " Customet proxy Id = " << proxy->getID() << "\n";
    cout << proxy->getOrders().size() << "\n";


    return 0;
}