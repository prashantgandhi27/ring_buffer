########################################################################################################################
# \author     Prashant Gandhi
# \date       02/14/2022
########################################################################################################################
cmake_minimum_required(VERSION 3.11-3.19)

project(ring_buffer
   DESCRIPTION "Ring Buffer Library")

project(ring_buffer)

add_library(ring_buffer src/ring_buffer.c)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main main.c)

target_link_libraries(main
    PRIVATE ring_buffer)
