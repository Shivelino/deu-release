/*********************************************************************
 * @file    macro.h
 * @brief   Define macros, including count macro, iterate macro.
 *          Macro started with "_" should use in this file.
 * @details
 * @author  Shivelino
 * @date
 * @version 
 * @par Copyright(c): 
 * @par todo:
 * @par history:
 *********************************************************************/
#pragma once

#ifdef _MSC_VER
//! MSVC_EXPAND解决MSVC编译器的特殊变长宏问题
#define MSVC_EXPAND(...) __VA_ARGS__
#elif defined __GNUC__
// todo __GNUC__
#endif

//! 拼接宏。拼接两个字符串
#define CEU_CAT(a, b) _CAT_I(a, b)
#define _CAT(a, b) _CAT_I(a, b)
#define _CAT_I(a, b) _CAT_II(~, a##b)
#define _CAT_II(_, res) res

//! 计数宏
#define _GET_MACRO_ARGS_COUNT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, \
                              _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, __COUNT, ...)                                                                                                                     \
    __COUNT
#ifdef _MSC_VER
//! 获取宏函数的参数个数(cnt)
#define GET_MACRO_ARGS_COUNT(...)                                                                                                                                                                                                                          \
    MSVC_EXPAND(_GET_MACRO_ARGS_COUNT(__VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, \
                                      14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))

