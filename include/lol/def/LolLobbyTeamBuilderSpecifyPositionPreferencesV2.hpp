#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolLobbyTeamBuilderSpecifyPositionPreferencesV2 { 
    std::string secondPreference;
    std::string excludedPreference;
    std::string firstPreference; 
  };
  inline void to_json(json& j, const LolLobbyTeamBuilderSpecifyPositionPreferencesV2& v) {
    j["secondPreference"] = v.secondPreference; 
    j["excludedPreference"] = v.excludedPreference; 
    j["firstPreference"] = v.firstPreference; 
  }
  inline void from_json(const json& j, LolLobbyTeamBuilderSpecifyPositionPreferencesV2& v) {
    v.secondPreference = j.at("secondPreference").get<std::string>(); 
    v.excludedPreference = j.at("excludedPreference").get<std::string>(); 
    v.firstPreference = j.at("firstPreference").get<std::string>(); 
  }
}