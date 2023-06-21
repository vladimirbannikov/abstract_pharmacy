#ifndef ARCHITECTURE_USER_H
#define ARCHITECTURE_USER_H

#include <string>
#include "AccountConstants.h"
#include "../userver_headers.h"

class Account {
public:
    virtual ~Account() = default;
    virtual userver::formats::json::Value GetData() const = 0;
    virtual accounts::Type GetType() const = 0;
    // enum GetType
};


#endif //ARCHITECTURE_USER_H
