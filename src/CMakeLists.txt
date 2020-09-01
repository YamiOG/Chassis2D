set(PROJECT_NAME Chassis2D)

find_package(SDL2 CONFIG REQUIRED)
message(" [INFO] Found SDL2")
find_package(sdl2-image CONFIG REQUIRED)
message(" [INFO] Found SDL2-Image")
find_package(sdl2-mixer CONFIG REQUIRED)
message(" [INFO] Found SDL2-Mixer")
find_package(sdl2-ttf CONFIG REQUIRED)
message(" [INFO] Found SDL2-TTF")
find_package(unofficial-box2d CONFIG REQUIRED)
message(" [INFO] Found Box2D")

file(GLOB HEADER_FILES "${CMAKE_SOURCE_DIR}/include/Chassis2D/*.h")
file(GLOB SOURCES "*.cpp")

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include/Chassis2D")

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main PRIVATE SDL2::SDL2_image PRIVATE SDL2::SDL2_mixer PRIVATE SDL2::SDL2_ttf PRIVATE unofficial::box2d::box2d )

set_target_properties( ${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)