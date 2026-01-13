

#include "hilog_helper.h"
#include <cstdarg>
#include <cstdio>

// 初始化静态成员变量
unsigned int HiLogHelper::globalDomain_ = LOG_DOMAIN;
const char* HiLogHelper::globalTag_ = "[coap]";

void HiLogHelper::PrintLog(LogLevel level, const char* tag, const char* fmt, va_list args) {
    const char* actualTag = (tag != nullptr) ? tag : (globalTag_ != nullptr ? globalTag_ : COAP_LOG_TAG);
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    OH_LOG_Print(LOG_APP, level, globalDomain_, actualTag, "%{public}s", buffer);
}

// Debug级别日志
void HiLogHelper::Debug(const char* tag, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    PrintLog(LOG_DEBUG, tag, fmt, args);
    va_end(args);
}


// Info级别日志
void HiLogHelper::Info(const char* tag, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    PrintLog(LOG_INFO, tag, fmt, args);
    va_end(args);
}

// Warn级别日志
void HiLogHelper::Warn(const char* tag, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    PrintLog(LOG_WARN, tag, fmt, args);
    va_end(args);
}


// Error级别日志
void HiLogHelper::Error(const char* tag, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    PrintLog(LOG_ERROR, tag, fmt, args);
    va_end(args);
}


// Fatal级别日志
void HiLogHelper::Fatal(const char* tag, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    PrintLog(LOG_FATAL, tag, fmt, args);
    va_end(args);
}
