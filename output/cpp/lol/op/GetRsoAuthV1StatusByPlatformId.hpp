#pragma once
#include<lol/base_op.hpp> 
#include <lol/def/RsoAuthRegionStatus.hpp>
namespace lol {
  Result<RsoAuthRegionStatus> GetRsoAuthV1StatusByPlatformId(const LeagueClient& _client, const std::string& platformId)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/rso-auth/v1/status/"+to_string(platformId)+"?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}