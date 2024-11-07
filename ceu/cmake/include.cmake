# ######################################################################################################################
# Function: ceu_target_include_external_utils_headers
#
# Description: target include CEU custom headers.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library
#
# Example Usage: ceu_target_include_external_utils_headers(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_include_external_utils_headers)
    set(options)
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    target_include_directories(${ARG_TARGET} ${ARG_VISIBILITY} "${CEU_INCLUDE_DIR}")
endfunction(ceu_target_include_external_utils_headers)

# ######################################################################################################################
# Function: ceu_target_include_header_only_3rdparty
#
# Description: target include header-only 3rdparty headers in CEU.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library
#
# Example Usage: ceu_target_include_header_only_3rdparty(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_include_header_only_3rdparty)
    set(options)
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    target_include_directories(${ARG_TARGET} ${ARG_VISIBILITY} "${CEU_3RDPARTY_DIR}")
endfunction(ceu_target_include_header_only_3rdparty)

# ######################################################################################################################
# Function: ceu_target_include_headers
#
# Description: target include CEU custom headers and 3rdparty headers.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library
#
# Example Usage: ceu_target_include_headers(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_include_headers)
    ceu_target_include_external_utils_headers(${ARGN})
    ceu_target_include_header_only_3rdparty(${ARGN})
endfunction(ceu_target_include_headers)
