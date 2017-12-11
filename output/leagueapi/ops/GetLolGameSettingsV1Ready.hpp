#pragma once
#include <leagueapi/https.hpp>

namespace leagueapi::op {
  /**/
  static https::Result<bool> GetLolGameSettingsV1Ready (const https::Info& _info_ )
  { 
    return { https::Do(_info_, "get", "/lol-game-settings/v1/ready?", { 
    }, { 
    },"") };
  }
} 