//
// Created by zhaoj on 25-7-13.
//

#ifndef HEMY_DEBUG_H
#define HEMY_DEBUG_H

#include <string>
#include <mutex>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

// 日志级别枚举
enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class Logger {
public:
    // 获取单例实例
    static Logger& getInstance();
    
    // 初始化日志系统
    void initialize(const std::string& filename = "", 
                   LogLevel level = LogLevel::INFO,
                   bool consoleOutput = true);
    
    // 日志记录接口
    // 日志记录接口
    void log(LogLevel level, const std::string& file,
             const std::string& func, int line,
             const std::string& message);
    // 禁止复制
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

private:
    Logger();
    ~Logger();
    
    // 内部实现方法
    std::string formatLogEntry(LogLevel level,
                              const std::string& file,
                              const std::string& func,
                              int line,
                              const std::string& message);
    std::string levelToString(LogLevel level);

    // 成员变量
    std::ofstream logFile;
    std::string filePath;
    LogLevel currentLevel;
    bool outputToConsole;
    std::mutex logMutex;
};

// =====================
// 便捷日志宏定义
// =====================

// 基本日志宏
#define HDEBUG(message)    Logger::getInstance().log(LogLevel::DEBUG, __FILE__, __func__, __LINE__, message)
#define HINFO(message)     Logger::getInstance().log(LogLevel::INFO, __FILE__, __func__, __LINE__, message)
#define HWARNING(message)  Logger::getInstance().log(LogLevel::WARNING, __FILE__, __func__, __LINE__, message)
#define HERROR(message)    Logger::getInstance().log(LogLevel::ERROR, __FILE__, __func__, __LINE__, message)
#define HCRITICAL(message) Logger::getInstance().log(LogLevel::CRITICAL, __FILE__, __func__, __LINE__, message)

// 格式化日志宏（带位置信息）
#define HF_DEBUG(format, ...)    do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    Logger::getInstance().log(LogLevel::DEBUG, __FILE__, __func__, __LINE__, buffer); \
} while(0)

#define HF_INFO(format, ...)     do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    Logger::getInstance().log(LogLevel::INFO, __FILE__, __func__, __LINE__, buffer); \
} while(0)

#define HF_WARNING(format, ...)  do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    Logger::getInstance().log(LogLevel::WARNING, __FILE__, __func__, __LINE__, buffer); \
} while(0)

#define HF_ERROR(format, ...)    do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    Logger::getInstance().log(LogLevel::ERROR, __FILE__, __func__, __LINE__, buffer); \
} while(0)

#define HF_CRITICAL(format, ...) do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    Logger::getInstance().log(LogLevel::CRITICAL, __FILE__, __func__, __LINE__, buffer); \
} while(0)

// 简化文件名宏（只保留文件名，去除路径）
#if defined(_WIN32)
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

// 简洁版日志宏（只显示文件名，不显示完整路径）
#define HS_DEBUG(message)    Logger::getInstance().log(LogLevel::DEBUG, __FILENAME__, __func__, __LINE__, message)
#define HS_INFO(message)     Logger::getInstance().log(LogLevel::INFO, __FILENAME__, __func__, __LINE__, message)
#define HS_WARNING(message)  Logger::getInstance().log(LogLevel::WARNING, __FILENAME__, __func__, __LINE__, message)
#define HS_ERROR(message)    Logger::getInstance().log(LogLevel::ERROR, __FILENAME__, __func__, __LINE__, message)
#define HS_CRITICAL(message) Logger::getInstance().log(LogLevel::CRITICAL, __FILENAME__, __func__, __LINE__, message)

#define HFS_DEBUG(format, ...)    do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    Logger::getInstance().log(LogLevel::DEBUG, __FILENAME__, __func__, __LINE__, buffer); \
} while(0)

#define HFS_INFO(format, ...)     do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    Logger::getInstance().log(LogLevel::INFO, __FILENAME__, __func__, __LINE__, buffer); \
} while(0)

#define HFS_WARNING(format, ...)  do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    Logger::getInstance().log(LogLevel::WARNING, __FILENAME__, __func__, __LINE__, buffer); \
} while(0)

#define HFS_ERROR(format, ...)    do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    Logger::getInstance().log(LogLevel::ERROR, __FILENAME__, __func__, __LINE__, buffer); \
} while(0)

#define HFS_CRITICAL(format, ...) do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    Logger::getInstance().log(LogLevel::CRITICAL, __FILENAME__, __func__, __LINE__, buffer); \
} while(0)


#endif //HEMY_DEBUG_H
