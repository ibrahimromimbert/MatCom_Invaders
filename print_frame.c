#include <curses.h>
#include <ncurses.h>
#include "print_frame.h"
#include "objects.h"
#include "ship.h"

void move_ship(int ch, MEVENT event, Object* ship)
{
    Point* position = ship->position;
    mov_dir direction = {.x_dir = 0, .y_dir = 0};
    switch (ch)
    {
    case KEY_MOUSE:
        if (getmouse(&event) == OK)
        {
            if (event.x > position->x) direction.x_dir = 1;
            else if (event.x < position->x) direction.x_dir = -1;

            if (event.y > position->y) direction.y_dir = 1;
            else if (event.y < position->y) direction.y_dir = -1;

            //mvprintw(1, 0, "Mouse position: (%d, %d)", event.x, event.y);
            //clrtoeol();
            // refresh();
        }
        break;
    default:
        break;
    }
    move_obj(ship, direction);
}

void move_bullet(void)
{
    if (bullet != NULL)
    {
        if (bullet->position->y <= 1)
        {
            free_obj(bullet);
            bullet = NULL;
        }
        else
        {
            mov_dir mov = {.y_dir = -1};
            move_obj(bullet, mov);
        }
    }
}

void print_global_frame(int ch, MEVENT event, global_environement* game)
{
    clear();
    move_ship(ch, event, game->ship);
    move_bullet();
    shot(ch, event, game->ship);
    print_obj(game->ship);
    print_shot();
}
