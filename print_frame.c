#include <curses.h>
#include <ncurses.h>
#include "print_frame.h"

#include "enemies.h"
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
    if (bullet_head != NULL)
    {
        Node* temp = bullet_head;
        mov_dir mov = {.y_dir = -1};
        while (temp != NULL)
        {
            if (temp->obj->position->y <= 1)
            {
                Node* temp_remove = temp;
                temp = temp->next;
                remove_node_bullet(temp_remove);
            }
            else
            {
                move_obj(temp->obj, mov);
                temp = temp->next;
            }
        }
    }
}

void print_global_frame(int ch, MEVENT event, global_environement* game)
{
    clear();
    move_ship(ch, event, game->ship);
    move_bullet();
    enemies_deployment();
    move_enemies();
    shot(ch, event, game->ship);
    print_obj(game->ship);
    print_enemies();
    print_shot();
    validate_colition();
}
