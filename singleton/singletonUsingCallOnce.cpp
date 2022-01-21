/// singletonCallOnce.cpp

#include <chrono>
#include <iostream>
#include <future>
#include <mutex>
#include <thread>

constexpr auto tenMill = 10000000;

class MySingleton {
public:
    void print()
    {
        std::cout << " singleton Print called\n";
    }
    static MySingleton& getInstance() {
        std::call_once(initInstanceFlag, &MySingleton::initSingleton);
        // volatile int dummy{};
        return *instance;
    }
private:
    MySingleton() { std::cout << " sinfgleton cotr called \n"; }
    ~MySingleton() = default;
    MySingleton(const MySingleton&) = delete;
    MySingleton& operator=(const MySingleton&) = delete;

    static MySingleton* instance;
    static std::once_flag initInstanceFlag;

    static void initSingleton() {
        instance = new MySingleton;
    }
};

MySingleton* MySingleton::instance = nullptr;
std::once_flag MySingleton::initInstanceFlag;

std::chrono::duration<double> getTime() {

    auto begin = std::chrono::system_clock::now();
    for (size_t i = 0; i <= tenMill; ++i) {
        MySingleton::getInstance();
    }
    return std::chrono::system_clock::now() - begin;

};

int main() {

    auto fut1 = std::async(std::launch::async, MySingleton::getInstance);
    auto fut2 = std::async(std::launch::async, MySingleton::getInstance);
    auto fut3 = std::async(std::launch::async, MySingleton::getInstance);
    auto fut4 = std::async(std::launch::async, MySingleton::getInstance);

    fut1.get().print();
    fut2.get().print();

    //std::cout << total.count() << std::endl;

}