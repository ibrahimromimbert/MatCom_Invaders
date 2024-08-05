#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include "ship.h"
#include "objects.c"

char* model[] = {
    "   ^  ",
    "  /|\\ ",
    "</_|_\\>"
};

Object* create_ship(void) //it creates the player's ship
{
    char* title = "Terminator";
    Point start;
    start.x = COLS / 2;
    start.y = LINES - 5;
    Object* obj = make_obj(title, model, start, ship, 3);
    return obj;
}

void create_bullet(Point* ship_position) //assignes to the bullet variable a new bullet object
{
    char* bullet_1 = "bullet_1";
    char* design[] = {"|"};
    Point start = {.x = ship_position->x, .y = ship_position->y};
    bullet = make_obj(bullet_1, design, start, s_bullet, 1);
}

void shot(int ch, MEVENT event, Object* ship)
{
    if (bullet == NULL)
    {
        if (ch == KEY_MOUSE)
        {
            if (getmouse(&event) == OK)
            {
                if (event.bstate & BUTTON1_PRESSED)
                {
                    create_bullet(ship->position);
                }
            }
        }
    }
}

void print_shot(void)
{
    if (bullet != NULL)
    {
        print_obj(bullet);
    }
}
