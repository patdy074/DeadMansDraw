cmake_minimum_required(VERSION 3.20)
project(DeadMansDraw++)

set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp" "main.cpp")

add_executable(DeadMansDraw ${SOURCES} "include/Game_Title.h" "include/Card.h" "include/Game.h" "include/Player.h" "src/Card.cpp" "src/Game.cpp" "src/Player.cpp")
