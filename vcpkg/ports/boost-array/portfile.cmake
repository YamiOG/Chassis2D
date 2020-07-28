# Automatically generated by boost-vcpkg-helpers/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/array
    REF boost-1.73.0
    SHA512 020eabd6bd57988a773656f5c41c17457e4f03d90bc3aa34b1f875e8af91d77f2911db5baeaf295c57cdc9e4df2687b659c6cee2a175504ca6cdabc73c028694
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})