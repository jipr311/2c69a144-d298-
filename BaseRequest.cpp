#include "BaseRequest.h"
namespace json
{

BaseRequest::BaseRequest()
{

}

BaseRequest::~BaseRequest()
{

}

bool BaseRequest::getIsValid() const
{
    return isValid;
}

void BaseRequest::setIsValid(bool value)
{
    isValid = value;
}

nlohmann::json BaseRequest::getChunk() const
{
    nlohmann::json j;
    j["a"] = *this;
    return j;
}
} //namespace json
