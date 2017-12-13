#pragma once
#include<lol/base_def.hpp> 
#include <lol/def/LolClashLoginSessionState.hpp>
namespace lol {
  struct LolClashLoginSession { 
    LolClashLoginSessionState state;
    std::optional<uint64_t> summonerId; 
  };
  void to_json(json& j, const LolClashLoginSession& v) {
  j["state"] = v.state; 
  j["summonerId"] = v.summonerId; 
  }
  void from_json(const json& j, LolClashLoginSession& v) {
  v.state = j.at("state").get<LolClashLoginSessionState>(); 
  v.summonerId = j.at("summonerId").get<std::optional<uint64_t>>(); 
  }
}