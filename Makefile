.PHONY: all debug release run

# Directory names
BUILD_DIR_DEBUG := out/Debug
BUILD_DIR_RELEASE := out/Release

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

# Run release
run: release
	cd $(BUILD_DIR_RELEASE) && ./everybodycodes

# Build both
all: debug release
