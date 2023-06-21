#ifndef ARCHITECTURE_ITEMPOLICY_H
#define ARCHITECTURE_ITEMPOLICY_H

#include "ValidatorConstants.h"
#include "../items/Item.h"
#include "../accounts/Account.h"
#include <memory>

class ItemPolicy {
public:
    ItemPolicy() = default;
    virtual ~ItemPolicy() = default;
    virtual validator::ErrorCode Check(const std::shared_ptr<const Account> &account,
                                       const std::shared_ptr<const Item> &item,
                                       userver::storages::postgres::ClusterPtr pg_cluster) const = 0;
};


#endif
