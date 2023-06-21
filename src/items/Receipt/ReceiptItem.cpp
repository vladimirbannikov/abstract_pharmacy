#include "ReceiptItem.h"

userver::formats::json::Value Serialize(
    const ReceiptItemDTO& data) {
  userver::formats::json::ValueBuilder jsonCourier;
  jsonCourier["id"] = data.id;
  jsonCourier["name"] = data.name;
  return jsonCourier.ExtractValue();
}

items::Type ReceiptItem::GetType() const{
    return _type;
}

ReceiptItem::ReceiptItem(const ReceiptItemDTO &data): _data(data) {}

ReceiptItem::ReceiptItem(const ReceiptItem &item) {
    this->_data = item._data;
}
userver::formats::json::Value ReceiptItem::GetData() const {
  return userver::formats::json::Value();
}
