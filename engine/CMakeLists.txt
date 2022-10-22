add_library(
    engine
    engine.cpp
    engine.h
)

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)