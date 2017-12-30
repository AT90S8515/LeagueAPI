#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolLoginRSOPlayerCredentials { 
    std::string password;
    std::string platformId;
    std::string username; 
  };
  inline void to_json(json& j, const LolLoginRSOPlayerCredentials& v) {
    j["password"] = v.password; 
    j["platformId"] = v.platformId; 
    j["username"] = v.username; 
  }
  inline void from_json(const json& j, LolLoginRSOPlayerCredentials& v) {
    v.password = j.at("password").get<std::string>(); 
    v.platformId = j.at("platformId").get<std::string>(); 
    v.username = j.at("username").get<std::string>(); 
  }
}