#ifndef ARCHITECTURE_VALIDATOR_H
#define ARCHITECTURE_VALIDATOR_H

#include <vector>
#include "../accounts/Account.h"
#include "../items/Item.h"
#include "PolicyCreator.h"
#include "ValidatorConstants.h"

#include "../userver_headers.h"

class Validator {
 public:
  static std::vector<validator::ErrorCode> Validate(
      const std::shared_ptr<const Account>& account,
      const std::vector<std::shared_ptr<const Item>>& items,
      userver::storages::postgres::ClusterPtr pg_cluster);
};

#endif
