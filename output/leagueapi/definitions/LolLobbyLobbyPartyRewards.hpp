#pragma once
#include <leagueapi/base.hpp>
#include "<leagueapi/definitions/LolLobbyPartyReward.hpp>"

namespace leagueapi {
  struct LolLobbyLobbyPartyRewards { /**/ 
    int32_t queueId;/**/
    std::vector<LolLobbyPartyReward> partyRewards;/**/
    bool isCustom;/**/
    bool isEnabled;/**/
  };
  static void to_json(json& j, const LolLobbyLobbyPartyRewards& v) { 
    j["queueId"] = v.queueId;
    j["partyRewards"] = v.partyRewards;
    j["isCustom"] = v.isCustom;
    j["isEnabled"] = v.isEnabled;
  }
  static void from_json(const json& j, LolLobbyLobbyPartyRewards& v) { 
    v.queueId = j.at("queueId").get<int32_t>(); 
    v.partyRewards = j.at("partyRewards").get<std::vector<LolLobbyPartyReward>>(); 
    v.isCustom = j.at("isCustom").get<bool>(); 
    v.isEnabled = j.at("isEnabled").get<bool>(); 
  }
} 