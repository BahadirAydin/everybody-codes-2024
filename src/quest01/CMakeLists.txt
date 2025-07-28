# Quest01 library
add_library(quest01 STATIC quest01.cpp quest01.hpp)

# Include directories for this quest
target_include_directories(
    quest01
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src
)

# Link with common utilities if needed
target_link_libraries(quest01 PRIVATE utils)

# Set target properties
set_target_properties(
    quest01
    PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON
)
