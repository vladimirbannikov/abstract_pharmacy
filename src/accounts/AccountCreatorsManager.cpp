#include "AccountCreatorsManager.h"

const userver::storages::postgres::Query CountOfUsersInTable{
    "SELECT COUNT(id) "
    "FROM $1 "
    "WHERE id = $2",
    userver::storages::postgres::Query::Name{"count-of-users-in-table"}};

AccountCreatorsManager::AccountCreatorsManager() {
  _tables_to_search = {accounts::table_names::user_table};
}

std::shared_ptr<AccountCreator> AccountCreatorsManager::GetAccountCreator(
    int32_t id, userver::storages::postgres::ClusterPtr pg_cluster) {
  AccountTypesManager accountTypesManager;
  accounts::Type type =
      accountTypesManager.GetAccountTypeFromTableName(SearchTableName(id, pg_cluster));
  return accountTypesManager.GetCreator(type);
}
std::string AccountCreatorsManager::SearchTableName(
    int32_t id, userver::storages::postgres::ClusterPtr pg_cluster) {
  for (auto name : _tables_to_search) {
    auto result = pg_cluster->Execute(
        userver::storages::postgres::ClusterHostType::kSlave, name, id);
    if (result.AsSingleRow<int>() == 0)
      return name;
  }
  throw "User not found";
}
