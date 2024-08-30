/*********************************************************************
 * @file    template_util.h
 * @brief   模板元编程工具
 * @details
 * @author  Shivelino
 * @date
 * @version 
 * @par Copyright(c): 
 * @par todo:
 * @par history:
 *********************************************************************/
#pragma once
#include <map>
#include <set>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

#include "macro.hpp"

namespace ceu {

/**
 * @brief   检查类型T是否具有拷贝构造函数.
 * @details 原理：SFINAE
 * @par todo:
 * @par history:
 */
template <typename Type>
class has_copy_constructor {
private:
    /**
     * @brief   测试函数1.
     * @details 尝试构造类型Ty的一个实例，使用C(std::declval<const C&>())的方式，其中std::declval用于生成一个类型Ty的虚拟实例。
     *          如果Ty有可访问的拷贝构造函数，那么这个表达式将合法，decltype 将得到一个有效的类型。在这种情况下，std::true_type
     *          被返回，表示拥有拷贝构造函数。
     * @par todo:
     * @par history:
     */
    template <typename Ty, typename = decltype(Ty(std::declval<const Ty&>()))>
    static std::true_type test(int);

    /**
     * @brief   测试函数2.
     * @details 重载采用了一个不具名参数（...），因此它可以匹配任何类型。这是备用重载，当第一个重载无法匹配时，编译器将调用此重载。
     *          在这里，返回std::false_type，表示没有拷贝构造函数。
     * @par todo:
     * @par history:
     */
    template <typename>
    static std::false_type test(...);

public:
    static const bool value = std::is_same<decltype(test<Type>(0)), std::true_type>::value;
};

/**
 * @brief   判断是否支持某个运算符。
 * @details 原理：SFINAE
 * @par todo:
 * @par history:
 */
#define _DECLARE_HAS_BINARY_OPERATOR(_operator, _operator_name)                                                                                 \
    template <typename _Type1, typename _Type2>                                                                                                 \
    class CEU_CAT(has_operator_, _operator_name) {                                                                                              \
    private:                                                                                                                                    \
        template <typename _Ty1, typename _Ty2, typename = decltype(EXPRESSION_BINARY(std::declval<_Ty1&>(), _operator, std::declval<_Ty2>()))> \
        static std::true_type test(int);                                                                                                        \
        template <typename _Ty1, typename _Ty2>                                                                                                 \
        static std::false_type test(...);                                                                                                       \
                                                                                                                                                \
    public:                                                                                                                                     \
        static const bool value = decltype(test<_Type1, _Type2>(0))::value;                                                                     \
    }

_DECLARE_HAS_BINARY_OPERATOR(+, add);                   // 判断是否支持运算符"+"
_DECLARE_HAS_BINARY_OPERATOR(+=, add_assign);           // 判断是否支持运算符"+="
_DECLARE_HAS_BINARY_OPERATOR(-, sub);                   // 判断是否支持运算符"-"
_DECLARE_HAS_BINARY_OPERATOR(-=, sub_assign);           // 判断是否支持运算符"-="
_DECLARE_HAS_BINARY_OPERATOR(*, mul);                   // 判断是否支持运算符"*"
_DECLARE_HAS_BINARY_OPERATOR(*=, mul_assign);           // 判断是否支持运算符"*="
_DECLARE_HAS_BINARY_OPERATOR(/, div);                   // 判断是否支持运算符"/"
_DECLARE_HAS_BINARY_OPERATOR(/=, div_assign);           // 判断是否支持运算符"/="
_DECLARE_HAS_BINARY_OPERATOR(%, mod);                   // 判断是否支持运算符"%"
_DECLARE_HAS_BINARY_OPERATOR(%=, mod_assign);           // 判断是否支持运算符"%="
_DECLARE_HAS_BINARY_OPERATOR(=, assign);                // 判断是否支持运算符"="
_DECLARE_HAS_BINARY_OPERATOR(==, equal);                // 判断是否支持运算符"=="
_DECLARE_HAS_BINARY_OPERATOR(!=, not_equal);            // 判断是否支持运算符"!="
_DECLARE_HAS_BINARY_OPERATOR(<, less);                  // 判断是否支持运算符"<"
_DECLARE_HAS_BINARY_OPERATOR(<=, less_equal);           // 判断是否支持运算符"<="
_DECLARE_HAS_BINARY_OPERATOR(>, greater);               // 判断是否支持运算符">"
_DECLARE_HAS_BINARY_OPERATOR(>=, greater_equal);        // 判断是否支持运算符">="
_DECLARE_HAS_BINARY_OPERATOR(&, and);                   // 判断是否支持运算符"&"
_DECLARE_HAS_BINARY_OPERATOR(&=, and_assign);           // 判断是否支持运算符"&="
_DECLARE_HAS_BINARY_OPERATOR(|, or);                    // 判断是否支持运算符"|"
_DECLARE_HAS_BINARY_OPERATOR(|=, or_assign);            // 判断是否支持运算符"|="
_DECLARE_HAS_BINARY_OPERATOR(^, xor);                   // 判断是否支持运算符"^"
_DECLARE_HAS_BINARY_OPERATOR(^=, xor_assign);           // 判断是否支持运算符"^="
_DECLARE_HAS_BINARY_OPERATOR(<<, left_shift);           // 判断是否支持运算符"<<"
_DECLARE_HAS_BINARY_OPERATOR(<<=, left_shift_assign);   // 判断是否支持运算符"<<="
_DECLARE_HAS_BINARY_OPERATOR(>>, right_shift);          // 判断是否支持运算符">>"
_DECLARE_HAS_BINARY_OPERATOR(>>=, right_shift_assign);  // 判断是否支持运算符">>="
#undef _DECLARE_HAS_BINARY_OPERATOR

//! 判断是否支持运算符"[]"
template <typename _Type1, typename _Type2>
class has_operator_bracket {
private:
    template <typename _Ty1, typename _Ty2, typename = decltype(std::declval<_Ty1&>()[std::declval<_Ty2>()])>
    static std::true_type test(int);
    template <typename _Ty1, typename _Ty2>
    static std::false_type test(...);

public:
    static const bool value = decltype(test<_Type1, _Type2>(0))::value;
};

/**
 * @brief   获取变长模板类型名拼接字符串.
 * @details
 * @return
 * @par todo:
 * @par history:
 */
template <typename... Types>
std::string types_string() {
    std::string ret = "";
    ((ret += typeid(Types).name()), ...);  // C++17 折叠表达式
    return ret;
}

/**
 * @brief   获取变长参数列表类型名拼接字符串.
 * @details 将每个参数的类型字符串简单拼接
 * @param[in] ...args 变长参数
 * @return
 * @par todo:
 * @par history:
 */
template <typename... Args>
std::string args_types_string(const Args&... args) {
    std::string ret = "";
    ((ret += typeid(args).name()), ...);
    return ret;
}

/**
 * @brief   是否是Map类型.
 * @details  
 * @par todo:
 * @par history: 
 */
template <class _MapTy>
concept map_like_type = std::is_same_v<typename _MapTy::value_type, std::pair<const typename _MapTy::key_type, typename _MapTy::mapped_type>>;

/**
 * @brief   if type is std::map.
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename _Ty>
struct is_std_map : std::false_type {};

template <class _Kty, class _Ty, class _Pr, class _Alloc>
struct is_std_map<std::map<_Kty, _Ty, _Pr, _Alloc>> : std::true_type {};

template <typename _Ty>
constexpr bool is_std_map_v = is_std_map<_Ty>::value;

/**
 * @brief   if type is std::unordered_map.
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename _Ty>
struct is_std_unordered_map : std::false_type {};

template <class _Kty, class _Ty, class _Hasher, class _Keyeq, class _Alloc>
struct is_std_unordered_map<std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq, _Alloc>> : std::true_type {};

template <typename _Ty>
constexpr bool is_std_unordered_map_v = is_std_unordered_map<_Ty>::value;

/**
 * @brief   if type is std::map or std::unordered_map.
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename _Ty>
constexpr bool is_map_type_v = is_std_map_v<_Ty> || is_std_unordered_map_v<_Ty>;

template <typename _Ty>
concept map_type = is_std_map_v<_Ty> || is_std_unordered_map_v<_Ty>;

/**
 * @brief   if type is std::set.
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename _Ty>
struct is_std_set : std::false_type {};

template <class _Kty, class _Pr, class _Alloc>
struct is_std_set<std::set<_Kty, _Pr, _Alloc>> : std::true_type {};

template <typename _Ty>
constexpr bool is_std_set_v = is_std_set<_Ty>::value;

/**
 * @brief   if type is std::unordered_set.
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename _Ty>
struct is_std_unordered_set : std::false_type {};

template <class _Kty, class _Hasher, class _Keyeq, class _Alloc>
struct is_std_unordered_set<std::unordered_set<_Kty, _Hasher, _Keyeq, _Alloc>> : std::true_type {};

template <typename _Ty>
constexpr bool is_std_unordered_set_v = is_std_unordered_set<_Ty>::value;

/**
 * @brief   if type is std::set or std::unordered_set.
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename _Ty>
constexpr bool is_set_type_v = is_std_set_v<_Ty> || is_std_unordered_set_v<_Ty>;

template <typename _Ty>
concept set_type = is_std_set_v<_Ty> || is_std_unordered_set_v<_Ty>;

}  // namespace ceu
