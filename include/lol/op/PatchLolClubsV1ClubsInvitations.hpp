#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/ClubInvite.hpp"
#include "../def/PlayerClubMembership.hpp"
namespace lol {
  inline Result<PlayerClubMembership> PatchLolClubsV1ClubsInvitations(LeagueClient& _client, const ClubInvite& invitation)
  {
    try {
      return ToResult<PlayerClubMembership>(_client.https.request("patch", "/lol-clubs/v1/clubs/invitations?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(invitation).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<PlayerClubMembership>(e.code());
    }
  }
  inline void PatchLolClubsV1ClubsInvitations(LeagueClient& _client, const ClubInvite& invitation, std::function<void(LeagueClient&, const Result<PlayerClubMembership>&)> cb)
  {
    _client.httpsa.request("patch", "/lol-clubs/v1/clubs/invitations?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(invitation).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<PlayerClubMembership>(e));
            else
              cb(_client, ToResult<PlayerClubMembership>(response));
        });
  }
}