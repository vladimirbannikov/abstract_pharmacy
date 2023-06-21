#ifndef ARCHITECTURE_RECEIPTITEM_H
#define ARCHITECTURE_RECEIPTITEM_H

#include "../Item.h"
#include "ReceiptItemDTO.h"

class ReceiptItem: public Item {
    ReceiptItemDTO _data;
    items::Type _type = items::Type::receipt;

public:
    ReceiptItem(const ReceiptItemDTO& data);
    ReceiptItem(const ReceiptItem& item);
    items::Type GetType() const override;
    userver::formats::json::Value GetData() const override;
};


#endif
