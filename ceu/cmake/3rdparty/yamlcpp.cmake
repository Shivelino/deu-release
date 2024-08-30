# ######################################################################################################################
# Function: ceu_fetch_yamlcpp
#
# Description: Fetch yaml-cpp from github repo.
#
# Parameters: PREFIX - FetchContent_Declare PREFIX; GIT_TAG - FetchContent_Declare GIT_TAG
#
# Example Usage: ceu_fetch_yamlcpp(PREFIX "${CUSTOM_PATH}" GIT_TAG 0.8.0)
# ######################################################################################################################
function(ceu_fetch_yamlcpp)
    set(options)
    set(oneValueArgs PREFIX GIT_TAG)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    include(FetchContent)
    message(STATUS "Start FetchContent_Declare: yaml-cpp.")
    FetchContent_Declare(
        yamlcpp
        PREFIX ${ARG_PREFIX}
        GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
        GIT_TAG ${ARG_GIT_TAG})

    message(STATUS "Start FetchContent_MakeAvailable: yaml-cpp.")
    FetchContent_MakeAvailable(yamlcpp)
    message(STATUS "Fetch Over: yaml-cpp.")

    set(CEU_YAML_SOURCE_DIR
        ${yamlcpp_SOURCE_DIR}
        PARENT_SCOPE)
endfunction(ceu_fetch_yamlcpp)

# ######################################################################################################################
# Function: ceu_find_yamlcpp
#
# Description: Find yaml-cpp. If not found, fetch yaml-cpp 0.8.0.
#
# Parameters:
#
# Example Usage: ceu_find_yamlcpp()
# ######################################################################################################################
function(ceu_find_yamlcpp)
    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: yaml-cpp.")

    # find in system
    find_package(yaml-cpp CONFIG QUIET)

    if(NOT ${yaml-cpp_FOUND})
        message(WARNING "Yaml-cpp NOT found in system.")
        ceu_fetch_yamlcpp(PREFIX "${CMAKE_BINARY_DIR}/_deps/yamlcpp" GIT_TAG 0.8.0)
    else()
        message(STATUS "Third party found: yaml-cpp.")
    endif()

    message(STATUS "=================================================================")
endfunction(ceu_find_yamlcpp)

# ######################################################################################################################
# Macro: ceu_import_yamlcpp
#
# Description: import yamlcpp.
#
# Parameters:
#
# Example Usage: ceu_import_yamlcpp()
# ######################################################################################################################
macro(ceu_import_yamlcpp)
    ceu_find_yamlcpp()
endmacro(ceu_import_yamlcpp)

# ######################################################################################################################
# Function: ceu_target_link_yamlcpp
#
# Description: target link yaml-cpp static library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library
#
# Example Usage: ceu_target_link_yamlcpp(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_yamlcpp)
    set(options)
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(DEFINED ARG_VISIBILITY)
        target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} yaml-cpp::yaml-cpp)
    else()
        target_link_libraries(${ARG_TARGET} yaml-cpp::yaml-cpp)
    endif()
endfunction(ceu_target_link_yamlcpp)
