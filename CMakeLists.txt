cmake_minimum_required(VERSION 3.10...3.30)
project(OPENGL VERSION 1.0.0)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
IF(APPLE)
  add_definitions(-Wno-nullability-completeness)
  add_definitions(-Wno-deprecated)
ENDIF()

add_compile_definitions(SHADER_PATH="${PROJECT_SOURCE_DIR}/shader" ASSET_PATH="${PROJECT_SOURCE_DIR}/assets")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
IF(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20")
ENDIF()

file(GLOB SOURCES
  src/*.h
  src/*.cpp
)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

#add OpenGL and GLUT
find_package(OpenGL REQUIRED)

#add glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glfw)

#add glm
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glm)

#add tinygltf
set(TINYGLTF_HEADER_ONLY ON CACHE INTERNAL "" FORCE)
set(TINYGLTF_INSTALL OFF CACHE INTERNAL "" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/tinygltf)

#link all libararies
target_link_libraries(${CMAKE_PROJECT_NAME} 
  ${OPENGL_LIBRARIES}
  glm 
  glfw
  glew
)

#include all necessary directories
include_directories(${CMAKE_PROJECT_NAME} PRIVATE
  ${OPENGL_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/lib/tinygltf
  ${PROJECT_SOURCE_DIR}/src
)