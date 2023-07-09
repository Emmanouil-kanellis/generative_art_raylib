cmake_minimum_required(VERSION 3.22)

project(gen_art_test)

add_executable(test_gen main_2.c memory_region.c)

target_link_libraries(test_gen 
PRIVATE
    raylib
)