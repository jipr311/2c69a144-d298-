#ifndef POINT_H
#define POINT_H

#include "libs/nlohmann.hpp"
#include "BaseRequest.h"
#include <QDebug>

namespace json
{

class Point : public BaseRequest
{
public:
    Point();


    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);
    virtual nlohmann::json getChild() const override;
    friend void from_json(const nlohmann::json& j, Point& p)
    {
        try
        {
            p.setX(j.at("x").get<int>());
            p.setY(j.at("y").get<int>());
            p.setIsValid(true);
        }
        catch(nlohmann::json::exception& e)
        {
            qWarning() << "exc: " << e.what();
        }
    }
private:
    int x{};
    int y{};
};

inline void to_json(nlohmann::json& j, const Point& p)
{
    j["x"] = p.getX();
    j["y"] = p.getY();
}



} //namespace json
#endif // POINT_H
