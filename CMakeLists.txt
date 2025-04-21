cmake_minimum_required(VERSION 3.20)
project(DeadMansDraw)

set(CMAKE_CXX_STANDARD 17)

# Include all headers
include_directories(include)

# Add the executable and list all source files explicitly
add_executable(DeadMansDraw
    main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Card.cpp
    src/SwordCard.cpp
    src/CannonCard.cpp
    src/ChestCard.cpp
    src/KeyCard.cpp
    src/KrakenCard.cpp
    src/HookCard.cpp
    src/OracleCard.cpp
    src/MapCard.cpp
    src/MermaidCard.cpp
    src/DeckFactory.cpp
)

# Include necessary headers to track in project
target_sources(DeadMansDraw PRIVATE
    include/Game_Title.h
    include/Game.h
    include/Card.h
    include/Player.h
    include/CardType.h
    include/SwordCard.h
    include/CannonCard.h
    include/ChestCard.h
    include/KeyCard.h
    include/KrakenCard.h
    include/HookCard.h
    include/OracleCard.h
    include/MapCard.h
    include/MermaidCard.h
    include/DeckFactory.h
    include/CardTypeUtils.h
)
