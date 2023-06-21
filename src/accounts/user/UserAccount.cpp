#include "UserAccount.h"

userver::formats::json::Value Serialize(
    const UserAccountDTO& data) {
  userver::formats::json::ValueBuilder jsonCourier;
  jsonCourier["id"] = data.id;
  jsonCourier["full_name"] = data.full_name;
  return jsonCourier.ExtractValue();
}

userver::formats::json::Value UserAccount::GetData() const{
    return Serialize(_data);
}

accounts::Type UserAccount::GetType() const{
    return _type;
}

UserAccount::UserAccount(const UserAccountDTO& data): _data(data){}

UserAccount::UserAccount(const UserAccount &otherAccount) {
    this->_data = otherAccount._data;
}
