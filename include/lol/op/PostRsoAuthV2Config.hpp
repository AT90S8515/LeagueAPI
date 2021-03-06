#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/RsoAuthPublicClientConfig.hpp"
namespace lol {
  template<typename T>
  inline Result<Nothing> PostRsoAuthV2Config(T& _client, const RsoAuthPublicClientConfig& config)
  {
    try {
      return ToResult<Nothing>(_client.https.request("post", "/rso-auth/v2/config?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(config).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<Nothing>(e.code());
    }
  }
  template<typename T>
  inline void PostRsoAuthV2Config(T& _client, const RsoAuthPublicClientConfig& config, std::function<void(T&, const Result<Nothing>&)> cb)
  {
    _client.httpsa.request("post", "/rso-auth/v2/config?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(config).dump(),
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