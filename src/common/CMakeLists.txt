# Common utilities library
add_library(utils STATIC
    input_reader.cpp
    input_reader.hpp
)

# Include directories for common utilities
target_include_directories(utils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

# Set target properties
set_target_properties(utils PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
