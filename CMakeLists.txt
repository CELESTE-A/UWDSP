cmake_minimum_required(VERSION 3.20)
project(UwaSimCpp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- core library ----
add_library(uwasim_core
  src/uwasim_core.cpp
)
target_include_directories(uwasim_core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (MSVC)
  target_compile_options(uwasim_core PRIVATE /W4 /permissive-)
else()
  target_compile_options(uwasim_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

# ---- app ----
add_executable(uwasim
  apps/uwasim_main.cpp
)
target_link_libraries(uwasim PRIVATE uwasim_core)

# ---- tests ----
enable_testing()

add_executable(uwasim_tests
  tests/test_basic.cpp
)
target_link_libraries(uwasim_tests PRIVATE uwasim_core)

add_test(NAME uwasim_tests COMMAND uwasim_tests)
