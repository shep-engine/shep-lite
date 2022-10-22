cmake_minimum_required(VERSION 3.22.1)

project(sheplite)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    game/game.cpp
    game/include/game.h
)

add_subdirectory(engine)

target_include_directories(${PROJECT_NAME} PRIVATE engine/)
target_link_directories(${PROJECT_NAME} PRIVATE engine/)
target_link_libraries(${PROJECT_NAME} engine SDL2 SDL2_image)