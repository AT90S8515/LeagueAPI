#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolLobbyServiceProxyPayload { 
    std::string method;
    std::string url;
    std::string body; 
  };
  inline void to_json(json& j, const LolLobbyServiceProxyPayload& v) {
    j["method"] = v.method; 
    j["url"] = v.url; 
    j["body"] = v.body; 
  }
  inline void from_json(const json& j, LolLobbyServiceProxyPayload& v) {
    v.method = j.at("method").get<std::string>(); 
    v.url = j.at("url").get<std::string>(); 
    v.body = j.at("body").get<std::string>(); 
  }
}