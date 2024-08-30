/*********************************************************************
 * @file    maths.h    
 * @brief   
 * @details  
 * @author  Shivelino
 * @date    2024.8.22
 * @version 
 * @par Copyright(c): 
 * @par todo:
 * @par history: 
 *********************************************************************/
#pragma once
#include <cmath>

#include "exceptions.hpp"
#include "macro.hpp"
#include "templates.hpp"

namespace ceu {

// ! equal check
/**
 * @brief 判断两个特定类型的值是否相等
 */
template <typename vtype>
bool is_equal(vtype v1, vtype v2) {
    if (!has_operator_equal<vtype, vtype>::value)
        throw ExceptionType("Type doesn't overload operator \"==\".");
    return v1 == v2;
}

template <typename vtype>
bool is_equal(vtype v1, vtype v2, vtype tol) {
    if (!has_operator_sub<vtype, vtype>::value)
        throw ExceptionType("Type doesn't overload operator \"-\".");
    if (!has_operator_less_equal<vtype, vtype>::value)
        throw ExceptionType("Type doesn't overload operator \"<=\".");
    return v1 - v2 <= tol || v2 - v1 <= tol;
}

template <>
bool is_equal<float>(float v1, float v2, float tol) {
    return abs(v1 - v2) <= tol;
}

template <>
bool is_equal<double>(double v1, double v2, double tol) {
    return fabs(v1 - v2) <= tol;
}

// ! legality
/**
 * @brief 检查数值类型是否为正值
 */
template <typename vtype>
bool expect_positive(vtype n) {
    if (std::is_arithmetic<vtype>::value)
        throw ExceptionType("Type isn't arithmetic.");
    return n > 0;
}

/**
 * @brief 检查数值类型是否为负值
 */
template <typename vtype>
bool expect_negative(vtype n) {
    if (std::is_arithmetic<vtype>::value)
        throw ExceptionType("Type isn't arithmetic.");
    return n < 0;
}

/**
 * @brief 检查数值类型是否为非负值
 */
template <typename vtype>
bool expect_no_negative(vtype n) {
    if (std::is_arithmetic<vtype>::value)
        throw ExceptionType("Type isn't arithmetic.");
    return n >= 0;
}

/**
 * @brief 检查数值类型是否为非正值
 */
template <typename vtype>
bool expect_no_positive(vtype n) {
    if (std::is_arithmetic<vtype>::value)
        throw ExceptionType("Type isn't arithmetic.");
    return n <= 0;
}

// ! convert
ALWAYS_INLINE_FUNCTION int double2int(double n) {
    return static_cast<int>(n);
}

}  // namespace ceu
