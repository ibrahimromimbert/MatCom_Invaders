//
// Created by 18137 on 16/08/2024.
//

#include "menu.h"
#include <curses.h>
#include <stdlib.h>
#include <string.h>

void draw_menu()
{

    //Definir colores
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

    clear();

    int height = LINES;
    int width = COLS;


    const char *title = "MATCOM INVADERS";
    const char *subtitle = "by Abraham & Richard";
    const char *option1 = "S - Empezar Partida";
    const char *option2 = "E - Salir del juego";
    const char *instructions = "Presione E o S para elegir una opción.";

    int titleX = (width - strlen(title)) / 2;
    int titleY = height/4;

    int subtitleX = (width - strlen(subtitle)) / 2;
    int subtitleY = titleY + 2;

    int option1X = (width - strlen(option1)) / 2;
    int option1Y = subtitleY + 10;

    int option2X = (width - strlen(option2)) / 2;
    int option2Y = option1Y + 1;

    int instructionsX = (width - strlen(instructions)) / 2;
    int instructionsY = option2Y + 2;

    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    mvprintw(titleY, titleX, "%s", title);
    attroff(COLOR_PAIR(1));
    attroff(A_BOLD);

    attron(COLOR_PAIR(2));
    mvprintw(subtitleY, subtitleX, "%s", subtitle);
    attroff(COLOR_PAIR(2));

    mvprintw(option1Y, option1X, "%s", option1);
    mvprintw(option2Y, option2X, "%s", option2);

    mvprintw(instructionsY, instructionsX, "%s", instructions);

    // Refrescar la pantalla para mostrar los cambios
    refresh();
}

char menu()
{

    char opcion;

    draw_menu();
    while(1)
    {
        opcion = getch();
        if(opcion == 'S' || opcion == 's')
        {
            break;
        }
        else if (opcion == 'E' || opcion == 'e')
        {
           // printf("\033[?1003l\n"); // Deshabilitar reporte de posición del mouse
            //endwin(); // Salir del modo curses
            //exit(0);
            break;
        }
    }
    return opcion;
}

int pause_menu()
{

    char opcion;

    int height = LINES;
    int width = COLS;
    move((LINES)-3, 0);
    addstr("PAUSA");

    const char *option1 = "1 - Reanudar Partida";
    const char *option2 = "2 - Ir al menú principal del juego";
    const char *option3 = "3 - Salir del juego";
    const char *instructions = "Presione [1,2,3] para elegir una opción.";

    int option1X = (width - strlen(option1)) / 2;
    int option1Y = height/4 + 10;

    int option2X = (width - strlen(option2)) / 2;
    int option2Y = option1Y + 1;

    int option3X = (width - strlen(option3)) / 2;
    int option3Y = option2Y + 1;

    int instructionsX = (width - strlen(instructions)) / 2;
    int instructionsY = option3Y + 2;

    mvprintw(option1Y, option1X, "%s", option1);
    mvprintw(option2Y, option2X, "%s", option2);
    mvprintw(option3Y, option3X, "%s", option3);

    mvprintw(instructionsY, instructionsX, "%s", instructions);

    refresh();

    while (1)
    {
        opcion = getch();
        if (opcion == '1')
        {
            return 1;
        }
        else if (opcion == '2')
        {
            return 2;
        }
        else if(opcion == '3')
        {
            printf("\033[?1003l\n"); // Deshabilitar reporte de posición del mouse
            endwin();                // Salir del modo curses
            exit(0);
        }
    }
}