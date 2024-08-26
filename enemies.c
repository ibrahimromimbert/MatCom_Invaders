//
// Created by 18137 on 16/08/2024.
//

#include "enemies.h"

#include <stddef.h>

#include "linked_list.h"

char* e1_title = "nibbler";
char* e1_model[] = {
    "   /\\",
    " :<[o]>:",
    "   \\/"
};

Object* create_enemie(char* title, Point start, char* design[],int model_size) //it creates the player's ship
{
    Object* obj = make_obj(title, design, start, enemie, model_size);
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
        }
    }
}