#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  template<typename T>
  inline Result<Nothing> PostLolLobbyV2PartiesOverridesEnabledForTeamBuilderQueues(T& _client, const bool& enabledForTeambuilderQueues)
  {
    try {
      return ToResult<Nothing>(_client.https.request("post", "/lol-lobby/v2/parties/overrides/EnabledForTeamBuilderQueues?" +
        SimpleWeb::QueryString::create(Args2Headers({ 
          { "enabledForTeambuilderQueues", to_string(enabledForTeambuilderQueues) }, })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<Nothing>(e.code());
    }
  }
  template<typename T>
  inline void PostLolLobbyV2PartiesOverridesEnabledForTeamBuilderQueues(T& _client, const bool& enabledForTeambuilderQueues, std::function<void(T&, const Result<Nothing>&)> cb)
  {
    _client.httpsa.request("post", "/lol-lobby/v2/parties/overrides/EnabledForTeamBuilderQueues?" +
      SimpleWeb::QueryString::create(Args2Headers({ 
          { "enabledForTeambuilderQueues", to_string(enabledForTeambuilderQueues) }, })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<Nothing>(e));
            else
              cb(_client, ToResult<Nothing>(response));
        });
  }
}