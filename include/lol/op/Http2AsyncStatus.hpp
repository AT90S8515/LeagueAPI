#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  inline Result<json> Http2AsyncStatus(LeagueClient& _client, const uint32_t& asyncToken)
  {
    try {
      return ToResult<json>(_client.https.request("get", "/async/v1/status/"+to_string(asyncToken)+"?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<json>(e.code());
    }
  }
  inline void Http2AsyncStatus(LeagueClient& _client, const uint32_t& asyncToken, std::function<void(LeagueClient&, const Result<json>&)> cb)
  {
    _client.httpsa.request("get", "/async/v1/status/"+to_string(asyncToken)+"?" +
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