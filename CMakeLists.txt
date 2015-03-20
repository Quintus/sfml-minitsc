cmake_minimum_required(VERSION 2.8)
project(MiniTSC)
enable_language(CXX)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
include(ExternalProject)

########################################
# Extra flags

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99")
endif()

if (${CMAKE_BUILD_TYPE} MATCHES Debug)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -D_PIPHONED_DEBUG")
endif()

add_definitions("-Wall")

########################################
# Dependencies

find_package(SFML COMPONENTS graphics window system REQUIRED)
#find_package(OpenGL REQUIRED)

include_directories(
  ${SFML_INCLUDE_DIRS}
  #${OPENGL_INCLUDE_DIR}
  )

########################################
# External projects

# Pathie
ExternalProject_Add(
  pathie
  PREFIX "${CMAKE_BINARY_DIR}/pathie"
  DOWNLOAD_COMMAND ""
  UPDATE_COMMAND ""
  CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/pathie/install"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/pathie")
include_directories(${CMAKE_BINARY_DIR}/pathie/install/include/pathie)

########################################
# Source files

file(GLOB minitsc_sources
  "src/*.cpp"
  "src/*.hpp")

########################################
# Targets

add_executable(minitsc ${minitsc_sources})
target_link_libraries(minitsc
  ${SFML_LIBRARIES}
  ${CMAKE_BINARY_DIR}/pathie/install/lib/libpathie.a
#  ${OPENGL_LIBRARIES}
)
add_dependencies(minitsc pathie)
