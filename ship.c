#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include "ship.h"
#include "objects.c"

Object* create_ship(void)
{
    char* title = "Terminator";
    char* m_title = malloc(strlen(title)+1);
    if(m_title == NULL)
    {
        printw("Error al asignar memoria");
    }
    strcpy(m_title,title);
    char* design = "/\\";
    char* m_design = malloc(strlen(design)+1);
    if(m_design == NULL)
    {
        printw("Error al asignar memoria");
    }
    strcpy(m_design,design);
    Point start;
    start.x = COLS / 2;
    start.y = LINES/2;
    Object* obj = make_obj(m_title, m_design, start, ship);
    return obj;
}
