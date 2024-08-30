/*********************************************************************
 * @file    func_comparator.hpp    
 * @brief   
 *  函数比较器。用于比较类似函数或者复现函数的行为以观测效果偏差。
 *	目前功能较弱。
 * @details  
 * @author  Shivelino
 * @date    2024.8.22
 * @version 
 * @par Copyright(c): Concloud Software Corporation
 * @par todo:
 * @par history: 
 *********************************************************************/
#pragma once

#include "macro.hpp"

// ! 对比函数执行相关宏。使用宏直接在同一个作用域中执行分别执行所有函数。
#ifdef _MSC_VER
// DECLARE VARIABLES
#define _DECLARE_VARS(_postfix, _args) _DECLARE_VARS_##_postfix##_args
// FUNC ID: 0
#define _DECLARE_VARS_0(...) MSVC_EXPAND(CEU_CAT(_DECLARE_VARS_0_, GET_MACRO_ARGS_COUNT##(__VA_ARGS__))(__VA_ARGS__))
#define _DECLARE_VARS_0_BASE(_level, _arg1) auto _##_level##_0 = ##_arg1##;
#define _DECLARE_VARS_0_1(_arg1) _DECLARE_VARS_0_BASE(1, _arg1)
#define _DECLARE_VARS_0_2(_arg1, _arg2) \
    _DECLARE_VARS_0_1(_arg1)            \
    _DECLARE_VARS_0_BASE(2, _arg2)
#define _DECLARE_VARS_0_3(_arg1, _arg2, _arg3) \
    _DECLARE_VARS_0_2(_arg1, _arg2)            \
    _DECLARE_VARS_0_BASE(3, _arg3)
#define _DECLARE_VARS_0_4(_arg1, _arg2, _arg3, _arg4) \
    _DECLARE_VARS_0_3(_arg1, _arg2, _arg3)            \
    _DECLARE_VARS_0_BASE(4, _arg4)
#define _DECLARE_VARS_0_5(_arg1, _arg2, _arg3, _arg4, _arg5) \
    _DECLARE_VARS_0_4(_arg1, _arg2, _arg3, _arg4)            \
    _DECLARE_VARS_0_BASE(5, _arg5)
#define _DECLARE_VARS_0_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6) \
    _DECLARE_VARS_0_5(_arg1, _arg2, _arg3, _arg4, _arg5)            \
    _DECLARE_VARS_0_BASE(6, _arg6)
#define _DECLARE_VARS_0_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7) \
    _DECLARE_VARS_0_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6)            \
    _DECLARE_VARS_0_BASE(7, _arg7)
#define _DECLARE_VARS_0_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8) \
    _DECLARE_VARS_0_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7)            \
    _DECLARE_VARS_0_BASE(8, _arg8)
#define _DECLARE_VARS_0_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9) \
    _DECLARE_VARS_0_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8)            \
    _DECLARE_VARS_0_BASE(9, _arg9)
#define _DECLARE_VARS_0_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10) \
    _DECLARE_VARS_0_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9)              \
    _DECLARE_VARS_0_BASE(10, _arg10)
#define _DECLARE_VARS_0_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11) \
    _DECLARE_VARS_0_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10)             \
    _DECLARE_VARS_0_BASE(11, _arg11)
#define _DECLARE_VARS_0_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12) \
    _DECLARE_VARS_0_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11)             \
    _DECLARE_VARS_0_BASE(12, _arg12)
#define _DECLARE_VARS_0_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13) \
    _DECLARE_VARS_0_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)             \
    _DECLARE_VARS_0_BASE(13, _arg13)
#define _DECLARE_VARS_0_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14) \
    _DECLARE_VARS_0_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13)             \
    _DECLARE_VARS_0_BASE(14, _arg14)
#define _DECLARE_VARS_0_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15) \
    _DECLARE_VARS_0_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14)             \
    _DECLARE_VARS_0_BASE(15, _arg15)
#define _DECLARE_VARS_0_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16) \
    _DECLARE_VARS_0_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)             \
    _DECLARE_VARS_0_BASE(16, _arg16)
#define _DECLARE_VARS_0_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17) \
    _DECLARE_VARS_0_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16)             \
    _DECLARE_VARS_0_BASE(17, _arg17)
#define _DECLARE_VARS_0_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18) \
    _DECLARE_VARS_0_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17)             \
    _DECLARE_VARS_0_BASE(18, _arg18)
#define _DECLARE_VARS_0_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19) \
    _DECLARE_VARS_0_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18)             \
    _DECLARE_VARS_0_BASE(19, _arg19)
#define _DECLARE_VARS_0_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20) \
    _DECLARE_VARS_0_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19)             \
    _DECLARE_VARS_0_BASE(20, _arg20)
#define _DECLARE_VARS_0_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21) \
    _DECLARE_VARS_0_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20)             \
    _DECLARE_VARS_0_BASE(21, _arg21)
#define _DECLARE_VARS_0_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22) \
    _DECLARE_VARS_0_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21)             \
    _DECLARE_VARS_0_BASE(22, _arg22)
#define _DECLARE_VARS_0_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23) \
    _DECLARE_VARS_0_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22)             \
    _DECLARE_VARS_0_BASE(23, _arg23)
#define _DECLARE_VARS_0_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24) \
    _DECLARE_VARS_0_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23)             \
    _DECLARE_VARS_0_BASE(24, _arg24)
#define _DECLARE_VARS_0_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25) \
    _DECLARE_VARS_0_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24)             \
    _DECLARE_VARS_0_BASE(25, _arg25)
#define _DECLARE_VARS_0_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26) \
    _DECLARE_VARS_0_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25)             \
    _DECLARE_VARS_0_BASE(26, _arg26)
#define _DECLARE_VARS_0_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27) \
    _DECLARE_VARS_0_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26)             \
    _DECLARE_VARS_0_BASE(27, _arg27)
#define _DECLARE_VARS_0_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28) \
    _DECLARE_VARS_0_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27)             \
    _DECLARE_VARS_0_BASE(28, _arg28)
#define _DECLARE_VARS_0_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29) \
    _DECLARE_VARS_0_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28)             \
    _DECLARE_VARS_0_BASE(29, _arg29)
#define _DECLARE_VARS_0_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30)                                                                                                                                                                                                                        \
    _DECLARE_VARS_0_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29)     \
    _DECLARE_VARS_0_BASE(30, _arg30)
#define _DECLARE_VARS_0_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31)                                                                                                                                                                                                                \
    _DECLARE_VARS_0_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30)                                                                                                                                                                                                                            \
    _DECLARE_VARS_0_BASE(31, _arg31)
#define _DECLARE_VARS_0_32(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31, _arg32)                                                                                                                                                                                                        \
    _DECLARE_VARS_0_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30, _arg31)                                                                                                                                                                                                                    \
    _DECLARE_VARS_0_BASE(32, _arg32)
// FUNC ID: 1
#define _DECLARE_VARS_1(...) MSVC_EXPAND(CEU_CAT(_DECLARE_VARS_1_, GET_MACRO_ARGS_COUNT##(__VA_ARGS__))(__VA_ARGS__))
#define _DECLARE_VARS_1_BASE(_level, _arg1) auto _##_level##_1 = ##_arg1##;
#define _DECLARE_VARS_1_1(_arg1) _DECLARE_VARS_1_BASE(1, _arg1)
#define _DECLARE_VARS_1_2(_arg1, _arg2) \
    _DECLARE_VARS_1_1(_arg1)            \
    _DECLARE_VARS_1_BASE(2, _arg2)
#define _DECLARE_VARS_1_3(_arg1, _arg2, _arg3) \
    _DECLARE_VARS_1_2(_arg1, _arg2)            \
    _DECLARE_VARS_1_BASE(3, _arg3)
