#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolGeoinfoWhereAmIResponse { 
    std::string country;
    std::string region;
    std::string city; 
  };
  inline void to_json(json& j, const LolGeoinfoWhereAmIResponse& v) {
    j["country"] = v.country; 
    j["region"] = v.region; 
    j["city"] = v.city; 
  }
  inline void from_json(const json& j, LolGeoinfoWhereAmIResponse& v) {
    v.country = j.at("country").get<std::string>(); 
    v.region = j.at("region").get<std::string>(); 
    v.city = j.at("city").get<std::string>(); 
  }
}