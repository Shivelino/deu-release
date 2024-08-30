/*********************************************************************
 * @file    casts.hpp    
 * @brief   cast utils
 * @details  
 * @author  Shivelino
 * @date    2024.8.22
 * @version 
 * @par Copyright(c): Concloud Software Corporation
 * @par todo:
 * @par history: 
 *********************************************************************/
#pragma once
#include <type_traits>

#include "exceptions.hpp"

namespace ceu {

/**
 * @brief 强制类型转换type_cast
 */
template <typename Ret, typename InType>
Ret ceu_force_cast(const InType v) {
    return (Ret)v;
}

/**
 * @brief const_cast
 */
template <typename Ret, typename ConstInType>
Ret ceu_const_cast(ConstInType v) {
    if (!std::is_const<ConstInType>::value)
        throw ExceptionType("Type isn't const.");
    return const_cast<Ret>(v);
}

/**
 * @brief 符号类型转换sign_cast。用于有符号数和无符号数的相互转换
 * @todo todo
 */
// template <typename Signed, typename Unsigned> Unsigned signed2unsigned(Signed v) {
//     // if(!std::is_same_v<Signed, int> || !std::is_same_v<Signed, int>) throw std::exception();
// }

}  // namespace ceu
