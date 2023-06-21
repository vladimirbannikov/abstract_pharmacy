#ifndef ARCHITECTURE_USERACCOUNT_H
#define ARCHITECTURE_USERACCOUNT_H

#include "../Account.h"
#include "UserAccountDTO.h"

class UserAccount: public Account{
    UserAccountDTO _data;
    accounts::Type _type = accounts::Type::user;
public:
    UserAccount(const UserAccountDTO& data);
    UserAccount(const UserAccount& otherAccount);
    userver::formats::json::Value GetData() const override;
    accounts::Type GetType() const override;
};


#endif //ARCHITECTURE_USERACCOUNT_H
