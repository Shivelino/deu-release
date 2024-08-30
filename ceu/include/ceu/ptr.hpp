/*********************************************************************
 * @file    ptr.hpp 
 * @brief   pointer utils
 * @details  
 * @author  Shivelino
 * @date    2024.8.22
 * @version 
 * @par Copyright(c): 
 * @par todo:
 * @par history: 
 *********************************************************************/
#pragma once
#include "types.hpp"

namespace ceu {
/**
 * @brief 指针偏移模板函数。支持正负offset
 */
template <typename Ret = void*, typename Relay = char>
Ret ptr_offset(const void* in_ptr, offset_t offset) {
    return (Ret)((Relay*)in_ptr + offset);
}
}  // namespace ceu
