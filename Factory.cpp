#include "Factory.h"

namespace json
{

Factory::Factory() : BaseRequest()
{

}

nlohmann::json Factory::getChild() const
{
 return *this;
}

Robot Factory::getR() const
{
    return r;
}

void Factory::setR(const Robot &value)
{
    r = value;
}

Point Factory::getP() const
{
    return p;
}

void Factory::setP(const Point &value)
{
    p = value;
}
} //namespace json
