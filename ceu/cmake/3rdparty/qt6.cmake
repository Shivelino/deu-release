# ######################################################################################################################
# Function: ceu_find_qt6
#
# Description: Find qt6.
#
# Parameters: COMPONENTS - components of Qt6
#
# Example Usage: ceu_find_qt6()
# ######################################################################################################################
function(ceu_find_qt6)
    if(NOT DEFINED Qt6_PATH)
        message(WARNING "Not predefiend `Qt6_PATH`, if not found automatically, please predefine `Qt6_PATH`.")
    endif()

    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: qt6.")

    set(options)
    set(oneValueArgs)
    set(multiValueArgs COMPONENTS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
    set(Qt6_DIR "${Qt6_PATH}/lib/cmake/Qt6")

    if(ARG_COMPONENTS)
        find_package(Qt6 REQUIRED COMPONENTS ${ARG_COMPONENTS})
    else()
        find_package(Qt6 REQUIRED)
    endif()

    qt6_standard_project_setup()
    message(STATUS "=================================================================")
endfunction(ceu_find_qt6)

# ######################################################################################################################
# Macro: ceu_import_qt6
#
# Description: import qt6.
#
# Parameters:
#
# Example Usage: ceu_import_qt6()
# ######################################################################################################################
macro(ceu_import_qt6)
    set(options)
    set(oneValueArgs)
    set(multiValueArgs COMPONENTS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    ceu_find_qt6(COMPONENTS ${ARG_COMPONENTS})
endmacro(ceu_import_qt6)

# ######################################################################################################################
# Function: ceu_target_link_qt6
#
# Description: target link qt6 library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library; DLL_DEST_DIR - dest dir
# that dll file is moved to; COMPONENTS - components of Qt6, if not set, default is "Core" "Gui" "Widgets".
#
# Example Usage: ceu_target_link_qt6(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_qt6)
    set(options)
    set(oneValueArgs TARGET VISIBILITY DLL_DEST_DIR)
    set(multiValueArgs COMPONENTS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT DEFINED ARG_COMPONENTS)
        set(ARG_COMPONENTS Core Gui Widgets)
    endif()

    foreach(comp ${ARG_COMPONENTS})
        target_include_directories(${ARG_TARGET} ${ARG_VISIBILITY}
                                   "$<TARGET_PROPERTY:Qt6::${comp},INTERFACE_INCLUDE_DIRECTORIES>")

        if(DEFINED ARG_VISIBILITY)
            target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} "Qt::${comp}")
        else()
            target_link_libraries(${ARG_TARGET} "Qt::${comp}")
        endif()

        add_custom_command(
            TARGET ${ARG_TARGET}
            POST_BUILD
            COMMAND
                ${CMAKE_COMMAND} ARGS -E copy
                "$<$<CONFIG:Debug>:${Qt6_PATH}/bin/Qt6${comp}d.dll>$<$<NOT:$<CONFIG:Debug>>:${Qt6_PATH}/bin/Qt6${comp}.dll>"
                ${ARG_DLL_DEST_DIR})
    endforeach(comp ${ARG_COMPONENTS})

    add_custom_command(
        TARGET ${ARG_TARGET}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} ARGS -E copy_directory ${Qt6_PATH}/plugins/platforms ${ARG_DLL_DEST_DIR}/platforms)
endfunction(ceu_target_link_qt6)
