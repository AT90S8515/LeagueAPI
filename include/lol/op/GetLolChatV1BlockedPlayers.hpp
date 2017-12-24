#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolChatBlockedPlayerResource.hpp"
namespace lol {
  inline Result<std::vector<LolChatBlockedPlayerResource>> GetLolChatV1BlockedPlayers(LeagueClient& _client)
  {
    try {
      return ToResult<std::vector<LolChatBlockedPlayerResource>>(_client.https.request("get", "/lol-chat/v1/blocked-players?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<std::vector<LolChatBlockedPlayerResource>>(e.code());
    }
  }
  inline void GetLolChatV1BlockedPlayers(LeagueClient& _client, std::function<void(LeagueClient&, const Result<std::vector<LolChatBlockedPlayerResource>>&)> cb)
  {
    _client.httpsa.request("get", "/lol-chat/v1/blocked-players?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<std::vector<LolChatBlockedPlayerResource>>(e));
            else
              cb(_client, ToResult<std::vector<LolChatBlockedPlayerResource>>(response));
        });
  }
}