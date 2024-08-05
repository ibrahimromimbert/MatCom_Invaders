#ifndef SHIP_H
#define SHIP_H

#include <ncurses.h>
#include "objects.h"

Object* bullet;

Object* create_ship(void);
void shot(int ch, MEVENT event, Object* ship);
void print_shot(void);

#endif //SHIP_H
