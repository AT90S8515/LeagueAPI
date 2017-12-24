#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolChatGameDataChampionSummary { 
    int32_t id;
    std::string alias; 
  };
  inline void to_json(json& j, const LolChatGameDataChampionSummary& v) {
    j["id"] = v.id; 
    j["alias"] = v.alias; 
  }
  inline void from_json(const json& j, LolChatGameDataChampionSummary& v) {
    v.id = j.at("id").get<int32_t>(); 
    v.alias = j.at("alias").get<std::string>(); 
  }
}