#define _DECLARE_VARS_1_4(_arg1, _arg2, _arg3, _arg4) \
    _DECLARE_VARS_1_3(_arg1, _arg2, _arg3)            \
    _DECLARE_VARS_1_BASE(4, _arg4)
#define _DECLARE_VARS_1_5(_arg1, _arg2, _arg3, _arg4, _arg5) \
    _DECLARE_VARS_1_4(_arg1, _arg2, _arg3, _arg4)            \
    _DECLARE_VARS_1_BASE(5, _arg5)
#define _DECLARE_VARS_1_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6) \
    _DECLARE_VARS_1_5(_arg1, _arg2, _arg3, _arg4, _arg5)            \
    _DECLARE_VARS_1_BASE(6, _arg6)
#define _DECLARE_VARS_1_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7) \
    _DECLARE_VARS_1_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6)            \
    _DECLARE_VARS_1_BASE(7, _arg7)
#define _DECLARE_VARS_1_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8) \
    _DECLARE_VARS_1_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7)            \
    _DECLARE_VARS_1_BASE(8, _arg8)
#define _DECLARE_VARS_1_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9) \
    _DECLARE_VARS_1_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8)            \
    _DECLARE_VARS_1_BASE(9, _arg9)
#define _DECLARE_VARS_1_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10) \
    _DECLARE_VARS_1_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9)              \
    _DECLARE_VARS_1_BASE(10, _arg10)
#define _DECLARE_VARS_1_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11) \
    _DECLARE_VARS_1_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10)             \
    _DECLARE_VARS_1_BASE(11, _arg11)
#define _DECLARE_VARS_1_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12) \
    _DECLARE_VARS_1_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11)             \
    _DECLARE_VARS_1_BASE(12, _arg12)
#define _DECLARE_VARS_1_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13) \
    _DECLARE_VARS_1_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)             \
    _DECLARE_VARS_1_BASE(13, _arg13)
#define _DECLARE_VARS_1_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14) \
    _DECLARE_VARS_1_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13)             \
    _DECLARE_VARS_1_BASE(14, _arg14)
#define _DECLARE_VARS_1_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15) \
    _DECLARE_VARS_1_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14)             \
    _DECLARE_VARS_1_BASE(15, _arg15)
#define _DECLARE_VARS_1_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16) \
    _DECLARE_VARS_1_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)             \
    _DECLARE_VARS_1_BASE(16, _arg16)
#define _DECLARE_VARS_1_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17) \
    _DECLARE_VARS_1_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16)             \
    _DECLARE_VARS_1_BASE(17, _arg17)
#define _DECLARE_VARS_1_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18) \
    _DECLARE_VARS_1_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17)             \
    _DECLARE_VARS_1_BASE(18, _arg18)
#define _DECLARE_VARS_1_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19) \
    _DECLARE_VARS_1_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18)             \
    _DECLARE_VARS_1_BASE(19, _arg19)
#define _DECLARE_VARS_1_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20) \
    _DECLARE_VARS_1_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19)             \
    _DECLARE_VARS_1_BASE(20, _arg20)
#define _DECLARE_VARS_1_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21) \
    _DECLARE_VARS_1_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20)             \
    _DECLARE_VARS_1_BASE(21, _arg21)
#define _DECLARE_VARS_1_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22) \
    _DECLARE_VARS_1_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21)             \
    _DECLARE_VARS_1_BASE(22, _arg22)
#define _DECLARE_VARS_1_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23) \
    _DECLARE_VARS_1_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22)             \
    _DECLARE_VARS_1_BASE(23, _arg23)
#define _DECLARE_VARS_1_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24) \
    _DECLARE_VARS_1_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23)             \
    _DECLARE_VARS_1_BASE(24, _arg24)
#define _DECLARE_VARS_1_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25) \
    _DECLARE_VARS_1_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24)             \
    _DECLARE_VARS_1_BASE(25, _arg25)
#define _DECLARE_VARS_1_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26) \
    _DECLARE_VARS_1_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25)             \
    _DECLARE_VARS_1_BASE(26, _arg26)
#define _DECLARE_VARS_1_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27) \
    _DECLARE_VARS_1_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26)             \
    _DECLARE_VARS_1_BASE(27, _arg27)
#define _DECLARE_VARS_1_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28) \
    _DECLARE_VARS_1_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27)             \
    _DECLARE_VARS_1_BASE(28, _arg28)
#define _DECLARE_VARS_1_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29) \
    _DECLARE_VARS_1_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28)             \
    _DECLARE_VARS_1_BASE(29, _arg29)
#define _DECLARE_VARS_1_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30)                                                                                                                                                                                                                        \
    _DECLARE_VARS_1_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29)     \
    _DECLARE_VARS_1_BASE(30, _arg30)
#define _DECLARE_VARS_1_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31)                                                                                                                                                                                                                \
    _DECLARE_VARS_1_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30)                                                                                                                                                                                                                            \
    _DECLARE_VARS_1_BASE(31, _arg31)
#define _DECLARE_VARS_1_32(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31, _arg32)                                                                                                                                                                                                        \
    _DECLARE_VARS_1_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30, _arg31)                                                                                                                                                                                                                    \
    _DECLARE_VARS_1_BASE(32, _arg32)
// FUNC ID: 2
#define _DECLARE_VARS_2(...) MSVC_EXPAND(CEU_CAT(_DECLARE_VARS_2_, GET_MACRO_ARGS_COUNT##(__VA_ARGS__))(__VA_ARGS__))
#define _DECLARE_VARS_2_BASE(_level, _arg1) auto _##_level##_2 = ##_arg1##;
#define _DECLARE_VARS_2_1(_arg1) _DECLARE_VARS_2_BASE(1, _arg1)
#define _DECLARE_VARS_2_2(_arg1, _arg2) \
    _DECLARE_VARS_2_1(_arg1)            \
    _DECLARE_VARS_2_BASE(2, _arg2)
#define _DECLARE_VARS_2_3(_arg1, _arg2, _arg3) \
    _DECLARE_VARS_2_2(_arg1, _arg2)            \
    _DECLARE_VARS_2_BASE(3, _arg3)
#define _DECLARE_VARS_2_4(_arg1, _arg2, _arg3, _arg4) \
    _DECLARE_VARS_2_3(_arg1, _arg2, _arg3)            \
    _DECLARE_VARS_2_BASE(4, _arg4)
#define _DECLARE_VARS_2_5(_arg1, _arg2, _arg3, _arg4, _arg5) \
    _DECLARE_VARS_2_4(_arg1, _arg2, _arg3, _arg4)            \
    _DECLARE_VARS_2_BASE(5, _arg5)
#define _DECLARE_VARS_2_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6) \
    _DECLARE_VARS_2_5(_arg1, _arg2, _arg3, _arg4, _arg5)            \
    _DECLARE_VARS_2_BASE(6, _arg6)
#define _DECLARE_VARS_2_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7) \
    _DECLARE_VARS_2_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6)            \
    _DECLARE_VARS_2_BASE(7, _arg7)
#define _DECLARE_VARS_2_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8) \
    _DECLARE_VARS_2_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7)            \
    _DECLARE_VARS_2_BASE(8, _arg8)
#define _DECLARE_VARS_2_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9) \
    _DECLARE_VARS_2_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8)            \
    _DECLARE_VARS_2_BASE(9, _arg9)
#define _DECLARE_VARS_2_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10) \
    _DECLARE_VARS_2_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9)              \
    _DECLARE_VARS_2_BASE(10, _arg10)
#define _DECLARE_VARS_2_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11) \
    _DECLARE_VARS_2_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10)             \
    _DECLARE_VARS_2_BASE(11, _arg11)
#define _DECLARE_VARS_2_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12) \
    _DECLARE_VARS_2_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11)             \
    _DECLARE_VARS_2_BASE(12, _arg12)
#define _DECLARE_VARS_2_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13) \
    _DECLARE_VARS_2_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)             \
    _DECLARE_VARS_2_BASE(13, _arg13)
