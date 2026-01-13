

#include "napi/native_api.h"
#include "hilog_helper.h"
#include <cstdint>
#include <string>
namespace napi_utils {
    std::string get_string_from_napi_value(napi_env env, napi_value value){
        size_t resLen;
        napi_status status;
        status = napi_get_value_string_utf8(env, value, nullptr, 0, &resLen);
        if (status != napi_ok) {
            LOGE("napi get string length failed");
            return "";
        }
        std::string res(resLen, '\0');
        status = napi_get_value_string_utf8(env, value, &res[0], resLen + 1, &resLen);
        if (status != napi_ok) {
            LOGE("napi get string failed");
            return "";
        }
        return res;
    }

    int64_t get_int64_from_napi_value(napi_env env, napi_value value){
        int64_t res = 0;
        napi_get_value_int64(env, value, &res);
        return res;
    }

    int32_t get_int32_from_napi_value(napi_env env, napi_value value){
        int32_t res = 0;
        napi_get_value_int32(env, value, &res);
        return res;
    }

    bool get_bool_from_napi_value(napi_env env, napi_value value){
        bool res = false;
        napi_get_value_bool(env, value, &res);
        return res;
    }

    napi_value get_named_property_from_napi_value(napi_env env, napi_value object, const std::string &name){
        napi_value value = nullptr;
        napi_get_named_property(env, object, name.c_str(), &value);
        return value;
    }

    napi_value create_string_for_napi_value(napi_env env, const std::string &str){
        napi_value value = nullptr;
        if (napi_create_string_utf8(env, str.c_str(), strlen(str.c_str()), &value) != napi_ok) {
            return nullptr;
        }
        return value;
    }

    napi_value create_undefined_for_napi_value(napi_env env){
        napi_value undefined = nullptr;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int32_t get_int32_from_named_property(napi_env env, napi_value object, const std::string &name){
        napi_value value = get_named_property_from_napi_value(env, object, name);
        if (value == nullptr) {
            return 0;
        }
        napi_valuetype valuetype;
        napi_typeof(env, value, &valuetype);
        if (valuetype != napi_number) {
            return 0;
        }
        return get_int32_from_napi_value(env, value);
    }

    int64_t get_int64_from_named_property(napi_env env, napi_value object, const std::string &name){
        napi_value value = get_named_property_from_napi_value(env, object, name);
        if (value == nullptr) {
            return 0;
        }
        napi_valuetype valuetype;
        napi_typeof(env, value, &valuetype);
        if (valuetype != napi_number) {
            return 0;
        }
        return get_int64_from_napi_value(env, value);
    }

    std::string get_string_from_named_property(napi_env env, napi_value object, const std::string &name){
        napi_value value = get_named_property_from_napi_value(env, object, name);
        if (value == nullptr) {
            return "";
        }
        napi_valuetype valuetype;
        napi_typeof(env, value, &valuetype);
        if (valuetype != napi_string) {
            return "";
        }
        return get_string_from_napi_value(env, value);
    }

    bool get_bool_from_named_property(napi_env env, napi_value object, const std::string &name){
        napi_value value = get_named_property_from_napi_value(env, object, name);
        if (value == nullptr) {
            return false;
        }
        napi_valuetype valuetype;
        napi_typeof(env, value, &valuetype);
        if (valuetype != napi_boolean) {
            return false;
        }
    }

}