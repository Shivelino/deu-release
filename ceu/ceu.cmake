cmake_minimum_required(VERSION 3.27)

set(CEU_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
set(CEU_3RDPARTY_DIR "${CMAKE_CURRENT_LIST_DIR}/3rdparty")
set(CEU_SCRIPTS_DIR "${CMAKE_CURRENT_LIST_DIR}/scripts")
set(CEU_CMAKE_DIR "${CMAKE_CURRENT_LIST_DIR}/cmake")
set(CEU_DOWNLOAD_DIR "${CMAKE_CURRENT_LIST_DIR}/download")

include("${CEU_CMAKE_DIR}/include.cmake")
include("${CEU_CMAKE_DIR}/target.cmake")
include("${CEU_CMAKE_DIR}/CPM.cmake")

# file(GLOB_RECURSE _3rdparty_cmake_lists "${CEU_CMAKE_DIR}/3rdparty/*.cmake")
file(GLOB _3rdparty_cmake_lists "${CEU_CMAKE_DIR}/3rdparty/*.cmake")

foreach(_cmake_file ${_3rdparty_cmake_lists})
    include(${_cmake_file})
endforeach(_cmake_file ${_3rdparty_cmake_lists})
