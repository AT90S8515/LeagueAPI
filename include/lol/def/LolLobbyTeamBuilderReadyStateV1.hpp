#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolLobbyTeamBuilderReadyStateV1 { 
    std::vector<int32_t> allowablePremadeSizes;
    bool requiredPositionCoverageMet;
    bool readyToMatchmake;
    bool premadeSizeAllowed; 
  };
  inline void to_json(json& j, const LolLobbyTeamBuilderReadyStateV1& v) {
    j["allowablePremadeSizes"] = v.allowablePremadeSizes; 
    j["requiredPositionCoverageMet"] = v.requiredPositionCoverageMet; 
    j["readyToMatchmake"] = v.readyToMatchmake; 
    j["premadeSizeAllowed"] = v.premadeSizeAllowed; 
  }
  inline void from_json(const json& j, LolLobbyTeamBuilderReadyStateV1& v) {
    v.allowablePremadeSizes = j.at("allowablePremadeSizes").get<std::vector<int32_t>>(); 
    v.requiredPositionCoverageMet = j.at("requiredPositionCoverageMet").get<bool>(); 
    v.readyToMatchmake = j.at("readyToMatchmake").get<bool>(); 
    v.premadeSizeAllowed = j.at("premadeSizeAllowed").get<bool>(); 
  }
}