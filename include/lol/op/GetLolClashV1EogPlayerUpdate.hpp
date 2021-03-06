#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolClashEogPlayerUpdateDTO.hpp"
namespace lol {
  template<typename T>
  inline Result<LolClashEogPlayerUpdateDTO> GetLolClashV1EogPlayerUpdate(T& _client)
  {
    try {
      return ToResult<LolClashEogPlayerUpdateDTO>(_client.https.request("get", "/lol-clash/v1/eogPlayerUpdate?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<LolClashEogPlayerUpdateDTO>(e.code());
    }
  }
  template<typename T>
  inline void GetLolClashV1EogPlayerUpdate(T& _client, std::function<void(T&, const Result<LolClashEogPlayerUpdateDTO>&)> cb)
  {
    _client.httpsa.request("get", "/lol-clash/v1/eogPlayerUpdate?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<LolClashEogPlayerUpdateDTO>(e));
            else
              cb(_client, ToResult<LolClashEogPlayerUpdateDTO>(response));
        });
  }
}