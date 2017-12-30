#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  template<typename T>
  inline Result<json> PostLolChampSelectV1BattleTrainingLaunch(T& _client)
  {
    try {
      return ToResult<json>(_client.https.request("post", "/lol-champ-select/v1/battle-training/launch?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<json>(e.code());
    }
  }
  template<typename T>
  inline void PostLolChampSelectV1BattleTrainingLaunch(T& _client, std::function<void(T&, const Result<json>&)> cb)
  {
    _client.httpsa.request("post", "/lol-champ-select/v1/battle-training/launch?" +
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