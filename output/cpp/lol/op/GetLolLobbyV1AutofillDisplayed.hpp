#pragma once
#include<lol/base_op.hpp> 
namespace lol {
  Result<bool> GetLolLobbyV1AutofillDisplayed(const LeagueClient& _client)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/lol-lobby/v1/autofill-displayed?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}