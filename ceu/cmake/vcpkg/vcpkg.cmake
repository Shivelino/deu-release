include("${CMAKE_CURRENT_LIST_DIR}/../program.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../pkgconfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../config.cmake")

# ######################################################################################################################
# Function: ceu_download_vcpkg
#
# Description: Download vcpkg from github
#
# Parameters: DL_DIR - download dir; VERSION - verison/tag/branch
#
# Example Usage: ceu_download_vcpkg(DL_DIR your_path VERSION 2024.08.23)
# ######################################################################################################################
function(ceu_download_vcpkg)
    set(options)
    set(oneValueArgs DL_DIR VERSION)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT EXISTS "${ARG_DL_DIR}/${ARG_VERSION}")
        message(STATUS "Not downloaded, start downloading vcpkg.")

        execute_process(
            COMMAND git clone -b ${ARG_VERSION} https://github.com/microsoft/vcpkg.git "${ARG_DL_DIR}/${ARG_VERSION}"
            --depth 1
            WORKING_DIRECTORY ${CEU_DOWNLOAD_DIR}
            RESULT_VARIABLE _result) # if success, _result == 0

        if(NOT ${_result} EQUAL 0)
            message(FATAL_ERROR "Download package error")
        endif()

        execute_process(
            COMMAND bootstrap-vcpkg.bat
            WORKING_DIRECTORY "${ARG_DL_DIR}/${ARG_VERSION}"
            RESULT_VARIABLE _result) # if success, _result == 0

        message(STATUS "vcpkg download successfully.")
    endif()
endfunction(ceu_download_vcpkg)

# ######################################################################################################################
# Macro: ceu_find_vcpkg
#
# Description: Find vcpkg
#
# Parameters: AUTO_DOWNLOAD - enable auto download
#
# Example Usage: ceu_find_vcpkg(AUTO_DOWNLOAD)
# ######################################################################################################################
macro(ceu_find_vcpkg)
    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: vcpkg.")

    set(options AUTO_DOWNLOAD REQUIRED)
    set(oneValueArgs)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    ceu_program_exist(CMD vcpkg)

    set(CEU_VCPKG_ROOT_DIR)

    if(CEU_PROGRAM_EXIST)
        ceu_program_locate(CMD vcpkg)
        set(CEU_VCPKG_ROOT_DIR ${CEU_EXECUTABLE_DIR_PATH_vcpkg})
    else()
        message(WARNING "`vcpkg` not exist. If option `AUTO_DOWNLOAD` is on, download will start")

        if(ARG_AUTO_DOWNLOAD)
            set(DOWNLOAD_VERSION 2024.08.23)
            set(DOWNLOAD_DIR "${CEU_DOWNLOAD_DIR}/vcpkg")
            ceu_download_vcpkg(DL_DIR ${DOWNLOAD_DIR} VERSION ${DOWNLOAD_VERSION})

            ceu_program_locate(CMD vcpkg HINTS "${DOWNLOAD_DIR}/${DOWNLOAD_VERSION}")
            set(CEU_VCPKG_ROOT_DIR ${CEU_EXECUTABLE_DIR_PATH_vcpkg})
        endif()
    endif()

    set(CMAKE_TOOLCHAIN_FILE
        "${CEU_VCPKG_ROOT_DIR}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "")

    message(WARNING "Attention: If import vcpkg, then find_package will find library in vcpkg first, if you want to find system or custom library, please pre-set `<library>_DIR` as cache.")

    message(STATUS "=================================================================")
endmacro(ceu_find_vcpkg)

# ######################################################################################################################
# Macro: ceu_enable_vcpkg
#
# Description: Enable vcpkg
#
# Parameters: AUTO_DOWNLOAD - enable auto download
#
# Example Usage: ceu_enable_vcpkg(AUTO_DOWNLOAD)
# ######################################################################################################################
macro(ceu_import_vcpkg)
    ceu_find_vcpkg(${ARGN})
endmacro(ceu_import_vcpkg)

# ######################################################################################################################
# Macro: ceu_vcpkg_install_library
#
# Description: Install vcpkg library.
#
# Parameters: LIBRARY - library; ARCH - architecture
#
# Example Usage: ceu_vcpkg_install_library(LIBRARY TBB ARCH "x64-windows")
# ######################################################################################################################
function(ceu_vcpkg_install_library)
    set(options LIBRARY)
    set(oneValueArgs ARCH)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT DEFINED ARG_LIBRARY OR NOT DEFINED ARG_ARCH)
        message(FATAL_ERROR "missing param: `ARG_LIBRARY` or `ARCH`")
    endif()

    execute_process(
        COMMAND ${CEU_EXECUTABLE_vcpkg} install "${ARG_LIBRARY}:${ARG_ARCH}"
        WORKING_DIRECTORY ${CEU_DOWNLOAD_DIR}
        RESULT_VARIABLE _result)

    if(NOT ${_result} EQUAL 0)
        message(FATAL_ERROR "ceu_vcpkg_install_library run error")
    endif()
