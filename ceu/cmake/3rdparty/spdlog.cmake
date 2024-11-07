# ######################################################################################################################
# Function: ceu_fetch_spdlog
#
# Description: Fetch spdlog from github repo.
#
# Parameters: PREFIX - FetchContent_Declare PREFIX; GIT_TAG - FetchContent_Declare GIT_TAG
#
# Example Usage: ceu_fetch_spdlog(PREFIX "${CUSTOM_PATH}" GIT_TAG v1.12.0)
# ######################################################################################################################
function(ceu_fetch_spdlog)
    set(options)
    set(oneValueArgs PREFIX GIT_TAG)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    include(FetchContent)
    message(STATUS "Start FetchContent_Declare: spdlog.")
    FetchContent_Declare(
        spdlog
        PREFIX ${ARG_PREFIX}
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG ${ARG_GIT_TAG})
    message(STATUS "Start FetchContent_MakeAvailable: spdlog.")
    FetchContent_MakeAvailable(spdlog)
    message(STATUS "Fetch Over: spdlog.")
endfunction(ceu_fetch_spdlog)

# ######################################################################################################################
# Function: ceu_find_spdlog
#
# Description: Find spdlog. If not found, fetch spdlog 10.1.1.
#
# Parameters: HEADER_ONLY - find spdlog as header-only mode, the headers are in `${CEU_3RDPARTY_DIR}/spdlog`
#
# Example Usage: ceu_find_spdlog(HEADER_ONLY)
# ######################################################################################################################
function(ceu_find_spdlog)
    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: spdlog.")

    set(options HEADER_ONLY)
    set(oneValueArgs)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(ARG_HEADER_ONLY)
        message(STATUS "Use spdlog as header-only mode.")
        message(STATUS "=================================================================")
        return()
    endif()

    find_package(spdlog CONFIG QUIET)

    if(NOT ${spdlog_FOUND})
        message(WARNING "spdlog NOT found in system.")
        ceu_fetch_spdlog(PREFIX "${CMAKE_BINARY_DIR}/_deps/spdlog" GIT_TAG v1.12.0)
    else()
        message(STATUS "Third party found: spdlog.")
    endif()

    message(STATUS "=================================================================")
endfunction(ceu_find_spdlog)

# ######################################################################################################################
# Macro: ceu_import_spdlog
#
# Description: import spdlog
#
# Parameters: HEADER_ONLY - find spdlog as header-only mode, the headers are in `${CEU_3RDPARTY_DIR}/spdlog`
#
# Example Usage: ceu_import_spdlog()
# ######################################################################################################################
macro(ceu_import_spdlog)
    set(options HEADER_ONLY)
    set(oneValueArgs)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    ceu_find_spdlog(${ARG_HEADER_ONLY})

    add_definitions(-DCEU_3RDPARTY_IMPORTED_SPDLOG)
endmacro(ceu_import_spdlog)

# ######################################################################################################################
# Function: ceu_target_link_spdlog
#
# Description: target link spdlog static library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library
#
# Example Usage: ceu_target_link_spdlog(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_spdlog)
    set(options)
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(DEFINED ARG_VISIBILITY)
        target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} spdlog::spdlog)
    else()
        target_link_libraries(${ARG_TARGET} spdlog::spdlog)
    endif()
endfunction(ceu_target_link_spdlog)
