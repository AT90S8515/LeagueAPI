#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/ClubInvite.hpp"
namespace lol {
  template<typename T>
  inline Result<std::vector<ClubInvite>> GetLolClubsV1ClubsInvitations(T& _client)
  {
    try {
      return ToResult<std::vector<ClubInvite>>(_client.https.request("get", "/lol-clubs/v1/clubs/invitations?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<std::vector<ClubInvite>>(e.code());
    }
  }
  template<typename T>
  inline void GetLolClubsV1ClubsInvitations(T& _client, std::function<void(T&, const Result<std::vector<ClubInvite>>&)> cb)
  {
    _client.httpsa.request("get", "/lol-clubs/v1/clubs/invitations?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<std::vector<ClubInvite>>(e));
            else
              cb(_client, ToResult<std::vector<ClubInvite>>(response));
        });
  }
}