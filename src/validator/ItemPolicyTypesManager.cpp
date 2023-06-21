#include "ItemPolicyTypesManager.h"

ItemPolicyTypesManager::ItemPolicyTypesManager() {
    _item_policy_map[accounts::Type::user][items::Type::receipt] =
            [] { return std::make_shared<user_policy::ReceiptPolicy>();};
}

std::shared_ptr<ItemPolicy>
ItemPolicyTypesManager::GetItemPolicyFromTypes(accounts::Type acc_type, items::Type item_type) {
    return _item_policy_map[acc_type][item_type]();
}


