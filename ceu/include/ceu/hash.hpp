/*********************************************************************
 * @file    hash.h    
 * @brief   
 * @details  
 * @author  Shivelino
 * @date
 * @version 
 * @par Copyright(c): Shivelino
 * @par todo:
 * @par history: 
 *********************************************************************/
#pragma once
#include <type_traits>

namespace ceu {

using hash_type = size_t;  // std::hash的返回值类型，std::hash返回值64位已足够使用，因为我不认为线程池能够创建2^64个

/**
 * @brief   .
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename T>
class is_hashable {
private:
    template <typename U>
    static auto test(int) -> decltype(std::declval<std::hash<U>>()(std::declval<U>()), std::true_type{});

    template <typename>
    static auto test(...) -> std::false_type;

public:
    static constexpr bool value = decltype(test<T>(0))::value;
};

/**
 * @brief   calculate hash value of input param.
 * @details  
 * @param[in] param: input praram
 * @return   
 * @par todo:
 * @par history: 
 */
template <typename _Ty>
inline hash_type calculate_hash(_Ty param) {
    static_assert(is_hashable<_Ty>::value, "Type T must be hashable.");
    std::hash<_Ty> hash_func;
    return hash_func(param);
}

}  // namespace ceu
