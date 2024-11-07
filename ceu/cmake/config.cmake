# ######################################################################################################################
# Function: ceu_find_library_config
#
# Description: Find config package.
#
# Parameters:
#
# Example Usage: ceu_find_library_config()
# ######################################################################################################################
macro(ceu_find_library_config)
    set(options)
    set(oneValueArgs LIBRARY LIB_DIR)
    set(multiValueArgs COMPONENTS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(${ARG_LIBRARY}_DIR ${ARG_LIB_DIR})
    find_package(${ARG_LIBRARY} CONFIG CONFIG COMPONENTS ${ARG_COMPONENTS})
endmacro(ceu_find_library_config)
