#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  template<typename T>
  inline Result<bool> GetLolQueueEligibilityV1InitialConfigurationComplete(T& _client)
  {
    try {
      return ToResult<bool>(_client.https.request("get", "/lol-queue-eligibility/v1/initial-configuration-complete?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<bool>(e.code());
    }
  }
  template<typename T>
  inline void GetLolQueueEligibilityV1InitialConfigurationComplete(T& _client, std::function<void(T&, const Result<bool>&)> cb)
  {
    _client.httpsa.request("get", "/lol-queue-eligibility/v1/initial-configuration-complete?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<bool>(e));
            else
              cb(_client, ToResult<bool>(response));
        });
  }
}