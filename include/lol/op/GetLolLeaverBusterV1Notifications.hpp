#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LeaverBusterNotificationResource.hpp"
namespace lol {
  template<typename T>
  inline Result<std::vector<LeaverBusterNotificationResource>> GetLolLeaverBusterV1Notifications(T& _client)
  {
    try {
      return ToResult<std::vector<LeaverBusterNotificationResource>>(_client.https.request("get", "/lol-leaver-buster/v1/notifications?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<std::vector<LeaverBusterNotificationResource>>(e.code());
    }
  }
  template<typename T>
  inline void GetLolLeaverBusterV1Notifications(T& _client, std::function<void(T&, const Result<std::vector<LeaverBusterNotificationResource>>&)> cb)
  {
    _client.httpsa.request("get", "/lol-leaver-buster/v1/notifications?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<std::vector<LeaverBusterNotificationResource>>(e));
            else
              cb(_client, ToResult<std::vector<LeaverBusterNotificationResource>>(response));
        });
  }
}