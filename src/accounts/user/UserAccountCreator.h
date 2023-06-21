#ifndef ARCHITECTURE_USERACCOUNTCREATOR_H
#define ARCHITECTURE_USERACCOUNTCREATOR_H

#include "../AccountCreator.h"
#include "UserAccount.h"

class UserAccountCreator : public AccountCreator {
public:
    UserAccountCreator() = default;
    std::shared_ptr<Account> CreateAccount(
        int32_t id, userver::storages::postgres::ClusterPtr pg_cluster) override;
};


#endif
