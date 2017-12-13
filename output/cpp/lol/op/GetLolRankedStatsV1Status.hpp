#pragma once
#include<lol/base_op.hpp> 
#include <lol/def/LolRankedStatsPluginStatus.hpp>
namespace lol {
  Result<LolRankedStatsPluginStatus> GetLolRankedStatsV1Status(const LeagueClient& _client)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/lol-ranked-stats/v1/status?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}