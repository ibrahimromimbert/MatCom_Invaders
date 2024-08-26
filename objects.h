#ifndef OBJECTS_H
#define OBJECTS_H


typedef struct Point
{
    /* A point structure for saving the characters and cordinate of an object*/
    int x, y;
} Point;

enum object_type { ship, s_bullet, enemie, e_bullet };

typedef struct movement_direction
{
    int x_dir;
    int y_dir;
} mov_dir;

typedef struct Object
{
    Point* position; //Position point
    char* title; //name of obj
    char** design; //string that represents de obj
    enum object_type type; //the type of the objec, ship, enemy, bullet...etc
    int life; // when it reaches 0 the obj is dead
    void* parent_list;
    int model_size;
    mov_dir last_dir;
} Object;



Object* make_obj(char* title, char* design[], Point start, enum object_type, int model_size);
void free_obj(Object* obj);
void print_obj(Object* obj);
void move_obj(Object* obj, mov_dir mov_dir);

#endif //OBJECTS_H
