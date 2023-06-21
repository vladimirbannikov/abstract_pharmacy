#include "AccountTypesManager.h"


std::shared_ptr<AccountCreator> AccountTypesManager::GetCreator(accounts::Type type) {
    if (_account_type_to_creator.find(type) != _account_type_to_creator.end()) {
        return _account_type_to_creator[type]();
    }
    else return nullptr;
}

accounts::Type AccountTypesManager::GetAccountTypeFromTableName(const std::string &tableName) {
    return _table_name_to_account_type[tableName];
}

AccountTypesManager::AccountTypesManager() {
    _account_type_to_creator = {
            {accounts::Type::user, [] { return std::make_shared<UserAccountCreator>(); }}
    };
    _table_name_to_account_type = {
            {accounts::table_names::user_table, accounts::Type::user}
    };
}


