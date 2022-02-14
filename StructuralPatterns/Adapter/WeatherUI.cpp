/*
The main difference:

Class Adapter uses inheritance and can only wrap a class. It cannot wrap an interface since by definition it must derive from some base class.

Object Adapter uses composition and can wrap classes or interfaces, or both. It can do this since it contains, as a private, encapsulated member, the class or interface object instance it wraps.
*/

#include"WeatherAdapter.cpp"

//This is a target class 
class WeatherUI
{
    WeatherAdaper adapter;
public:
    int findTemparature(int pin)
    {
        return adapter.findTemparature(pin);
    }

};

int main()
{
    // {110001, "Delhi"},
    // { 752103,"Bhubaneswara" },
    // { 400067,"Mumbai" },
    // { 600040,"Chennai" },
    // { 380001 ,"Ahmedabad " },
    // { 700003,"Kolkata" },
    WeatherUI ui;
    cout << ui.findTemparature(400067) << "\n";

    return 0;
}
