#ifndef BASEREQUEST_H
#define BASEREQUEST_H

#include "libs/nlohmann.hpp"

namespace json
{

class BaseRequest
{
public:
    BaseRequest();
    virtual ~BaseRequest();
    bool getIsValid() const;

    nlohmann::json getChunk() const;
    virtual nlohmann::json getChild() const = 0;
    explicit operator bool()
    {
        return isValid;
    }
protected:
    void setIsValid(bool value);
private:
    bool isValid{false};
};

inline void to_json(nlohmann::json& j, const BaseRequest& p)
{
    j = p.getChild();
}

} //namespace json
#endif // BASEREQUEST_H
