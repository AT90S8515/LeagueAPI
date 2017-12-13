#pragma once
#include<lol/base_op.hpp> 
namespace lol {
  Result<json> GetPerformanceV1SystemInfo(const LeagueClient& _client, const std::optional<int32_t>& full = std::nullopt)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/performance/v1/system-info?" + SimpleWeb::QueryString::create(Args2Headers({ { "full", to_string(full) } })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}