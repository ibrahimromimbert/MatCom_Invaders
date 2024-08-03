#include "objects.h"
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>

Object* make_obj(char* title, char* design, Point start, enum object_type type)
{
    Object* obj = malloc(sizeof(Object));
    obj->position = start;
    obj->design = design;
    obj->title = title; //falta copiar a memoria
    obj->life = 1;
    obj->type = type;

    return obj;
}

void print_obj(Object* obj)
{
    mvprintw(obj->position.y, obj->position.x, "%s", obj->design);
}

void move_obj(Object* obj, mov_dir mov_dir)
{
    obj->position.x += mov_dir.x_dir;
    obj->position.y += mov_dir.y_dir;
}
