#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolReplaysReplayContextData.hpp"
namespace lol {
  template<typename T>
  inline Result<Nothing> PostLolReplaysV1RoflsByGameIdDownload(T& _client, const uint64_t& gameId, const LolReplaysReplayContextData& contextData)
  {
    try {
      return ToResult<Nothing>(_client.https.request("post", "/lol-replays/v1/rofls/"+to_string(gameId)+"/download?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(contextData).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<Nothing>(e.code());
    }
  }
  template<typename T>
  inline void PostLolReplaysV1RoflsByGameIdDownload(T& _client, const uint64_t& gameId, const LolReplaysReplayContextData& contextData, std::function<void(T&, const Result<Nothing>&)> cb)
  {
    _client.httpsa.request("post", "/lol-replays/v1/rofls/"+to_string(gameId)+"/download?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(contextData).dump(),
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