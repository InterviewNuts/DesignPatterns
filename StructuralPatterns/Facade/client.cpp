#include"OrderFacade.cpp"

int main()
{
    OrderFacade of;
    try {
        of.processOrder(110);
    }

    catch (const std::invalid_argument& e)
    {
        cout << e.what() << "\n";
        of.processOrder(10);
    }
    catch (exception e)
    {
        cout << e.what() << "\n";
    }
    return 0;
}