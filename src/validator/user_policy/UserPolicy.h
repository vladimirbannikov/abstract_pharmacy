#ifndef ARCHITECTURE_USERPOLICY_H
#define ARCHITECTURE_USERPOLICY_H

#include "../AccountPolicy.h"
#include "../../accounts/user/UserAccount.h"
#include "ReceiptPolicy.h"


class UserPolicy: public AccountPolicy {
public:
    UserPolicy() = default;
    validator::ErrorCode Check(const std::shared_ptr<const Account> &account,
                               const std::shared_ptr<const Item> &item,
                               userver::storages::postgres::ClusterPtr pg_cluster) const override;
};


#endif
