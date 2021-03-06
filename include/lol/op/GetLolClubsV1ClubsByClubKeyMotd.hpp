#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  template<typename T>
  inline Result<std::string> GetLolClubsV1ClubsByClubKeyMotd(T& _client, const std::string& clubKey)
  {
    try {
      return ToResult<std::string>(_client.https.request("get", "/lol-clubs/v1/clubs/"+to_string(clubKey)+"/motd?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<std::string>(e.code());
    }
  }
  template<typename T>
  inline void GetLolClubsV1ClubsByClubKeyMotd(T& _client, const std::string& clubKey, std::function<void(T&, const Result<std::string>&)> cb)
  {
    _client.httpsa.request("get", "/lol-clubs/v1/clubs/"+to_string(clubKey)+"/motd?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<std::string>(e));
            else
              cb(_client, ToResult<std::string>(response));
        });
  }
}