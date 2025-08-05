# Quest02 library
add_library(quest02 STATIC quest02.cpp quest02.hpp)

# Include directories for this quest
target_include_directories(
    quest02
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src
)

# Link with common utilities if needed
target_link_libraries(quest02 PRIVATE utils)

# Set target properties
set_target_properties(
    quest02
    PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON
)
