#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolChampSelectChampSelectTradeContract.hpp"
namespace lol {
  template<typename T>
  inline Result<LolChampSelectChampSelectTradeContract> PostLolChampSelectV1SessionTradesByIdRequest(T& _client, const int64_t& id)
  {
    try {
      return ToResult<LolChampSelectChampSelectTradeContract>(_client.https.request("post", "/lol-champ-select/v1/session/trades/"+to_string(id)+"/request?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<LolChampSelectChampSelectTradeContract>(e.code());
    }
  }
  template<typename T>
  inline void PostLolChampSelectV1SessionTradesByIdRequest(T& _client, const int64_t& id, std::function<void(T&, const Result<LolChampSelectChampSelectTradeContract>&)> cb)
  {
    _client.httpsa.request("post", "/lol-champ-select/v1/session/trades/"+to_string(id)+"/request?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<LolChampSelectChampSelectTradeContract>(e));
            else
              cb(_client, ToResult<LolChampSelectChampSelectTradeContract>(response));
        });
  }
}