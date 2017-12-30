#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolChampionsCollectionsChampionPlayableCounts { 
    uint32_t championsRented;
    uint32_t championsFreeToPlayReward;
    uint32_t championsFreeToPlay;
    uint32_t championsOwned; 
  };
  inline void to_json(json& j, const LolChampionsCollectionsChampionPlayableCounts& v) {
    j["championsRented"] = v.championsRented; 
    j["championsFreeToPlayReward"] = v.championsFreeToPlayReward; 
    j["championsFreeToPlay"] = v.championsFreeToPlay; 
    j["championsOwned"] = v.championsOwned; 
  }
  inline void from_json(const json& j, LolChampionsCollectionsChampionPlayableCounts& v) {
    v.championsRented = j.at("championsRented").get<uint32_t>(); 
    v.championsFreeToPlayReward = j.at("championsFreeToPlayReward").get<uint32_t>(); 
    v.championsFreeToPlay = j.at("championsFreeToPlay").get<uint32_t>(); 
    v.championsOwned = j.at("championsOwned").get<uint32_t>(); 
  }
}