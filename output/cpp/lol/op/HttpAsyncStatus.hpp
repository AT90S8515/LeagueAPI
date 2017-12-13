#pragma once
#include<lol/base_op.hpp> 
namespace lol {
  Result<json> HttpAsyncStatus(const LeagueClient& _client, const uint32_t& asyncToken)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/async/v1/status/"+to_string(asyncToken)+"?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}