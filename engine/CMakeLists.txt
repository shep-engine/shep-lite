add_library(
    engine
    hello.cpp
)

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)