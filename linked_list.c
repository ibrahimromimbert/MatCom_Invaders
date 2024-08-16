//
// Created by 18137 on 06/08/2024.
//

#include "linked_list.h"
#include <stdlib.h>
#include <curses.h>

// Función para crear un nuevo nodo
Node* create_node(Object* obj)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printw("Error al asignar memoria\n");
        exit(1);
    }
    newNode->obj = obj;
    newNode->next = NULL;
    return newNode;
}

// Función para agregar un nodo al final de la lista
void append_node(Node* head, Object* obj)
{
    Node* newNode = create_node(obj);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Función para imprimir la lista
void print_list(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        print_obj(temp->obj);
        temp = temp->next;
    }
}

void move_obj_from_list(Node* head, mov_dir dir)
{
    Node* temp = head;
    while (temp != NULL)
    {
        //Moverlo
        move_obj(temp->obj, dir);
        temp = temp->next;
    }
}

void free_node(Node* node)
{
    free(node->obj->title);
    free(node->obj->position);

    // Liberar memoria del modelo y puntos si es necesario
    for (int i = 0; i < node->obj->model_size; i++)
    {
        free(node->obj->design[i]);
    }
    free(node->obj->design);
    free(node->obj);
    free(node);
}

// Función para liberar la memoria de la lista
void free_list(Node* head)
{
    Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;

        free_node(temp);
    }
}

void remove_node(Node* head, Node* node)
{
    if (head == node)
    {
        head = node->next; //global
        free_node(node);
        return;
    }
    Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        if (head == node)
        {
            temp->next = head->next;
            free_node(head);
        }
    }
}
