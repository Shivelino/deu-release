/*********************************************************************
 * @file    traits.hpp    
 * @brief   
 *  1, traits: 声明时给类附加功能
 *  2, decorated: 通过1个类实例在作用域中派生新的类，不改变父类的方法，新增成员变量或函数
 *  3, wrap: 通过1个类实例在作用域中派生新的类，改变父类的方法，（暂不支持,TODO）可选新增成员变量或函数
 *	   以上三种类型的类型附加均通过宏的方式进行，所受限制很大，预想后续改为通过模板元的方式进行
 * @details  
 * @author  Shivelino
 * @date    2024.8.22
 * @version 
 * @par Copyright(c): 
 * @par todo:
 *  1, not tested
 * @par history: 
 *********************************************************************/
#pragma once
#include "../macro.hpp"

// traits: 声明时给类附加功能
#define extend : public
#define trait_with , public
#define traits_base(_type) trait_with _type
#define traits_1(_t1) extend _t1
#define traits_2(_t1, _t2) traits_1(_t1) traits_base(_t2)
#define traits_3(_t1, _t2, _t3) traits_2(_t1, _t2) traits_base(_t3)
#define traits_4(_t1, _t2, _t3, _t4) traits_3(_t1, _t2, _t3) traits_base(_t4)
#define traits_5(_t1, _t2, _t3, _t4, _t5) traits_4(_t1, _t2, _t3, _t4) traits_base(_t5)
#define traits_6(_t1, _t2, _t3, _t4, _t5, _t6) traits_5(_t1, _t2, _t3, _t4, _t5) traits_base(_t6)
#define traits_7(_t1, _t2, _t3, _t4, _t5, _t6, _t7) traits_6(_t1, _t2, _t3, _t4, _t5, _t6) traits_base(_t7)
#define traits_8(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8) traits_7(_t1, _t2, _t3, _t4, _t5, _t6, _t7) traits_base(_t8)
#define traits_9(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9) traits_8(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8) traits_base(_t9)
#define traits_10(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10) traits_9(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9) traits_base(_t10)
#define traits_11(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11) traits_10(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10) traits_base(_t11)
#define traits_12(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12) traits_11(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11) traits_base(_t12)
#define traits_13(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13) traits_12(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12) traits_base(_t13)
#define traits_14(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13, _t14) traits_13(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13) traits_base(_t14)
#define traits_15(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13, _t14, _t15) traits_14(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13, _t14) traits_base(_t15)
#define traits_16(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13, _t14, _t15, _t16) traits_15(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13, _t14, _t15) traits_base(_t16)
#define traits(...) MSVC_EXPAND(CEU_CAT(traits_, GET_MACRO_ARGS_COUNT##(__VA_ARGS__))(__VA_ARGS__))

// decorated: 通过1个类实例在作用域中派生新的类，不改变父类的方法，新增成员变量或函数
#define decorate(_obj, _type)    \
    class CEU_CAT(_obj, _type) : \
        public decltype(_obj) trait_with _type

// wrap: 通过1个类实例在作用域中派生新的类，改变父类的方法，（暂不支持,TODO）可选新增成员变量或函数
#define wrap(_obj)               \
    class CEU_CAT(_obj, Deriv) : \
        public decltype(_obj)

namespace ceu {

class Traitable {};  // 所有特征类的基类。这里只是定义形式，用于类型编程。

}  // namespace ceu
