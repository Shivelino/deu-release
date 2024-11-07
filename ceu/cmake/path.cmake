# ######################################################################################################################
# Function: ceu_get_path_dirname
#
# Description: get `DIR_PATH` of `PATH`, save value in `DIR_PATH`
#
# Parameters: PATH - path; DIR_PATH - save result dir path
#
# Example Usage: ceu_get_path_dirname(PATH your-path DIR_PATH your-var)
# ######################################################################################################################
function(ceu_get_path_dirname)
    set(options)
    set(oneValueArgs PATH DIR_PATH)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT DEFINED ARG_PATH OR NOT DEFINED ARG_DIR_PATH)
        message(FATAL_ERROR "`PATH` or `DIR_PATH` not exists")
    endif()

    get_filename_component(__temp_dir ${ARG_PATH} DIRECTORY)
    set(${ARG_DIR_PATH}
        ${__temp_dir}
        PARENT_SCOPE)
endfunction(ceu_get_path_dirname)
