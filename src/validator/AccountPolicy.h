#ifndef ARCHITECTURE_ACCOUNTPOLICY_H
#define ARCHITECTURE_ACCOUNTPOLICY_H

#include "../accounts/Account.h"
#include "../items//Item.h"
#include "ValidatorConstants.h"
#include <memory>

class AccountPolicy {
public:
    AccountPolicy() = default;
    virtual ~AccountPolicy() = default;
    virtual validator::ErrorCode Check(const std::shared_ptr<const Account> &account,
                                       const std::shared_ptr<const Item> &item,
                                       userver::storages::postgres::ClusterPtr pg_cluster) const = 0;
};


#endif //ARCHITECTURE_ACCOUNTPOLICY_H
