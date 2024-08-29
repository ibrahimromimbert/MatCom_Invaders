cmake_minimum_required(VERSION 3.30)

project(Space_Invaders C)

set(CMAKE_C_STANDARD 11)

# Buscar la biblioteca ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Space_Invaders main.c
        print_frame.h
        print_frame.c
        objects.h
        objects.c
        ship.h
        ship.c
        linked_list.c
        linked_list.h
        linked_list.h
        enemies.c
        enemies.h
        enemies.h
        menu.c
        menu.h
        menu.h
        bullets_p_c.c
        bullets_p_c.h
        bullets_p_c.h)

# Enlazar el ejecutable con la biblioteca ncurses
target_link_libraries(Space_Invaders ${CURSES_LIBRARIES})