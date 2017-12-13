#pragma once
#include<lol/base_def.hpp> 
#include <lol/def/LolGameQueuesQueueGameTypeConfig.hpp>
namespace lol {
  struct LolGameQueuesLoginDataPacket { 
    std::vector<LolGameQueuesQueueGameTypeConfig> gameTypeConfigs; 
  };
  void to_json(json& j, const LolGameQueuesLoginDataPacket& v) {
  j["gameTypeConfigs"] = v.gameTypeConfigs; 
  }
  void from_json(const json& j, LolGameQueuesLoginDataPacket& v) {
  v.gameTypeConfigs = j.at("gameTypeConfigs").get<std::vector<LolGameQueuesQueueGameTypeConfig>>(); 
  }
}