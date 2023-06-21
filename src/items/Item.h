#ifndef ARCHITECTURE_ITEM_H
#define ARCHITECTURE_ITEM_H

#include "ItemConstants.h"
#include <string>

#include "../userver_headers.h"


class Item {
public:
    virtual ~Item() = default;
    virtual items::Type GetType() const = 0;
    virtual userver::formats::json::Value GetData() const = 0;
};


#endif //ARCHITECTURE_ITEM_H