#define _DECLARE_VARS_2_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14) \
    _DECLARE_VARS_2_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13)             \
    _DECLARE_VARS_2_BASE(14, _arg14)
#define _DECLARE_VARS_2_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15) \
    _DECLARE_VARS_2_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14)             \
    _DECLARE_VARS_2_BASE(15, _arg15)
#define _DECLARE_VARS_2_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16) \
    _DECLARE_VARS_2_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)             \
    _DECLARE_VARS_2_BASE(16, _arg16)
#define _DECLARE_VARS_2_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17) \
    _DECLARE_VARS_2_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16)             \
    _DECLARE_VARS_2_BASE(17, _arg17)
#define _DECLARE_VARS_2_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18) \
    _DECLARE_VARS_2_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17)             \
    _DECLARE_VARS_2_BASE(18, _arg18)
#define _DECLARE_VARS_2_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19) \
    _DECLARE_VARS_2_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18)             \
    _DECLARE_VARS_2_BASE(19, _arg19)
#define _DECLARE_VARS_2_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20) \
    _DECLARE_VARS_2_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19)             \
    _DECLARE_VARS_2_BASE(20, _arg20)
#define _DECLARE_VARS_2_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21) \
    _DECLARE_VARS_2_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20)             \
    _DECLARE_VARS_2_BASE(21, _arg21)
#define _DECLARE_VARS_2_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22) \
    _DECLARE_VARS_2_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21)             \
    _DECLARE_VARS_2_BASE(22, _arg22)
#define _DECLARE_VARS_2_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23) \
    _DECLARE_VARS_2_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22)             \
    _DECLARE_VARS_2_BASE(23, _arg23)
#define _DECLARE_VARS_2_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24) \
    _DECLARE_VARS_2_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23)             \
    _DECLARE_VARS_2_BASE(24, _arg24)
#define _DECLARE_VARS_2_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25) \
    _DECLARE_VARS_2_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24)             \
    _DECLARE_VARS_2_BASE(25, _arg25)
#define _DECLARE_VARS_2_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26) \
    _DECLARE_VARS_2_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25)             \
    _DECLARE_VARS_2_BASE(26, _arg26)
#define _DECLARE_VARS_2_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27) \
    _DECLARE_VARS_2_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26)             \
    _DECLARE_VARS_2_BASE(27, _arg27)
#define _DECLARE_VARS_2_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28) \
    _DECLARE_VARS_2_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27)             \
    _DECLARE_VARS_2_BASE(28, _arg28)
#define _DECLARE_VARS_2_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29) \
    _DECLARE_VARS_2_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28)             \
    _DECLARE_VARS_2_BASE(29, _arg29)
#define _DECLARE_VARS_2_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30)                                                                                                                                                                                                                        \
    _DECLARE_VARS_2_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29)     \
    _DECLARE_VARS_2_BASE(30, _arg30)
#define _DECLARE_VARS_2_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31)                                                                                                                                                                                                                \
    _DECLARE_VARS_2_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30)                                                                                                                                                                                                                            \
    _DECLARE_VARS_2_BASE(31, _arg31)
#define _DECLARE_VARS_2_32(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31, _arg32)                                                                                                                                                                                                        \
    _DECLARE_VARS_2_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30, _arg31)                                                                                                                                                                                                                    \
    _DECLARE_VARS_2_BASE(32, _arg32)
// FUNC ID: 3
#define _DECLARE_VARS_3(...) MSVC_EXPAND(CEU_CAT(_DECLARE_VARS_3_, GET_MACRO_ARGS_COUNT##(__VA_ARGS__))(__VA_ARGS__))
#define _DECLARE_VARS_3_BASE(_level, _arg1) auto _##_level##_3 = ##_arg1##;
#define _DECLARE_VARS_3_1(_arg1) _DECLARE_VARS_3_BASE(1, _arg1)
#define _DECLARE_VARS_3_2(_arg1, _arg2) \
    _DECLARE_VARS_3_1(_arg1)            \
    _DECLARE_VARS_3_BASE(2, _arg2)
#define _DECLARE_VARS_3_3(_arg1, _arg2, _arg3) \
    _DECLARE_VARS_3_2(_arg1, _arg2)            \
    _DECLARE_VARS_3_BASE(3, _arg3)
#define _DECLARE_VARS_3_4(_arg1, _arg2, _arg3, _arg4) \
    _DECLARE_VARS_3_3(_arg1, _arg2, _arg3)            \
    _DECLARE_VARS_3_BASE(4, _arg4)
#define _DECLARE_VARS_3_5(_arg1, _arg2, _arg3, _arg4, _arg5) \
    _DECLARE_VARS_3_4(_arg1, _arg2, _arg3, _arg4)            \
    _DECLARE_VARS_3_BASE(5, _arg5)
#define _DECLARE_VARS_3_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6) \
    _DECLARE_VARS_3_5(_arg1, _arg2, _arg3, _arg4, _arg5)            \
    _DECLARE_VARS_3_BASE(6, _arg6)
#define _DECLARE_VARS_3_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7) \
    _DECLARE_VARS_3_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6)            \
    _DECLARE_VARS_3_BASE(7, _arg7)
#define _DECLARE_VARS_3_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8) \
    _DECLARE_VARS_3_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7)            \
    _DECLARE_VARS_3_BASE(8, _arg8)
#define _DECLARE_VARS_3_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9) \
    _DECLARE_VARS_3_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8)            \
    _DECLARE_VARS_3_BASE(9, _arg9)
#define _DECLARE_VARS_3_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10) \
    _DECLARE_VARS_3_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9)              \
    _DECLARE_VARS_3_BASE(10, _arg10)
#define _DECLARE_VARS_3_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11) \
    _DECLARE_VARS_3_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10)             \
    _DECLARE_VARS_3_BASE(11, _arg11)
#define _DECLARE_VARS_3_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12) \
    _DECLARE_VARS_3_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11)             \
    _DECLARE_VARS_3_BASE(12, _arg12)
#define _DECLARE_VARS_3_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13) \
    _DECLARE_VARS_3_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)             \
    _DECLARE_VARS_3_BASE(13, _arg13)
#define _DECLARE_VARS_3_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14) \
    _DECLARE_VARS_3_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13)             \
    _DECLARE_VARS_3_BASE(14, _arg14)
#define _DECLARE_VARS_3_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15) \
    _DECLARE_VARS_3_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14)             \
    _DECLARE_VARS_3_BASE(15, _arg15)
#define _DECLARE_VARS_3_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16) \
    _DECLARE_VARS_3_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)             \
    _DECLARE_VARS_3_BASE(16, _arg16)
#define _DECLARE_VARS_3_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17) \
    _DECLARE_VARS_3_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16)             \
    _DECLARE_VARS_3_BASE(17, _arg17)
#define _DECLARE_VARS_3_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18) \
    _DECLARE_VARS_3_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17)             \
    _DECLARE_VARS_3_BASE(18, _arg18)
#define _DECLARE_VARS_3_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19) \
    _DECLARE_VARS_3_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18)             \
    _DECLARE_VARS_3_BASE(19, _arg19)
#define _DECLARE_VARS_3_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20) \
    _DECLARE_VARS_3_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19)             \
    _DECLARE_VARS_3_BASE(20, _arg20)
#define _DECLARE_VARS_3_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21) \
    _DECLARE_VARS_3_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20)             \
    _DECLARE_VARS_3_BASE(21, _arg21)
#define _DECLARE_VARS_3_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22) \
    _DECLARE_VARS_3_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21)             \
    _DECLARE_VARS_3_BASE(22, _arg22)
#define _DECLARE_VARS_3_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23) \
    _DECLARE_VARS_3_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22)             \
    _DECLARE_VARS_3_BASE(23, _arg23)
