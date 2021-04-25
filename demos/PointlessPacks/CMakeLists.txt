set(PROJECT_NAME PointlessPacks)

file(GLOB SOURCES "*.cpp")

include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} ${SOURCES})

#include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include" PUBLIC "${CMAKE_SOURCE_DIR}/extern/SDL2/include/" PUBLIC "${CMAKE_SOURCE_DIR}/extern/SDL2_ttf" PUBLIC "${CMAKE_SOURCE_DIR}/extern/stb/include/")

target_link_libraries(${PROJECT_NAME} Chassis2D)

set_target_properties( ${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
)