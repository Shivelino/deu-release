# ######################################################################################################################
# Function: ceu_fetch_libigl_glad
#
# Description: Fetch libigl-glad from github repo.
#
# Parameters: PREFIX - FetchContent_Declare PREFIX; GIT_TAG - FetchContent_Declare GIT_TAG
#
# Example Usage: ceu_fetch_libigl_glad(PREFIX "${CUSTOM_PATH}" GIT_TAG ead2d21fd1d9f566d8f9a9ce99ddf85829258c7a)
# ######################################################################################################################
function(ceu_fetch_libigl_glad)
    set(options)
    set(oneValueArgs PREFIX GIT_TAG)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(TARGET libigl_glad::libigl_glad)
        return()
    endif()

    include(FetchContent)
    message(STATUS "Start FetchContent_Declare: libigl-glad.")
    FetchContent_Declare(
        glad
        PREFIX ${ARG_PREFIX}
        GIT_REPOSITORY https://github.com/libigl/libigl-glad.git
        GIT_TAG ${ARG_GIT_TAG}) # OVERRIDE_FIND_PACKAGE
    message(STATUS "Start FetchContent_MakeAvailable: libigl-glad.")
    FetchContent_MakeAvailable(glad)
    message(STATUS "Fetch Over: libigl-glad.")

    add_library(glad::glad ALIAS glad)
    add_library(libigl_glad::glad ALIAS glad)
    add_library(libigl_glad::libigl_glad ALIAS glad)
endfunction(ceu_fetch_libigl_glad)

# ######################################################################################################################
# Function: ceu_find_libigl_glad
#
# Description: Find libigl-glad. If not found, fetch libigl-glad ead2d21fd1d9f566d8f9a9ce99ddf85829258c7a.
#
# Parameters:
#
# Example Usage: ceu_find_libigl_glad()
# ######################################################################################################################
macro(ceu_find_libigl_glad)
    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: libigl-glad.")

    # find in system
    find_package(libigl_glad CONFIG QUIET) # TODO: Always failed, because libigl-glad is a custom library of libigl

    if(NOT ${libigl_glad_FOUND})
        message(WARNING "Libigl_glad NOT found in system.")
        ceu_fetch_libigl_glad(PREFIX "${CMAKE_BINARY_DIR}/_deps/libigl_glad" GIT_TAG
                              ead2d21fd1d9f566d8f9a9ce99ddf85829258c7a)
    else()
        message(STATUS "Third party found: libigl-glad.")
    endif()

    message(STATUS "=================================================================")
endmacro(ceu_find_libigl_glad)

# ######################################################################################################################
# Macro: ceu_import_libigl_glad
#
# Description: import libigl-glad
#
# Parameters:
#
# Example Usage: ceu_import_libigl_glad()
# ######################################################################################################################
macro(ceu_import_libigl_glad)
    ceu_find_libigl_glad()

    add_definitions(-DCEU_3RDPARTY_IMPORTED_LIBIGL_GLAD)
endmacro(ceu_import_libigl_glad)

# ######################################################################################################################
# Function: ceu_target_link_libigl_glab
#
# Description: target link libigl-glab static library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library
#
# Example Usage: ceu_target_link_libigl_glab(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_libigl_glab)
    set(options)
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} libigl_glad::libigl_glad)
endfunction(ceu_target_link_libigl_glab)
