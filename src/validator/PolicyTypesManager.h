#ifndef ARCHITECTURE_POLICYTYPESMANAGER_H
#define ARCHITECTURE_POLICYTYPESMANAGER_H

#include "ValidatorConstants.h"
#include "user_policy/UserPolicy.h"
#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>

class PolicyTypesManager {
    std::unordered_map<accounts::Type, std::function<std::shared_ptr<AccountPolicy>()>> _account_policy_map;
public:
    PolicyTypesManager();
    std::shared_ptr<AccountPolicy> GetAccountPolicyFromType(accounts::Type acc_type);
};


#endif //ARCHITECTURE_POLICYTYPESMANAGER_H
