//
// Created by 18137 on 29/08/2024.
//
#ifndef BULLETS_P_C_H
#define BULLETS_P_C_H

#include <semaphore.h>
#include "objects.h"

#define MAX_VALUE 10

int variable = 0;
sem_t sem;

void* consumidor(Object* ship);
void* productor(void* arg);

#endif //BULLETS_P_C_H
