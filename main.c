#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "objects.h"
#include "ship.h"
#include "print_frame.h"
#include "ship.c"
#include "print_frame.c"

#define DELAY 1000

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
    /////////////////Area del juego///////////////////////////////////

    printf("\033[?1003h\n"); // Habilitar reporte de posición del mouse

    ////////////Inicializar los elementos////////

    Object* ship = create_ship(); //La nave del jugador
    global_environement* game = malloc(sizeof(global_environement));
    game->ship = ship;

    ///Fin de las inicializaciones///

    while ((ch = getch()) != 'q')
    {

        print_global_frame(ch, event, game);

        refresh(); //Pintar en pantalla
        usleep(DELAY); //Esperar para volver a actualizar
    }
    printf("\033[?1003l\n"); // Deshabilitar reporte de posición del mouse

    ///////////////////Cerrar Area del juego///////////////////////////////////////
    endwin(); // Salir del modo curses
    return 0;
}
