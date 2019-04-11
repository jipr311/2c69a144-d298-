#include "Point.h"
namespace json
{

Point::Point() : BaseRequest()
{

}

int Point::getX() const
{
    return x;
}

void Point::setX(int value)
{
    x = value;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int value)
{
    y = value;
}

nlohmann::json Point::getChild() const
{
    return *this;
}

} //namespace json
