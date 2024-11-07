# ######################################################################################################################
# Function: ceu_fetch_benchmark
#
# Description: Fetch benchmark from github repo.
#
# Parameters: PREFIX - FetchContent_Declare PREFIX; GIT_TAG - FetchContent_Declare GIT_TAG
#
# Example Usage: ceu_fetch_benchmark(PREFIX "${CUSTOM_PATH}" GIT_TAG v1.8.0)
# ######################################################################################################################
function(ceu_fetch_benchmark)
    set(options)
    set(oneValueArgs PREFIX GIT_TAG)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Options
    set(BENCHMARK_ENABLE_TESTING OFF)
    set(BENCHMARK_ENABLE_INSTALL OFF)
    set(BENCHMARK_INSTALL_DOCS OFF)

    include(FetchContent)
    message(STATUS "Start FetchContent_Declare: benchmark.")
    FetchContent_Declare(
        benchmark
        PREFIX ${ARG_PREFIX}
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG ${ARG_GIT_TAG}) # OVERRIDE_FIND_PACKAGE
    message(STATUS "Start FetchContent_MakeAvailable: benchmark.")
    FetchContent_MakeAvailable(benchmark)
    message(STATUS "Fetch Over: benchmark.")
endfunction(ceu_fetch_benchmark)

# ######################################################################################################################
# Function: ceu_find_benchmark
#
# Description: Find benchmark. If not found, fetch google benchmark v1.8.0.
#
# Parameters:
#
# Example Usage: ceu_find_benchmark()
# ######################################################################################################################
function(ceu_find_benchmark)
    message(STATUS "=================================================================")
    message(STATUS "Start finding third party: benchmark.")

    # find in system
    find_package(benchmark CONFIG QUIET)

    if(NOT ${benchmark_FOUND})
        message(WARNING "Benchmark NOT found in system.")
        ceu_fetch_benchmark(PREFIX "${CMAKE_BINARY_DIR}/_deps/benchmark" GIT_TAG v1.8.0)
    else()
        message(STATUS "Third party found: benchmark.")
    endif()

    message(STATUS "=================================================================")
endfunction(ceu_find_benchmark)

# ######################################################################################################################
# Macro: ceu_import_benchmark
#
# Description: import benchmark
#
# Parameters:
#
# Example Usage: ceu_import_benchmark()
# ######################################################################################################################
macro(ceu_import_benchmark)
    ceu_find_benchmark()
    
    add_definitions(-DCEU_3RDPARTY_IMPORTED_BENCHMARK)
endmacro(ceu_import_benchmark)

# ######################################################################################################################
# Function: ceu_target_link_benchmark
#
# Description: target link benchmark static library. If Visibility is not configured, target_link use Plain.
#
# Parameters: TARGET - target to configure; VISIBILITY - visibility when target_link_library
#
# Example Usage: ceu_target_link_benchmark(TARGET project_name VISIBILITY PUBLIC)
# ######################################################################################################################
function(ceu_target_link_benchmark)
    set(options)
    set(oneValueArgs TARGET VISIBILITY)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(DEFINED ARG_VISIBILITY)
        target_link_libraries(${ARG_TARGET} ${ARG_VISIBILITY} benchmark::benchmark benchmark::benchmark_main)
    else()
        target_link_libraries(${ARG_TARGET} benchmark::benchmark benchmark::benchmark_main)
    endif()
endfunction(ceu_target_link_benchmark)
