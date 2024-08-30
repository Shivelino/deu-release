/*********************************************************************
 * @file    dllexport.h    
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

// export/import
#define _EXPORT_DLL __declspec(dllexport)
#define _IMPORT_DLL __declspec(dllimport)

#ifdef LIB_BUILD_AS_HEADER_ONLY  // build as header-only
#define DLL_OPTION
#else
#ifdef LIB_BUILD_AS_SHARED  // build as shared
#ifdef LIB_EXPORT_DLL
#define DLL_OPTION _EXPORT_DLL
#else
#define DLL_OPTION _IMPORT_DLL
#endif
#else  // build as static
#define DLL_OPTION
#endif
#endif
