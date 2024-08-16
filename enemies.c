//
// Created by 18137 on 16/08/2024.
//

#include "enemies.h"

char* e1_title = "nibbler";
char* e1_model[] = {
    "   /\\",
    " :<[o]>:",
    "   \\/"
};

Object* create_enemie(char* title, Point start, char* design[],int model_size) //it creates the player's ship
{
    Object* obj = make_obj(title, design, start, enemie, model_size);
    return obj;
}