#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolChampSelectLegacyChampSelectSession.hpp"
namespace lol {
  inline Result<LolChampSelectLegacyChampSelectSession> GetLolChampSelectLegacyV1Session(LeagueClient& _client)
  {
    try {
      return ToResult<LolChampSelectLegacyChampSelectSession>(_client.https.request("get", "/lol-champ-select-legacy/v1/session?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<LolChampSelectLegacyChampSelectSession>(e.code());
    }
  }
  inline void GetLolChampSelectLegacyV1Session(LeagueClient& _client, std::function<void(LeagueClient&, const Result<LolChampSelectLegacyChampSelectSession>&)> cb)
  {
    _client.httpsa.request("get", "/lol-champ-select-legacy/v1/session?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<LolChampSelectLegacyChampSelectSession>(e));
            else
              cb(_client, ToResult<LolChampSelectLegacyChampSelectSession>(response));
        });
  }
}