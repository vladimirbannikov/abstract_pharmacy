#ifndef ARCHITECTURE_ACCOUNTCREATOR_H
#define ARCHITECTURE_ACCOUNTCREATOR_H

#include "Account.h"
#include <memory>
#include "../userver_headers.h"

class AccountCreator {
public:
    AccountCreator() = default;
    virtual ~AccountCreator() = default;
    virtual std::shared_ptr<Account> CreateAccount(
        int32_t id, userver::storages::postgres::ClusterPtr pg_cluster) = 0;
};


#endif //ARCHITECTURE_ACCOUNTCREATOR_H
