#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct MissionProgressDTO { 
    int32_t lastViewedProgress;
    int32_t currentProgress;
    int32_t totalCount; 
  };
  inline void to_json(json& j, const MissionProgressDTO& v) {
    j["lastViewedProgress"] = v.lastViewedProgress; 
    j["currentProgress"] = v.currentProgress; 
    j["totalCount"] = v.totalCount; 
  }
  inline void from_json(const json& j, MissionProgressDTO& v) {
    v.lastViewedProgress = j.at("lastViewedProgress").get<int32_t>(); 
    v.currentProgress = j.at("currentProgress").get<int32_t>(); 
    v.totalCount = j.at("totalCount").get<int32_t>(); 
  }
}