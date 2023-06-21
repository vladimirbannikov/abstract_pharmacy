//
// Created by vladimir on 21.06.23.
//

#include "ItemTypesManager.h"

ItemTypesManager::ItemTypesManager() {
  _item_type_to_creator = {{items::Type::receipt, [] {
                              return std::make_shared<ReceiptItemCreator>();
                            }}};
  _item_name_to_item_type = {
      {items::type_names::receipt, items::Type::receipt}};
}

std::shared_ptr<ItemCreator> ItemTypesManager::GetCreator(items::Type type) {
  if (_item_type_to_creator.find(type) != _item_type_to_creator.end()) {
    return _item_type_to_creator[type]();
  } else
    return nullptr;
}

items::Type ItemTypesManager::GetItemTypeFromTypeName(
    const std::string& typeName) {
  return _item_name_to_item_type[typeName];
}
