#pragma once
#include <leagueapi/https.hpp>

namespace leagueapi::op {
  /**/
  static https::Result<bool> GetLolClashV1Ready (const https::Info& _info_ )
  { 
    return { https::Do(_info_, "get", "/lol-clash/v1/ready?", { 
    }, { 
    },"") };
  }
} 