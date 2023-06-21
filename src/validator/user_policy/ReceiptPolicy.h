#ifndef ARCHITECTURE_RECEIPTPOLICY_H
#define ARCHITECTURE_RECEIPTPOLICY_H
#include "../ItemPolicy.h"
#include "../../accounts/user/UserAccount.h"

namespace user_policy {

    class ReceiptPolicy: public ItemPolicy {
    public:
        validator::ErrorCode Check(const std::shared_ptr<const Account> &account,
                                   const std::shared_ptr<const Item> &item,
                                userver::storages::postgres::ClusterPtr pg_cluster) const override;
    };
}


#endif
