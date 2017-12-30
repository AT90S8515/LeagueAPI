#pragma once
#include "../base_def.hpp" 
#include "MatchmakingLcdsSummoner.hpp"
namespace lol {
  struct MatchmakingLcdsBustedLeaver { 
    MatchmakingLcdsSummoner summoner;
    std::string accessToken;
    std::string reasonFailed;
    uint64_t leaverPenaltyMillisRemaining; 
  };
  inline void to_json(json& j, const MatchmakingLcdsBustedLeaver& v) {
    j["summoner"] = v.summoner; 
    j["accessToken"] = v.accessToken; 
    j["reasonFailed"] = v.reasonFailed; 
    j["leaverPenaltyMillisRemaining"] = v.leaverPenaltyMillisRemaining; 
  }
  inline void from_json(const json& j, MatchmakingLcdsBustedLeaver& v) {
    v.summoner = j.at("summoner").get<MatchmakingLcdsSummoner>(); 
    v.accessToken = j.at("accessToken").get<std::string>(); 
    v.reasonFailed = j.at("reasonFailed").get<std::string>(); 
    v.leaverPenaltyMillisRemaining = j.at("leaverPenaltyMillisRemaining").get<uint64_t>(); 
  }
}