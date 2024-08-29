//
// Created by 18137 on 16/08/2024.
//

#ifndef ENEMIES_H
#define ENEMIES_H

#include "linked_list.h"

Node* enemies_head;
int MAX_ENEMIES_COUNT;
void enemies_deployment(void);
void print_enemies(void);
void move_enemies(void);
void validate_colition(void);

#endif //ENEMIES_H
