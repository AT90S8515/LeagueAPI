#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolClubsPublicUserResource { 
    int32_t icon;
    std::map<std::string, std::string> lol;
    std::string name;
    uint64_t id;
    std::optional<std::string> lastSeenOnlineTimestamp;
    std::string availability; 
  };
  inline void to_json(json& j, const LolClubsPublicUserResource& v) {
    j["icon"] = v.icon; 
    j["lol"] = v.lol; 
    j["name"] = v.name; 
    j["id"] = v.id; 
    if(v.lastSeenOnlineTimestamp)
      j["lastSeenOnlineTimestamp"] = *v.lastSeenOnlineTimestamp;
    j["availability"] = v.availability; 
  }
  inline void from_json(const json& j, LolClubsPublicUserResource& v) {
    v.icon = j.at("icon").get<int32_t>(); 
    v.lol = j.at("lol").get<std::map<std::string, std::string>>(); 
    v.name = j.at("name").get<std::string>(); 
    v.id = j.at("id").get<uint64_t>(); 
    if(auto it = j.find("lastSeenOnlineTimestamp"); it != j.end() && !it->is_null())
      v.lastSeenOnlineTimestamp = it->get<std::optional<std::string>>(); 
    v.availability = j.at("availability").get<std::string>(); 
  }
}