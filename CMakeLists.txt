cmake_minimum_required(VERSION 3.20)
project(UwaSimCpp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(uwasim
  apps/uwasim_main.cpp
)

if (MSVC)
  target_compile_options(uwasim PRIVATE /W4 /permissive-)
else()
  target_compile_options(uwasim PRIVATE -Wall -Wextra -Wpedantic)
endif()
