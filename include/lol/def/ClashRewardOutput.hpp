#pragma once
#include "../base_def.hpp" 
#include "ClashRewardTime.hpp"
#include "ClashRewardDefinition.hpp"
namespace lol {
  struct ClashRewardOutput { 
    ClashRewardTime show;
    ClashRewardDefinition primary;
    ClashRewardTime grant;
    ClashRewardDefinition alternative; 
  };
  inline void to_json(json& j, const ClashRewardOutput& v) {
    j["show"] = v.show; 
    j["primary"] = v.primary; 
    j["grant"] = v.grant; 
    j["alternative"] = v.alternative; 
  }
  inline void from_json(const json& j, ClashRewardOutput& v) {
    v.show = j.at("show").get<ClashRewardTime>(); 
    v.primary = j.at("primary").get<ClashRewardDefinition>(); 
    v.grant = j.at("grant").get<ClashRewardTime>(); 
    v.alternative = j.at("alternative").get<ClashRewardDefinition>(); 
  }
}