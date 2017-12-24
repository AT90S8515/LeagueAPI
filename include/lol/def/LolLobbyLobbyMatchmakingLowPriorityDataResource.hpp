#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolLobbyLobbyMatchmakingLowPriorityDataResource { 
    double penaltyTimeRemaining;
    double penaltyTime;
    std::vector<uint64_t> penalizedSummonerIds;
    std::string bustedLeaverAccessToken; 
  };
  inline void to_json(json& j, const LolLobbyLobbyMatchmakingLowPriorityDataResource& v) {
    j["penaltyTimeRemaining"] = v.penaltyTimeRemaining; 
    j["penaltyTime"] = v.penaltyTime; 
    j["penalizedSummonerIds"] = v.penalizedSummonerIds; 
    j["bustedLeaverAccessToken"] = v.bustedLeaverAccessToken; 
  }
  inline void from_json(const json& j, LolLobbyLobbyMatchmakingLowPriorityDataResource& v) {
    v.penaltyTimeRemaining = j.at("penaltyTimeRemaining").get<double>(); 
    v.penaltyTime = j.at("penaltyTime").get<double>(); 
    v.penalizedSummonerIds = j.at("penalizedSummonerIds").get<std::vector<uint64_t>>(); 
    v.bustedLeaverAccessToken = j.at("bustedLeaverAccessToken").get<std::string>(); 
  }
}