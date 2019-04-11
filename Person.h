#ifndef PERSON_H
#define PERSON_H
#include "libs/nlohmann.hpp"
#include "BaseRequest.h"
namespace json
{

class Person : public BaseRequest
{
public:
    Person();
    std::string getName() const;
    void setName(const std::string &value);

    int getAge() const;
    void setAge(int value);
    virtual nlohmann::json getChild() const override;


private:
    std::string name{};
    int age{};
};

inline void to_json(nlohmann::json& j, const Person& p)
{
    j["name"] = p.getName();
    j["age"] = p.getAge();
}

inline void from_json(const nlohmann::json& j, Person& p)
{
    p.setName(j.at("name").get<std::string>());
    p.setAge(j.at("age").get<int>());
}

} //namespace json
#endif // PERSON_H
