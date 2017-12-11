#pragma once
#include <leagueapi/base.hpp>
#include "<leagueapi/definitions/BindingFullArgumentHelp.hpp>"
#include "<leagueapi/definitions/BindingFullTypeIdentifier.hpp>"

namespace leagueapi {
  struct BindingFullFunctionHelp { /*Describes a function.*/ 
    std::vector<BindingFullArgumentHelp> arguments;/**/
    std::string nameSpace;/**/
    std::string help;/**/
    bool threadSafe;/**/
    std::vector<std::string> tags;/**/
    std::string async;/**/
    std::string description;/**/
    std::string name;/**/
    BindingFullTypeIdentifier returns;/**/
  };
  static void to_json(json& j, const BindingFullFunctionHelp& v) { 
    j["arguments"] = v.arguments;
    j["nameSpace"] = v.nameSpace;
    j["help"] = v.help;
    j["threadSafe"] = v.threadSafe;
    j["tags"] = v.tags;
    j["async"] = v.async;
    j["description"] = v.description;
    j["name"] = v.name;
    j["returns"] = v.returns;
  }
  static void from_json(const json& j, BindingFullFunctionHelp& v) { 
    v.arguments = j.at("arguments").get<std::vector<BindingFullArgumentHelp>>(); 
    v.nameSpace = j.at("nameSpace").get<std::string>(); 
    v.help = j.at("help").get<std::string>(); 
    v.threadSafe = j.at("threadSafe").get<bool>(); 
    v.tags = j.at("tags").get<std::vector<std::string>>(); 
    v.async = j.at("async").get<std::string>(); 
    v.description = j.at("description").get<std::string>(); 
    v.name = j.at("name").get<std::string>(); 
    v.returns = j.at("returns").get<BindingFullTypeIdentifier>(); 
  }
} 