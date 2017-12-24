#pragma once
#include "../base_def.hpp" 
#include "LolGameQueuesQueueGameTypeConfig.hpp"
#include "LolGameQueuesQueueAvailability.hpp"
namespace lol {
  struct LolGameQueuesQueueCustomGameSubcategory { 
    uint32_t maxLevel;
    std::string gameMutator;
    int32_t mapId;
    int32_t maxPlayerCount;
    std::string gameMode;
    LolGameQueuesQueueAvailability queueAvailability;
    std::vector<LolGameQueuesQueueGameTypeConfig> mutators;
    int32_t maximumParticipantListSize;
    int32_t minimumParticipantListSize;
    uint32_t minLevel;
    int32_t numPlayersPerTeam; 
  };
  inline void to_json(json& j, const LolGameQueuesQueueCustomGameSubcategory& v) {
    j["maxLevel"] = v.maxLevel; 
    j["gameMutator"] = v.gameMutator; 
    j["mapId"] = v.mapId; 
    j["maxPlayerCount"] = v.maxPlayerCount; 
    j["gameMode"] = v.gameMode; 
    j["queueAvailability"] = v.queueAvailability; 
    j["mutators"] = v.mutators; 
    j["maximumParticipantListSize"] = v.maximumParticipantListSize; 
    j["minimumParticipantListSize"] = v.minimumParticipantListSize; 
    j["minLevel"] = v.minLevel; 
    j["numPlayersPerTeam"] = v.numPlayersPerTeam; 
  }
  inline void from_json(const json& j, LolGameQueuesQueueCustomGameSubcategory& v) {
    v.maxLevel = j.at("maxLevel").get<uint32_t>(); 
    v.gameMutator = j.at("gameMutator").get<std::string>(); 
    v.mapId = j.at("mapId").get<int32_t>(); 
    v.maxPlayerCount = j.at("maxPlayerCount").get<int32_t>(); 
    v.gameMode = j.at("gameMode").get<std::string>(); 
    v.queueAvailability = j.at("queueAvailability").get<LolGameQueuesQueueAvailability>(); 
    v.mutators = j.at("mutators").get<std::vector<LolGameQueuesQueueGameTypeConfig>>(); 
    v.maximumParticipantListSize = j.at("maximumParticipantListSize").get<int32_t>(); 
    v.minimumParticipantListSize = j.at("minimumParticipantListSize").get<int32_t>(); 
    v.minLevel = j.at("minLevel").get<uint32_t>(); 
    v.numPlayersPerTeam = j.at("numPlayersPerTeam").get<int32_t>(); 
  }
}