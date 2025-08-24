//
// Created by zhaoj on 25-7-13.
//

#ifndef HEMY_DEBUG_H
#define HEMY_DEBUG_H

#include <string>
#include <mutex>
#include <fstream>
#include <filesystem>
#include <iostream>
// 添加Qt支持
#include <QString>   // 添加QString支持
#include <QByteArray> // 添加QByteArray支持

namespace fs = std::filesystem;

// 日志级别枚举
enum class LogLevel {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_CRITICAL
};

namespace HEMY_API
{
    class Logger {
    public:
        // 获取单例实例
        static Logger& getInstance();

        // 初始化日志系统
        void initialize(const std::string& filename = "",
                       LogLevel level = LogLevel::LOG_INFO,
                       bool consoleOutput = true);

        // 日志记录接口
        template <class ... Args>
        void log(LogLevel level, const std::string& file, const std::string& func, int line, Args&&... args);
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

    template<typename T>
    auto convertForLogging(T&& value) {
        using Type = std::decay_t<T>;
        if constexpr (std::is_same_v<Type, QString>) {
            return value.toStdString();
        } else if constexpr (std::is_same_v<Type, QByteArray>) {
            return std::string(value.constData(), value.size());
        } else if constexpr (std::is_convertible_v<Type, std::string>) {
            return static_cast<std::string>(value);
        } else {
            return std::forward<T>(value);
        }
    }

    // 模板函数实现（必须在头文件中）
    template<typename... Args>
    void Logger::log(LogLevel level, const std::string& file,
                    const std::string& func, int line,
                    Args&&... args) {
        // 检查日志级别
        if (static_cast<int>(level) < static_cast<int>(currentLevel)) {
            return;
        }

        // 拼接所有参数
        std::ostringstream oss;
        ((oss << convertForLogging(std::forward<Args>(args))), ...);  // C++17折叠表达式

        std::string message = oss.str();

        // 加锁确保线程安全
        std::lock_guard<std::mutex> lock(logMutex);

        // 格式化日志条目
        std::string logEntry = formatLogEntry(level, file, func, line, message);

        // 输出到控制台
        if (outputToConsole) {
            std::cout << logEntry << std::endl;
        }

        // 输出到文件
        if (logFile.is_open()) {
            logFile << logEntry << std::endl;
            logFile.flush();  // 确保及时写入
        }
    }
}

// =====================
// 便捷日志宏定义
// =====================

// 基本日志宏
#define LOG_DEBUG(...)    HEMY_API::Logger::getInstance().log(LogLevel::LOG_DEBUG, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define LOG_INFO(...)     HEMY_API::Logger::getInstance().log(LogLevel::LOG_INFO, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define LOG_WARNING(...)  HEMY_API::Logger::getInstance().log(LogLevel::LOG_WARNING, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define LOG_ERROR(...)    HEMY_API::Logger::getInstance().log(LogLevel::LOG_ERROR, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define LOG_CRITICAL(...) HEMY_API::Logger::getInstance().log(LogLevel::LOG_CRITICAL, __FILE__, __func__, __LINE__, __VA_ARGS__)

/*
// 格式化日志宏（带位置信息）
#define LOG_DEBUG(format, ...)    do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    HEMY_API::Logger::getInstance().log(LogLevel::DEBUG, __FILE__, __func__, __LINE__, buffer); \
} while(0)

#define LOG_INFO(format, ...)     do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    HEMY_API::Logger::getInstance().log(LogLevel::INFO, __FILE__, __func__, __LINE__, buffer); \
} while(0)

#define LOG_WARN(format, ...)  do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    HEMY_API::Logger::getInstance().log(LogLevel::WARNING, __FILE__, __func__, __LINE__, buffer); \
} while(0)

#define LOG_ERROR(format, ...)    do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    HEMY_API::Logger::getInstance().log(LogLevel::ERROR, __FILE__, __func__, __LINE__, buffer); \
} while(0)

#define LOG_CRITICAL(format, ...) do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    HEMY_API::Logger::getInstance().log(LogLevel::CRITICAL, __FILE__, __func__, __LINE__, buffer); \
} while(0)*/

// 简化文件名宏（只保留文件名，去除路径）
#if defined(_WIN32)
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

// 简洁版日志宏（只显示文件名，不显示完整路径）
#define LOG_SDEBUG(...)    HEMY_API::Logger::getInstance().log(LogLevel::LOG_DEBUG, __FILENAME__, __func__, __LINE__, __VA_ARGS__)
#define LOG_SINFO(...)     HEMY_API::Logger::getInstance().log(LogLevel::LOG_INFO, __FILENAME__, __func__, __LINE__, __VA_ARGS__)
#define LOG_SWARNING(...)  HEMY_API::Logger::getInstance().log(LogLevel::LOG_WARNING, __FILENAME__, __func__, __LINE__, __VA_ARGS__)
#define LOG_SERROR(...)    HEMY_API::Logger::getInstance().log(LogLevel::LOG_ERROR, __FILENAME__, __func__, __LINE__, __VA_ARGS__)
#define LOG_SCRITICAL(...) HEMY_API::Logger::getInstance().log(LogLevel::LOG_CRITICAL, __FILENAME__, __func__, __LINE__, __VA_ARGS__)

#define LOG_S_DEBUG(format, ...)    do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    HEMY_API::Logger::getInstance().log(LogLevel::DEBUG, __FILENAME__, __func__, __LINE__, buffer); \
} while(0)

#define LOG_S_INFO(format, ...)     do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    HEMY_API::Logger::getInstance().log(LogLevel::INFO, __FILENAME__, __func__, __LINE__, buffer); \
} while(0)

#define LOG_S_WARNING(format, ...)  do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    HEMY_API::Logger::getInstance().log(LogLevel::WARNING, __FILENAME__, __func__, __LINE__, buffer); \
} while(0)

#define LOG_S_ERROR(format, ...)    do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    HEMY_API::Logger::getInstance().log(LogLevel::ERROR, __FILENAME__, __func__, __LINE__, buffer); \
} while(0)

#define LOG_S_CRITICAL(format, ...) do { \
    char buffer[1024]; \
    snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
    HEMY_API::Logger::getInstance().log(LogLevel::CRITICAL, __FILENAME__, __func__, __LINE__, buffer); \
} while(0)


#endif //HEMY_DEBUG_H
