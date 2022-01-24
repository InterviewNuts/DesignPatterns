
#include"Shape.cpp"
#include<map>


class shapeFactory
{
private:
    map<string, Shape*>shapeMap;
public:
    Shape* getShape(string type)
    {
        Shape* shape = nullptr;
        if (shapeMap.find(type) != shapeMap.end())
        {
            return shapeMap[type];
        }
        else
        {
            if (type.compare("Circle") == 0)
            {
                shape = new Circle();
            }
            else if (type.compare("Rectangle") == 0)
            {
                shape = new Rectangle();
            }
            shapeMap[type] = shape;

            return shape;

        }
        return shape;
    }
    shapeFactory() = default;
    ~shapeFactory() = default;
};

