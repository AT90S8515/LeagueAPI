#pragma once
#include "../base_def.hpp" 
#include "ServiceStatusIncident_Severity.hpp"
namespace lol {
  struct TickerMessage { 
    std::string message;
    std::string createdAt;
    std::string heading;
    ServiceStatusIncident_Severity severity;
    std::string updatedAt; 
  };
  inline void to_json(json& j, const TickerMessage& v) {
    j["message"] = v.message; 
    j["createdAt"] = v.createdAt; 
    j["heading"] = v.heading; 
    j["severity"] = v.severity; 
    j["updatedAt"] = v.updatedAt; 
  }
  inline void from_json(const json& j, TickerMessage& v) {
    v.message = j.at("message").get<std::string>(); 
    v.createdAt = j.at("createdAt").get<std::string>(); 
    v.heading = j.at("heading").get<std::string>(); 
    v.severity = j.at("severity").get<ServiceStatusIncident_Severity>(); 
    v.updatedAt = j.at("updatedAt").get<std::string>(); 
  }
}