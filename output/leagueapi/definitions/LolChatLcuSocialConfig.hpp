#pragma once
#include <leagueapi/base.hpp>

namespace leagueapi {
  struct LolChatLcuSocialConfig { /**/ 
    bool ForceChatFilter;/**/
    uint64_t QueueJobGraceSeconds;/**/
    bool AggressiveScanning;/**/
    bool SilenceChatWhileInGame;/**/
  };
  static void to_json(json& j, const LolChatLcuSocialConfig& v) { 
    j["ForceChatFilter"] = v.ForceChatFilter;
    j["QueueJobGraceSeconds"] = v.QueueJobGraceSeconds;
    j["AggressiveScanning"] = v.AggressiveScanning;
    j["SilenceChatWhileInGame"] = v.SilenceChatWhileInGame;
  }
  static void from_json(const json& j, LolChatLcuSocialConfig& v) { 
    v.ForceChatFilter = j.at("ForceChatFilter").get<bool>(); 
    v.QueueJobGraceSeconds = j.at("QueueJobGraceSeconds").get<uint64_t>(); 
    v.AggressiveScanning = j.at("AggressiveScanning").get<bool>(); 
    v.SilenceChatWhileInGame = j.at("SilenceChatWhileInGame").get<bool>(); 
  }
} 