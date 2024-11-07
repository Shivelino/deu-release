# ######################################################################################################################
# Macro: ceu_find_boost
#
# Description: Find boost. Please predefine `BOOST_ROOT` path.
#
# Parameters: MIN_VERSION - min version of boost; COMPONENTS - components of boost
#
# Example Usage: ceu_find_boost("1.84.0")
# ######################################################################################################################
macro(ceu_find_boost)
    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: boost.")

    set(options)
    set(oneValueArgs MIN_VERSION)
    set(multiValueArgs COMPONENTS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # find in system
    find_package(Boost ${ARG_MIN_VERSION} REQUIRED COMPONENTS ${ARG_COMPONENTS})

    if(NOT Boost_FOUND)
        if(NOT DEFINED Boost_DIR)
            message(WARNING "Not found automatically, not predefiend `Boost_DIR`")
        else()
            message(WARNING "Not found automatically, predefiend `Boost_DIR`, probably wrong path")
        endif()
    endif()

    message(STATUS "=================================================================")
endmacro(ceu_find_boost)

# ######################################################################################################################
# Macro: ceu_import_boost
#
# Description: Import boost by find and pre-set directory. Please predefine `BOOST_ROOT` path.
#
# Parameters: MIN_VERSION - min version of boost; COMPONENTS - components of boost
#
# Example Usage: ceu_import_boost("1.84.0")
# ######################################################################################################################
macro(ceu_import_boost)
    set(options)
    set(oneValueArgs MIN_VERSION)
    set(multiValueArgs COMPONENTS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    ceu_find_boost(MIN_VERSION ${ARG_MIN_VERSION} COMPONENTS ${ARG_COMPONENTS}) # find boost

    set(CEU_BOOST_LIB_DIR "${BOOST_ROOT}/stage/lib")
    
    add_definitions(-DCEU_3RDPARTY_IMPORTED_BOOST)
endmacro(ceu_import_boost)

# ######################################################################################################################
# Function: ceu_target_link_boost
#
# Description: target link boost library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library
#
# Example Usage: ceu_target_link_boost(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_boost)
    if(NOT DEFINED CEU_BOOST_LIB_DIR)
        message(FATAL_ERROR "Please find boost first before target link.")
    endif()

    set(options)
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(DEFINED ARG_VISIBILITY)
        target_link_directories(${ARG_TARGET} ${ARG_VISIBILITY} ${CEU_BOOST_LIB_DIR})
        target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} Boost::boost)
    else()
        target_link_directories(${ARG_TARGET} PUBLIC ${CEU_BOOST_LIB_DIR})
        target_link_libraries(${ARG_TARGET} Boost::boost)
    endif()
endfunction(ceu_target_link_boost)
