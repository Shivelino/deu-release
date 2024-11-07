/*********************************************************************
 * @file    string.hpp
 * @brief   functions of string
 * @details
 * @author  Shivelino
 * @date
 * @version 
 * @par Copyright(c): 
 * @par todo:
 * @par history:
 *********************************************************************/
#pragma once
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

namespace ceu {

/**
 * @brief   字符串转小写.
 * @details
 * @param[in] s 输入字符串
 * @return  小写字符串
 * @par todo:
 * @par history:
 */
inline std::string string_lower(const std::string& s) {
    std::string ret = s;
    std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
    return ret;
}

/**
 * @brief   字符串转大写.
 * @details
 * @param[in] s 输入字符串
 * @return  大写字符串
 * @par todo:
 * @par history:
 */
inline std::string string_upper(const std::string& s) {
    std::string ret = s;
    std::transform(ret.begin(), ret.end(), ret.begin(), ::toupper);
    return ret;
}

/**
 * @brief   .
 * @details  
 * @param[in] s
 * @param[in] prefix
 * @return   
 * @par todo:
 * @par history: 
 */
inline std::string string_add_prefix(const std::string& s, const std::string& prefix) {
    return prefix + s;
}

inline std::string string_add_prefix(const char* s, const char* prefix) {
    return std::string(prefix) + s;
}

/**
 * @brief   .
 * @details  
 * @param[in] s
 * @param[in] postfix
 * @return   
 * @par todo:
 * @par history: 
 */
inline std::string string_add_postfix(const std::string& s, const std::string& postfix) {
    return s + postfix;
}

inline std::string string_add_postfix(const char* s, const char* postfix) {
    return std::string(s) + postfix;
}

/**
 * @brief   .
 * @details  
 * @param[in] str
 * @param[in] delimiter
 * @return   
 * @par todo:
 * @par history: 
 */
inline std::vector<std::string> string_split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;  // todo: copy construct leads to low efficiency
}

/**
 * @brief   generate tabs with specific cnt.
 * @details  
 * @par todo:
 * @par history: 
 */
inline std::string string_tabs(size_t cnt) {
    return std::string(cnt, '\t');
}

}  // namespace ceu
