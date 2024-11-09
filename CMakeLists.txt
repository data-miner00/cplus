cmake_minimum_required(VERSION 3.10)

project(
  cplus

  VERSION 1.0.0.0
  DESCRIPTION "Dumpster for C++ related resources"
  LANGUAGES CXX
)

set(AUTHOR_NAME shaun)

# Enabling C++11 features
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# For clangd to pick up
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# Declares the executable
add_executable(
  # Name of executable. Using project name.
  ${PROJECT_NAME}

  # Source of executable
  main.cc bubble_sort.cc
)

# First boolean variable indicates that the recently called
# `project()` was in the top level `CMakeLists.txt` file.
if (PROJECT_IS_TOP_LEVEL AND UNIX)
  # Create symlink to compile_commands.json
  execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
endif()

message(STATUS "The project ${PROJECT_NAME} has been built successfully")
