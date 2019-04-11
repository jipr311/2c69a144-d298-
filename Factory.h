#ifndef FACTORY_H
#define FACTORY_H

#include <QDebug>
#include "libs/nlohmann.hpp"
#include "BaseRequest.h"

#include "Robot.h"
#include "Point.h"

namespace json
{

class Factory : public BaseRequest
{
public:
    Factory();
    virtual nlohmann::json getChild() const override;
    friend void from_json(const nlohmann::json& j, Factory& p)
    {
        try
        {
            p.setR(j.at("robot").get<Robot>());
            p.setP(j.at("point").get<Point>());
            p.setIsValid(true);
        }
        catch(nlohmann::json::exception& e)
        {
            qWarning() << "exc: " << e.what();
        }
    }
    Robot getR() const;
    void setR(const Robot &value);

    Point getP() const;
    void setP(const Point &value);

private:
    Robot r{};
    Point p{};


};

inline void to_json(nlohmann::json& j, const Factory& p)
{
    j["robot"] = p.getR();
    j["point"] = p.getP();
}
} //namespace json
#endif // FACTORY_H
