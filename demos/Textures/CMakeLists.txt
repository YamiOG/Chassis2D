set(PROJECT_NAME Textures)

file(GLOB SOURCES "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

#target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include")

include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include" PUBLIC "${CMAKE_SOURCE_DIR}/extern/SDL2/include/" PUBLIC "${CMAKE_SOURCE_DIR}/extern/SDL2_ttf" PUBLIC "${CMAKE_SOURCE_DIR}/extern/stb/include/" PUBLIC "${CMAKE_SOURCE_DIR}/extern/Miniaudio")

target_link_libraries(${PROJECT_NAME} Chassis2D)

set_target_properties( ${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
)