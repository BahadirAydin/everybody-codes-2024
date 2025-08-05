cmake_minimum_required(VERSION 3.20)
project(EverybodyCodes CXX)

# Set C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable debug info and optimizations
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Add common warning flags
add_compile_options(
  -Wall # All common warnings
  -Wextra # Extra warnings
  -Wpedantic # Enforce strict ISO C++ compliance
  -Wconversion # Implicit conversions that may alter values
  -Wsign-conversion # Signed/unsigned conversions
  -Wshadow # Variable shadowing
  -Wnon-virtual-dtor # Warn if base class has non-virtual destructor
  -Wold-style-cast # Warn on C-style casts
  -Wnull-dereference # Detect null dereferencing
)

# Default to Release build
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Treat warnings as errors in debug builds
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_options(-Werror)
endif()

# Include src directory for headers
include_directories(src)

# Add common utilities subdirectory
add_subdirectory(src/common)

# Add quest subdirectories
add_subdirectory(src/quest01)
add_subdirectory(src/quest02)

# Create main executable
add_executable(everybodycodes src/main.cpp)

# Link against quest libraries
target_link_libraries(everybodycodes utils quest01)
target_link_libraries(everybodycodes utils quest02)

# Print build information
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")

# Copy input files to build directory for each quest
function(copy_quest_inputs quest_name)
  file(GLOB INPUT_FILES "src/${quest_name}/*.txt")
  foreach(INPUT_FILE ${INPUT_FILES})
    get_filename_component(INPUT_NAME ${INPUT_FILE} NAME)
    configure_file(${INPUT_FILE} ${CMAKE_BINARY_DIR}/${INPUT_NAME} COPYONLY)
  endforeach()
endfunction()

# Copy inputs for quests
copy_quest_inputs(quest01)
copy_quest_inputs(quest02)
