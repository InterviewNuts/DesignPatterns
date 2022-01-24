
#include "shapeFactory.cpp"
class PaintApp
{
public:
    void render(int numOfTimes)
    {
        shapeFactory factory;
        Shape* shape = nullptr;
        for (int i = 0;i < numOfTimes;i++)
        {
            if ((i % 2) == 0)
            {
                shape = factory.getShape("Circle");
                shape->draw(i + 2, "RED", "WHITE");
            }
            else {
                shape = factory.getShape("Rectangle");
                shape->draw(i, i + 1, "Yellow");;
            }
        }
    }

};