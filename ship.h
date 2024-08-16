#ifndef SHIP_H
#define SHIP_H

#include <ncurses.h>
#include "objects.h"
#include "linked_list.h"


Node* bullet_head;
Object* bullet;  //quitar

Object* create_ship(void);
void shot(int ch, MEVENT event, Object* ship);
void print_shot(void);
void remove_node_bullet(Node* node);

#endif //SHIP_H
