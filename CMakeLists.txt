cmake_minimum_required(VERSION 3.12)
project(tigerFish)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the sources
set(SOURCES
    src/image.cpp
    main.cpp
)

# Add an executable target
add_executable(tigerFish ${SOURCES})

# Include directories
target_include_directories(tigerFish PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
