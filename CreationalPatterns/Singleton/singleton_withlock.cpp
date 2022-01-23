
#include <chrono>
#include <iostream>
#include <future>
#include <mutex>
using namespace std;
std::mutex mu;

class Singleton
{
public:
    static Singleton* getInstance()
    {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> guard(mu);
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;

    }

    void print()
    {
        cout << " singleton Print called\n";
    }
private:
    // delete copy and move constructors and assign operators
    Singleton(Singleton const&) = delete;             // Copy construct
    //Singleton(Singleton&&) = delete;                  // Move construct
    Singleton& operator=(Singleton const&) = delete;  // Copy assign
    //Singleton& operator=(Singleton&&) = delete;      // Move assign
    Singleton() = default;
    ~Singleton() = default;


    static  Singleton* instance;
};

Singleton* Singleton::instance = nullptr;



int main() {

    Singleton::getInstance()->print();
}