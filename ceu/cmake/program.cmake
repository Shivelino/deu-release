include("${CMAKE_CURRENT_LIST_DIR}/path.cmake")

# ######################################################################################################################
# Function: ceu_find_program
#
# Description: find program and set a glabal var `CEU_EXECUTABLE_${CMD}`
#
# Parameters: CMD - cmd; HINTS - hints for find_program; REQUIRED - required
#
# Example Usage: ceu_find_program(CMD vcpkg REQUIRED)
# ######################################################################################################################
macro(ceu_find_program)
    set(options REQUIRED)
    set(oneValueArgs CMD)
    set(multiValueArgs HINTS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    find_program(CEU_EXECUTABLE_${ARG_CMD} ${ARG_CMD} HINTS ${ARG_HINTS} ${ARG_REQUIRED})
endmacro(ceu_find_program)

# ######################################################################################################################
# Function: ceu_program_exist
#
# Description: check if a program exists, set global var `CEU_PROGRAM_EXIST` as result
#
# Parameters: CMD - cmd
#
# Example Usage: ceu_program_exist(CMD vcpkg)
# ######################################################################################################################
macro(ceu_program_exist)
    set(options)
    set(oneValueArgs CMD)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT CEU_EXECUTABLE_${ARG_CMD})
        ceu_find_program(${ARGN})
    endif()

    set(CEU_PROGRAM_EXIST)

    if(CEU_EXECUTABLE_${ARG_CMD})
        set(CEU_PROGRAM_EXIST TRUE)
    else()
        set(CEU_PROGRAM_EXIST FALSE)
    endif()
endmacro(ceu_program_exist)

# ######################################################################################################################
# Function: ceu_program_locate
#
# Description: Locate a program, set global var `CEU_EXECUTABLE_DIR_PATH_${CMD}`
#
# Parameters: CMD - cmd
#
# Example Usage: ceu_program_locate(CMD vcpkg)
# ######################################################################################################################
macro(ceu_program_locate)
    set(options)
    set(oneValueArgs CMD)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT CEU_EXECUTABLE_${ARG_CMD})
        ceu_find_program(${ARGN})
    endif()

    if(NOT CEU_EXECUTABLE_${ARG_CMD})
        message(FATAL_ERROR "[CEU/FATAL]: ${ARG_CMD} not found")
    endif()

    set(__program_dir_path)
    ceu_get_path_dirname(PATH ${CEU_EXECUTABLE_${ARG_CMD}} DIR_PATH __program_dir_path)
    set(CEU_EXECUTABLE_DIR_PATH_${ARG_CMD} ${__program_dir_path})
endmacro(ceu_program_locate)
