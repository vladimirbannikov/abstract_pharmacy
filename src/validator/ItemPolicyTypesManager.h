#ifndef ARCHITECTURE_ITEMPOLICYTYPESMANAGER_H
#define ARCHITECTURE_ITEMPOLICYTYPESMANAGER_H

#include "ValidatorConstants.h"
#include "user_policy/ReceiptPolicy.h"
#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>

using itemsMap = std::unordered_map<items::Type, std::function<std::shared_ptr<ItemPolicy>()>>;

class ItemPolicyTypesManager {
    std::unordered_map<accounts::Type, itemsMap> _item_policy_map;
public:
    ItemPolicyTypesManager();
    std::shared_ptr<ItemPolicy> GetItemPolicyFromTypes(accounts::Type acc_type, items::Type item_type);
};


#endif
