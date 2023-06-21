#include "ReceiptPolicy.h"

validator::ErrorCode user_policy::ReceiptPolicy::Check(const std::shared_ptr<const Account> &account,
                                                       const std::shared_ptr<const Item> &item,
                                                       userver::storages::postgres::ClusterPtr pg_cluster) const {

  // конкретная реализация выбранной политики
  // делает свои запросы к бд, смотрит что надо

    return validator::ErrorCode::ITEM_IS_SPECIAL;
}
