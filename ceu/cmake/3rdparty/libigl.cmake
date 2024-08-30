include("${CMAKE_CURRENT_LIST_DIR}/libigl_glad.cmake")

# ######################################################################################################################
# Function: ceu_fetch_libigl
#
# Description: Fetch libigl from github repo.
#
# Parameters: PREFIX - FetchContent_Declare PREFIX; GIT_TAG - FetchContent_Declare GIT_TAG
#
# Example Usage: ceu_fetch_libigl(PREFIX "${CUSTOM_PATH}" GIT_TAG v2.5.0)
# ######################################################################################################################
function(ceu_fetch_libigl)
    set(options)
    set(oneValueArgs PREFIX GIT_TAG)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(TARGET igl::core)
        return()
    endif()

    include(FetchContent)
    message(STATUS "Start FetchContent_Declare: libigl.")
    FetchContent_Declare(
        libigl
        PREFIX ${ARG_PREFIX}
        GIT_REPOSITORY https://github.com/libigl/libigl.git
        GIT_TAG ${ARG_GIT_TAG}) # OVERRIDE_FIND_PACKAGE
    message(STATUS "Start FetchContent_MakeAvailable: libigl.")
    FetchContent_MakeAvailable(libigl)
    message(STATUS "Fetch Over: libigl.")
endfunction(ceu_fetch_libigl)

# ######################################################################################################################
# Function: ceu_find_libigl
#
# Description: Find libigl. If not found, fetch libigl ead2d21fd1d9f566d8f9a9ce99ddf85829258c7a.
#
# Parameters:
#
# Example Usage: ceu_find_libigl()
# ######################################################################################################################
macro(ceu_find_libigl)
    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: libigl.")

    # find in system
    find_package(libigl CONFIG QUIET) # TODO: Always failed, because libigl is not popular

    if(NOT ${libigl_FOUND})
        message(WARNING "Libigl NOT found in system.")
        ceu_fetch_libigl(PREFIX "${CMAKE_BINARY_DIR}/_deps/libigl" GIT_TAG v2.5.0)
    else()
        message(STATUS "Third party found: libigl.")
    endif()

    message(STATUS "=================================================================")
endmacro(ceu_find_libigl)

# ######################################################################################################################
# ######################################################################################################################
macro(ceu_import_libigl_deps)
    ceu_import_libigl()
endmacro(ceu_import_libigl_deps)

# ######################################################################################################################
# Macro: ceu_import_libigl
#
# Description: import libigl.
#
# Parameters: WITH_DEPS - import libigl deps
#
# Example Usage: ceu_import_libigl()
# ######################################################################################################################
macro(ceu_import_libigl)
    set(options WITH_DEPS)
    set(oneValueArgs)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(ARG_WITH_DEPS)
        ceu_import_libigl_deps() # import deps
    endif()

    ceu_find_libigl(${ARGN}) # find libigl
endmacro(ceu_import_libigl)

# ######################################################################################################################
# Function: ceu_target_link_libigl_deps
#
# Description: target link libigl deps library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library
#
# Example Usage: ceu_target_link_libigl_deps(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_libigl_deps)
    set(options)
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    ceu_target_link_libigl_glab(TARGET ${ARG_TARGET} VISIBILITY ${ARG_VISIBILITY})
endfunction(ceu_target_link_libigl_deps)

# ######################################################################################################################
# Function: ceu_target_link_libigl
#
# Description: target link libigl library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library; COMPONENTS - components
#
# Example Usage: ceu_target_link_libigl(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_libigl)
    set(options WITH_DEPS) # only usable
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs COMPONENTS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT DEFINED ARG_COMPONENTS)
        set(ARG_COMPONENTS "glfw")
    endif()

    # all components.
    # igl::glfw, igl::embree, igl::imgui, igl::opengl, igl::stb, igl::predicates, igl::xml, igl_copyleft::cgal, igl_copyleft::comiso, igl_copyleft::core, igl_copyleft::cork, igl_copyleft::tetgen, igl_restricted::matlab, igl_restricted::mosek, igl_restricted::triangle
    foreach(comp ${ARG_COMPONENTS})
        igl_include(${comp})
        target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} "igl::${comp}")
    endforeach(comp ${ARG_COMPONENTS})

    # deps
    if(ARG_WITH_DEPS)
        ceu_target_link_libigl_deps(TARGET ${ARG_TARGET} VISIBILITY ${ARG_VISIBILITY})
    endif()
endfunction(ceu_target_link_libigl)
