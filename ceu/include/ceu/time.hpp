/*********************************************************************
 * @file    times.hpp
 * @brief   define time functions
 * @details 常用处理最小时间：微秒/microseconds
 * @author  Shivelino
 * @date
 * @version 
 * @par Copyright(c): 
 * @par todo:
 * @par history:
 *********************************************************************/
#pragma once
#include <chrono>
#include <string>
#include <thread>

#include "type.h"

namespace ceu {

/**
 * @brief   获取程序执行时间（steady_clock）.
 * @details 程序从开始执行计算的的timestamp.
 * @return  毫秒时间戳（steady_clock）
 * @par todo:
 * @par history:
 */
inline ll get_procedure_time_milli() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

/**
 * @brief   获取程序执行时间（steady_clock）.
 * @details 程序从开始执行计算的的timestamp.
 * @return  微秒时间戳（steady_clock）
 * @par todo:
 * @par history:
 */
inline ll get_procedure_time_micro() {
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

/**
 * @brief   获取系统时间戳（system_clock）.
 * @details 按照ISO 8601规范从1970-01-01T00:00:00Z开始计算
 * @return  毫秒时间戳（system_clock）
 * @par todo:
 * @par history:
 */
inline ll get_time_stamp_milli() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/**
 * @brief   获取系统时间戳（system_clock）.
 * @details 按照ISO 8601规范从1970-01-01T00:00:00Z开始计算
 * @return  微秒时间戳（system_clock）
 * @par todo:
 * @par history:
 */
inline ll get_time_stamp_micro() {
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/**
 * @brief   获取当前系统时间的年月日时分秒.
 * @details
 * @param[out] year   年份
 * @param[out] month  月份
 * @param[out] day    日期
 * @param[out] hour   小时数
 * @param[out] minute 分钟数
 * @param[out] second 秒数
 * @par todo:
 * @par history:
 */
inline void get_now_time(int& year, int& month, int& day, int& hour, int& minute, int& second) {
    auto now = std::chrono::system_clock::now();  // 获取当前系统时间
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    struct std::tm* timeInfo = std::localtime(&currentTime);
    year = timeInfo->tm_year + 1900;
    month = timeInfo->tm_mon + 1;
    day = timeInfo->tm_mday;
    hour = timeInfo->tm_hour;
    minute = timeInfo->tm_min;
    second = timeInfo->tm_sec;
}

/**
 * @brief   微秒时间戳转time_t格式.
 * @details
 * @param[in] time_stamp_micro
 * @return
 * @par todo:
 * @par history:
 */
inline std::time_t time_stamp2time_t(ll time_stamp_micro) {
    auto epoch = std::chrono::time_point<std::chrono::system_clock>(std::chrono::milliseconds(0));  // 系统起始时间
    auto time_point = epoch + std::chrono::microseconds(time_stamp_micro);
    return std::chrono::system_clock::to_time_t(time_point);
}

/**
 * @brief   获取时间戳对应的格式化时间字符串.
 * @details
 * @par todo:
 * @par history:
 */
inline std::string get_format_time_string(ll time_stamp_micro) {
    std::time_t time_stamp_time_t = time_stamp2time_t(time_stamp_micro);
    std::tm local_time = *std::localtime(&time_stamp_time_t);
    ll micro_ms = time_stamp_micro % 1000;
    ll milli_ms = (time_stamp_micro / 1000) % 1000;
    std::stringstream ss;
    ss << std::put_time(&local_time, "%Y-%m-%d %H:%M:%S") << ":" << milli_ms << ":" << micro_ms;
    return ss.str();
}

/**
 * @brief   获取格式化时间字符串.
 * @details
 * @par todo:
 * @par history:
 */
inline std::string get_format_time_string_now() {
    ll time_stamp_micro = get_time_stamp_micro();
    return get_format_time_string(time_stamp_micro);
}

/**
 * @brief   毫秒休眠.
 * @details  
 * @param[in] num
 * @par todo:
 * @par history: 
 */
inline void sleep_milli(ull num) {
    std::chrono::milliseconds sleepDuration(num);
    std::this_thread::sleep_for(sleepDuration);
}

/**
 * @brief   微秒休眠.
 * @details  
 * @param[in] num
 * @par todo:
 * @par history: 
 */
inline void sleep_micro(ull num) {
    std::chrono::microseconds sleepDuration(num);
    std::this_thread::sleep_for(sleepDuration);
}

/**
 * @brief   .
 * @details  
 * @par todo:
 * @par history: 
 */
class ScopeTimer {
private:
    ll _start_stamp = 0;
    ll _end_stamp = 0;
    bool _print_flag;

public:
    inline ScopeTimer() {
        _print_flag = true;
        _start_stamp = get_time_stamp_micro();
    }

    inline ScopeTimer(bool print_flag) {
        _print_flag = print_flag;
        _start_stamp = get_time_stamp_micro();
    }

    inline ~ScopeTimer() {
        _end_stamp = get_time_stamp_micro();
        printf("Running Time(us): %lld\n", _end_stamp - _start_stamp);
    }

public:
    inline void until_now() { printf("Until Now Running Time(us): %lld\n", get_time_stamp_micro() - _start_stamp); }
};

/**
 * @brief   .
 * @details  
 * @param[in] value
 * @return   
 * @par todo:
 * @par history: 
 */

namespace duration {

namespace units {
using nanoseconds = std::chrono::duration<double, std::ratio<1, 1000000000>>;
using microseconds = std::chrono::duration<double, std::ratio<1, 1000000>>;
using milliseconds = std::chrono::duration<double, std::ratio<1, 1000>>;
using seconds = std::chrono::duration<double>;
using minutes = std::chrono::duration<double, std::ratio<60>>;
using hours = std::chrono::duration<double, std::ratio<3600>>;

}  // namespace units

enum class TimeUnitOption { NanoSeconds, MicroSeconds, MilliSeconds, Seconds, Minutes, Hours };

template <TimeUnitOption unit>
struct TimeUnitSelector;

template <>
struct TimeUnitSelector<TimeUnitOption::NanoSeconds> {
    using Type = units::nanoseconds;
};

template <>
struct TimeUnitSelector<TimeUnitOption::MicroSeconds> {
    using Type = units::microseconds;
};

template <>
struct TimeUnitSelector<TimeUnitOption::MilliSeconds> {
    using Type = units::milliseconds;
};

template <>
struct TimeUnitSelector<TimeUnitOption::Seconds> {
    using Type = units::seconds;
};

template <>
struct TimeUnitSelector<TimeUnitOption::Minutes> {
    using Type = units::minutes;
};

template <>
struct TimeUnitSelector<TimeUnitOption::Hours> {
    using Type = units::hours;
};

template <TimeUnitOption unit>
using TimeUnit = typename TimeUnitSelector<unit>::Type;

template <TimeUnitOption _from_unit, TimeUnitOption _to_unit>
inline double duration_convert(double dur) {
    TimeUnit<_from_unit> d1(dur);
    TimeUnit<_to_unit> d2 = std::chrono::duration_cast<TimeUnit<_to_unit>>(d1);
    return d2.count();
}

}  // namespace duration
}  // namespace ceu
