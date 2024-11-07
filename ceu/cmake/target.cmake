# ######################################################################################################################
# Function: ceu_print_target_property
#
# Description: print property of a target
#
# Parameters: TARGET - target
#
# Example Usage: ceu_print_target_property(TARGET my_target)
# ######################################################################################################################
function(ceu_print_target_property)
    message(STATUS "#################################################################")

    set(options)
    set(oneValueArgs TARGET)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(PROPERTIES_LIST
        LOCATION
        TYPE
        SOURCES
        INCLUDE_DIRECTORIES
        LINK_DIRECTORIES
        LINK_LIBRARIES
        LINK_FLAGS
        COMPILE_DEFINITIONS
        COMPILE_OPTIONS
        COMPILE_FEATURES
        INTERFACE_INCLUDE_DIRECTORIES
        INTERFACE_LINK_DIRECTORIES
        INTERFACE_LINK_LIBRARIES)

    message(STATUS "${ARG_TARGET} all properties:")

    foreach(prop ${PROPERTIES_LIST})
        get_target_property(TMP_PROPERTY_VALUE ${ARG_TARGET} ${prop})
        message(STATUS "${prop}: ${TMP_PROPERTY_VALUE}")
    endforeach()

    message(STATUS "#################################################################")
endfunction(ceu_print_target_property)
