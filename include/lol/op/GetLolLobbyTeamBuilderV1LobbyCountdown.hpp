#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolLobbyTeamBuilderLobbyCountdownTimer.hpp"
namespace lol {
  template<typename T>
  inline Result<LolLobbyTeamBuilderLobbyCountdownTimer> GetLolLobbyTeamBuilderV1LobbyCountdown(T& _client)
  {
    try {
      return ToResult<LolLobbyTeamBuilderLobbyCountdownTimer>(_client.https.request("get", "/lol-lobby-team-builder/v1/lobby/countdown?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<LolLobbyTeamBuilderLobbyCountdownTimer>(e.code());
    }
  }
  template<typename T>
  inline void GetLolLobbyTeamBuilderV1LobbyCountdown(T& _client, std::function<void(T&, const Result<LolLobbyTeamBuilderLobbyCountdownTimer>&)> cb)
  {
    _client.httpsa.request("get", "/lol-lobby-team-builder/v1/lobby/countdown?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<LolLobbyTeamBuilderLobbyCountdownTimer>(e));
            else
              cb(_client, ToResult<LolLobbyTeamBuilderLobbyCountdownTimer>(response));
        });
  }
}