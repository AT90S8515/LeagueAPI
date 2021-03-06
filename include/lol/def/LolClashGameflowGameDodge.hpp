#pragma once
#include "../base_def.hpp" 
#include "LolClashMatchmakingDodgeState.hpp"
namespace lol {
  struct LolClashGameflowGameDodge { 
    LolClashMatchmakingDodgeState state;
    std::vector<uint64_t> dodgeIds; 
  };
  inline void to_json(json& j, const LolClashGameflowGameDodge& v) {
    j["state"] = v.state; 
    j["dodgeIds"] = v.dodgeIds; 
  }
  inline void from_json(const json& j, LolClashGameflowGameDodge& v) {
    v.state = j.at("state").get<LolClashMatchmakingDodgeState>(); 
    v.dodgeIds = j.at("dodgeIds").get<std::vector<uint64_t>>(); 
  }
}