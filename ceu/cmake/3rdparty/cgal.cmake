include("${CMAKE_CURRENT_LIST_DIR}/../include.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/gmp.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/mpfr.cmake")

# ######################################################################################################################
# Macro: ceu_find_cgal
#
# Description: Find cgal. If it could not be found automatically, please predefine `CGAL_DIR`.
#
# Parameters: COMPONENTS - components
#
# Example Usage: ceu_find_cgal()
# ######################################################################################################################
macro(ceu_find_cgal)
    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: cgal.")

    set(options FIND_HEADER_ONLY FIND_VCPKG) # todo: header-only and vcpkg are conflict
    set(oneValueArgs)
    set(multiValueArgs COMPONENTS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT ARG_FIND_HEADER_ONLY AND NOT ARG_FIND_VCPKG)
        message(FATAL_ERROR "Please configure the way to find: `FIND_HEADER_ONLY` or `FIND_VCPKG`")
    endif()

    if(ARG_FIND_HEADER_ONLY)
    # there is no more action to do
    elseif(ARG_FIND_VCPKG)
        if(NOT DEFINED CGAL_DIR)
            message(WARNING "Not predefine `CGAL_DIR`. If not found automatically, predefine `CGAL_DIR`.")
        endif()

        # find in system
        find_package(CGAL CONFIG REQUIRED COMPONENTS ${ARG_COMPONENTS})

        if(NOT ${CGAL_FOUND})
            message(FATAL_ERROR "cgal NOT found in system.")
        else()
            message(STATUS "Third party found: cgal.")
        endif()
    endif()

    # vars
    set(CEU_CGAL_HEADER_ONLY ${ARG_FIND_HEADER_ONLY})
    message(STATUS "=================================================================")
endmacro(ceu_find_cgal)

# ######################################################################################################################
# ######################################################################################################################
macro(ceu_import_cgal_deps)
    ceu_import_gmp()
    ceu_import_mpfr()
    ceu_import_boost()
endmacro(ceu_import_cgal_deps)

# ######################################################################################################################
# Macro: ceu_import_cgal
#
# Description: import cgal.
#
# Parameters: COMPONENTS - components
#
# Example Usage: ceu_import_cgal()
# ######################################################################################################################
macro(ceu_import_cgal)
    set(options WITH_DEPS)
    set(oneValueArgs)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(ARG_WITH_DEPS)
        ceu_import_cgal_deps() # import deps
    endif()

    ceu_find_cgal(${ARGN}) # find cgal
endmacro(ceu_import_cgal)

# ######################################################################################################################
# ######################################################################################################################
macro(ceu_target_link_cgal_deps)
    set(options)
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    ceu_target_link_gmp(TARGET ${ARG_TARGET} VISIBILITY ${ARG_VISIBILITY})
    ceu_target_link_mpfr(TARGET ${ARG_TARGET} VISIBILITY ${ARG_VISIBILITY})
    ceu_target_link_boost(TARGET ${ARG_TARGET} VISIBILITY ${ARG_VISIBILITY})
endmacro(ceu_target_link_cgal_deps)

# ######################################################################################################################
# Function: ceu_target_link_cgal
#
# Description: target link cgal library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library; COMPONENTS - components
#
# Example Usage: ceu_target_link_cgal(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_cgal)
    set(options WITH_DEPS) # only usable
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs COMPONENTS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # cgal, link only when not header-only
    if(CEU_CGAL_HEADER_ONLY)
        # ceu_target_include_header_only_3rdparty(TARGET ${ARG_TARGET} VISIBILITY ${ARG_VISIBILITY})
        message(WARNING "Do not use `ceu_target_link_cgal` when you use header-only CGAL, you should use `ceu_target_include_header_only_3rdparty` to include CGAL headers, then use `ceu_target_link_cgal_deps` to link deps")
    else()
        # target_include_directories(${ARG_TARGET} ${ARG_VISIBILITY} ${CEU_CGAL_INCLUDE_DIRS})
        target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} CGAL::CGAL)

        if(DEFINED ARG_COMPONENTS)
            foreach(comp ${ARG_COMPONENTS})
                target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} "CGAL::CGAL_${comp}")
            endforeach(comp ${ARG_COMPONENTS})
        endif()
    endif()

    # deps
    if(ARG_WITH_DEPS)
        ceu_target_link_cgal_deps(TARGET ${ARG_TARGET} VISIBILITY ${ARG_VISIBILITY})
    endif()
endfunction(ceu_target_link_cgal)
