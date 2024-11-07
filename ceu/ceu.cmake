cmake_minimum_required(VERSION 3.27)

set(CEU_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
set(CEU_3RDPARTY_DIR "${CMAKE_CURRENT_LIST_DIR}/3rdparty")
set(CEU_SCRIPTS_DIR "${CMAKE_CURRENT_LIST_DIR}/scripts")
set(CEU_CMAKE_DIR "${CMAKE_CURRENT_LIST_DIR}/cmake")
set(CEU_PERSONAL_DIR "${CEU_CMAKE_DIR}/personal")
set(CEU_DOWNLOAD_DIR "${CMAKE_CURRENT_LIST_DIR}/download")

# include personal file
if(DEFINED CEU_PERSONAL_CONFIG)
    set(CEU_PERSONAL_CONFIG_LOWER)
    string(TOLOWER ${CEU_PERSONAL_CONFIG} CEU_PERSONAL_CONFIG_LOWER)
    include("${CEU_PERSONAL_DIR}/${CEU_PERSONAL_CONFIG_LOWER}.cmake")
    message(STATUS "Using personal config: ${CEU_PERSONAL_CONFIG_LOWER}.cmake")
endif()

# include other files
include("${CEU_CMAKE_DIR}/include.cmake")
include("${CEU_CMAKE_DIR}/target.cmake")
include("${CEU_CMAKE_DIR}/path.cmake")
include("${CEU_CMAKE_DIR}/program.cmake")
include("${CEU_CMAKE_DIR}/CPM.cmake")
include("${CEU_CMAKE_DIR}/compiler.cmake")
include("${CEU_CMAKE_DIR}/config.cmake")
include("${CEU_CMAKE_DIR}/pkgconfig.cmake")
include("${CEU_CMAKE_DIR}/vcpkg/vcpkg.cmake")

# file(GLOB_RECURSE _3rdparty_cmake_lists "${CEU_CMAKE_DIR}/3rdparty/*.cmake")
file(GLOB _3rdparty_cmake_lists "${CEU_CMAKE_DIR}/3rdparty/*.cmake")

foreach(_cmake_file ${_3rdparty_cmake_lists})
    include(${_cmake_file})
endforeach(_cmake_file ${_3rdparty_cmake_lists})

# solve vcpkg
if(CEU_AUTO_SOLVE_VCPKG) # solve vcpkg automatically
    ceu_import_vcpkg()
endif()
