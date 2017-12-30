#pragma once
#include "../base_def.hpp" 
#include "SubState.hpp"
#include "Position.hpp"
namespace lol {
  struct PhaseRosterSubDTO { 
    int32_t bet;
    uint64_t replacedPlayerId;
    int32_t pay;
    Position position;
    uint64_t playerId;
    SubState subState; 
  };
  inline void to_json(json& j, const PhaseRosterSubDTO& v) {
    j["bet"] = v.bet; 
    j["replacedPlayerId"] = v.replacedPlayerId; 
    j["pay"] = v.pay; 
    j["position"] = v.position; 
    j["playerId"] = v.playerId; 
    j["subState"] = v.subState; 
  }
  inline void from_json(const json& j, PhaseRosterSubDTO& v) {
    v.bet = j.at("bet").get<int32_t>(); 
    v.replacedPlayerId = j.at("replacedPlayerId").get<uint64_t>(); 
    v.pay = j.at("pay").get<int32_t>(); 
    v.position = j.at("position").get<Position>(); 
    v.playerId = j.at("playerId").get<uint64_t>(); 
    v.subState = j.at("subState").get<SubState>(); 
  }
}