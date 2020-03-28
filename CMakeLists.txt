cmake_minimum_required(VERSION 3.0.0)
project(VisualConstruct VERSION 0.0.1)

find_package(OpenGL REQUIRED)

# Set default build type
if(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_CONFIGURATION_TYPES "Release;" CACHE STRING "Release configurations")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
elseif(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CONFIGURATION_TYPES "Debug;" CACHE STRING "Debug configurations") 
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
endif()

# Dependeny subdsirectory project
add_subdirectory(${PROJECT_SOURCE_DIR}/dep/glfw)
add_subdirectory(${PROJECT_SOURCE_DIR}/dep/glm)


# Set constants
# set(FILE_SOURCE )
file(GLOB SOURCES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/dep/imgui/*.cpp
)
set(INCLUDES 
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/dep/spdlog/include
    ${PROJECT_SOURCE_DIR}/dep/vulkan/include
    ${PROJECT_SOURCE_DIR}/dep/imgui
    ${PROJECT_SOURCE_DIR}/dep/bullet3/src
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


# Setting output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Application
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# glad
set(GLAD_DIR ${PROJECT_SOURCE_DIR}/dep/glad)
add_library(glad ${GLAD_DIR}/src/glad.c)
target_include_directories(glad PRIVATE ${GLAD_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLAD_DIR}/include)

# Vulkan
find_library(VULKAN_LIB vulkan-1.lib PATHS ${PROJECT_SOURCE_DIR}/dep/vulkan/lib)

# Linking Libraries
if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(BULLET3_LIB_DEBUG ${PROJECT_SOURCE_DIR}/dep/bullet3/lib/Debug)
    target_link_libraries(${PROJECT_NAME} ${BULLET3_LIB_DEBUG}/LinearMath_Debug.lib ${BULLET3_LIB_DEBUG}/BulletDynamics_Debug.lib ${BULLET3_LIB_DEBUG}/BulletCollision_Debug.lib)
else()
    set(BULLET3_LIB_RELEASE ${PROJECT_SOURCE_DIR}/dep/bullet3/lib/Release)
    target_link_libraries(${PROJECT_NAME} ${BULLET3_LIB_RELEASE}/LinearMath.lib ${BULLET3_LIB_RELEASE}/BulletDynamics.lib ${BULLET3_LIB_RELEASE}/BulletCollision.lib)
endif()
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} glfw glm glad ${CMAKE_DL_LIBS} ${VULKAN_LIB})

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(${PROJECT_NAME} PRIVATE VC_DEBUG)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_definitions(${PROJECT_NAME} PRIVATE VC_RELEASE)
endif()
