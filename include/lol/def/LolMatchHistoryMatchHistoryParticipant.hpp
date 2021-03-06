#pragma once
#include "../base_def.hpp" 
#include "LolMatchHistoryMatchHistoryTimeline.hpp"
#include "LolMatchHistoryMatchHistoryParticipantStatistics.hpp"
namespace lol {
  struct LolMatchHistoryMatchHistoryParticipant { 
    uint16_t participantId;
    uint16_t teamId;
    int32_t championId;
    uint16_t spell1Id;
    uint16_t spell2Id;
    std::string highestAchievedSeasonTier;
    LolMatchHistoryMatchHistoryParticipantStatistics stats;
    LolMatchHistoryMatchHistoryTimeline timeline; 
  };
  inline void to_json(json& j, const LolMatchHistoryMatchHistoryParticipant& v) {
    j["participantId"] = v.participantId; 
    j["teamId"] = v.teamId; 
    j["championId"] = v.championId; 
    j["spell1Id"] = v.spell1Id; 
    j["spell2Id"] = v.spell2Id; 
    j["highestAchievedSeasonTier"] = v.highestAchievedSeasonTier; 
    j["stats"] = v.stats; 
    j["timeline"] = v.timeline; 
  }
  inline void from_json(const json& j, LolMatchHistoryMatchHistoryParticipant& v) {
    v.participantId = j.at("participantId").get<uint16_t>(); 
    v.teamId = j.at("teamId").get<uint16_t>(); 
    v.championId = j.at("championId").get<int32_t>(); 
    v.spell1Id = j.at("spell1Id").get<uint16_t>(); 
    v.spell2Id = j.at("spell2Id").get<uint16_t>(); 
    v.highestAchievedSeasonTier = j.at("highestAchievedSeasonTier").get<std::string>(); 
    v.stats = j.at("stats").get<LolMatchHistoryMatchHistoryParticipantStatistics>(); 
    v.timeline = j.at("timeline").get<LolMatchHistoryMatchHistoryTimeline>(); 
  }
}