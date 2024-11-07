# ######################################################################################################################
# Macro:
#
# Description:
#
# Parameters:
#
# Example Usage:
# ######################################################################################################################
macro(ceu_get_hearers_in_folder _dir_in, _list_out)
    file(GLOB __tmp_list "${ARGV0}/*.h" "${ARGV0}/*.hpp" "${ARGV0}/*.hxx")
    set(${ARGV1} ${__tmp_list})
endmacro()

# ######################################################################################################################
# Macro:
#
# Description:
#
# Parameters:
#
# Example Usage:
# ######################################################################################################################
macro(ceu_get_sources_in_folder _dir_in, _list_out)
    file(GLOB __tmp_list "${ARGV0}/*.c" "${ARGV0}/*.cpp" "${ARGV0}/*.cxx")
    set(${ARGV1} ${__tmp_list})
endmacro()

# ######################################################################################################################
# Macro:
#
# Description:
#
# Parameters:
#
# Example Usage:
# ######################################################################################################################
macro(ceu_get_all_headers _dir_in, _list_out)
    file(GLOB_RECURSE __tmp_list "${ARGV0}/*.h" "${ARGV0}/*.hpp" "${ARGV0}/*.hxx")
    set(${ARGV1} ${__tmp_list})
endmacro()

# ######################################################################################################################
# Macro:
#
# Description:
#
# Parameters:
#
# Example Usage:
# ######################################################################################################################
macro(ceu_get_all_sources _dir_in, _list_out)
    file(GLOB_RECURSE __tmp_list "${ARGV0}/*.c" "${ARGV0}/*.cpp" "${ARGV0}/*.cxx")
    set(${ARGV1} "${__tmp_list}")
endmacro()

# ######################################################################################################################
# Macro:
#
# Description:
#
# Parameters:
#
# Example Usage:
# ######################################################################################################################
macro(ceu_get_all_libs _dir_in, _list_out)
    file(GLOB_RECURSE __tmp_list "${ARGV0}/*.lib")
    set(${ARGV1} "${__tmp_list}")
endmacro()
