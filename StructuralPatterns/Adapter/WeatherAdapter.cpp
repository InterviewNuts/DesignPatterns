#include"WeatherFinder.cpp"
#include<map>
class WeatherAdaper
{
    map<int, string>pinCode{
        {110001,"Delhi"},
        {752103,"Bhubaneswara"},
        {400067,"Mumbai"},
        {600040,"Chennai"},
        {380001 ,"Ahmedabad "},
        {700003,"Kolkata"},
    };
    WeatherFinderImpl finder;

public:
    int findTemparature(int pin)
    {
        //! actual conversion haapen here in the adapter class
        return finder.find(pinCode[pin]);
    }

};