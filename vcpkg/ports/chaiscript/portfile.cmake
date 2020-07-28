include(vcpkg_common_functions)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO ChaiScript/ChaiScript
    REF v6.1.0
    SHA512 7728abd8d3e1e8007f4d95c8065ba5a9154583bcd1d493bfd96d608ff91f4c9bb23e538378b77c1cfd6c637d6b4885af94ac0a2a9a34b6bae19581d9f1a831cc
    HEAD_REF master
)

file(INSTALL ${SOURCE_PATH}/include/ DESTINATION ${CURRENT_PACKAGES_DIR}/include/)

file(INSTALL ${SOURCE_PATH}/LICENSE DESTINATION ${CURRENT_PACKAGES_DIR}/share/${PORT} RENAME copyright)