#define _DECLARE_VARS_3_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24) \
    _DECLARE_VARS_3_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23)             \
    _DECLARE_VARS_3_BASE(24, _arg24)
#define _DECLARE_VARS_3_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25) \
    _DECLARE_VARS_3_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24)             \
    _DECLARE_VARS_3_BASE(25, _arg25)
#define _DECLARE_VARS_3_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26) \
    _DECLARE_VARS_3_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25)             \
    _DECLARE_VARS_3_BASE(26, _arg26)
#define _DECLARE_VARS_3_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27) \
    _DECLARE_VARS_3_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26)             \
    _DECLARE_VARS_3_BASE(27, _arg27)
#define _DECLARE_VARS_3_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28) \
    _DECLARE_VARS_3_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27)             \
    _DECLARE_VARS_3_BASE(28, _arg28)
#define _DECLARE_VARS_3_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29) \
    _DECLARE_VARS_3_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28)             \
    _DECLARE_VARS_3_BASE(29, _arg29)
#define _DECLARE_VARS_3_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30)                                                                                                                                                                                                                        \
    _DECLARE_VARS_3_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29)     \
    _DECLARE_VARS_3_BASE(30, _arg30)
#define _DECLARE_VARS_3_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31)                                                                                                                                                                                                                \
    _DECLARE_VARS_3_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30)                                                                                                                                                                                                                            \
    _DECLARE_VARS_3_BASE(31, _arg31)
#define _DECLARE_VARS_3_32(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31, _arg32)                                                                                                                                                                                                        \
    _DECLARE_VARS_3_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30, _arg31)                                                                                                                                                                                                                    \
    _DECLARE_VARS_3_BASE(32, _arg32)
// FUNC ID: 4
#define _DECLARE_VARS_4(...) MSVC_EXPAND(CEU_CAT(_DECLARE_VARS_4_, GET_MACRO_ARGS_COUNT##(__VA_ARGS__))(__VA_ARGS__))
#define _DECLARE_VARS_4_BASE(_level, _arg1) auto _##_level##_4 = ##_arg1##;
#define _DECLARE_VARS_4_1(_arg1) _DECLARE_VARS_4_BASE(1, _arg1)
#define _DECLARE_VARS_4_2(_arg1, _arg2) \
    _DECLARE_VARS_4_1(_arg1)            \
    _DECLARE_VARS_4_BASE(2, _arg2)
#define _DECLARE_VARS_4_3(_arg1, _arg2, _arg3) \
    _DECLARE_VARS_4_2(_arg1, _arg2)            \
    _DECLARE_VARS_4_BASE(3, _arg3)
#define _DECLARE_VARS_4_4(_arg1, _arg2, _arg3, _arg4) \
    _DECLARE_VARS_4_3(_arg1, _arg2, _arg3)            \
    _DECLARE_VARS_4_BASE(4, _arg4)
#define _DECLARE_VARS_4_5(_arg1, _arg2, _arg3, _arg4, _arg5) \
    _DECLARE_VARS_4_4(_arg1, _arg2, _arg3, _arg4)            \
    _DECLARE_VARS_4_BASE(5, _arg5)
#define _DECLARE_VARS_4_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6) \
    _DECLARE_VARS_4_5(_arg1, _arg2, _arg3, _arg4, _arg5)            \
    _DECLARE_VARS_4_BASE(6, _arg6)
#define _DECLARE_VARS_4_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7) \
    _DECLARE_VARS_4_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6)            \
    _DECLARE_VARS_4_BASE(7, _arg7)
#define _DECLARE_VARS_4_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8) \
    _DECLARE_VARS_4_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7)            \
    _DECLARE_VARS_4_BASE(8, _arg8)
#define _DECLARE_VARS_4_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9) \
    _DECLARE_VARS_4_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8)            \
    _DECLARE_VARS_4_BASE(9, _arg9)
#define _DECLARE_VARS_4_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10) \
    _DECLARE_VARS_4_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9)              \
    _DECLARE_VARS_4_BASE(10, _arg10)
#define _DECLARE_VARS_4_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11) \
    _DECLARE_VARS_4_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10)             \
    _DECLARE_VARS_4_BASE(11, _arg11)
#define _DECLARE_VARS_4_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12) \
    _DECLARE_VARS_4_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11)             \
    _DECLARE_VARS_4_BASE(12, _arg12)
#define _DECLARE_VARS_4_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13) \
    _DECLARE_VARS_4_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)             \
    _DECLARE_VARS_4_BASE(13, _arg13)
#define _DECLARE_VARS_4_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14) \
    _DECLARE_VARS_4_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13)             \
    _DECLARE_VARS_4_BASE(14, _arg14)
#define _DECLARE_VARS_4_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15) \
    _DECLARE_VARS_4_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14)             \
    _DECLARE_VARS_4_BASE(15, _arg15)
#define _DECLARE_VARS_4_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16) \
    _DECLARE_VARS_4_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)             \
    _DECLARE_VARS_4_BASE(16, _arg16)
#define _DECLARE_VARS_4_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17) \
    _DECLARE_VARS_4_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16)             \
    _DECLARE_VARS_4_BASE(17, _arg17)
#define _DECLARE_VARS_4_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18) \
    _DECLARE_VARS_4_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17)             \
    _DECLARE_VARS_4_BASE(18, _arg18)
#define _DECLARE_VARS_4_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19) \
    _DECLARE_VARS_4_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18)             \
    _DECLARE_VARS_4_BASE(19, _arg19)
#define _DECLARE_VARS_4_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20) \
    _DECLARE_VARS_4_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19)             \
    _DECLARE_VARS_4_BASE(20, _arg20)
#define _DECLARE_VARS_4_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21) \
    _DECLARE_VARS_4_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20)             \
    _DECLARE_VARS_4_BASE(21, _arg21)
#define _DECLARE_VARS_4_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22) \
    _DECLARE_VARS_4_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21)             \
    _DECLARE_VARS_4_BASE(22, _arg22)
#define _DECLARE_VARS_4_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23) \
    _DECLARE_VARS_4_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22)             \
    _DECLARE_VARS_4_BASE(23, _arg23)
#define _DECLARE_VARS_4_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24) \
    _DECLARE_VARS_4_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23)             \
    _DECLARE_VARS_4_BASE(24, _arg24)
#define _DECLARE_VARS_4_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25) \
    _DECLARE_VARS_4_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24)             \
    _DECLARE_VARS_4_BASE(25, _arg25)
#define _DECLARE_VARS_4_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26) \
    _DECLARE_VARS_4_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25)             \
    _DECLARE_VARS_4_BASE(26, _arg26)
#define _DECLARE_VARS_4_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27) \
    _DECLARE_VARS_4_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26)             \
    _DECLARE_VARS_4_BASE(27, _arg27)
#define _DECLARE_VARS_4_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28) \
    _DECLARE_VARS_4_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27)             \
    _DECLARE_VARS_4_BASE(28, _arg28)
#define _DECLARE_VARS_4_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29) \
    _DECLARE_VARS_4_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28)             \
    _DECLARE_VARS_4_BASE(29, _arg29)
#define _DECLARE_VARS_4_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30)                                                                                                                                                                                                                        \
    _DECLARE_VARS_4_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29)     \
    _DECLARE_VARS_4_BASE(30, _arg30)
#define _DECLARE_VARS_4_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31)                                                                                                                                                                                                                \
    _DECLARE_VARS_4_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30)                                                                                                                                                                                                                            \
    _DECLARE_VARS_4_BASE(31, _arg31)
#define _DECLARE_VARS_4_32(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31, _arg32)                                                                                                                                                                                                        \
    _DECLARE_VARS_4_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30, _arg31)                                                                                                                                                                                                                    \
    _DECLARE_VARS_4_BASE(32, _arg32)
