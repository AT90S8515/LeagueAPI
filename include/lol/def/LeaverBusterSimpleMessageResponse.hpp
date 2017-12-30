#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LeaverBusterSimpleMessageResponse { 
    uint64_t accountId;
    std::string command;
    std::string msgId; 
  };
  inline void to_json(json& j, const LeaverBusterSimpleMessageResponse& v) {
    j["accountId"] = v.accountId; 
    j["command"] = v.command; 
    j["msgId"] = v.msgId; 
  }
  inline void from_json(const json& j, LeaverBusterSimpleMessageResponse& v) {
    v.accountId = j.at("accountId").get<uint64_t>(); 
    v.command = j.at("command").get<std::string>(); 
    v.msgId = j.at("msgId").get<std::string>(); 
  }
}