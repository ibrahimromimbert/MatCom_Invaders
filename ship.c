#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include "ship.h"
#include "objects.c"

char* model[] = {
    "  ^  ",
    " /|\\ ",
    "/_|_\\"
                };

Object* create_ship(void)
{
    char* title = "Terminator";
    char* m_title = malloc(strlen(title)+1);
    if(m_title == NULL)
    {
        printw("Error al asignar memoria");
    }
    strcpy(m_title,title);
    Point start;
    start.x = COLS / 2;
    start.y = LINES/2;
    Object* obj = make_obj(m_title, model, start, ship,3);
    return obj;
}