# ######################################################################################################################
# Function: ceu_find_pkgconfig
#
# Description: Find pkgconfig.
# package.
#
# Parameters:
#
# Example Usage: ceu_find_pkgconfig()
# ######################################################################################################################
macro(ceu_find_pkgconfig)
    include(FindPkgConfig)
    find_package(PkgConfig REQUIRED)
endmacro(ceu_find_pkgconfig)

# ######################################################################################################################
# Function: ceu_import_pkgconfig
#
# Description: Import pkgconfig.
# package.
#
# Parameters:
#
# Example Usage: ceu_import_pkgconfig()
# ######################################################################################################################
macro(ceu_import_pkgconfig)
    ceu_find_pkgconfig()
endmacro(ceu_import_pkgconfig)
