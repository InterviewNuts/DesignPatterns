#include<iostream>
#include<thread>
using namespace std;
/*
Meyers Singleton
The beauty of the Meyers Singleton in C++11 is that it's automatically thread-safe.
That is guaranteed by the standard: Static variables with block scope.
The Meyers Singleton is a static variable with block scope, so we are done.


*/
class Singleton {
public:
    //In C++11, the following is guaranteed to perform thread - safe initialisation :
    static Singleton& Instance() {
        // Since it's a static variable, if the class has already been created,
        // it won't be created again.
        // And it **is** thread-safe in C++11.
        static Singleton myInstance;

        // Return a reference to our instance.
        return myInstance;
    }

    // delete copy and move constructors and assign operators
    Singleton(Singleton const&) = delete;             // Copy construct
    Singleton(Singleton&&) = delete;                  // Move construct
    Singleton& operator=(Singleton const&) = delete;  // Copy assign
    Singleton& operator=(Singleton&&) = delete;      // Move assign

    // Any other public methods.

protected:
    Singleton() {
        cout << " Singleton is called cotr\n";
        // Constructor code goes here.
    }

    ~Singleton() {
        // Destructor code goes here.
    }
    // And any other protected methods.
};



int main()
{
    thread t1(Singleton::Instance);
    thread t2(Singleton::Instance);
    t1.join();
    t2.join();
    return 0;
}