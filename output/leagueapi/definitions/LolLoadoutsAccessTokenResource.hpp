#pragma once
#include <leagueapi/base.hpp>

namespace leagueapi {
  struct LolLoadoutsAccessTokenResource { /**/ 
    std::vector<std::string> scopes;/**/
    uint64_t expiry;/**/
    std::string token;/**/
  };
  static void to_json(json& j, const LolLoadoutsAccessTokenResource& v) { 
    j["scopes"] = v.scopes;
    j["expiry"] = v.expiry;
    j["token"] = v.token;
  }
  static void from_json(const json& j, LolLoadoutsAccessTokenResource& v) { 
    v.scopes = j.at("scopes").get<std::vector<std::string>>(); 
    v.expiry = j.at("expiry").get<uint64_t>(); 
    v.token = j.at("token").get<std::string>(); 
  }
} 