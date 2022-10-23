add_library(
    engine
    engine.cpp
    engine.h
    input.cpp
    input.h
    sprite.h
    sprite.cpp
)

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)