/*********************************************************************
 * @file    dll_linker.hpp    
 * @brief   dll链接器。用于在代码中手动加载并运行dll。
 * @details  
 * @author  Shivelino
 * @date    2024.8.22
 * @version 
 * @par Copyright(c): Concloud Software Corporation
 * @par todo:
 * @par history: 
 *********************************************************************/
#pragma once
#include <string>
#include <vector>

#include "exceptions.hpp"
#include "macro.hpp"

namespace ceu {

// ! 在程序中手动加载DLL并调用其中的函数
#ifdef WIN32
#include <Windows.h>  // Windows 特定头文件
// 函数是否存在返回值的option
#define OPTION_WITH_RET(_ret_type) _ret_type func_ret =
#define OPTION_NO_RET(_ret_type)
// 函数调用方式
#define _FUNCTION_CALL_THIS(_instance_ptr, ...) func_ptr(reinterpret_cast<void*>(_instance_ptr), ##__VA_ARGS__);
#define _FUNCTION_CALL_STD(...) func_ptr(__VA_ARGS__);
// 直接通过DLL加载对应函数：成员函数
#define CALL_DLL_THIS(_mode, _dll, _func_id, _ret_type, ... /*变长参数type*/)       \
    typedef _ret_type(__thiscall* func_ptr_type)(void*, ##__VA_ARGS__);             \
    func_ptr_type func_ptr = nullptr;                                               \
    if (hDLL != NULL) {                                                             \
        func_ptr = reinterpret_cast<func_ptr_type>(GetProcAddress(_dll, _func_id)); \
    }                                                                               \
    _mode##(_ret_type)_FUNCTION_CALL_THIS
// 直接通过DLL加载对应函数：独立函数
#define CALL_DLL_STD(_mode, _dll, _func_id, _ret_type, ... /*变长参数type*/)        \
    typedef _ret_type(__stdcall* func_ptr_type)(__VA_ARGS__);                       \
    func_ptr_type func_ptr = nullptr;                                               \
    if (hDLL != NULL) {                                                             \
        func_ptr = reinterpret_cast<func_ptr_type>(GetProcAddress(_dll, _func_id)); \
    }                                                                               \
    _mode##(_ret_type)_FUNCTION_CALL_STD

// 加载DLL文件
#define LOAD_DLL(_file_path) LoadLibrary(_file_path)
// 释放DLL文件
#define FREE_DLL(_dll) FreeLibrary(_dll)

#else
// todo linux
#endif

// ! 加载DLL文件并获取相关信息
ALWAYS_INLINE_FUNCTION void dll_get_export(const char* dll_path, std::vector<std::string>& exports) {
#ifdef WIN32
    size_t size = strlen(dll_path);
    wchar_t* wArr = new wchar_t[size];
    for (size_t i = 0; i < size; ++i)
        wArr[i] = dll_path[i];

    HMODULE dll_module = LOAD_DLL(&wArr[0]);
    if (dll_module == nullptr) {
        FREE_DLL(dll_module);
        throw Exception();
    }
    // DWORD num_funcs = EnumExportedFunctions(dll_module, nullptr, 0);
    // todo windows并不直接提供PE文件的解析接口，只能将DLL加载进进程然后调用。如果需要导出export，则应该使用PE文件的解析库。

    SET_NULLPTR_BY_DELETE_ARR(wArr);
#else
    // todo linux
#endif
}

}  // namespace ceu
