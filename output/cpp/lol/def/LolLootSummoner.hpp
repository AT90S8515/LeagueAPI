#pragma once
#include<lol/base_def.hpp> 
namespace lol {
  struct LolLootSummoner { 
    uint32_t summonerLevel; 
  };
  void to_json(json& j, const LolLootSummoner& v) {
  j["summonerLevel"] = v.summonerLevel; 
  }
  void from_json(const json& j, LolLootSummoner& v) {
  v.summonerLevel = j.at("summonerLevel").get<uint32_t>(); 
  }
}