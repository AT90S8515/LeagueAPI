#pragma once
#include <leagueapi/base.hpp>

namespace leagueapi {
  struct LolChampSelectLegacyChampSelectTimer { /**/ 
    int64_t adjustedTimeLeftInPhase;/**/
    bool isInfinite;/**/
    uint64_t internalNowInEpochMs;/**/
    int64_t timeLeftInPhase;/**/
    int64_t totalTimeInPhase;/**/
    std::string phase;/**/
    int32_t adjustedTimeLeftInPhaseInSec;/**/
    int32_t timeLeftInPhaseInSec;/**/
  };
  static void to_json(json& j, const LolChampSelectLegacyChampSelectTimer& v) { 
    j["adjustedTimeLeftInPhase"] = v.adjustedTimeLeftInPhase;
    j["isInfinite"] = v.isInfinite;
    j["internalNowInEpochMs"] = v.internalNowInEpochMs;
    j["timeLeftInPhase"] = v.timeLeftInPhase;
    j["totalTimeInPhase"] = v.totalTimeInPhase;
    j["phase"] = v.phase;
    j["adjustedTimeLeftInPhaseInSec"] = v.adjustedTimeLeftInPhaseInSec;
    j["timeLeftInPhaseInSec"] = v.timeLeftInPhaseInSec;
  }
  static void from_json(const json& j, LolChampSelectLegacyChampSelectTimer& v) { 
    v.adjustedTimeLeftInPhase = j.at("adjustedTimeLeftInPhase").get<int64_t>(); 
    v.isInfinite = j.at("isInfinite").get<bool>(); 
    v.internalNowInEpochMs = j.at("internalNowInEpochMs").get<uint64_t>(); 
    v.timeLeftInPhase = j.at("timeLeftInPhase").get<int64_t>(); 
    v.totalTimeInPhase = j.at("totalTimeInPhase").get<int64_t>(); 
    v.phase = j.at("phase").get<std::string>(); 
    v.adjustedTimeLeftInPhaseInSec = j.at("adjustedTimeLeftInPhaseInSec").get<int32_t>(); 
    v.timeLeftInPhaseInSec = j.at("timeLeftInPhaseInSec").get<int32_t>(); 
  }
} 