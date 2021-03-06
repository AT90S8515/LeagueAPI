#pragma once
#include "../base_def.hpp" 
#include "LolLobbyQueueAvailability.hpp"
namespace lol {
  struct LolLobbyQueueCustomGame { 
    LolLobbyQueueAvailability queueAvailability; 
  };
  inline void to_json(json& j, const LolLobbyQueueCustomGame& v) {
    j["queueAvailability"] = v.queueAvailability; 
  }
  inline void from_json(const json& j, LolLobbyQueueCustomGame& v) {
    v.queueAvailability = j.at("queueAvailability").get<LolLobbyQueueAvailability>(); 
  }
}