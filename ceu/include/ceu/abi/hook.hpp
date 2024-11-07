/*********************************************************************
 * @file    hook.hpp    
 * @brief   
 * @details Before usage, you should link safetyhook first
 * @author  Shivelino
 * @date    2024.10.9
 * @version 
 * @par Copyright(c): Concloud Software Corporation
 * @par todo:
 * @par history: 
 *********************************************************************/
#pragma once

#if __has_include(<safetyhook.hpp>)
#include <safetyhook.hpp>

namespace ceu {

/**
 * @brief   Hook Inline by safetyhook.
 * @details  
 * @par todo:
 * @par history: 
 */
class HookInlineBySth {
private:
    bool _unhookable = true;
    SafetyHookInline _g_hook{};

public:
    template <typename... ArgsTy>
    HookInlineBySth(ArgsTy&&... args) {
        _g_hook = safetyhook::create_inline(std::forward<ArgsTy>(args)...);
    }

    ~HookInlineBySth() {
        if (_unhookable)
            _g_hook.reset();
    }

public:
    void unhook() {
        if (_unhookable) {
            _g_hook.reset();
            _unhookable = false;
        }
    };
};

}  // namespace ceu
#endif
