#include "ItemCreatorsManager.h"

std::shared_ptr<ItemCreator> ItemCreatorsManager::GetItemCreator(
    const std::string& category) {
  ItemTypesManager manager;
  items::Type type = manager.GetItemTypeFromTypeName(category);
  return manager.GetCreator(type);
}
