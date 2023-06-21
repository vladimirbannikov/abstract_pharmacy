#include "UserPolicy.h"
#include "ReceiptPolicy.h"
#include "../ItemPolicyTypesManager.h"


validator::ErrorCode UserPolicy::Check(
        const std::shared_ptr<const Account> &account,
        const std::shared_ptr<const Item> &item,
    userver::storages::postgres::ClusterPtr pg_cluster) const{
    ItemPolicyTypesManager manager;
    auto itemPolicy = manager.GetItemPolicyFromTypes(account->GetType(), item->GetType());
    return itemPolicy->Check(account, item, pg_cluster);
}
