# ######################################################################################################################
# Function: ceu_find_tbb
#
# Description: Find tbb. If it could not be found automatically, please predefine `TBB_DIR`.
#
# Parameters:
#
# Example Usage: ceu_find_tbb()
# ######################################################################################################################
function(ceu_find_tbb)
    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: tbb.")

    if(NOT DEFINED TBB_DIR)
        message(WARNING "Not predefine `TBB_DIR`. If not found automatically, predefine `TBB_DIR`.")
    endif()

    # find in system
    find_package(TBB CONFIG REQUIRED)

    if(NOT ${tbb_FOUND})
        message(WARNING "TBB NOT found in system.")

        # Options
        set(TBB_TEST OFF)

        # fetch will get an target_link error. TODO: fix target_link error

        # Fetch include(FetchContent)

        # message(STATUS "Start FetchContent_Declare: tbb.")

        # FetchContent_Declare(tbb PREFIX "${CMAKE_BINARY_DIR}/_deps/tbb" GIT_REPOSITORY
        # https://github.com/oneapi-src/oneTBB.git GIT_TAG v2021.11.0)

        # message(STATUS "Start FetchContent_MakeAvailable: tbb.")

        # FetchContent_MakeAvailable(tbb)

        # message(STATUS "Fetch Over: tbb.")
    else()
        message(STATUS "Third party found: tbb.")
    endif()

    message(STATUS "=================================================================")
endfunction(ceu_find_tbb)

# ######################################################################################################################
# Macro: ceu_import_tbb
#
# Description: import tbb.
#
# Parameters:
#
# Example Usage: ceu_import_tbb()
# ######################################################################################################################
macro(ceu_import_tbb)
    ceu_find_tbb()
endmacro(ceu_import_tbb)

# ######################################################################################################################
# Function: ceu_target_link_tbb
#
# Description: target link tbb library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library; DYNAMIC - link as dynamic;
# DLL_DEST_DIR - dest dir that dll file is moved to
#
# Example Usage: ceu_target_link_tbb(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_tbb)
    set(options DYNAMIC)
    set(oneValueArgs TARGET VISIBILITY DLL_DEST_DIR)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(DEFINED ARG_VISIBILITY)
        target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} TBB::tbb)
    else()
        target_link_libraries(${ARG_TARGET} TBB::tbb)
    endif()

    if(ARG_DYNAMIC AND ARG_DLL_DEST_DIR)
        get_target_property(TBB_LIBRARY_DIR_DEB TBB::tbb IMPORTED_LOCATION_DEBUG)
        get_target_property(TBB_LIBRARY_DIR_REL TBB::tbb IMPORTED_LOCATION_RELEASE)
        set(TBB_DLL_FILE "$<$<CONFIG:Debug>:${TBB_LIBRARY_DIR_DEB}>$<$<NOT:$<CONFIG:Debug>>:${TBB_LIBRARY_DIR_REL}>")
        add_custom_command(
            TARGET ${ARG_TARGET}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${TBB_DLL_FILE} ${ARG_DLL_DEST_DIR})
    endif()
endfunction(ceu_target_link_tbb)
