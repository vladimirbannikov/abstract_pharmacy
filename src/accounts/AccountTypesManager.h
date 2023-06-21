#ifndef ARCHITECTURE_ACCOUNTTYPESMANAGER_H
#define ARCHITECTURE_ACCOUNTTYPESMANAGER_H

#include <unordered_map>
#include <string>
#include "AccountCreator.h"
#include "user/UserAccountCreator.h"
#include <functional>
#include <memory>
#include "AccountConstants.h"


class AccountTypesManager {
    std::unordered_map<std::string, accounts::Type> _table_name_to_account_type;
    std::unordered_map<accounts::Type, std::function<std::shared_ptr<AccountCreator>()>> _account_type_to_creator;
    std::unordered_map<accounts::Type, std::string> _account_type_to_table_name;
public:
    AccountTypesManager();
    std::shared_ptr<AccountCreator> GetCreator(accounts::Type type);
    accounts::Type GetAccountTypeFromTableName(const std::string& tableName);
};


#endif
