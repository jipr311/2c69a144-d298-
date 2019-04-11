#include "Robot.h"

namespace json
{

Robot::Robot() : BaseRequest()
{

}

nlohmann::json Robot::getChild() const
{
    return *this;
}

std::string Robot::getModelName() const
{
    return modelName;
}

void Robot::setModelName(const std::string &value)
{
    modelName = value;
}
} //namespace json
