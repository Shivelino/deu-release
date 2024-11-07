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

/**
 * @brief   Integral Concept.
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename Ty>
concept ConceptIntegral = std::is_integral_v<Ty>;

/**
 * @brief   Floating Concept.
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename Ty>
concept ConceptFloating = std::is_floating_point_v<Ty>;

/**
 * @brief   Arithmetic Concept.
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename Ty>
concept ConceptArithmetic = std::is_arithmetic_v<Ty>;

/**
 * @brief   Check if a Type is std::tuple.
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename Ty>
struct is_tuple : std::false_type {};

template <typename... ArgsTy>
struct is_tuple<std::tuple<ArgsTy...>> : std::true_type {};

template <typename Ty>
constexpr bool is_tuple_v = is_tuple<Ty>::value;

/**
 * @brief   Tuple Concept.
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename Ty>
concept CoceptTupleTy = is_tuple_v<Ty>;

}  // namespace ceu
