# ######################################################################################################################
# Function: ceu_fetch_fmt
#
# Description: Fetch fmt from github repo.
#
# Parameters: PREFIX - FetchContent_Declare PREFIX; GIT_TAG - FetchContent_Declare GIT_TAG
#
# Example Usage: ceu_fetch_fmt(PREFIX "${CUSTOM_PATH}" GIT_TAG 10.1.1)
# ######################################################################################################################
function(ceu_fetch_fmt)
    set(options)
    set(oneValueArgs PREFIX GIT_TAG)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    include(FetchContent)
    message(STATUS "Start FetchContent_Declare: fmt.")
    FetchContent_Declare(
        fmt
        PREFIX ${ARG_PREFIX}
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG ${ARG_GIT_TAG})
    message(STATUS "Start FetchContent_MakeAvailable: fmt.")
    FetchContent_MakeAvailable(fmt)
    message(STATUS "Fetch Over: fmt.")
endfunction(ceu_fetch_fmt)

# ######################################################################################################################
# Function: ceu_find_fmt
#
# Description: Find fmt. If not found, fetch fmt 10.1.1.
#
# Parameters: HEADER_ONLY - find fmt as header-only mode, the headers are in `${CEU_3RDPARTY_DIR}/fmt`
#
# Example Usage: ceu_find_fmt(HEADER_ONLY)
# ######################################################################################################################
function(ceu_find_fmt)
    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: fmt.")

    set(options HEADER_ONLY)
    set(oneValueArgs)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(ARG_HEADER_ONLY)
        message(STATUS "Use fmt as header-only mode.")
        add_definitions(-DFMT_HEADER_ONLY)
        message(STATUS "=================================================================")
        return()
    endif()

    find_package(FMT CONFIG QUIET)

    if(NOT ${FMT_FOUND})
        message(WARNING "FMT NOT found in system.")
        ceu_fetch_fmt(PREFIX "${CMAKE_BINARY_DIR}/_deps/fmt" GIT_TAG 10.1.1)
    else()
        message(STATUS "Third party found: fmt.")
    endif()

    message(STATUS "=================================================================")
endfunction(ceu_find_fmt)

# ######################################################################################################################
# Macro: ceu_import_fmt
#
# Description: import fmt
#
# Parameters: HEADER_ONLY - find fmt as header-only mode, the headers are in `${CEU_3RDPARTY_DIR}/fmt`
#
# Example Usage: ceu_import_fmt()
# ######################################################################################################################
macro(ceu_import_fmt)
    set(options HEADER_ONLY)
    set(oneValueArgs)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    ceu_find_fmt(${ARG_HEADER_ONLY})
endmacro(ceu_import_fmt)

# ######################################################################################################################
# Function: ceu_target_link_fmt
#
# Description: target link fmt static library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library
#
# Example Usage: ceu_target_link_fmt(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_fmt)
    set(options)
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(DEFINED ARG_VISIBILITY)
        target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} fmt::fmt)
    else()
        target_link_libraries(${ARG_TARGET} fmt::fmt)
    endif()
endfunction(ceu_target_link_fmt)
