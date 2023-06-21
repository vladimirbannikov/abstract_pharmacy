#include "PolicyCreator.h"

std::shared_ptr<AccountPolicy> PolicyCreator::CreatePolicy(const std::shared_ptr<const Account> &account) {
    PolicyTypesManager manager;
    return manager.GetAccountPolicyFromType(account->GetType());
}
