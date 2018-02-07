#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  template<typename T>
  inline Result<json> PostLolLobbyV2PartyByPartyIdJoin(T& _client, const std::string& partyId)
  {
    try {
      return ToResult<json>(_client.https.request("post", "/lol-lobby/v2/party/"+to_string(partyId)+"/join?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<json>(e.code());
    }
  }
  template<typename T>
  inline void PostLolLobbyV2PartyByPartyIdJoin(T& _client, const std::string& partyId, std::function<void(T&, const Result<json>&)> cb)
  {
    _client.httpsa.request("post", "/lol-lobby/v2/party/"+to_string(partyId)+"/join?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<json>(e));
            else
              cb(_client, ToResult<json>(response));
        });
  }
}