/*********************************************************************
 * @file    logger.hpp    
 * @brief   
 * @details  
 * @author  Shivelino
 * @date    2024.8.22
 * @version 
 * @par Copyright(c): Concloud Software Corporation
 * @par todo:
 * @par history: 
 *********************************************************************/
#pragma once
#include <chrono>
#include <string>
#include <vector>

#include "metaprogramming/traits.hpp"

namespace ceu {

enum class LogLevel { None, Fatal, Error, Warn, Info, Debug, Trace };

#pragma warning(push)
#pragma warning(disable : 4251)  // 提示使用std::string需要有dll接口, todo, 可以使用Impl方式改写

class LogInfo {
private:
    std::time_t _time;  // log信息记录的时间
    LogLevel _level;    // log信息等级
    std::string _msg;   // log信息内容
    std::string _file;  // log信息记录时的文件
    int _line;          // log信息记录时的行数

public:
    explicit LogInfo(LogLevel level, const std::string& msg, const std::string& file, int line) noexcept {
        _time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        _level = level;
        _msg = msg;
        _file = file;
        _line = line;
    }

    virtual ~LogInfo() noexcept {}

public:
    [[nodiscard]] ALWAYS_INLINE_FUNCTION void print() const {
        std::tm time_info;
        localtime_s(&time_info, &_time);
        printf("|\t%d.%d.%d %d:%d:%d\t|\t%s\t|\t%d\t|\t%s\t|\n", time_info.tm_year + 1900, time_info.tm_mon + 1, time_info.tm_mday, time_info.tm_hour, time_info.tm_min, time_info.tm_sec, _file.c_str(), _line, _msg.c_str());
    }

    [[nodiscard]] ALWAYS_INLINE_FUNCTION void write(FILE* file) const {
        std::tm time_info;
        localtime_s(&time_info, &_time);
        fprintf(file, "|\t%d.%d.%d %d:%d:%d\t|\t%s\t|\t%d\t|\t%s\t|\n", time_info.tm_year + 1900, time_info.tm_mon + 1, time_info.tm_mday, time_info.tm_hour, time_info.tm_min, time_info.tm_sec, _file.c_str(), _line, _msg.c_str());
    }
};

class Logger : public Traitable {
private:
    std::vector<LogInfo> _records;  // todo vector并不优雅，应该改为链表可能会更加灵活

public:
    explicit Logger() noexcept {}

    virtual ~Logger() noexcept {}

public:
    [[nodiscard]] ALWAYS_INLINE_FUNCTION void add(const LogInfo& info) { _records.push_back(info); }

    [[nodiscard]] ALWAYS_INLINE_FUNCTION void remove() { _records.pop_back(); }

    [[nodiscard]] ALWAYS_INLINE_FUNCTION void print() const {
        printf("|\tyear.month.day hour:minute:seconds\t|\tfile\t|\tline\t|\tmessage\t|\n");
        for (const auto& info : _records)
            info.print();
    }

    [[nodiscard]] ALWAYS_INLINE_FUNCTION void write(FILE* file) const {
        fprintf(file, "|\tyear.month.day hour:minute:seconds\t|\tfile\t|\tline\t|\tmessage\t|\n");
        for (const auto& info : _records)
            info.write(file);
    }
};

#pragma warning(pop)

extern Logger* global_logger = new Logger();

}  // namespace ceu
