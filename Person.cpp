#include "Person.h"

namespace json
{
    Person::Person() : BaseRequest()
    {
    }

    std::string Person::getName() const
    {
        return name;
    }

    void Person::setName(const std::string &value)
    {
        name = value;
    }

    int Person::getAge() const
    {
        return age;
    }

    void Person::setAge(int value)
    {
        age = value;
    }

    nlohmann::json Person::getChild() const
    {
        return *this;
    }

} //namespace json