// FUNC ID: 5
#define _DECLARE_VARS_5(...) MSVC_EXPAND(CEU_CAT(_DECLARE_VARS_5_, GET_MACRO_ARGS_COUNT##(__VA_ARGS__))(__VA_ARGS__))
#define _DECLARE_VARS_5_BASE(_level, _arg1) auto _##_level##_5 = ##_arg1##;
#define _DECLARE_VARS_5_1(_arg1) _DECLARE_VARS_5_BASE(1, _arg1)
#define _DECLARE_VARS_5_2(_arg1, _arg2) \
    _DECLARE_VARS_5_1(_arg1)            \
    _DECLARE_VARS_5_BASE(2, _arg2)
#define _DECLARE_VARS_5_3(_arg1, _arg2, _arg3) \
    _DECLARE_VARS_5_2(_arg1, _arg2)            \
    _DECLARE_VARS_5_BASE(3, _arg3)
#define _DECLARE_VARS_5_4(_arg1, _arg2, _arg3, _arg4) \
    _DECLARE_VARS_5_3(_arg1, _arg2, _arg3)            \
    _DECLARE_VARS_5_BASE(4, _arg4)
#define _DECLARE_VARS_5_5(_arg1, _arg2, _arg3, _arg4, _arg5) \
    _DECLARE_VARS_5_4(_arg1, _arg2, _arg3, _arg4)            \
    _DECLARE_VARS_5_BASE(5, _arg5)
#define _DECLARE_VARS_5_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6) \
    _DECLARE_VARS_5_5(_arg1, _arg2, _arg3, _arg4, _arg5)            \
    _DECLARE_VARS_5_BASE(6, _arg6)
#define _DECLARE_VARS_5_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7) \
    _DECLARE_VARS_5_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6)            \
    _DECLARE_VARS_5_BASE(7, _arg7)
#define _DECLARE_VARS_5_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8) \
    _DECLARE_VARS_5_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7)            \
    _DECLARE_VARS_5_BASE(8, _arg8)
#define _DECLARE_VARS_5_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9) \
    _DECLARE_VARS_5_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8)            \
    _DECLARE_VARS_5_BASE(9, _arg9)
#define _DECLARE_VARS_5_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10) \
    _DECLARE_VARS_5_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9)              \
    _DECLARE_VARS_5_BASE(10, _arg10)
#define _DECLARE_VARS_5_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11) \
    _DECLARE_VARS_5_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10)             \
    _DECLARE_VARS_5_BASE(11, _arg11)
#define _DECLARE_VARS_5_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12) \
    _DECLARE_VARS_5_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11)             \
    _DECLARE_VARS_5_BASE(12, _arg12)
#define _DECLARE_VARS_5_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13) \
    _DECLARE_VARS_5_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)             \
    _DECLARE_VARS_5_BASE(13, _arg13)
#define _DECLARE_VARS_5_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14) \
    _DECLARE_VARS_5_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13)             \
    _DECLARE_VARS_5_BASE(14, _arg14)
#define _DECLARE_VARS_5_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15) \
    _DECLARE_VARS_5_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14)             \
    _DECLARE_VARS_5_BASE(15, _arg15)
#define _DECLARE_VARS_5_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16) \
    _DECLARE_VARS_5_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)             \
    _DECLARE_VARS_5_BASE(16, _arg16)
#define _DECLARE_VARS_5_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17) \
    _DECLARE_VARS_5_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16)             \
    _DECLARE_VARS_5_BASE(17, _arg17)
#define _DECLARE_VARS_5_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18) \
    _DECLARE_VARS_5_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17)             \
    _DECLARE_VARS_5_BASE(18, _arg18)
#define _DECLARE_VARS_5_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19) \
    _DECLARE_VARS_5_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18)             \
    _DECLARE_VARS_5_BASE(19, _arg19)
#define _DECLARE_VARS_5_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20) \
    _DECLARE_VARS_5_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19)             \
    _DECLARE_VARS_5_BASE(20, _arg20)
#define _DECLARE_VARS_5_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21) \
    _DECLARE_VARS_5_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20)             \
    _DECLARE_VARS_5_BASE(21, _arg21)
#define _DECLARE_VARS_5_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22) \
    _DECLARE_VARS_5_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21)             \
    _DECLARE_VARS_5_BASE(22, _arg22)
#define _DECLARE_VARS_5_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23) \
    _DECLARE_VARS_5_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22)             \
    _DECLARE_VARS_5_BASE(23, _arg23)
#define _DECLARE_VARS_5_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24) \
    _DECLARE_VARS_5_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23)             \
    _DECLARE_VARS_5_BASE(24, _arg24)
#define _DECLARE_VARS_5_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25) \
    _DECLARE_VARS_5_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24)             \
    _DECLARE_VARS_5_BASE(25, _arg25)
#define _DECLARE_VARS_5_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26) \
    _DECLARE_VARS_5_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25)             \
    _DECLARE_VARS_5_BASE(26, _arg26)
#define _DECLARE_VARS_5_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27) \
    _DECLARE_VARS_5_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26)             \
    _DECLARE_VARS_5_BASE(27, _arg27)
#define _DECLARE_VARS_5_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28) \
    _DECLARE_VARS_5_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27)             \
    _DECLARE_VARS_5_BASE(28, _arg28)
#define _DECLARE_VARS_5_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29) \
    _DECLARE_VARS_5_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28)             \
    _DECLARE_VARS_5_BASE(29, _arg29)
#define _DECLARE_VARS_5_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30)                                                                                                                                                                                                                        \
    _DECLARE_VARS_5_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29)     \
    _DECLARE_VARS_5_BASE(30, _arg30)
#define _DECLARE_VARS_5_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31)                                                                                                                                                                                                                \
    _DECLARE_VARS_5_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30)                                                                                                                                                                                                                            \
    _DECLARE_VARS_5_BASE(31, _arg31)
#define _DECLARE_VARS_5_32(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31, _arg32)                                                                                                                                                                                                        \
    _DECLARE_VARS_5_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30, _arg31)                                                                                                                                                                                                                    \
    _DECLARE_VARS_5_BASE(32, _arg32)
// FUNC ID: 6
#define _DECLARE_VARS_6(...) MSVC_EXPAND(CEU_CAT(_DECLARE_VARS_6_, GET_MACRO_ARGS_COUNT##(__VA_ARGS__))(__VA_ARGS__))
#define _DECLARE_VARS_6_BASE(_level, _arg1) auto _##_level##_6 = ##_arg1##;
#define _DECLARE_VARS_6_1(_arg1) _DECLARE_VARS_6_BASE(1, _arg1)
#define _DECLARE_VARS_6_2(_arg1, _arg2) \
    _DECLARE_VARS_6_1(_arg1)            \
    _DECLARE_VARS_6_BASE(2, _arg2)
#define _DECLARE_VARS_6_3(_arg1, _arg2, _arg3) \
    _DECLARE_VARS_6_2(_arg1, _arg2)            \
    _DECLARE_VARS_6_BASE(3, _arg3)
#define _DECLARE_VARS_6_4(_arg1, _arg2, _arg3, _arg4) \
    _DECLARE_VARS_6_3(_arg1, _arg2, _arg3)            \
    _DECLARE_VARS_6_BASE(4, _arg4)
#define _DECLARE_VARS_6_5(_arg1, _arg2, _arg3, _arg4, _arg5) \
    _DECLARE_VARS_6_4(_arg1, _arg2, _arg3, _arg4)            \
    _DECLARE_VARS_6_BASE(5, _arg5)
#define _DECLARE_VARS_6_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6) \
    _DECLARE_VARS_6_5(_arg1, _arg2, _arg3, _arg4, _arg5)            \
    _DECLARE_VARS_6_BASE(6, _arg6)
#define _DECLARE_VARS_6_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7) \
    _DECLARE_VARS_6_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6)            \
    _DECLARE_VARS_6_BASE(7, _arg7)
