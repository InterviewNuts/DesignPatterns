#ifndef CLASS_TYRE_H
#define CLASS_TYRE_H
#include<string>

class Tyre
{
protected:
    int t_presure;
    std::string t_name;
public:
    Tyre() = default;
    Tyre(std::string n, int presure) :t_name(n), t_presure(presure) {}

    std::string getTyreName() { return t_name; };
    int getTyrePresure() { return t_presure; };
};

class SimpleTyre :public Tyre
{
public:
    SimpleTyre() :Tyre("SimpleTire", 75) {}

};


class LuxuryTyre :public Tyre
{
public:
    LuxuryTyre() :Tyre("LuxuryTyre", 175) {}

};
#endif