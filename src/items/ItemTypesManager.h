#ifndef ARCHITECTURE_ITEMTYPESMANAGER_H
#define ARCHITECTURE_ITEMTYPESMANAGER_H

#include "ItemConstants.h"
#include "ItemCreator.h"
#include "Receipt/ReceiptItemCreator.h"
#include <memory>
#include <unordered_map>
#include <functional>

class ItemTypesManager {
    std::unordered_map<items::Type, std::function<std::shared_ptr<ItemCreator>()>> _item_type_to_creator;
    std::unordered_map<std::string, items::Type> _item_name_to_item_type;
public:
    ItemTypesManager();
    std::shared_ptr<ItemCreator> GetCreator(items::Type type);
    items::Type GetItemTypeFromTypeName(const std::string& typeName);
};


#endif