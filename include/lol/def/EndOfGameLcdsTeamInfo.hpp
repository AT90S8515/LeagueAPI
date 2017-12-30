#pragma once
#include "../base_def.hpp" 
#include "EndOfGameLcdsTeamId.hpp"
namespace lol {
  struct EndOfGameLcdsTeamInfo { 
    EndOfGameLcdsTeamId teamId;
    std::string name;
    std::string tag;
    std::string memberStatusString;
    int64_t secondsUntilEligibleForDeletion; 
  };
  inline void to_json(json& j, const EndOfGameLcdsTeamInfo& v) {
    j["teamId"] = v.teamId; 
    j["name"] = v.name; 
    j["tag"] = v.tag; 
    j["memberStatusString"] = v.memberStatusString; 
    j["secondsUntilEligibleForDeletion"] = v.secondsUntilEligibleForDeletion; 
  }
  inline void from_json(const json& j, EndOfGameLcdsTeamInfo& v) {
    v.teamId = j.at("teamId").get<EndOfGameLcdsTeamId>(); 
    v.name = j.at("name").get<std::string>(); 
    v.tag = j.at("tag").get<std::string>(); 
    v.memberStatusString = j.at("memberStatusString").get<std::string>(); 
    v.secondsUntilEligibleForDeletion = j.at("secondsUntilEligibleForDeletion").get<int64_t>(); 
  }
}