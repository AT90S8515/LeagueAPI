#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolChatUserResource.hpp"
namespace lol {
  template<typename T>
  inline Result<json> PostLolChatV1ConversationsByIdParticipants(T& _client, const std::string& id, const LolChatUserResource& invitee)
  {
    try {
      return ToResult<json>(_client.https.request("post", "/lol-chat/v1/conversations/"+to_string(id)+"/participants?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(invitee).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<json>(e.code());
    }
  }
  template<typename T>
  inline void PostLolChatV1ConversationsByIdParticipants(T& _client, const std::string& id, const LolChatUserResource& invitee, std::function<void(T&, const Result<json>&)> cb)
  {
    _client.httpsa.request("post", "/lol-chat/v1/conversations/"+to_string(id)+"/participants?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(invitee).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<json>(e));
            else
              cb(_client, ToResult<json>(response));
        });
  }
}