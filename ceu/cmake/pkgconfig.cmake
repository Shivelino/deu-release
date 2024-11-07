include("${CMAKE_CURRENT_LIST_DIR}/program.cmake")

# ######################################################################################################################
# Function: ceu_find_pkgconfig
#
# Description: Find pkgconfig package.
#
# Parameters:
#
# Example Usage: ceu_find_pkgconfig()
# ######################################################################################################################
macro(ceu_find_pkgconfig)
    set(options)
    set(oneValueArgs ARCH)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT DEFINED ARG_ARCH)
        set(ARG_ARCH "x64-windows")
    endif()

    ceu_find_program(CMD pkgconf HINTS "${CEU_VCPKG_ROOT_DIR}/packages/pkgconf_${ARG_ARCH}/tools/pkgconf" REQUIRED)
    set(PKG_CONFIG_EXECUTABLE ${CEU_EXECUTABLE_pkgconf})
    include(FindPkgConfig)
    find_package(PkgConfig REQUIRED)
endmacro(ceu_find_pkgconfig)

# ######################################################################################################################
# Function: ceu_import_pkgconfig
#
# Description: Import pkgconfig. package.
#
# Parameters:
#
# Example Usage: ceu_import_pkgconfig()
# ######################################################################################################################
macro(ceu_import_pkgconfig)
    ceu_find_pkgconfig(${ARGN})
endmacro(ceu_import_pkgconfig)

# ######################################################################################################################
# Function: ceu_find_library_pkgconfig
#
# Description: Find library(pkgconfig).
#
# Parameters:
#
# Example Usage: ceu_find_library_pkgconfig()
# ######################################################################################################################
macro(ceu_find_library_pkgconfig)
    set(options)
    set(oneValueArgs LIBRARY LIB_DIR)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    ceu_import_pkgconfig()

    set(ENV{PKG_CONFIG_PATH} "${ARG_LIB_DIR};$ENV{PKG_CONFIG_PATH}")
    pkg_check_modules(${ARG_LIBRARY} REQUIRED IMPORTED_TARGET ${ARG_LIBRARY})
endmacro(ceu_find_library_pkgconfig)
