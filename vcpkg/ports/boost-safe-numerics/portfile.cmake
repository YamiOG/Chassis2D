# Automatically generated by boost-vcpkg-helpers/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/safe_numerics
    REF boost-1.73.0
    SHA512 1046d8f8a69137d260dc57dc183c1761dbfcf89479ef4e7112d91de82ff858e57f919db35729a648f972d946bfeaa3d8a9f80f85a9544d1a4b144f8c888a2ef8
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})