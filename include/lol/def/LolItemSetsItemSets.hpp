#pragma once
#include "../base_def.hpp" 
#include "LolItemSetsItemSet.hpp"
namespace lol {
  struct LolItemSetsItemSets { 
    uint64_t timestamp;
    std::vector<LolItemSetsItemSet> itemSets;
    uint64_t accountId; 
  };
  inline void to_json(json& j, const LolItemSetsItemSets& v) {
    j["timestamp"] = v.timestamp; 
    j["itemSets"] = v.itemSets; 
    j["accountId"] = v.accountId; 
  }
  inline void from_json(const json& j, LolItemSetsItemSets& v) {
    v.timestamp = j.at("timestamp").get<uint64_t>(); 
    v.itemSets = j.at("itemSets").get<std::vector<LolItemSetsItemSet>>(); 
    v.accountId = j.at("accountId").get<uint64_t>(); 
  }
}