

#ifndef HILOG_HELPER_H
#define HILOG_HELPER_H

#include <hilog/log.h>
#define COAP_LOG_TAG "CoAP Kit"
/**
 * 日志助手类
 * 提供便捷的日志打印接口，封装鸿蒙HiLog
 */
class HiLogHelper {
public:
    /**
     * 打印DEBUG级别日志
     * @param tag 日志标签（可选，为nullptr则使用全局标签）
     * @param fmt 格式化字符串
     * @param ... 可变参数
     */
    static void Debug(const char* tag, const char* fmt, ...);
    
    /**
     * 打印INFO级别日志
     * @param tag 日志标签（可选，为nullptr则使用全局标签）
     * @param fmt 格式化字符串
     * @param ... 可变参数
     */
    static void Info(const char* tag, const char* fmt, ...);

    /**
     * 打印WARN级别日志
     * @param tag 日志标签（可选，为nullptr则使用全局标签）
     * @param fmt 格式化字符串
     * @param ... 可变参数
     */
    static void Warn(const char* tag, const char* fmt, ...);

    /**
     * 打印ERROR级别日志
     * @param tag 日志标签（可选，为nullptr则使用全局标签）
     * @param fmt 格式化字符串
     * @param ... 可变参数
     */
    static void Error(const char* tag, const char* fmt, ...);

    /**
     * 打印FATAL级别日志
     * @param tag 日志标签（可选，为nullptr则使用全局标签）
     * @param fmt 格式化字符串
     * @param ... 可变参数
     */
    static void Fatal(const char* tag, const char* fmt, ...);


private:
    static unsigned int globalDomain_;
    static const char* globalTag_;
    /**
     * 内部日志打印函数
     * @param level 日志级别
     * @param tag 日志标签
     * @param fmt 格式化字符串
     * @param args 可变参数列表
     */
    static void PrintLog(LogLevel level, const char* tag, const char* fmt, va_list args);
};

// 便捷宏定义
#define LOGD(...) HiLogHelper::Debug(COAP_LOG_TAG, __VA_ARGS__)
#define LOGI(...) HiLogHelper::Info(COAP_LOG_TAG, __VA_ARGS__)
#define LOGW(...) HiLogHelper::Warn(COAP_LOG_TAG, __VA_ARGS__)
#define LOGE(...) HiLogHelper::Error(COAP_LOG_TAG, __VA_ARGS__)
#define LOGF(...) HiLogHelper::Fatal(COAP_LOG_TAG, __VA_ARGS__)
// 带标签的便捷宏
#define LOGD_TAG(tag, ...) HiLogHelper::Debug(tag, __VA_ARGS__)
#define LOGI_TAG(tag, ...) HiLogHelper::Info(tag, __VA_ARGS__)
#define LOGW_TAG(tag, ...) HiLogHelper::Warn(tag, __VA_ARGS__)
#define LOGE_TAG(tag, ...) HiLogHelper::Error(tag, __VA_ARGS__)
#define LOGF_TAG(tag, ...) HiLogHelper::Fatal(tag, __VA_ARGS__)

#endif // HILOG_HELPER_H
