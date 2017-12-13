#pragma once
#include<lol/base_op.hpp> 
#include <lol/def/LolPersonalizedOffersUIOffer.hpp>
namespace lol {
  Result<std::vector<LolPersonalizedOffersUIOffer>> GetLolPersonalizedOffersV1Offers(const LeagueClient& _client)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/lol-personalized-offers/v1/offers?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}