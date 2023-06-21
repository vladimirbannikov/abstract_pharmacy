#include "ReceiptItemCreator.h"

std::shared_ptr<Item> ReceiptItemCreator::CreateItem(
    int32_t id, userver::storages::postgres::ClusterPtr pg_cluster) {

    // делаем запрос по id, получаем ReceiptItemDTO
    // если не найден - throw

    ReceiptItemDTO dto{id, "receipt1"};
    return std::make_shared<ReceiptItem>(dto);
}
