#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  template<typename T>
  inline Result<Nothing> PutLolLobbyV1PartiesByPartyIdMembersByPuuidRole(T& _client, const std::string& partyId, const std::string& puuid, const std::string& role)
  {
    try {
      return ToResult<Nothing>(_client.https.request("put", "/lol-lobby/v1/parties/"+to_string(partyId)+"/members/"+to_string(puuid)+"/role?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(role).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<Nothing>(e.code());
    }
  }
  template<typename T>
  inline void PutLolLobbyV1PartiesByPartyIdMembersByPuuidRole(T& _client, const std::string& partyId, const std::string& puuid, const std::string& role, std::function<void(T&, const Result<Nothing>&)> cb)
  {
    _client.httpsa.request("put", "/lol-lobby/v1/parties/"+to_string(partyId)+"/members/"+to_string(puuid)+"/role?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(role).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<Nothing>(e));
            else
              cb(_client, ToResult<Nothing>(response));
        });
  }
}