#pragma once
#include "../base_def.hpp" 
#include "LolPurchaseWidgetBalance.hpp"
namespace lol {
  struct LolPurchaseWidgetWallet { 
    std::vector<LolPurchaseWidgetBalance> balances;
    uint64_t accountId;
    int32_t version; 
  };
  inline void to_json(json& j, const LolPurchaseWidgetWallet& v) {
    j["balances"] = v.balances; 
    j["accountId"] = v.accountId; 
    j["version"] = v.version; 
  }
  inline void from_json(const json& j, LolPurchaseWidgetWallet& v) {
    v.balances = j.at("balances").get<std::vector<LolPurchaseWidgetBalance>>(); 
    v.accountId = j.at("accountId").get<uint64_t>(); 
    v.version = j.at("version").get<int32_t>(); 
  }
}