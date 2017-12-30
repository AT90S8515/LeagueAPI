#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolChampSelectLegacyChampSelectMySelection.hpp"
namespace lol {
  template<typename T>
  inline Result<json> PatchLolChampSelectLegacyV1SessionMySelection(T& _client, const LolChampSelectLegacyChampSelectMySelection& selection)
  {
    try {
      return ToResult<json>(_client.https.request("patch", "/lol-champ-select-legacy/v1/session/my-selection?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(selection).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<json>(e.code());
    }
  }
  template<typename T>
  inline void PatchLolChampSelectLegacyV1SessionMySelection(T& _client, const LolChampSelectLegacyChampSelectMySelection& selection, std::function<void(T&, const Result<json>&)> cb)
  {
    _client.httpsa.request("patch", "/lol-champ-select-legacy/v1/session/my-selection?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(selection).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<json>(e));
            else
              cb(_client, ToResult<json>(response));
        });
  }
}