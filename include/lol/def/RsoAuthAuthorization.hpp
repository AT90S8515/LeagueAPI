#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct RsoAuthAuthorization { 
    std::string currentPlatformId;
    std::string subject;
    uint64_t currentAccountId; 
  };
  inline void to_json(json& j, const RsoAuthAuthorization& v) {
    j["currentPlatformId"] = v.currentPlatformId; 
    j["subject"] = v.subject; 
    j["currentAccountId"] = v.currentAccountId; 
  }
  inline void from_json(const json& j, RsoAuthAuthorization& v) {
    v.currentPlatformId = j.at("currentPlatformId").get<std::string>(); 
    v.subject = j.at("subject").get<std::string>(); 
    v.currentAccountId = j.at("currentAccountId").get<uint64_t>(); 
  }
}