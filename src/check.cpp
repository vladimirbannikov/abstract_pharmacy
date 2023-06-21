#include "check.hpp"

#include <fmt/format.h>

#include <userver/clients/dns/component.hpp>
#include <userver/server/handlers/http_handler_base.hpp>
#include <userver/storages/postgres/cluster.hpp>
#include <userver/storages/postgres/component.hpp>
#include <userver/utils/assert.hpp>

#include "accounts/AccountCreatorsManager.h"

#include "items/ItemCreatorsManager.h"

#include "validator/Validator.h"

namespace code_architecture {

namespace {

class Check final : public userver::server::handlers::HttpHandlerBase {
 public:
  static constexpr std::string_view kName = "handler-couriers";
  userver::storages::postgres::ClusterPtr pg_cluster_;

  Check(const userver::components::ComponentConfig& config,
        const userver::components::ComponentContext& component_context)
      : HttpHandlerBase(config, component_context),
        pg_cluster_(
            component_context
                .FindComponent<userver::components::Postgres>("postgres-db-1")
                .GetCluster()){};

  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest& request,
      userver::server::request::RequestContext&) const override {
    const auto& user_id = request.GetArg("user_id");
    const auto& item_ids = request.GetArgVector("user_id");

    std::vector<std::pair<std::string, std::string>> items_names;

    for (auto item_id : item_ids) {
      std::string category =
          std::string(item_id.begin(), item_id.begin() + item_id.find('_'));
      std::string id =
          std::string(item_id.begin() + item_id.find('_') + 1, item_id.end());

      items_names.push_back(std::make_pair(category, id));
    }

    AccountCreatorsManager accountCreatorsManager;
    auto accountCreator = accountCreatorsManager.GetAccountCreator(
        std::stoi(user_id), pg_cluster_);
    auto account =
        accountCreator->CreateAccount(std::stoi(user_id), pg_cluster_);

    std::vector<std::shared_ptr<const Item>> items;
    ItemCreatorsManager itemCreatorsManager;
    for (auto item_name : items_names) {
      auto itemCreator = itemCreatorsManager.GetItemCreator(item_name.first);
      auto item = itemCreator->CreateItem(std::stoi(item_name.second), pg_cluster_);
      items.push_back(item);
    }

    auto codes_array = Validator::Validate(account, items, pg_cluster_);

    // формирование ответа на основе codes_array и исключений

  }
};

}  // namespace

void AppendCheck(userver::components::ComponentList& component_list) {
  component_list.Append<Check>();
  component_list.Append<userver::components::Postgres>("postgres-db-1");
  component_list.Append<userver::clients::dns::Component>();
}

}  // namespace code_architecture
