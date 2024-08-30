/*********************************************************************
 * @file    concepts.h    
 * @brief   
 * @details  
 * @author  Shivelino
 * @date
 * @version 
 * @par Copyright(c): 
 * @par todo:
 * @par history: 
 *********************************************************************/
#pragma once

#include <type_traits>

namespace ceu {

template <typename _Ty>
concept integral_type = std::is_integral_v<_Ty>;

template <typename _Ty>
concept floating_type = std::is_floating_point_v<_Ty>;

template <typename _Ty>
concept arithmetic_type = std::is_arithmetic_v<_Ty>;

}  // namespace ceu
