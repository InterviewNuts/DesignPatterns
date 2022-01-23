#include<iostream>
using namespace std;

//! This is a simple prototype pattern examples. In C++ term, it is a implementation of Copy constructor.

class MemberShip
{
    bool isMemberRegisted;
public:
    MemberShip() = default;
    MemberShip(bool yes = false) :isMemberRegisted(yes)
    {

    }
    bool getMemberRegisted() { return isMemberRegisted; }
    //! intentionaly left blank. Y
    //! you can fill it as per your requirement. Just an example of deep copy
};
class GameApp
{
private:
    int id;
    string name;
    MemberShip* member;
public:
    GameApp() = default;
    GameApp(int id, string name, MemberShip* m)
    {
        this->id = id;
        this->name = name;
        this->member = new MemberShip(true);
    }
    //! deep copy implementattion ( it is the copy cotr )
    GameApp(const GameApp& GA)
    {
        this->id = GA.id;
        this->name = GA.name;
        this->member = new MemberShip(true);
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


    MemberShip getMemberShip()
    {
        return member;
    }

    // void setId(MemberShip & m)
    // {
    //     this->member=m;
    // }


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