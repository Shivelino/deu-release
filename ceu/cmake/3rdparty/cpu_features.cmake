# ######################################################################################################################
# Function: ceu_fetch_cpu_features
#
# Description: Fetch cpu_features from github repo.
#
# Parameters: PREFIX - FetchContent_Declare PREFIX; GIT_TAG - FetchContent_Declare GIT_TAG
#
# Example Usage: ceu_fetch_cpu_features(PREFIX "${CUSTOM_PATH}" GIT_TAG v1.14.0)
# ######################################################################################################################
function(ceu_fetch_cpu_features)
    set(options)
    set(oneValueArgs PREFIX GIT_TAG)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Options
    set(ENABLE_INSTALL OFF)
    set(BUILD_EXECUTABLE OFF)

    include(FetchContent)
    message(STATUS "Start FetchContent_Declare: cpu_features.")
    FetchContent_Declare(
        cpu_features
        PREFIX ${ARG_PREFIX}
        GIT_REPOSITORY https://github.com/google/cpu_features.git
        GIT_TAG ${ARG_GIT_TAG}) # OVERRIDE_FIND_PACKAGE
    message(STATUS "Start FetchContent_MakeAvailable: cpu_features.")
    FetchContent_MakeAvailable(cpu_features)
    message(STATUS "Fetch Over: cpu_features.")
endfunction(ceu_fetch_cpu_features)

# ######################################################################################################################
# Function: ceu_find_cpu_features
#
# Description: Find cpu_features. If not found, fetch cpu_features v0.9.0.
#
# Parameters:
#
# Example Usage: ceu_find_cpu_features()
# ######################################################################################################################
function(ceu_find_cpu_features)
    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: cpu_features.")

    # find in system
    find_package(cpu_features CONFIG QUIET)

    if(NOT ${cpu_features_FOUND})
        message(WARNING "Cpu_features NOT found in system.")
        ceu_fetch_cpu_features(PREFIX "${CMAKE_BINARY_DIR}/_deps/cpu_features" GIT_TAG v0.9.0)
        add_library(cpu_features::cpu_features ALIAS cpu_features)
    else()
        message(STATUS "Third party found: cpu_features.")
        add_library(cpu_features::cpu_features ALIAS cpu_features)
    endif()

    message(STATUS "=================================================================")
endfunction(ceu_find_cpu_features)

# ######################################################################################################################
# Macro: ceu_import_cpu_features
#
# Description: import cpu_features
#
# Parameters:
#
# Example Usage: ceu_import_cpu_features()
# ######################################################################################################################
macro(ceu_import_cpu_features)
    ceu_find_cpu_features()
endmacro(ceu_import_cpu_features)

# ######################################################################################################################
# Function: ceu_target_link_cpu_features
#
# Description: target link cpu_features library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library
#
# Example Usage: ceu_target_link_cpu_features(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_cpu_features)
    set(options)
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(DEFINED ARG_VISIBILITY)
        target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} cpu_features::cpu_features)
    else()
        target_link_libraries(${ARG_TARGET} cpu_features::cpu_features)
    endif()
endfunction(ceu_target_link_cpu_features)
