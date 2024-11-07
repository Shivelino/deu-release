# ######################################################################################################################
# Function: ceu_msvc_compile_option
#
# Description: set compile option of MSVC.
#
# Parameters:
#
# Example Usage: ceu_msvc_compile_option(TARGET target1 OPTIONS /Zc:preprocessor)
# ######################################################################################################################
function(ceu_msvc_compile_option)
    set(options)
    set(oneValueArgs TARGET)
    set(multiValueArgs OPTIONS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(MSVC)
        if(DEFINED ARG_TARGET)
            target_compile_options(${ARG_TARGET} PUBLIC ${ARG_OPTIONS})
        else()
            add_compile_options(${ARG_OPTIONS})
        endif()
    endif()
endfunction()

# ######################################################################################################################
# Function: ceu_msvc_compile_option_enable_preprocessor
#
# Description: enable MSVC /Zc:preprocessor.
#
# Parameters:
#
# Example Usage: ceu_msvc_compile_option_enable_preprocessor(TARGET target1)
# ######################################################################################################################
function(ceu_msvc_compile_option_enable_preprocessor)
    ceu_msvc_compile_option(${ARGN} OPTIONS /Zc:preprocessor)
endfunction()
