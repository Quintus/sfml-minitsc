cmake_minimum_required(VERSION 2.8)
project(MiniTSC)
enable_language(CXX)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

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
# Source files

file(GLOB minitsc_sources
  "src/*.cpp"
  "src/*.hpp")

########################################
# Targets

add_executable(minitsc ${minitsc_sources})
target_link_libraries(minitsc
  ${SFML_LIBRARIES}
#  ${OPENGL_LIBRARIES}
)
