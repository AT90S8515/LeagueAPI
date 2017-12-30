#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  template<typename T>
  inline Result<json> PostLolGameflowV1WatchLaunch(T& _client, const std::vector<std::string>& args)
  {
    try {
      return ToResult<json>(_client.https.request("post", "/lol-gameflow/v1/watch/launch?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(args).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<json>(e.code());
    }
  }
  template<typename T>
  inline void PostLolGameflowV1WatchLaunch(T& _client, const std::vector<std::string>& args, std::function<void(T&, const Result<json>&)> cb)
  {
    _client.httpsa.request("post", "/lol-gameflow/v1/watch/launch?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(args).dump(),
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