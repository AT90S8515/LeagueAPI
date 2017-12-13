#pragma once
#include<lol/base_op.hpp> 
#include <lol/def/TickerMessage.hpp>
namespace lol {
  Result<std::vector<TickerMessage>> GetLolServiceStatusV1TickerMessages(const LeagueClient& _client)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/lol-service-status/v1/ticker-messages?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}