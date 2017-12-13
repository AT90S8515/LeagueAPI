#pragma once
#include<lol/base_def.hpp> 
namespace lol {
  struct SpectatorLcdsSpectateAvailabilityDto { 
    std::vector<std::string> teamOrSummonerIds; 
  };
  void to_json(json& j, const SpectatorLcdsSpectateAvailabilityDto& v) {
  j["teamOrSummonerIds"] = v.teamOrSummonerIds; 
  }
  void from_json(const json& j, SpectatorLcdsSpectateAvailabilityDto& v) {
  v.teamOrSummonerIds = j.at("teamOrSummonerIds").get<std::vector<std::string>>(); 
  }
}