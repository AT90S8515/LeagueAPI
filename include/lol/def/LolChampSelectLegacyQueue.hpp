#pragma once
#include "../base_def.hpp" 
#include "LolChampSelectLegacyQueueGameTypeConfig.hpp"
namespace lol {
  struct LolChampSelectLegacyQueue { 
    LolChampSelectLegacyQueueGameTypeConfig gameTypeConfig;
    bool areFreeChampionsAllowed; 
  };
  inline void to_json(json& j, const LolChampSelectLegacyQueue& v) {
    j["gameTypeConfig"] = v.gameTypeConfig; 
    j["areFreeChampionsAllowed"] = v.areFreeChampionsAllowed; 
  }
  inline void from_json(const json& j, LolChampSelectLegacyQueue& v) {
    v.gameTypeConfig = j.at("gameTypeConfig").get<LolChampSelectLegacyQueueGameTypeConfig>(); 
    v.areFreeChampionsAllowed = j.at("areFreeChampionsAllowed").get<bool>(); 
  }
}