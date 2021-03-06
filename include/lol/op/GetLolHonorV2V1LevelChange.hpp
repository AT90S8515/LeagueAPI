#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolHonorV2VendedHonorChange.hpp"
namespace lol {
  template<typename T>
  inline Result<LolHonorV2VendedHonorChange> GetLolHonorV2V1LevelChange(T& _client)
  {
    try {
      return ToResult<LolHonorV2VendedHonorChange>(_client.https.request("get", "/lol-honor-v2/v1/level-change?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<LolHonorV2VendedHonorChange>(e.code());
    }
  }
  template<typename T>
  inline void GetLolHonorV2V1LevelChange(T& _client, std::function<void(T&, const Result<LolHonorV2VendedHonorChange>&)> cb)
  {
    _client.httpsa.request("get", "/lol-honor-v2/v1/level-change?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<LolHonorV2VendedHonorChange>(e));
            else
              cb(_client, ToResult<LolHonorV2VendedHonorChange>(response));
        });
  }
}