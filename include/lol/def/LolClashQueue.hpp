#pragma once
#include "../base_def.hpp" 
#include "LolClashQueueReward.hpp"
#include "LolClashQueueAvailability.hpp"
#include "LolClashQueueGameTypeConfig.hpp"
#include "LolClashQueueGameCategory.hpp"
namespace lol {
  struct LolClashQueue { 
    LolClashQueueAvailability queueAvailability;
    bool isTeamOnly;
    int32_t maximumParticipantListSize;
    int32_t numPlayersPerTeam;
    std::string description;
    LolClashQueueGameTypeConfig gameTypeConfig;
    LolClashQueueGameCategory category;
    std::string gameMode;
    std::string gameMutator;
    bool isTeamBuilderManaged;
    std::string type;
    std::string detailedDescription;
    bool isRanked;
    std::string name;
    bool spectatorEnabled;
    int32_t mapId;
    uint32_t maxLevel;
    uint32_t maxSummonerLevelForFirstWinOfTheDay;
    int32_t minimumParticipantListSize;
    std::string shortName;
    int32_t id;
    LolClashQueueReward queueRewards;
    bool areFreeChampionsAllowed;
    uint32_t minLevel; 
  };
  inline void to_json(json& j, const LolClashQueue& v) {
    j["queueAvailability"] = v.queueAvailability; 
    j["isTeamOnly"] = v.isTeamOnly; 
    j["maximumParticipantListSize"] = v.maximumParticipantListSize; 
    j["numPlayersPerTeam"] = v.numPlayersPerTeam; 
    j["description"] = v.description; 
    j["gameTypeConfig"] = v.gameTypeConfig; 
    j["category"] = v.category; 
    j["gameMode"] = v.gameMode; 
    j["gameMutator"] = v.gameMutator; 
    j["isTeamBuilderManaged"] = v.isTeamBuilderManaged; 
    j["type"] = v.type; 
    j["detailedDescription"] = v.detailedDescription; 
    j["isRanked"] = v.isRanked; 
    j["name"] = v.name; 
    j["spectatorEnabled"] = v.spectatorEnabled; 
    j["mapId"] = v.mapId; 
    j["maxLevel"] = v.maxLevel; 
    j["maxSummonerLevelForFirstWinOfTheDay"] = v.maxSummonerLevelForFirstWinOfTheDay; 
    j["minimumParticipantListSize"] = v.minimumParticipantListSize; 
    j["shortName"] = v.shortName; 
    j["id"] = v.id; 
    j["queueRewards"] = v.queueRewards; 
    j["areFreeChampionsAllowed"] = v.areFreeChampionsAllowed; 
    j["minLevel"] = v.minLevel; 
  }
  inline void from_json(const json& j, LolClashQueue& v) {
    v.queueAvailability = j.at("queueAvailability").get<LolClashQueueAvailability>(); 
    v.isTeamOnly = j.at("isTeamOnly").get<bool>(); 
    v.maximumParticipantListSize = j.at("maximumParticipantListSize").get<int32_t>(); 
    v.numPlayersPerTeam = j.at("numPlayersPerTeam").get<int32_t>(); 
    v.description = j.at("description").get<std::string>(); 
    v.gameTypeConfig = j.at("gameTypeConfig").get<LolClashQueueGameTypeConfig>(); 
    v.category = j.at("category").get<LolClashQueueGameCategory>(); 
    v.gameMode = j.at("gameMode").get<std::string>(); 
    v.gameMutator = j.at("gameMutator").get<std::string>(); 
    v.isTeamBuilderManaged = j.at("isTeamBuilderManaged").get<bool>(); 
    v.type = j.at("type").get<std::string>(); 
    v.detailedDescription = j.at("detailedDescription").get<std::string>(); 
    v.isRanked = j.at("isRanked").get<bool>(); 
    v.name = j.at("name").get<std::string>(); 
    v.spectatorEnabled = j.at("spectatorEnabled").get<bool>(); 
    v.mapId = j.at("mapId").get<int32_t>(); 
    v.maxLevel = j.at("maxLevel").get<uint32_t>(); 
    v.maxSummonerLevelForFirstWinOfTheDay = j.at("maxSummonerLevelForFirstWinOfTheDay").get<uint32_t>(); 
    v.minimumParticipantListSize = j.at("minimumParticipantListSize").get<int32_t>(); 
    v.shortName = j.at("shortName").get<std::string>(); 
    v.id = j.at("id").get<int32_t>(); 
    v.queueRewards = j.at("queueRewards").get<LolClashQueueReward>(); 
    v.areFreeChampionsAllowed = j.at("areFreeChampionsAllowed").get<bool>(); 
    v.minLevel = j.at("minLevel").get<uint32_t>(); 
  }
}