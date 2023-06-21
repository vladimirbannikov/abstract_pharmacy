#ifndef ARCHITECTURE_RECEIPTITEMCREATOR_H
#define ARCHITECTURE_RECEIPTITEMCREATOR_H

#include "../ItemCreator.h"
#include "ReceiptItem.h"

class ReceiptItemCreator: public ItemCreator{
public:
    ReceiptItemCreator() = default;
    std::shared_ptr<Item> CreateItem(
        int32_t id, userver::storages::postgres::ClusterPtr pg_cluster) override;
};


#endif
