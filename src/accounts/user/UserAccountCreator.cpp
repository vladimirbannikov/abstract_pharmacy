#include "UserAccountCreator.h"

std::shared_ptr<Account> UserAccountCreator::CreateAccount(
    int32_t id, userver::storages::postgres::ClusterPtr pg_cluster) {

  // делаем запрос по id, получаем UserAccountDTO
  // если не найден - throw

  UserAccountDTO dto{1, "user1"};
  return std::make_shared<UserAccount>(dto);
}
