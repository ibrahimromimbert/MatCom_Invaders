//
// Created by 18137 on 29/08/2024.
//

#include "bullets_p_c.h"
#include "objects.h"
#include "ship.h"
#include <unistd.h>

void* productor(void* arg)
{
    while (1)
    {
        sleep(1); // Espera 1 segundo
        sem_wait(&sem); // Espera a obtener el semáforo

        if (variable < MAX_VALUE)
        {
            variable++;
        }

        sem_post(&sem); // Libera el semáforo
    }
    return NULL;
}

void* consumidor(Object* ship)
{
    sem_wait(&sem); // Espera a obtener el semáforo

    if (variable > 0)
    {
        variable--;
        // Y DISPARO
        Object* bullet = create_bullet(ship->position);
        append_node_bullet(bullet);
    }

    sem_post(&sem); // Libera el semáforo

    return NULL;
}
