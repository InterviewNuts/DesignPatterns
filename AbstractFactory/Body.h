#ifndef CLASS_BODY_H
#define CLASS_BODY_H
class Body
{
protected:
    int b_strength;
    std::string b_name;
public:
    Body() = default;
    Body(std::string n, int strength) :b_name(n), b_strength(strength) {}

    std::string getBodyName() { return b_name; }
    int getBodyStrength() { return b_strength; }
};

class SimpleBody :public Body
{
public:
    SimpleBody() :Body("SimpleBody", 705) {}

};


class LuxuryBody :public Body
{
public:
    LuxuryBody() :Body("LuxuryBody", 175) {}

};
#endif