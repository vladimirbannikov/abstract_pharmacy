#include "PolicyTypesManager.h"


PolicyTypesManager::PolicyTypesManager() {
    _account_policy_map = {
            {accounts::Type::user, [] { return std::make_shared<UserPolicy>();}}
    };
}

std::shared_ptr<AccountPolicy> PolicyTypesManager::GetAccountPolicyFromType(accounts::Type acc_type) {
    return _account_policy_map[acc_type]();
}



