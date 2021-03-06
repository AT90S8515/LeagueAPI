#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/TencentQTNotification.hpp"
namespace lol {
  template<typename T>
  inline Result<TencentQTNotification> GetLolTencentQtV1UiStatesByFeature(T& _client, const std::string& feature)
  {
    try {
      return ToResult<TencentQTNotification>(_client.https.request("get", "/lol-tencent-qt/v1/ui-states/"+to_string(feature)+"?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<TencentQTNotification>(e.code());
    }
  }
  template<typename T>
  inline void GetLolTencentQtV1UiStatesByFeature(T& _client, const std::string& feature, std::function<void(T&, const Result<TencentQTNotification>&)> cb)
  {
    _client.httpsa.request("get", "/lol-tencent-qt/v1/ui-states/"+to_string(feature)+"?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<TencentQTNotification>(e));
            else
              cb(_client, ToResult<TencentQTNotification>(response));
        });
  }
}