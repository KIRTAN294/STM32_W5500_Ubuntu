cmake_minimum_required(VERSION 3.10)

project(MyCApp VERSION 1.0 LANGUAGES C)

# Include the header directory
include_directories(Inc)

# Automatically include all .c files from src/
file(GLOB SOURCES "Src/*.c")

# Create the executable
add_executable(main ${SOURCES})

# Install the executable
install(TARGETS main DESTINATION bin)

