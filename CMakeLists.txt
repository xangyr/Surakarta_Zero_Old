cmake_minimum_required(VERSION 3.15)
project(Surakarta_Zero)

set(CMAKE_CXX_STANDARD 14)
find_package(SDL2_IMAGE REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_TTF REQUIRED)

add_executable(Surakarta_Zero main.cpp basic.cpp basic.h evaluator.cpp evaluator.h game_ai.cpp game_ai.h hash_table.cpp hash_table.h initialization.cpp initialization.h interact.cpp interact.h move_generator.cpp move_generator.h record.cpp record.h run.h run.cpp search_engine.cpp search_engine.h sort.cpp sort.h test.h test.cpp ui.cpp ui.h)

target_link_libraries(Surakarta_Zero ${SDL2_IMAGE_LIBRARY} ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY})

