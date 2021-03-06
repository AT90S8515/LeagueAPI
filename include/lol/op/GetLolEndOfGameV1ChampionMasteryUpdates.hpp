#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolEndOfGameChampionMasteryUpdate.hpp"
namespace lol {
  template<typename T>
  inline Result<LolEndOfGameChampionMasteryUpdate> GetLolEndOfGameV1ChampionMasteryUpdates(T& _client)
  {
    try {
      return ToResult<LolEndOfGameChampionMasteryUpdate>(_client.https.request("get", "/lol-end-of-game/v1/champion-mastery-updates?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<LolEndOfGameChampionMasteryUpdate>(e.code());
    }
  }
  template<typename T>
  inline void GetLolEndOfGameV1ChampionMasteryUpdates(T& _client, std::function<void(T&, const Result<LolEndOfGameChampionMasteryUpdate>&)> cb)
  {
    _client.httpsa.request("get", "/lol-end-of-game/v1/champion-mastery-updates?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<LolEndOfGameChampionMasteryUpdate>(e));
            else
              cb(_client, ToResult<LolEndOfGameChampionMasteryUpdate>(response));
        });
  }
}