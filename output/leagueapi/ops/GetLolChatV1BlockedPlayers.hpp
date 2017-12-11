#pragma once
#include <leagueapi/https.hpp>
#include <leagueapi/definitions/LolChatBlockedPlayerResource.hpp>

namespace leagueapi::op {
  /**/
  static https::Result<std::vector<LolChatBlockedPlayerResource>> GetLolChatV1BlockedPlayers (const https::Info& _info_ )
  { 
    return { https::Do(_info_, "get", "/lol-chat/v1/blocked-players?", { 
    }, { 
    },"") };
  }
} 