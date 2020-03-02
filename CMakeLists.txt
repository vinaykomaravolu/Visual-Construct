cmake_minimum_required(VERSION 3.0.0)
project(VisualConstruct VERSION 0.0.1)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Set constants
# set(FILE_SOURCE )
file(GLOB SOURCES "src/*.cpp")
set(INCLUDES ${PROJECT_SOURCE_DIR}/include)
# Definitions
# GLFW
#set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#set(GLFW_VULKAN_STATIC ON CACHE BOOL "" FORCE)
# GLM
#set(GLM_TEST_ENABLE OFF CACHE BOOL "" FORCE)

#Windows
if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
endif()

# Dependeny subdirectory project
#add_subdirectory(${PROJECT_SOURCE_DIR}/deps/glfw)
#add_subdirectory(${PROJECT_SOURCE_DIR}/deps/glm)

# Setting output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(VisualConstruct ${SOURCES})

target_include_directories(VisualConstruct PRIVATE ${INCLUDES})
