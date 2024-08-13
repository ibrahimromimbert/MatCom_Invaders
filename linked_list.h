//
// Created by 18137 on 06/08/2024.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "objects.h"

// Definición de la estructura del nodo de la lista enlazada
typedef struct Node
{
    Object* obj; // El objeto que almacenamos
    struct Node* next; // Puntero al siguiente nodo
} Node;

Node* create_node(Object* obj);
void append_node(Node* head, Object* obj);
void print_list(Node* head);
void free_node(Node* node);
void free_list(Node* head);
void remove_node(Node* head, Node* node);

#endif //LINKED_LIST_H
