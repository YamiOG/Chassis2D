file(GLOB HEADER_FILES "${CMAKE_SOURCE_DIR}/include/Chassis2D/*.h")
file(GLOB SOURCES "*.cpp")

file(GLOB EXTERN_SOURCES "${CMAKE_SOURCE_DIR}/extern/stb/include/*.h" "${CMAKE_SOURCE_DIR}/extern/stb/src/*.cpp" "${CMAKE_SOURCE_DIR}/extern/Miniaudio/include/*.h" "${CMAKE_SOURCE_DIR}/extern/Miniaudio/src/*.c")

include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include/Chassis2D" PUBLIC "${CMAKE_SOURCE_DIR}/extern/SDL2/include/" PUBLIC "${CMAKE_SOURCE_DIR}/extern/SDL2_ttf" PUBLIC "{CMAKE_SOURCE_DIR}/extern/Box2D/include" PUBLIC "${CMAKE_SOURCE_DIR}/extern/stb/include/")

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADER_FILES} ${EXTERN_SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC SDL2 SDL2main SDL2_ttf box2d)

set_target_properties( ${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)