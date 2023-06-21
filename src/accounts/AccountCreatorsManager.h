#ifndef ARCHITECTURE_ACCOUNTCREATORSMANAGER_H
#define ARCHITECTURE_ACCOUNTCREATORSMANAGER_H

#include "AccountCreator.h"
#include "AccountTypesManager.h"

class AccountCreatorsManager {
    std::string SearchTableName(int32_t id, userver::storages::postgres::ClusterPtr pg_cluster);
    std::vector<std::string> _tables_to_search;
public:
    AccountCreatorsManager();
    std::shared_ptr<AccountCreator> GetAccountCreator(int32_t id, userver::storages::postgres::ClusterPtr pg_cluster);
};


#endif //ARCHITECTURE_ACCOUNTCREATORSMANAGER_H
