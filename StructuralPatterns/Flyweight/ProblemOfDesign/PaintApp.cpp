
#include "Shape.cpp"
#include<vector>
class PaintApp
{
public:
    void render(int numOfTimes)
    {
        vector<Shape*>vec(numOfTimes);

        for (int i = 0;i < numOfTimes;i++)
        {
            if ((i % 2) == 0)
            {
                vec[i] = new Circle();
                static_cast<Circle*>(vec[i])->setRadius(i);
                static_cast<Circle*>(vec[i])->setlineColor("red");
                static_cast<Circle*>(vec[i])->setfillColor("White");
                vec[i]->draw();
            }
            else {
                vec[i] = new Rectangle();
                static_cast<Rectangle*>(vec[i])->setBreadth(i);
                static_cast<Rectangle*>(vec[i])->setLength(i + 2);
                static_cast<Rectangle*>(vec[i])->setfillStyle("Green");
                vec[i]->draw();
            }
        }
    }

};