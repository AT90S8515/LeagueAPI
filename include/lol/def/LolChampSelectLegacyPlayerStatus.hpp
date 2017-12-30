#pragma once
#include "../base_def.hpp" 
#include "LolChampSelectLegacyLobbyStatus.hpp"
namespace lol {
  struct LolChampSelectLegacyPlayerStatus { 
    std::optional<LolChampSelectLegacyLobbyStatus> lastQueuedLobbyStatus;
    std::optional<LolChampSelectLegacyLobbyStatus> currentLobbyStatus; 
  };
  inline void to_json(json& j, const LolChampSelectLegacyPlayerStatus& v) {
    if(v.lastQueuedLobbyStatus)
      j["lastQueuedLobbyStatus"] = *v.lastQueuedLobbyStatus;
    if(v.currentLobbyStatus)
      j["currentLobbyStatus"] = *v.currentLobbyStatus;
  }
  inline void from_json(const json& j, LolChampSelectLegacyPlayerStatus& v) {
    if(auto it = j.find("lastQueuedLobbyStatus"); it != j.end() && !it->is_null())
      v.lastQueuedLobbyStatus = it->get<std::optional<LolChampSelectLegacyLobbyStatus>>(); 
    if(auto it = j.find("currentLobbyStatus"); it != j.end() && !it->is_null())
      v.currentLobbyStatus = it->get<std::optional<LolChampSelectLegacyLobbyStatus>>(); 
  }
}