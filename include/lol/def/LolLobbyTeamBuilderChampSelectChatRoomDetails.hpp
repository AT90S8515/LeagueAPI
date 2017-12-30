#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolLobbyTeamBuilderChampSelectChatRoomDetails { 
    std::string chatRoomName;
    std::optional<std::string> chatRoomPassword; 
  };
  inline void to_json(json& j, const LolLobbyTeamBuilderChampSelectChatRoomDetails& v) {
    j["chatRoomName"] = v.chatRoomName; 
    if(v.chatRoomPassword)
      j["chatRoomPassword"] = *v.chatRoomPassword;
  }
  inline void from_json(const json& j, LolLobbyTeamBuilderChampSelectChatRoomDetails& v) {
    v.chatRoomName = j.at("chatRoomName").get<std::string>(); 
    if(auto it = j.find("chatRoomPassword"); it != j.end() && !it->is_null())
      v.chatRoomPassword = it->get<std::optional<std::string>>(); 
  }
}