endfunction(ceu_vcpkg_install_library)

# ######################################################################################################################
# Macro: ceu_enable_vcpkg_pkgconfig
#
# Description: Enable pkgconfig in vcpkg, by installing vcpkg library `pkgconf`.
#
# Parameters: ARCH - architecture
#
# Example Usage: ceu_enable_vcpkg_pkgconfig(ARCH "x64-windows")
# ######################################################################################################################
function(ceu_enable_vcpkg_pkgconfig)
    set(options)
    set(oneValueArgs ARCH)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    ceu_vcpkg_install_library(LIBRARY "pkgconf" ARCH ${ARG_ARCH})
endfunction(ceu_enable_vcpkg_pkgconfig)

# ######################################################################################################################
# Macro: ceu_find_library_vcpkg
#
# Description: Find library in vcpkg.
#
# TODO: delete, after set vcpkg as CMAKE_TOOL_CHAIN_FILE, this function is useless mostly
#
# Parameters: LIBRARY - library; ARCH - architecture
#
# Example Usage: ceu_find_library_vcpkg(LIBRARY CGAL ARCH "x64-windows")
# ######################################################################################################################
macro(ceu_find_library_vcpkg)
    set(options)
    set(oneValueArgs LIBRARY ARCH)
    set(multiValueArgs COMPONENTS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # import vcpkg and pkgconfig
    # ceu_import_vcpkg()
    ceu_import_pkgconfig()

    string(TOLOWER ${ARG_LIBRARY} ARG_LIBRARY_LOWER)
    string(TOUPPER ${ARG_LIBRARY} ARG_LIBRARY_UPPER)

    set(CEU_VCKPG_FOUND_${ARG_LIBRARY} FALSE)
    set(CEU_VCKPG_DIR_${ARG_LIBRARY})
    set(CEU_VCKPG_MODE_${ARG_LIBRARY})

    if(IS_DIRECTORY "${CEU_VCPKG_ROOT_DIR}/packages/${ARG_LIBRARY}_${ARG_ARCH}")
        set(CEU_VCKPG_FOUND_${ARG_LIBRARY} TRUE)
        set(CEU_VCKPG_DIR_${ARG_LIBRARY} "${CEU_VCPKG_ROOT_DIR}/packages/${ARG_LIBRARY}_${ARG_ARCH}")

        # config
        ceu_find_library_config(
            LIBRARY ${ARG_LIBRARY} LIB_DIR
            "${CEU_VCPKG_ROOT_DIR}/packages/${ARG_LIBRARY_LOWER}_${ARG_ARCH}/share/${ARG_LIBRARY_LOWER}" COMPONENTS ${ARG_COMPONENTS})

        if(NOT ${ARG_LIBRARY}_FOUND)
            message(WARNING "${ARG_LIBRARY} not found by config.cmake")

            # pkgconfig
            ceu_find_library_pkgconfig(LIBRARY ${ARG_LIBRARY} LIB_DIR
                "${CEU_VCPKG_ROOT_DIR}/packages/${ARG_LIBRARY_LOWER}_${ARG_ARCH}/lib/pkgconfig")
        endif()
    else()
        message(WARNING "ceu_vcpkg_find_library: ${ARG_LIBRARY}:${ARG_ARCH} not found")
    endif()
endmacro(ceu_find_library_vcpkg)
