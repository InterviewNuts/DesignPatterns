#include<iostream>

using namespace std;
class WeatherFinder
{
public:
    virtual int find(string city) = 0;
};

class WeatherFinderImpl : public WeatherFinder
{
public:
    WeatherFinderImpl() = default;
    int find(string city)
    {
        if (!city.compare("Mumbai"))
        {
            return 22;
        }
        else if (!city.compare("Ahmedabad"))
        {
            return 24;
        }
        else if (!city.compare("Kolkata"))
        {
            return 21;
        }
        else if (!city.compare("Delhi"))
        {
            return 27;
        }
        else if (!city.compare("Chennai"))
        {
            return 30;
        }
        else if (!city.compare("Bhubaneswara"))
        {
            return 30;
        }
        else
            return 1000;
    }
};