#pragma once
#include <leagueapi/base.hpp>

namespace leagueapi {
  struct LolInventoryInventoryDTO { /**/ 
    uint64_t summonerId;/**/
    std::map<std::string, json> items;/**/
    std::string puuid;/**/
    std::string expires;/**/
    std::string itemsJwt;/**/
    uint64_t accountId;/**/
  };
  static void to_json(json& j, const LolInventoryInventoryDTO& v) { 
    j["summonerId"] = v.summonerId;
    j["items"] = v.items;
    j["puuid"] = v.puuid;
    j["expires"] = v.expires;
    j["itemsJwt"] = v.itemsJwt;
    j["accountId"] = v.accountId;
  }
  static void from_json(const json& j, LolInventoryInventoryDTO& v) { 
    v.summonerId = j.at("summonerId").get<uint64_t>(); 
    v.items = j.at("items").get<std::map<std::string, json>>(); 
    v.puuid = j.at("puuid").get<std::string>(); 
    v.expires = j.at("expires").get<std::string>(); 
    v.itemsJwt = j.at("itemsJwt").get<std::string>(); 
    v.accountId = j.at("accountId").get<uint64_t>(); 
  }
} 