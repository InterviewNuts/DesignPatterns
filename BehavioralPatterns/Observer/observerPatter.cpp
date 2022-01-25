#include <iostream>
#include <vector>
using namespace std;

// class Observer;
class Subject {
    // 1. "independent" functionality
    vector <class Observer* > views;
public:
    void attach(Observer* obs) {
        views.push_back(obs);
    }
    void setVal(int val) {
        cout << " Event happend " << val << endl;
        notify();
    }
    void notify();
};

class Observer
{
    Subject* model;
public:
    virtual void update() = 0;
    Subject* getSub() { return model; }
    Observer(Subject* s)
    {
        model = s;
        model->attach(this);
    }

};

void Subject::notify()
{
    // for (int i = 0; i < views.size(); i++)
    //     views[i]->update();

    for (auto it : views) {
        it->update();
    }
}

class MyOpserver : public Observer
{
public:
    MyOpserver(Subject* s) :Observer(s)
    {

    }
    void update()
    {
        cout << " I am updated\n";
    }
};

int main()
{
    Subject* sub = new Subject();
    Observer* o = new MyOpserver(sub);
    Observer* o1 = new MyOpserver(sub);
    sub->setVal(9);
    return 0;

}