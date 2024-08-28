#include "objects.h"
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
#include <string.h>

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
    // obj->col_points_amount = 1;
    int col_p_a = 0;
    int capacity = 1; //Primeramente solo un punto de colision
    obj->colition_points = malloc(capacity * sizeof(Point));
    if (obj->colition_points == NULL)
    {
        printw("Error al asignar memoria");
    }
    for (int i = 0; i < obj->model_size; i++)
    {
        int len = strlen(design[i]);
        for (int j = 0; j < len; ++j) //Recorro cada char del design
        {
            if (col_p_a >= capacity)
            {
                capacity *= 2;
                obj->colition_points = realloc(obj->colition_points, capacity * sizeof(Point));
            }
            if (obj->colition_points == NULL)
            {
                printw("Error al asignar memoria");
            }
            if (design[i][j] != ' ')
            {
                Point p = {.x = start.x + j, .y = start.y + i};
                obj->colition_points[col_p_a] = p;
                col_p_a++;
            }
        }
    }
    obj->col_points_amount = col_p_a - 1;
    return obj;
}

// void print_obj(Object* obj)
// {
//     int y = obj->position->y;
//     char** design = obj->design;
//     for (int i = 0; i < obj->model_size; i++)
//     {
//         mvprintw(y + i, obj->position->x, "%s", design[i]);
//     }
// }

void print_obj(Object* obj)
{
    int y = obj->position->y;
    char** design = obj->design;
    for (int i = 0; i < obj->model_size; i++)
    {
        int len = strlen(design[i]);
        for (int j = 0; j < len; ++j)
        {
            move(y+i, obj->position->x+j);
            if (design[i][j] != ' ')
            {
                printw("%c", design[i][j]);
            }
        }
    }
}

void move_obj(Object* obj, mov_dir mov_dir)
{
    obj->position->x += mov_dir.x_dir;
    obj->position->y += mov_dir.y_dir;
    for (int i = 0; i < obj->col_points_amount; ++i)
    {
        obj->colition_points[i].x += mov_dir.x_dir;
        obj->colition_points[i].y += mov_dir.y_dir;
    }
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

    free(obj->colition_points);

    //free obj structure
    free(obj);
    //obj = NULL;
}
