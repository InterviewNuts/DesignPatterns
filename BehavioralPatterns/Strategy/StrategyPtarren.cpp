#include <iostream>
using namespace std;

class SortingStrategy
{
public:
    SortingStrategy() = default;
    virtual void  sort() = 0;
};

class SelectionSort :public SortingStrategy
{
public:
    SelectionSort() = default;
    virtual void  sort()
    {
        cout << " Seletion sort executed here \n";
    }

};

class BubbleSort :public SortingStrategy
{
public:
    BubbleSort() = default;
    virtual void  sort()
    {
        cout << " Bubble sort executed here \n";
    }

};


class MergeSort :public SortingStrategy
{
public:
    MergeSort() = default;
    virtual void  sort()
    {
        cout << " Merge sort executed here \n";
    }

};


class Context
{
private:
    SortingStrategy* sortType;
public:

    Context(SortingStrategy* ss) :sortType(ss)
    {

    }
    void setContext(SortingStrategy* ss)
    {
        sortType = ss;
    }
    void execute()
    {
        sortType->sort();
    }


};


int main()
{
    SortingStrategy* select = new SelectionSort();
    //Sorting Strategy
    Context* context = new Context(select);
    context->execute();
    context->setContext(new MergeSort());
    context->execute();
    context->setContext(new BubbleSort());
    context->execute();
    return 0;
}