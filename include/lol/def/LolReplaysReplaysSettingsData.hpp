#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolReplaysReplaysSettingsData { 
    std::string replays_folder_path;
    std::string highlights_folder_path; 
  };
  inline void to_json(json& j, const LolReplaysReplaysSettingsData& v) {
    j["replays-folder-path"] = v.replays_folder_path; 
    j["highlights-folder-path"] = v.highlights_folder_path; 
  }
  inline void from_json(const json& j, LolReplaysReplaysSettingsData& v) {
    v.replays_folder_path = j.at("replays-folder-path").get<std::string>(); 
    v.highlights_folder_path = j.at("highlights-folder-path").get<std::string>(); 
  }
}