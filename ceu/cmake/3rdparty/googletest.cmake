# ######################################################################################################################
# Function: ceu_fetch_googletest
#
# Description: Fetch googletest from github repo.
#
# Parameters: PREFIX - FetchContent_Declare PREFIX; GIT_TAG - FetchContent_Declare GIT_TAG
#
# Example Usage: ceu_fetch_googletest(PREFIX "${CUSTOM_PATH}" GIT_TAG v1.14.0)
# ######################################################################################################################
function(ceu_fetch_googletest)
    set(options)
    set(oneValueArgs PREFIX GIT_TAG)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Options
    set(INSTALL_GTEST OFF)

    include(FetchContent)
    message(STATUS "Start FetchContent_Declare: gtest.")
    FetchContent_Declare(
        googletest
        PREFIX ${ARG_PREFIX}
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG ${ARG_GIT_TAG}) # OVERRIDE_FIND_PACKAGE
    message(STATUS "Start FetchContent_MakeAvailable: gtest.")
    FetchContent_MakeAvailable(googletest)
    message(STATUS "Fetch Over: gtest.")
endfunction(ceu_fetch_googletest)

# ######################################################################################################################
# Function: ceu_find_googletest
#
# Description: Find google test. If not found, fetch google test v1.14.0.
#
# Parameters:
#
# Example Usage: ceu_find_googletest()
# ######################################################################################################################
function(ceu_find_googletest)
    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: gtest.")

    # find in system
    find_package(gtest CONFIG QUIET)

    if(NOT ${gtest_FOUND})
        message(WARNING "Gtest NOT found in system.")
        ceu_fetch_googletest(PREFIX "${CMAKE_BINARY_DIR}/_deps/gtest" GIT_TAG v1.14.0)
        add_library(gtest::gtest ALIAS gtest)
        add_library(gtest::gtest_main ALIAS gtest_main)
    else()
        message(STATUS "Third party found: gtest.")
        add_library(gtest::gtest ALIAS GTest::gtest)
        add_library(gtest::gtest_main ALIAS GTest::gtest_main)
    endif()

    message(STATUS "=================================================================")
endfunction(ceu_find_googletest)

# ######################################################################################################################
# Macro: ceu_import_googletest
#
# Description: import googletest.
#
# Parameters:
#
# Example Usage: ceu_import_googletest()
# ######################################################################################################################
macro(ceu_import_googletest)
    ceu_find_googletest()
endmacro(ceu_import_googletest)

# ######################################################################################################################
# Function: ceu_target_link_gtest
#
# Description: target link gtest static library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library
#
# Example Usage: ceu_target_link_gtest(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_gtest)
    set(options)
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(DEFINED ARG_VISIBILITY)
        target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} gtest::gtest gtest::gtest_main)
    else()
        target_link_libraries(${ARG_TARGET} gtest::gtest gtest::gtest_main)
    endif()
endfunction(ceu_target_link_gtest)

# ######################################################################################################################
# Macro: ceu_find_gtest
#
# Description: alias of ceu_find_googletest.
#
# Parameters:
#
# Example Usage: ceu_find_gtest()
# ######################################################################################################################
macro(ceu_find_gtest)
    ceu_find_googletest()
endmacro(ceu_find_gtest)

# ######################################################################################################################
# Macro: ceu_import_gtest
#
# Description: alias of ceu_import_googletest.
#
# Parameters:
#
# Example Usage: ceu_import_gtest()
# ######################################################################################################################
macro(ceu_import_gtest)
    ceu_import_googletest()
endmacro(ceu_import_gtest)
