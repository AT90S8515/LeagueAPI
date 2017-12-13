#pragma once
#include<lol/base_op.hpp> 
namespace lol {
  Result<json> GetLolSettingsV2AccountByPpTypeByCategory(const LeagueClient& _client, const std::string& ppType, const std::string& category)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/lol-settings/v2/account/"+to_string(ppType)+"/"+to_string(category)+"?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}