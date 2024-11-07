include("${CMAKE_CURRENT_LIST_DIR}/../vcpkg/vcpkg.cmake")

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
    if(NOT TARGET TBB::tbb)
        message(STATUS "=================================================================")
        message(STATUS "Start finding third party: tbb.")

        set(options FIND_WITH_VCPKG)
        set(oneValueArgs VCPKG_ARCH)
        set(multiValueArgs)
        cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

        if(DEFINED ARG_FIND_WITH_VCPKG) # find in vcpkg
            ceu_find_library_vcpkg(LIBRARY TBB ARCH ${ARG_VCPKG_ARCH})
        else() # find in system
            find_package(TBB CONFIG REQUIRED)

            if(NOT ${tbb_FOUND})
                message(WARNING "TBB NOT found in system.")
            else()
                message(STATUS "Third party found: tbb.")
            endif()
        endif()

        message(STATUS "=================================================================")
    endif()
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
    ceu_find_tbb(${ARGN})

    add_definitions(-DCEU_3RDPARTY_IMPORTED_TBB)
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
