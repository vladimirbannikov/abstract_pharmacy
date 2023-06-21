#ifndef ARCHITECTURE_ITEMCREATORSMANAGER_H
#define ARCHITECTURE_ITEMCREATORSMANAGER_H

#include "ItemTypesManager.h"

class ItemCreatorsManager {
public:
    ItemCreatorsManager() = default;
    std::shared_ptr<ItemCreator> GetItemCreator(
        const std::string& category);
};


#endif //ARCHITECTURE_ITEMCREATORSMANAGER_H
