#include<iostream>
using namespace std;

//! This is a simple prototype pattern examples. In C++ term, it is a implementation of Copy constructor.

class GameApp
{
private:
    int id;
    string name;
public:
    GameApp() = default;
    GameApp(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    void playingGame()
    {
        std::cout << " Gamne is on by id = " << id << " name = " << name << endl;
    }
    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }
    void setId(int id)
    {
        this->id = id;
    }

    void setName(string name)
    {
        this->name = name;;
    }
};

/*
class racingGame :public GameApp
{
public:
    racingGame(int id, string name)
    {
        setId(id);
        setName(name);
    }

};

class shootingGame :public GameApp
{
public:
    shootingGame(int id, string name)
    {
        setId(id);
        setName(name);
    }

};
*/