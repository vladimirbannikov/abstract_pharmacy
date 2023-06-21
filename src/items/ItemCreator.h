#ifndef ARCHITECTURE_ITEMCREATOR_H
#define ARCHITECTURE_ITEMCREATOR_H

#include <memory>
#include "Item.h"

class ItemCreator {
public:
    ItemCreator() = default;
    virtual ~ItemCreator() = default;
    virtual std::shared_ptr<Item> CreateItem(
        int32_t id, userver::storages::postgres::ClusterPtr pg_cluster) = 0;
};


#endif
