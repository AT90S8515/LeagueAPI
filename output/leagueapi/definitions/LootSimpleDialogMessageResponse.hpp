#pragma once
#include <leagueapi/base.hpp>

namespace leagueapi {
  struct LootSimpleDialogMessageResponse { /**/ 
    std::string command;/**/
    std::string msgId;/**/
    uint64_t accountId;/**/
  };
  static void to_json(json& j, const LootSimpleDialogMessageResponse& v) { 
    j["command"] = v.command;
    j["msgId"] = v.msgId;
    j["accountId"] = v.accountId;
  }
  static void from_json(const json& j, LootSimpleDialogMessageResponse& v) { 
    v.command = j.at("command").get<std::string>(); 
    v.msgId = j.at("msgId").get<std::string>(); 
    v.accountId = j.at("accountId").get<uint64_t>(); 
  }
} 