#define _DECLARE_VARS_6_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8) \
    _DECLARE_VARS_6_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7)            \
    _DECLARE_VARS_6_BASE(8, _arg8)
#define _DECLARE_VARS_6_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9) \
    _DECLARE_VARS_6_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8)            \
    _DECLARE_VARS_6_BASE(9, _arg9)
#define _DECLARE_VARS_6_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10) \
    _DECLARE_VARS_6_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9)              \
    _DECLARE_VARS_6_BASE(10, _arg10)
#define _DECLARE_VARS_6_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11) \
    _DECLARE_VARS_6_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10)             \
    _DECLARE_VARS_6_BASE(11, _arg11)
#define _DECLARE_VARS_6_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12) \
    _DECLARE_VARS_6_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11)             \
    _DECLARE_VARS_6_BASE(12, _arg12)
#define _DECLARE_VARS_6_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13) \
    _DECLARE_VARS_6_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)             \
    _DECLARE_VARS_6_BASE(13, _arg13)
#define _DECLARE_VARS_6_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14) \
    _DECLARE_VARS_6_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13)             \
    _DECLARE_VARS_6_BASE(14, _arg14)
#define _DECLARE_VARS_6_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15) \
    _DECLARE_VARS_6_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14)             \
    _DECLARE_VARS_6_BASE(15, _arg15)
#define _DECLARE_VARS_6_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16) \
    _DECLARE_VARS_6_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)             \
    _DECLARE_VARS_6_BASE(16, _arg16)
#define _DECLARE_VARS_6_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17) \
    _DECLARE_VARS_6_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16)             \
    _DECLARE_VARS_6_BASE(17, _arg17)
#define _DECLARE_VARS_6_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18) \
    _DECLARE_VARS_6_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17)             \
    _DECLARE_VARS_6_BASE(18, _arg18)
#define _DECLARE_VARS_6_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19) \
    _DECLARE_VARS_6_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18)             \
    _DECLARE_VARS_6_BASE(19, _arg19)
#define _DECLARE_VARS_6_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20) \
    _DECLARE_VARS_6_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19)             \
    _DECLARE_VARS_6_BASE(20, _arg20)
#define _DECLARE_VARS_6_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21) \
    _DECLARE_VARS_6_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20)             \
    _DECLARE_VARS_6_BASE(21, _arg21)
#define _DECLARE_VARS_6_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22) \
    _DECLARE_VARS_6_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21)             \
    _DECLARE_VARS_6_BASE(22, _arg22)
#define _DECLARE_VARS_6_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23) \
    _DECLARE_VARS_6_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22)             \
    _DECLARE_VARS_6_BASE(23, _arg23)
#define _DECLARE_VARS_6_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24) \
    _DECLARE_VARS_6_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23)             \
    _DECLARE_VARS_6_BASE(24, _arg24)
#define _DECLARE_VARS_6_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25) \
    _DECLARE_VARS_6_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24)             \
    _DECLARE_VARS_6_BASE(25, _arg25)
#define _DECLARE_VARS_6_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26) \
    _DECLARE_VARS_6_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25)             \
    _DECLARE_VARS_6_BASE(26, _arg26)
#define _DECLARE_VARS_6_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27) \
    _DECLARE_VARS_6_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26)             \
    _DECLARE_VARS_6_BASE(27, _arg27)
#define _DECLARE_VARS_6_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28) \
    _DECLARE_VARS_6_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27)             \
    _DECLARE_VARS_6_BASE(28, _arg28)
#define _DECLARE_VARS_6_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29) \
    _DECLARE_VARS_6_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28)             \
    _DECLARE_VARS_6_BASE(29, _arg29)
#define _DECLARE_VARS_6_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30)                                                                                                                                                                                                                        \
    _DECLARE_VARS_6_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29)     \
    _DECLARE_VARS_6_BASE(30, _arg30)
#define _DECLARE_VARS_6_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31)                                                                                                                                                                                                                \
    _DECLARE_VARS_6_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30)                                                                                                                                                                                                                            \
    _DECLARE_VARS_6_BASE(31, _arg31)
#define _DECLARE_VARS_6_32(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31, _arg32)                                                                                                                                                                                                        \
    _DECLARE_VARS_6_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30, _arg31)                                                                                                                                                                                                                    \
    _DECLARE_VARS_6_BASE(32, _arg32)
// FUNC ID: 7
#define _DECLARE_VARS_7(...) MSVC_EXPAND(CEU_CAT(_DECLARE_VARS_7_, GET_MACRO_ARGS_COUNT##(__VA_ARGS__))(__VA_ARGS__))
#define _DECLARE_VARS_7_BASE(_level, _arg1) auto _##_level##_7 = ##_arg1##;
#define _DECLARE_VARS_7_1(_arg1) _DECLARE_VARS_7_BASE(1, _arg1)
#define _DECLARE_VARS_7_2(_arg1, _arg2) \
    _DECLARE_VARS_7_1(_arg1)            \
    _DECLARE_VARS_7_BASE(2, _arg2)
#define _DECLARE_VARS_7_3(_arg1, _arg2, _arg3) \
    _DECLARE_VARS_7_2(_arg1, _arg2)            \
    _DECLARE_VARS_7_BASE(3, _arg3)
#define _DECLARE_VARS_7_4(_arg1, _arg2, _arg3, _arg4) \
    _DECLARE_VARS_7_3(_arg1, _arg2, _arg3)            \
    _DECLARE_VARS_7_BASE(4, _arg4)
#define _DECLARE_VARS_7_5(_arg1, _arg2, _arg3, _arg4, _arg5) \
    _DECLARE_VARS_7_4(_arg1, _arg2, _arg3, _arg4)            \
    _DECLARE_VARS_7_BASE(5, _arg5)
#define _DECLARE_VARS_7_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6) \
    _DECLARE_VARS_7_5(_arg1, _arg2, _arg3, _arg4, _arg5)            \
    _DECLARE_VARS_7_BASE(6, _arg6)
#define _DECLARE_VARS_7_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7) \
    _DECLARE_VARS_7_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6)            \
    _DECLARE_VARS_7_BASE(7, _arg7)
#define _DECLARE_VARS_7_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8) \
    _DECLARE_VARS_7_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7)            \
    _DECLARE_VARS_7_BASE(8, _arg8)
#define _DECLARE_VARS_7_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9) \
    _DECLARE_VARS_7_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8)            \
    _DECLARE_VARS_7_BASE(9, _arg9)
#define _DECLARE_VARS_7_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10) \
    _DECLARE_VARS_7_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9)              \
    _DECLARE_VARS_7_BASE(10, _arg10)
#define _DECLARE_VARS_7_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11) \
    _DECLARE_VARS_7_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10)             \
    _DECLARE_VARS_7_BASE(11, _arg11)
#define _DECLARE_VARS_7_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12) \
    _DECLARE_VARS_7_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11)             \
    _DECLARE_VARS_7_BASE(12, _arg12)
#define _DECLARE_VARS_7_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13) \
    _DECLARE_VARS_7_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)             \
    _DECLARE_VARS_7_BASE(13, _arg13)
#define _DECLARE_VARS_7_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14) \
    _DECLARE_VARS_7_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13)             \
    _DECLARE_VARS_7_BASE(14, _arg14)
#define _DECLARE_VARS_7_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15) \
    _DECLARE_VARS_7_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14)             \
    _DECLARE_VARS_7_BASE(15, _arg15)
#define _DECLARE_VARS_7_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16) \
    _DECLARE_VARS_7_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)             \
    _DECLARE_VARS_7_BASE(16, _arg16)
#define _DECLARE_VARS_7_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17) \
    _DECLARE_VARS_7_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16)             \
    _DECLARE_VARS_7_BASE(17, _arg17)
#define _DECLARE_VARS_7_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18) \
    _DECLARE_VARS_7_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17)             \
    _DECLARE_VARS_7_BASE(18, _arg18)
