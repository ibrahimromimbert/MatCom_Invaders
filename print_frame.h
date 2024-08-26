#ifndef PRINT_FRAME_H
#define PRINT_FRAME_H

#include <curses.h>
#include <ncurses.h>
#include "objects.h"

typedef struct Area_Limits
{
    int UP_lim;
    int Down_lim;
    int Left_lim;
    int Right_lim;
} Valid_Area;

Valid_Area Ship_Area;
Valid_Area Enemies_Area;

typedef struct global_environement
{
    Object* ship;
    Object** enemies;
    Object* gaming_interface;
} global_environement;

void print_global_frame(int ch, MEVENT event, global_environement* game);

#endif //PRINT_FRAME_H
