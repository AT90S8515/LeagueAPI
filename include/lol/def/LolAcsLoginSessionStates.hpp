#pragma once
#include "../base_def.hpp" 
namespace lol {
  enum struct LolAcsLoginSessionStates {  
    ERROR_e = 3,
    IN_PROGRESS_e = 0,
    LOGGING_OUT_e = 2,
    SUCCEEDED_e = 1,
  };
  inline void to_json(json& j, const LolAcsLoginSessionStates& v) {
    if(v == LolAcsLoginSessionStates::ERROR_e) {
      j = "ERROR";
      return;
    }
    if(v == LolAcsLoginSessionStates::IN_PROGRESS_e) {
      j = "IN_PROGRESS";
      return;
    }
    if(v == LolAcsLoginSessionStates::LOGGING_OUT_e) {
      j = "LOGGING_OUT";
      return;
    }
    if(v == LolAcsLoginSessionStates::SUCCEEDED_e) {
      j = "SUCCEEDED";
      return;
    }
  }
  inline void from_json(const json& j, LolAcsLoginSessionStates& v) {
    if(j.get<std::string>() == "ERROR") {
      v = LolAcsLoginSessionStates::ERROR_e;
      return;
    } 
    if(j.get<std::string>() == "IN_PROGRESS") {
      v = LolAcsLoginSessionStates::IN_PROGRESS_e;
      return;
    } 
    if(j.get<std::string>() == "LOGGING_OUT") {
      v = LolAcsLoginSessionStates::LOGGING_OUT_e;
      return;
    } 
    if(j.get<std::string>() == "SUCCEEDED") {
      v = LolAcsLoginSessionStates::SUCCEEDED_e;
      return;
    } 
  }
}