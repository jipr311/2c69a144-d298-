#ifndef ROBOT_H
#define ROBOT_H

#include "libs/nlohmann.hpp"
#include "BaseRequest.h"
#include <QDebug>

namespace json
{

class Robot : public BaseRequest
{
public:
    Robot();
    std::string getModelName() const;
    void setModelName(const std::string &value);

    virtual nlohmann::json getChild() const override;
    friend void from_json(const nlohmann::json& j, Robot& p)
    {
        try
        {
            p.setModelName(j.at("modelName").get<std::string>());
            p.setIsValid(true);
        }
        catch(nlohmann::json::exception& e)
        {
            qWarning() << "exc: " << e.what();
        }
    }

private:
    std::string modelName{};
};

inline void to_json(nlohmann::json& j, const Robot& p)
{
    j["modelName"] = p.getModelName();
}

} //namespace json
#endif // ROBOT_H
