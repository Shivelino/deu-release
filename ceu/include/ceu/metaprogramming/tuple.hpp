/*********************************************************************
 * @file    tuple.hpp    
 * @brief   
 * @details  
 * @author  Shivelino
 * @date    2024.9.14
 * @version 
 * @par Copyright(c): Concloud Software Corporation
 * @par todo:
 * @par history: 
 *********************************************************************/
#pragma once
#include <tuple>
#include <utility>

namespace ceu {

/**
 * @brief   take the elements of std::tuple
 * @details  
 * @par todo:
 * @par history: 
 */
template <std::size_t... Indices, typename Tuple>
auto tuple_take(const Tuple& t, std::index_sequence<Indices...>) {
    return std::forward_as_tuple(std::get<Indices>(t)...);
}

/**
 * @brief   take the first N elements of std::tuple
 * @details  
 * @par todo:
 * @par history: 
 */
template <std::size_t N, typename Tuple>
auto tuple_take_first_N(const Tuple& t) {
    return tuple_take(t, std::make_index_sequence<N>{});
}

}  // namespace ceu
