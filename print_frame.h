#include <curses.h>
#include <ncurses.h>
#include "objects.h"

#ifndef PRINT_FRAME_H
#define PRINT_FRAME_H



typedef struct global_environement
{
    Object* ship;
    Object** enemies;
    Object* gaming_interface;
} global_environement;

void print_global_frame(int ch, MEVENT event, global_environement* game);

#endif //PRINT_FRAME_H
