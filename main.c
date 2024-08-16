#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "objects.h"
#include "ship.h"
#include "print_frame.h"
#include "menu.h"
#include "linked_list.h"
#include "ship.c"
#include "print_frame.c"
#include "linked_list.c"
#include "menu.c"

#define DELAY 10000

int main()
{
    MEVENT event;
    int ch;

    // Inicializa ncurses
    initscr();
    raw();
    nodelay(stdscr, TRUE);
    noecho();
    keypad(stdscr, TRUE); //Entrada por teclado
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL); //Entrada por mouse
    curs_set(FALSE);


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
        printf("\033[?1003h\n"); // Habilitar reporte de posición del mouse
        ///////////////////Cerrar Area del juego///////////////////////////////////////
    }
    endwin(); // Salir del modo curses
    return 0;
}
