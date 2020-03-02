cmake_minimum_required(VERSION 3.0.0)
project(VisualConstruct VERSION 0.0.1)


find_package(OpenGL REQUIRED)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Set constants
# set(FILE_SOURCE )
file(GLOB SOURCES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)
set(INCLUDES 
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/dep/spdlog/include
    ${PROJECT_SOURCE_DIR}/dep/vulkan/include
)
# Definitions
# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_VULKAN_STATIC ON CACHE BOOL "" FORCE)
# GLM
set(GLM_TEST_ENABLE OFF CACHE BOOL "" FORCE)

#Windows
if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
endif()

# Dependeny subdirectory project
add_subdirectory(${PROJECT_SOURCE_DIR}/dep/glfw)
add_subdirectory(${PROJECT_SOURCE_DIR}/dep/glm)

# Setting output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Application
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# glad
set(GLAD_DIR ${PROJECT_SOURCE_DIR}/dep/glad)
add_library(glad ${GLAD_DIR}/src/glad.c)
target_include_directories(glad PRIVATE ${GLAD_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLAD_DIR}/include)

# Vulkan
find_library(VULKAN_LIB vulkan-1.lib PATHS ${PROJECT_SOURCE_DIR}/dep/vulkan/lib)

# Linking Libraries
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} glfw glm glad ${CMAKE_DL_LIBS} ${VULKAN_LIB})