#define _DECLARE_VARS_7_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19) \
    _DECLARE_VARS_7_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18)             \
    _DECLARE_VARS_7_BASE(19, _arg19)
#define _DECLARE_VARS_7_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20) \
    _DECLARE_VARS_7_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19)             \
    _DECLARE_VARS_7_BASE(20, _arg20)
#define _DECLARE_VARS_7_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21) \
    _DECLARE_VARS_7_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20)             \
    _DECLARE_VARS_7_BASE(21, _arg21)
#define _DECLARE_VARS_7_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22) \
    _DECLARE_VARS_7_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21)             \
    _DECLARE_VARS_7_BASE(22, _arg22)
#define _DECLARE_VARS_7_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23) \
    _DECLARE_VARS_7_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22)             \
    _DECLARE_VARS_7_BASE(23, _arg23)
#define _DECLARE_VARS_7_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24) \
    _DECLARE_VARS_7_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23)             \
    _DECLARE_VARS_7_BASE(24, _arg24)
#define _DECLARE_VARS_7_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25) \
    _DECLARE_VARS_7_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24)             \
    _DECLARE_VARS_7_BASE(25, _arg25)
#define _DECLARE_VARS_7_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26) \
    _DECLARE_VARS_7_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25)             \
    _DECLARE_VARS_7_BASE(26, _arg26)
#define _DECLARE_VARS_7_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27) \
    _DECLARE_VARS_7_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26)             \
    _DECLARE_VARS_7_BASE(27, _arg27)
#define _DECLARE_VARS_7_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28) \
    _DECLARE_VARS_7_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27)             \
    _DECLARE_VARS_7_BASE(28, _arg28)
#define _DECLARE_VARS_7_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29) \
    _DECLARE_VARS_7_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28)             \
    _DECLARE_VARS_7_BASE(29, _arg29)
#define _DECLARE_VARS_7_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30)                                                                                                                                                                                                                        \
    _DECLARE_VARS_7_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29)     \
    _DECLARE_VARS_7_BASE(30, _arg30)
#define _DECLARE_VARS_7_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31)                                                                                                                                                                                                                \
    _DECLARE_VARS_7_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30)                                                                                                                                                                                                                            \
    _DECLARE_VARS_7_BASE(31, _arg31)
#define _DECLARE_VARS_7_32(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31, _arg32)                                                                                                                                                                                                        \
    _DECLARE_VARS_7_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30, _arg31)                                                                                                                                                                                                                    \
    _DECLARE_VARS_7_BASE(32, _arg32)
// FUNC ID: 8
#define _DECLARE_VARS_8(...) MSVC_EXPAND(CEU_CAT(_DECLARE_VARS_8_, GET_MACRO_ARGS_COUNT##(__VA_ARGS__))(__VA_ARGS__))
#define _DECLARE_VARS_8_BASE(_level, _arg1) auto _##_level##_8 = ##_arg1##;
#define _DECLARE_VARS_8_1(_arg1) _DECLARE_VARS_8_BASE(1, _arg1)
#define _DECLARE_VARS_8_2(_arg1, _arg2) \
    _DECLARE_VARS_8_1(_arg1)            \
    _DECLARE_VARS_8_BASE(2, _arg2)
#define _DECLARE_VARS_8_3(_arg1, _arg2, _arg3) \
    _DECLARE_VARS_8_2(_arg1, _arg2)            \
    _DECLARE_VARS_8_BASE(3, _arg3)
#define _DECLARE_VARS_8_4(_arg1, _arg2, _arg3, _arg4) \
    _DECLARE_VARS_8_3(_arg1, _arg2, _arg3)            \
    _DECLARE_VARS_8_BASE(4, _arg4)
#define _DECLARE_VARS_8_5(_arg1, _arg2, _arg3, _arg4, _arg5) \
    _DECLARE_VARS_8_4(_arg1, _arg2, _arg3, _arg4)            \
    _DECLARE_VARS_8_BASE(5, _arg5)
#define _DECLARE_VARS_8_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6) \
    _DECLARE_VARS_8_5(_arg1, _arg2, _arg3, _arg4, _arg5)            \
    _DECLARE_VARS_8_BASE(6, _arg6)
#define _DECLARE_VARS_8_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7) \
    _DECLARE_VARS_8_6(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6)            \
    _DECLARE_VARS_8_BASE(7, _arg7)
#define _DECLARE_VARS_8_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8) \
    _DECLARE_VARS_8_7(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7)            \
    _DECLARE_VARS_8_BASE(8, _arg8)
#define _DECLARE_VARS_8_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9) \
    _DECLARE_VARS_8_8(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8)            \
    _DECLARE_VARS_8_BASE(9, _arg9)
#define _DECLARE_VARS_8_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10) \
    _DECLARE_VARS_8_9(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9)              \
    _DECLARE_VARS_8_BASE(10, _arg10)
#define _DECLARE_VARS_8_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11) \
    _DECLARE_VARS_8_10(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10)             \
    _DECLARE_VARS_8_BASE(11, _arg11)
#define _DECLARE_VARS_8_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12) \
    _DECLARE_VARS_8_11(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11)             \
    _DECLARE_VARS_8_BASE(12, _arg12)
#define _DECLARE_VARS_8_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13) \
    _DECLARE_VARS_8_12(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)             \
    _DECLARE_VARS_8_BASE(13, _arg13)
#define _DECLARE_VARS_8_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14) \
    _DECLARE_VARS_8_13(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13)             \
    _DECLARE_VARS_8_BASE(14, _arg14)
#define _DECLARE_VARS_8_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15) \
    _DECLARE_VARS_8_14(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14)             \
    _DECLARE_VARS_8_BASE(15, _arg15)
#define _DECLARE_VARS_8_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16) \
    _DECLARE_VARS_8_15(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)             \
    _DECLARE_VARS_8_BASE(16, _arg16)
#define _DECLARE_VARS_8_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17) \
    _DECLARE_VARS_8_16(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16)             \
    _DECLARE_VARS_8_BASE(17, _arg17)
#define _DECLARE_VARS_8_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18) \
    _DECLARE_VARS_8_17(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17)             \
    _DECLARE_VARS_8_BASE(18, _arg18)
#define _DECLARE_VARS_8_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19) \
    _DECLARE_VARS_8_18(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18)             \
    _DECLARE_VARS_8_BASE(19, _arg19)
#define _DECLARE_VARS_8_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20) \
    _DECLARE_VARS_8_19(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19)             \
    _DECLARE_VARS_8_BASE(20, _arg20)
#define _DECLARE_VARS_8_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21) \
    _DECLARE_VARS_8_20(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20)             \
    _DECLARE_VARS_8_BASE(21, _arg21)
#define _DECLARE_VARS_8_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22) \
    _DECLARE_VARS_8_21(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21)             \
    _DECLARE_VARS_8_BASE(22, _arg22)
#define _DECLARE_VARS_8_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23) \
    _DECLARE_VARS_8_22(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22)             \
    _DECLARE_VARS_8_BASE(23, _arg23)
#define _DECLARE_VARS_8_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24) \
    _DECLARE_VARS_8_23(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23)             \
    _DECLARE_VARS_8_BASE(24, _arg24)
#define _DECLARE_VARS_8_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25) \
    _DECLARE_VARS_8_24(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24)             \
    _DECLARE_VARS_8_BASE(25, _arg25)
#define _DECLARE_VARS_8_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26) \
    _DECLARE_VARS_8_25(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25)             \
    _DECLARE_VARS_8_BASE(26, _arg26)
#define _DECLARE_VARS_8_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27) \
    _DECLARE_VARS_8_26(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26)             \
    _DECLARE_VARS_8_BASE(27, _arg27)
#define _DECLARE_VARS_8_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28) \
    _DECLARE_VARS_8_27(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27)             \
    _DECLARE_VARS_8_BASE(28, _arg28)
