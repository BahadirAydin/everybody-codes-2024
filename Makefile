.PHONY: all debug release

# Directory names
BUILD_DIR_DEBUG := out/debug
BUILD_DIR_RELEASE := out/release

# Default target
default: release

# Debug build
debug:
	cmake -S . -B $(BUILD_DIR_DEBUG) -DCMAKE_BUILD_TYPE=Debug
	cmake --build $(BUILD_DIR_DEBUG)

# Release build
release:
	cmake -S . -B $(BUILD_DIR_RELEASE) -DCMAKE_BUILD_TYPE=Release
	cmake --build $(BUILD_DIR_RELEASE)

# Build both
all: debug release