//! 获取宏函数的参数个数并减一(cnt-1)
#define GET_MACRO_ARGS_COUNT_S1(...)                                                                                                                                                                                                                       \
    MSVC_EXPAND(_GET_MACRO_ARGS_COUNT(__VA_ARGS__, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, \
                                      13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
#else
//! 获取宏函数的参数个数(cnt)
#define GET_MACRO_ARGS_COUNT(...)                                                                                                                                                                                                                          \
    _GET_MACRO_ARGS_COUNT(__VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, \
                          11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)

//! 获取宏函数的参数个数并减一(cnt-1)
#define GET_MACRO_ARGS_COUNT_S1(...)                                                                                                                                                                                                                       \
    _GET_MACRO_ARGS_COUNT(__VA_ARGS__, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, \
                          10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#endif

// ! 迭代宏
#ifdef _MSC_VER
/**
 * @brief 自动迭代宏，一般用于没有提供变长参数的宏或者具有1+个固定参数的宏。根据_paramx固定参数的个数选择不同的迭代宏
 * @note 需要base宏提供不同sise后缀的宏。ep: CAT_1, CAT_2
 * @param _macro 需要进行迭代的base宏
 * @param _paramx 迭代的宏所需的固定参数，最多支持4
 * @param __VA_ARGS__ 自动迭代宏的不定长参数，即迭代调用的参数
 */
#define ITERATE_MACRO(_macro, ...) MSVC_EXPAND(_CAT(_macro##_, GET_MACRO_ARGS_COUNT(__VA_ARGS__))(__VA_ARGS__))
#define ITERATE_MACRO_WITH_PARAM1(_macro, _param1, ...) MSVC_EXPAND(_CAT(_macro##_, GET_MACRO_ARGS_COUNT(__VA_ARGS__))(_param1, __VA_ARGS__))
#define ITERATE_MACRO_WITH_PARAM2(_macro, _param1, _param2, ...) MSVC_EXPAND(_CAT(_macro##_, GET_MACRO_ARGS_COUNT(__VA_ARGS__))(_param1, _param2, __VA_ARGS__))
#define ITERATE_MACRO_WITH_PARAM3(_macro, _param1, _param2, _param3, ...) MSVC_EXPAND(_CAT(_macro##_, GET_MACRO_ARGS_COUNT(__VA_ARGS__))(_param1, _param2, _param3, __VA_ARGS__))
#define ITERATE_MACRO_WITH_PARAM4(_macro, _param1, _param2, _param3, _param4, ...) MSVC_EXPAND(_CAT(_macro##_, GET_MACRO_ARGS_COUNT(__VA_ARGS__))(_param1, _param2, _param3, _param4, __VA_ARGS__))
#else
/**
 * @brief 自动迭代宏，一般用于没有提供变长参数的宏或者具有1+个固定参数的宏。根据_paramx固定参数的个数选择不同的迭代宏
 * @note 需要base宏提供不同sise后缀的宏。ep: CAT_1, CAT_2
 * @param _macro 需要进行迭代的base宏
 * @param _paramx 迭代的宏所需的固定参数，最多支持4
 * @param __VA_ARGS__ 自动迭代宏的不定长参数，即迭代调用的参数
 */
#define ITERATE_MACRO(_macro, ...) _CAT(_macro##_, GET_MACRO_ARGS_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define ITERATE_MACRO_WITH_PARAM1(_macro, _param1, ...) _CAT(_macro##_, GET_MACRO_ARGS_COUNT(__VA_ARGS__))(_param1, __VA_ARGS__)
#define ITERATE_MACRO_WITH_PARAM2(_macro, _param1, _param2, ...) _CAT(_macro##_, GET_MACRO_ARGS_COUNT(__VA_ARGS__))(_param1, _param2, __VA_ARGS__)
#define ITERATE_MACRO_WITH_PARAM3(_macro, _param1, _param2, _param3, ...) _CAT(_macro##_, GET_MACRO_ARGS_COUNT(__VA_ARGS__))(_param1, _param2, _param3, __VA_ARGS__)
#define ITERATE_MACRO_WITH_PARAM4(_macro, _param1, _param2, _param3, _param4, ...) \
    _CAT(_macro##_, GET_MACRO_ARGS_COUNT(__VA_ARGS__))                             \
    (_param1, _param2, _param3, _param4, __VA_ARGS__)
#endif

// ! 代码简化

// C/C++混合
#ifdef __cplusplus
//! C++中用于extern C的简化宏.
#define EXTERN_C_STATEMENT(_statement) \
    extern "C" {                       \
    _statement;                        \
    }

//! 用于C++和C语言混用时的声明宏.

//! 开始声明。用于C++和C语言混用时的声明宏.
#define BEGIN_DECLS extern "C" {
//! 结束声明。用于C++和C语言混用时的声明宏.
#define END_DECLS }
#else
//! 用于C++和C语言混用时的声明宏.

//! 开始声明。用于C++和C语言混用时的声明宏.
#define BEGIN_DECLS
//! 结束声明。用于C++和C语言混用时的声明宏.
#define END_DECLS
#endif

// 置空：用于设置nullptr和NULL
#ifdef __cplusplus
//! 指针置nullptr
#define SET_NULLPTR_BY_DELETE(_ptr) \
    if (_ptr != nullptr) {          \
        delete _ptr;                \
        _ptr = nullptr;             \
    }

//! 指针置nullptr
#define SET_NULLPTR_BY_DELETE_ARR(_ptr) \
    if (_ptr != nullptr) {              \
        delete[] _ptr;                  \
        _ptr = nullptr;                 \
    }

//! 指针置nullptr
#define SET_NULLPTR_BY_FREE(_ptr) \
    if (_ptr != nullptr) {        \
        free(_ptr);               \
        _ptr = nullptr;           \
    }
#else
// todo C语言应该设置为NULL
#endif

//! switc-case简写宏
#define SWITCH_CASE(_case, _statement) \
    case (_case): {                    \
        _statement;                    \
        break;                         \
    }

//! switc-default简写宏
#define SWITCH_DEFAULT(_statement) \
    default: {                     \
        _statement;                \
        break;                     \
    }

//! switc-default简写置空
#define SWITCH_DEFAULT_NULL SWITCH_DEFAULT({})

//! 表达式简化宏：函数调用型，双目运算符交互型，数组和小括号型。此宏一般用于给其他宏提供支持

//! 二元表达式简写宏
#define EXPRESSION_BINARY(_param1, _operator, _param2) _param1 _operator _param2
//! 中括号表达式简写宏
#define EXPRESSION_BRACKET(_param1, _param2) _param1[_param2]
//! 函数调用表达式简写宏
#define EXPRESSION_FUNCTION(_param, _call_way /* "->" or "." */, _func, ...) _param _call_way _func(__VA_ARGS__)
//! 小括号表达式简写宏
#define EXPRESSION_PARENTHESIS(_param1, ...) _param1(__VA_ARGS__)

//! Always inline
#if defined(__clang__)
#define ALWAYS_INLINE_FUNCTION inline __attribute__((always_inline))
#define ALWAYS_INLINE __attribute__((always_inline))
#endif

#ifndef ALWAYS_INLINE_FUNCTION
#define ALWAYS_INLINE_FUNCTION inline
#endif

#ifndef ALWAYS_INLINE
#define ALWAYS_INLINE inline
#endif
