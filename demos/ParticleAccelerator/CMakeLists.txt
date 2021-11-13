set(PROJECT_NAME ParticleAccelerator)

file(GLOB SOURCES "*.cpp")

include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Chassis2D)

set_target_properties( ${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
)