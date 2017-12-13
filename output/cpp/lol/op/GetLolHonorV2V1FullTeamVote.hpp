#pragma once
#include<lol/base_op.hpp> 
#include <lol/def/LolHonorV2FullTeamVote.hpp>
namespace lol {
  Result<LolHonorV2FullTeamVote> GetLolHonorV2V1FullTeamVote(const LeagueClient& _client)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/lol-honor-v2/v1/full-team-vote?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}