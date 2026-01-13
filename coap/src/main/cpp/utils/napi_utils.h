

#ifndef COAP_OPENHARMONY_NAPI_UTILS_H
#define COAP_OPENHARMONY_NAPI_UTILS_H

#include <string>
#include "napi/native_api.h"
namespace napi_utils {
    std::string get_string_from_napi_value(napi_env env, napi_value value);
    int32_t get_int32_from_napi_value(napi_env env, napi_value value);
    int64_t get_int64_from_napi_value(napi_env env, napi_value value);
    bool get_bool_from_napi_value(napi_env env, napi_value value);
    napi_value get_named_property_from_napi_value(napi_env env, napi_value object, const std::string &name);
    napi_value create_string_for_napi_value(napi_env env, const std::string &str);
    napi_value create_undefined_for_napi_value(napi_env env);
    int32_t get_int32_from_named_property(napi_env env, napi_value object, const std::string &name);
    int64_t get_int64_from_named_property(napi_env env, napi_value object, const std::string &name);
    std::string get_string_from_named_property(napi_env env, napi_value object, const std::string &name);
    bool get_bool_from_named_property(napi_env env, napi_value object, const std::string &name);
}
#endif //COAP_OPENHARMONY_NAPI_UTILS_H
