cmake_minimum_required(VERSION 3.20)
project(DeadMansDraw++)

set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp" "main.cpp")

add_executable(DeadMansDraw ${SOURCES} "include/Game_Title.h" "include/Card.h" "include/Game.h" "include/Player.h" "src/Card.cpp" "src/Game.cpp" "src/Player.cpp" "include/CardType.h" "include/SwordCard.h" "src/SwordCard.cpp" "include/CannonCard.h" "src/CannonCard.cpp" "include/ChestCard.h" "src/ChestCard.cpp" "include/KeyCard.h" "src/KeyCard.cpp" "include/KrakenCard.h" "src/KrakenCard.cpp" "include/HookCard.h" "src/HookCard.cpp" "include/OracleCard.h" "src/OracleCard.cpp" "include/MapCard.h" "src/MapCard.cpp" "include/MermaidCard.h" "src/MermaidCard.cpp" "include/DeckFactory.h" "src/DeckFactory.cpp")
