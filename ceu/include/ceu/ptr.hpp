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
#include <memory>

#include "types.hpp"

namespace ceu {
/**
 * @brief 指针偏移模板函数。支持正负offset
 */
template <typename Ret = void*, typename Relay = char>
Ret ptr_offset(const void* in_ptr, offset_t offset) {
    return (Ret)((Relay*)in_ptr + offset);
}

/**
 * @brief   Create a shared ptr.
 * @details  
 * @par todo:
 * @par history: 
 */
template <typename RealTy, typename... ArgsTy>
std::shared_ptr<RealTy> api_create_sptr(ArgsTy&&... args) {
    // 移交raw指针给shared_ptr，这里不使用make_shared的原因是make_shared调用了其他的函数无法访问private构造器
    return std::shared_ptr<RealTy>(new RealTy(std::forward<ArgsTy>(args)...));
}
}  // namespace ceu
