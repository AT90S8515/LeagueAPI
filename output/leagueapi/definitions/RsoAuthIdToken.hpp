#pragma once
#include <leagueapi/base.hpp>

namespace leagueapi {
  struct RsoAuthIdToken { /**/ 
    uint64_t expiry;/**/
    std::string token;/**/
  };
  static void to_json(json& j, const RsoAuthIdToken& v) { 
    j["expiry"] = v.expiry;
    j["token"] = v.token;
  }
  static void from_json(const json& j, RsoAuthIdToken& v) { 
    v.expiry = j.at("expiry").get<uint64_t>(); 
    v.token = j.at("token").get<std::string>(); 
  }
} 