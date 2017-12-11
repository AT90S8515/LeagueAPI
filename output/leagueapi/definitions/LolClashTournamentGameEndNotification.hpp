#pragma once
#include <leagueapi/base.hpp>
#include "<leagueapi/definitions/LolClashRosterNotifyReason.hpp>"
#include "<leagueapi/definitions/Bracket.hpp>"

namespace leagueapi {
  struct LolClashTournamentGameEndNotification { /**/ 
    int64_t timestamp;/**/
    int64_t currentMatchId;/**/
    Bracket bracket;/**/
    LolClashRosterNotifyReason notifyReason;/**/
    int64_t tournamentId;/**/
  };
  static void to_json(json& j, const LolClashTournamentGameEndNotification& v) { 
    j["timestamp"] = v.timestamp;
    j["currentMatchId"] = v.currentMatchId;
    j["bracket"] = v.bracket;
    j["notifyReason"] = v.notifyReason;
    j["tournamentId"] = v.tournamentId;
  }
  static void from_json(const json& j, LolClashTournamentGameEndNotification& v) { 
    v.timestamp = j.at("timestamp").get<int64_t>(); 
    v.currentMatchId = j.at("currentMatchId").get<int64_t>(); 
    v.bracket = j.at("bracket").get<Bracket>(); 
    v.notifyReason = j.at("notifyReason").get<LolClashRosterNotifyReason>(); 
    v.tournamentId = j.at("tournamentId").get<int64_t>(); 
  }
} 