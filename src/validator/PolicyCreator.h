#ifndef ARCHITECTURE_POLICYCREATOR_H
#define ARCHITECTURE_POLICYCREATOR_H

#include "AccountPolicy.h"
#include "user_policy/UserPolicy.h"
#include <memory>
#include "PolicyTypesManager.h"


class PolicyCreator {
public:
    std::shared_ptr<AccountPolicy> CreatePolicy(const std::shared_ptr<const Account> &account);
};


#endif //ARCHITECTURE_POLICYCREATOR_H
