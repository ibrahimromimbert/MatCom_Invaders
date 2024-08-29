//
// Created by 18137 on 16/08/2024.
//

#include "enemies.h"
#include <stddef.h>
#include "linked_list.h"
#include "objects.h"
#include "curses.h"
#include "ship.h"

char* e1_title = "nibbler";
char* e1_model[] = {
    "   /\\",
    " :<[o]>:",
    "   \\/"
};

Object* create_enemie(char* title, Point start, char* design[], int model_size) //it creates the player's ship
{
    Object* obj = make_obj(title, design, start, enemie, model_size);
    obj->last_dir.x_dir = 1;
    obj->last_dir.y_dir = 0;
    return obj;
}

void append_node_enemie(Object* obj)
{
    Node* newNode = create_node(obj);
    if (enemies_head == NULL)
    {
        enemies_head = newNode;
        return;
    }
    Node* temp = enemies_head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void print_enemies(void)
{
    if (enemies_head != NULL)
    {
        print_list(enemies_head);
    }
}

void remove_node_enemie(Node* node)
{
    if (enemies_head == node)
    {
        enemies_head = node->next; //global
        free_node(node);
        return;
    }
    Node* head = enemies_head;
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        if (head == node)
        {
            temp->next = head->next;
            free_node(head);
            return;
        }
    }
}

void create_enemies_group(int count)
{
    int x = 0;
    int y = 0;
    Point point = {.x = x, .y = y};
    for (int i = 0; i < count; i++)
    {
        Object* enemie = create_enemie(e1_title, point, e1_model, 3);
        append_node_enemie(enemie);
        point.x += 10; //POSIBLE CAMBIO
    }
}

int pass_limit()
{
    int count = 0;
    Node* temp = enemies_head;
    while (temp->next != NULL)
    {
        count++;
        if (temp->obj->position->y < 10) //POSIBLE CHANGE
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void enemies_deployment(void)
{
    int c;
    if (enemies_head == NULL)
    {
        create_enemies_group(MAX_ENEMIES_COUNT / 4);
    }
    else if ((c = pass_limit()) > 0) //POSIBLEMENTE MAL
    {
        int x = MAX_ENEMIES_COUNT - c;
        int y = MAX_ENEMIES_COUNT / 4;
        create_enemies_group((x < y) ? x : y);
    }
}


void move_enemies(void)
{
    if (enemies_head != NULL)
    {
        Node* temp = enemies_head;
        mov_dir mov = temp->obj->last_dir;
        while (temp != NULL)
        {
            if (temp->obj->position->y >= LINES)
            {
                Node* temp_remove = temp;
                temp = temp->next;
                remove_node_enemie(temp_remove);
            }

            else if (temp->obj->position->x >= COLS - 10 && temp->obj->last_dir.x_dir == 1)
            {
                temp->obj->last_dir.x_dir = 0;
                temp->obj->last_dir.y_dir = 1;
                mov.y_dir = 1;
                mov.x_dir = 0;
            }
            else if (temp->obj->position->x <= 0 && temp->obj->last_dir.x_dir == -1)
            {
                temp->obj->last_dir.x_dir = 0;
                temp->obj->last_dir.y_dir = 1;
                mov.y_dir = 1;
                mov.x_dir = 0;
            }
            else if (temp->obj->position->x <= 0 && temp->obj->last_dir.y_dir == 1)
            {
                temp->obj->last_dir.x_dir = 1;
                temp->obj->last_dir.y_dir = 0;
                mov.x_dir = 1;
                mov.y_dir = 0;
            }
            else if (temp->obj->position->x >= COLS - 10 && temp->obj->last_dir.y_dir == 1)
            {
                temp->obj->last_dir.x_dir = -1;
                temp->obj->last_dir.y_dir = 0;
                mov.x_dir = -1;
                mov.y_dir = 0;
            }

            move_obj(temp->obj, mov);
            temp = temp->next;
        }
    }
}

void validate_colition(void)
{
    Node* current_enemie = enemies_head;
    while (current_enemie != NULL)
    {
        int muerte = 0;
        Node* current_bullet = bullet_head;

        while (current_bullet != NULL)
        {
            for (int i = 0; i < current_enemie->obj->col_points_amount; i++)
            {
                if (current_enemie->obj->colition_points[i].x == current_bullet->obj->position->x &&
                    current_enemie->obj->colition_points[i].y == current_bullet->obj->position->y)
                {
                    Node* temp_remove_bullet = current_bullet;
                    current_bullet = current_bullet->next;
                    remove_node_bullet(temp_remove_bullet);

                    Node* temp_remove_enemie = current_enemie;
                    current_enemie = current_enemie->next;
                    remove_node_enemie(temp_remove_enemie);
                    muerte = 1;
                    break;

                    //remove_node_bullet(current_bullet);
                    //remove_node_enemie(current_enemie);
                }
            }
            if (muerte == 0)
            {
                current_bullet = current_bullet->next;
            }
        }
        if (muerte == 0)
        {
            current_enemie = current_enemie->next;
        }
    }
}
