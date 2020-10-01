cmake_minimum_required(VERSION 2.6)
project(CMENGINE)

include_directories(
  src
)

add_executable(demo
  src/demo/main.cpp
)

target_link_libraries(demo cmengine)

# .h files included to show in Visual Studio

add_library(cmengine SHARED
  src/cmengine/Core.cpp
  src/cmengine/Core.h
)