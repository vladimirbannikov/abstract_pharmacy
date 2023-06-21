#include "Validator.h"

std::vector<validator::ErrorCode> Validator::Validate(
    const std::shared_ptr<const Account>& account,
    const std::vector<std::shared_ptr<const Item>>& items,
    userver::storages::postgres::ClusterPtr pg_cluster) {
  std::vector<validator::ErrorCode> codes;
  PolicyCreator creator;
  auto policy = creator.CreatePolicy(account);
  codes.reserve(items.size());
  for (const auto& item : items) {
    codes.emplace_back(policy->Check(account, item, pg_cluster));
  }
  return codes;
}
