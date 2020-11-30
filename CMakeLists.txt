cmake_minimum_required(VERSION 3.17)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(main main.c)
add_executable(alphatoe alphatoe.c ttt1.c ttt2.c)
add_executable(show_node ttt1.c show_node.c ttt1.c ttt2.c)
add_executable(count_node ttt1.c count_nodes.c ttt1.c ttt2.c)
