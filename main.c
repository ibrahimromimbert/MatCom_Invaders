#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "objects.h"
#include "ship.h"
#include "print_frame.h"
#include "menu.h"
#include "linked_list.h"
#include "ship.c"
#include "print_frame.c"
#include "linked_list.c"
#include "menu.c"
#include "enemies.h"
#include "enemies.c"
#include "bullets_p_c.h"
#include "bullets_p_c.c"

#define DELAY 5000

int main()
{
    MEVENT event;
    int ch;

    // Inicializa ncurses
    initscr();
    start_color();
    raw();
    nodelay(stdscr, TRUE);
    noecho();
    keypad(stdscr, TRUE); //Entrada por teclado
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL); //Entrada por mouse
    curs_set(FALSE);

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2,COLOR_GREEN, COLOR_BLACK);

    while (true)
    {
        char m = menu();
        if (m == 'E' || m == 'e')
        {
            break;
        }
        /////////////////Area del juego///////////////////////////////////
        printf("\033[?1003h\n"); // Habilitar reporte de posición del mouse

        ////////////Inicializar los elementos////////

        Object* ship = create_ship(); //La nave del jugador
        global_environement* game = malloc(sizeof(global_environement));
        game->ship = ship;
        MAX_ENEMIES_COUNT = 20;
        pthread_t hilo_productor;
        sem_init(&sem, 0, 1);
        pthread_create(&hilo_productor, NULL, productor, NULL);

        //////////Inicializar Areas de juego///////////////
        Enemies_Area.UP_lim = 0;
        Enemies_Area.Down_lim =LINES/2 ;
        Enemies_Area.Left_lim = 0;
        Enemies_Area.Right_lim = COLS-5;

        Ship_Area.UP_lim = LINES/2 ;
        Ship_Area.Down_lim = LINES;
        Ship_Area.Left_lim =0 ;
        Ship_Area.Right_lim = COLS-3;
        /////////////Fin de Area///////////


        ///Fin de las inicializaciones///

        while (true)
        {
            print_global_frame(ch, event, game);

            refresh();     // Pintar en pantalla
            usleep(DELAY); // Esperar para volver a actualizar
            if ((ch = getch()) == 'p' && pause_menu() == 2)
            {
                break;
            }
        }
        ///
        ///FALTA LIBERAR LA MEMORIA DESPUES DEL JUEGO;
        ///
        pthread_join(hilo_productor, NULL);
        sem_destroy(&sem); // Destruye el semáforo
        printf("\033[?1003h\n"); // Habilitar reporte de posición del mouse
        ///////////////////Cerrar Area del juego///////////////////////////////////////
    }
    endwin(); // Salir del modo curses
    return 0;
}
