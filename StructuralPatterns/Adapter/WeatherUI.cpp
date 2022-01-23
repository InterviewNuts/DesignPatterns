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