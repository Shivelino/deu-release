/*********************************************************************
 * @file    memory.hpp    
 * @brief   basic memory utils
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

// ! 猜测内存数据的可能类型。一般用于多态以及void*指针
// DECLARE UNION VARIABLES
#define _DECLARE_VARS_UNION_BASE(_level, _t) _t _arg_##_level;
#define _DECLARE_VARS_UNION_1(_t1) _DECLARE_VARS_UNION_BASE(1, _t1)
#define _DECLARE_VARS_UNION_2(_t1, _t2) \
    _DECLARE_VARS_UNION_1(_t1)          \
    _DECLARE_VARS_UNION_BASE(2, _t2)
#define _DECLARE_VARS_UNION_3(_t1, _t2, _t3) \
    _DECLARE_VARS_UNION_2(_t1, _t2)          \
    _DECLARE_VARS_UNION_BASE(3, _t3)
#define _DECLARE_VARS_UNION_4(_t1, _t2, _t3, _t4) \
    _DECLARE_VARS_UNION_3(_t1, _t2, _t3)          \
    _DECLARE_VARS_UNION_BASE(4, _t4)
#define _DECLARE_VARS_UNION_5(_t1, _t2, _t3, _t4, _t5) \
    _DECLARE_VARS_UNION_4(_t1, _t2, _t3, _t4)          \
    _DECLARE_VARS_UNION_BASE(5, _t5)
#define _DECLARE_VARS_UNION_6(_t1, _t2, _t3, _t4, _t5, _t6) \
    _DECLARE_VARS_UNION_5(_t1, _t2, _t3, _t4, _t5)          \
    _DECLARE_VARS_UNION_BASE(6, _t6)
#define _DECLARE_VARS_UNION_7(_t1, _t2, _t3, _t4, _t5, _t6, _t7) \
    _DECLARE_VARS_UNION_6(_t1, _t2, _t3, _t4, _t5, _t6)          \
    _DECLARE_VARS_UNION_BASE(7, _t7)
#define _DECLARE_VARS_UNION_8(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8) \
    _DECLARE_VARS_UNION_7(_t1, _t2, _t3, _t4, _t5, _t6, _t7)          \
    _DECLARE_VARS_UNION_BASE(8, _t8)
#define _DECLARE_VARS_UNION_9(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9) \
    _DECLARE_VARS_UNION_8(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8)          \
    _DECLARE_VARS_UNION_BASE(9, _t9)
#define _DECLARE_VARS_UNION_10(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10) \
    _DECLARE_VARS_UNION_9(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9)            \
    _DECLARE_VARS_UNION_BASE(10, _t10)
#define _DECLARE_VARS_UNION_11(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11) \
    _DECLARE_VARS_UNION_10(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10)           \
    _DECLARE_VARS_UNION_BASE(11, _t11)
#define _DECLARE_VARS_UNION_12(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12) \
    _DECLARE_VARS_UNION_11(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11)           \
    _DECLARE_VARS_UNION_BASE(12, _t12)
#define _DECLARE_VARS_UNION_13(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13) \
    _DECLARE_VARS_UNION_12(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12)           \
    _DECLARE_VARS_UNION_BASE(13, _t13)
#define _DECLARE_VARS_UNION_14(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13, _t14) \
    _DECLARE_VARS_UNION_13(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13)           \
    _DECLARE_VARS_UNION_BASE(14, _t14)
#define _DECLARE_VARS_UNION_15(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13, _t14, _t15) \
    _DECLARE_VARS_UNION_14(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13, _t14)           \
    _DECLARE_VARS_UNION_BASE(15, _t15)
#define _DECLARE_VARS_UNION_16(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13, _t14, _t15, _t16) \
    _DECLARE_VARS_UNION_15(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13, _t14, _t15)           \
    _DECLARE_VARS_UNION_BASE(16, _t16)

/**
 * @brief 通过union尝试转换以猜测数据的可能类型
 */
#define TRY_CAST_MEM(_in, ...)                            \
    union _U {                                            \
        ITERATE_MACRO(_DECLARE_VARS_UNION, ##__VA_ARGS__) \
    };                                                    \
    _U _parsed = *(_U*)(&_in);