#define _DECLARE_VARS_8_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29) \
    _DECLARE_VARS_8_28(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28)             \
    _DECLARE_VARS_8_BASE(29, _arg29)
#define _DECLARE_VARS_8_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30)                                                                                                                                                                                                                        \
    _DECLARE_VARS_8_29(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29)     \
    _DECLARE_VARS_8_BASE(30, _arg30)
#define _DECLARE_VARS_8_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31)                                                                                                                                                                                                                \
    _DECLARE_VARS_8_30(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30)                                                                                                                                                                                                                            \
    _DECLARE_VARS_8_BASE(31, _arg31)
#define _DECLARE_VARS_8_32(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29, \
                           _arg30, _arg31, _arg32)                                                                                                                                                                                                        \
    _DECLARE_VARS_8_31(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18, _arg19, _arg20, _arg21, _arg22, _arg23, _arg24, _arg25, _arg26, _arg27, _arg28, _arg29,     \
                       _arg30, _arg31)                                                                                                                                                                                                                    \
    _DECLARE_VARS_8_BASE(32, _arg32)

// COMPARE FUNCTION RUN
// 无返回值函数的比较宏
// 宏函数参数：f1, f2, ..., args
#define COMPARE_FUNCS_NORET(...)                                                             \
    MSVC_EXPAND(CEU_CAT(_PARAMS_BACKUP_, GET_MACRO_ARGS_COUNT_S1(__VA_ARGS__))(__VA_ARGS__)) \
    MSVC_EXPAND(CEU_CAT(_COMPARE_FUNC_NORET_, GET_MACRO_ARGS_COUNT_S1(__VA_ARGS__))(__VA_ARGS__))
#define _COMPARE_FUNC_NORET_BASE(_level, _f1, _args) _DECLARE_VARS(_level, _args) _f1##_args;
#define _COMPARE_FUNC_NORET_1(_f1, _args) _COMPARE_FUNC_NORET_BASE(1, _f1, _args)
#define _COMPARE_FUNC_NORET_2(_f1, _f2, _args) \
    _COMPARE_FUNC_NORET_1(_f1, _args)          \
    _COMPARE_FUNC_NORET_BASE(2, _f2, _args)
#define _COMPARE_FUNC_NORET_3(_f1, _f2, _f3, _args) \
    _COMPARE_FUNC_NORET_2(_f1, _f2, _args)          \
    _COMPARE_FUNC_NORET_BASE(3, _f3, _args)
#define _COMPARE_FUNC_NORET_4(_f1, _f2, _f3, _f4, _args) \
    _COMPARE_FUNC_NORET_3(_f1, _f2, _f3, _args)          \
    _COMPARE_FUNC_NORET_BASE(4, _f4, _args)
#define _COMPARE_FUNC_NORET_5(_f1, _f2, _f3, _f4, _f5, _args) \
    _COMPARE_FUNC_NORET_4(_f1, _f2, _f3, _f4, _args)          \
    _COMPARE_FUNC_NORET_BASE(5, _f5, _args)
#define _COMPARE_FUNC_NORET_6(_f1, _f2, _f3, _f4, _f5, _f6, _args) \
    _COMPARE_FUNC_NORET_5(_f1, _f2, _f3, _f4, _f5, _args)          \
    _COMPARE_FUNC_NORET_BASE(6, _f6, _args)
#define _COMPARE_FUNC_NORET_7(_f1, _f2, _f3, _f4, _f5, _f6, _f7, _args) \
    _COMPARE_FUNC_NORET_6(_f1, _f2, _f3, _f4, _f5, _f6, _args)          \
    _COMPARE_FUNC_NORET_BASE(7, _f7, _args)
#define _COMPARE_FUNC_NORET_8(_f1, _f2, _f3, _f4, _f5, _f6, _f7, _f8, _args) \
    _COMPARE_FUNC_NORET_7(_f1, _f2, _f3, _f4, _f5, _f6, _f7, _args)          \
    _COMPARE_FUNC_NORET_BASE(8, _f8, _args)
// 有返回值函数的比较宏
// 宏函数参数：f1, f2, ..., args
#define COMPARE_FUNCS(...)                                                                   \
    MSVC_EXPAND(CEU_CAT(_PARAMS_BACKUP_, GET_MACRO_ARGS_COUNT_S1(__VA_ARGS__))(__VA_ARGS__)) \
    MSVC_EXPAND(CEU_CAT(_COMPARE_FUNC_, GET_MACRO_ARGS_COUNT_S1(__VA_ARGS__))(__VA_ARGS__))
#define _COMPARE_FUNC_BASE(_level, _f1, _args) \
    auto _ret_##_level = _f1##_args;           \
    _DECLARE_VARS(_level, _args)
#define _COMPARE_FUNC_1(_f1, _args) _COMPARE_FUNC_BASE(1, _f1, _args)
#define _COMPARE_FUNC_2(_f1, _f2, _args) \
    _COMPARE_FUNC_1(_f1, _args)          \
    _COMPARE_FUNC_BASE(2, _f2, _args)
#define _COMPARE_FUNC_3(_f1, _f2, _f3, _args) \
    _COMPARE_FUNC_2(_f1, _f2, _args)          \
    _COMPARE_FUNC_BASE(3, _f3, _args)
#define _COMPARE_FUNC_4(_f1, _f2, _f3, _f4, _args) \
    _COMPARE_FUNC_3(_f1, _f2, _f3, _args)          \
    _COMPARE_FUNC_BASE(4, _f4, _args)
#define _COMPARE_FUNC_5(_f1, _f2, _f3, _f4, _f5, _args) \
    _COMPARE_FUNC_4(_f1, _f2, _f3, _f4, _args)          \
    _COMPARE_FUNC_BASE(5, _f5, _args)
#define _COMPARE_FUNC_6(_f1, _f2, _f3, _f4, _f5, _f6, _args) \
    _COMPARE_FUNC_5(_f1, _f2, _f3, _f4, _f5, _args)          \
    _COMPARE_FUNC_BASE(6, _f6, _args)
#define _COMPARE_FUNC_7(_f1, _f2, _f3, _f4, _f5, _f6, _f7, _args) \
    _COMPARE_FUNC_6(_f1, _f2, _f3, _f4, _f5, _f6, _args)          \
    _COMPARE_FUNC_BASE(7, _f7, _args)
#define _COMPARE_FUNC_8(_f1, _f2, _f3, _f4, _f5, _f6, _f7, _f8, _args) \
    _COMPARE_FUNC_7(_f1, _f2, _f3, _f4, _f5, _f6, _f7, _args)          \
    _COMPARE_FUNC_BASE(8, _f8, _args)
// PARAM BACKUP
#define _PARAMS_BACKUP_1(_1, _args) _DECLARE_VARS(0, _args)
#define _PARAMS_BACKUP_2(_1, _2, _args) _DECLARE_VARS(0, _args)
#define _PARAMS_BACKUP_3(_1, _2, _3, _args) _DECLARE_VARS(0, _args)
#define _PARAMS_BACKUP_4(_1, _2, _3, _4, _args) _DECLARE_VARS(0, _args)
#define _PARAMS_BACKUP_5(_1, _2, _3, _4, _5, _args) _DECLARE_VARS(0, _args)
#define _PARAMS_BACKUP_6(_1, _2, _3, _4, _5, _6, _args) _DECLARE_VARS(0, _args)
#define _PARAMS_BACKUP_7(_1, _2, _3, _4, _5, _6, _7, _args) _DECLARE_VARS(0, _args)
#define _PARAMS_BACKUP_8(_1, _2, _3, _4, _5, _6, _7, _8, _args) _DECLARE_VARS(0, _args)
#else
// todo GNU_C
#endif

// ! 通过多线程/多进程进行对比（即基于hook）
void compare_funcs_by_hook() {}  // todo
