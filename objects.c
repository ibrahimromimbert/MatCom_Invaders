#include "objects.h"
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>

Object* make_obj(char* title, char* design[], Point start, enum object_type type, int model_size)
{
    Object* obj = malloc(sizeof(Object));

    Point* pos = malloc(sizeof(Point));
    if (pos == NULL)
    {
        printw("Error al asignar memoria");
    }
    else
    {
        pos->x = start.x;
        pos->y = start.y;
        obj->position = pos;
    }

    char* m_title = malloc(strlen(title) + 1);
    if (m_title == NULL)
    {
        printw("Error al asignar memoria");
    }
    strcpy(m_title, title);
    obj->title = m_title;

    obj->life = 1;
    obj->type = type;
    obj->model_size = model_size;
    char** m_design = malloc(model_size * sizeof(char*));
    if (m_design == NULL)
    {
        printw("Error al asignar memoria");
    }
    else
    {
        for (int i = 0; i < model_size; i++)
        {
            m_design[i] = malloc(strlen(design[i]) + 1);
            strcpy(m_design[i], design[i]);
        }
        obj->design = m_design;
    }
    return obj;
}

void print_obj(Object* obj)
{
    int y = obj->position->y;
    char** design = obj->design;
    for (int i = 0; i < obj->model_size; i++)
    {
        mvprintw(y + i, obj->position->x, "%s", design[i]);
    }
}

void move_obj(Object* obj, mov_dir mov_dir)
{
    obj->position->x += mov_dir.x_dir;
    obj->position->y += mov_dir.y_dir;
}

void free_obj(Object* obj)
{
    /*realses allocated memory*/

    // relase model's strs
    for (int i = 0; i < obj->model_size; i++)
    {
        free(obj->design[i]);
        //design[i] = NULL;
    }
    //free obj title
    free(obj->title);

    free(obj->position);

    //free model array
    free(obj->design);
    //design = NULL;

    //free obj structure
    free(obj);
    //obj = NULL;
}
