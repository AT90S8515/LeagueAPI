#pragma once
#include "../base_def.hpp" 
#include "LolLeaguesLeague.hpp"
namespace lol {
  struct LolLeaguesApexLeagues { 
    std::vector<LolLeaguesLeague> challengers;
    std::vector<LolLeaguesLeague> masters; 
  };
  inline void to_json(json& j, const LolLeaguesApexLeagues& v) {
    j["challengers"] = v.challengers; 
    j["masters"] = v.masters; 
  }
  inline void from_json(const json& j, LolLeaguesApexLeagues& v) {
    v.challengers = j.at("challengers").get<std::vector<LolLeaguesLeague>>(); 
    v.masters = j.at("masters").get<std::vector<LolLeaguesLeague>>(); 
  }
}