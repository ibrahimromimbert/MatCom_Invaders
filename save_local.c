//
// Created by 18137 on 29/08/2024.
//

#include "save_local.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enemies.h"
#include "objects.h"
#include "linked_list.h"
#include "ship.h"

// Función para guardar la lista enlazada en un archivo
void saveLinkedList(Node* head, const char* filename)
{
    FILE* file = fopen(filename, "wb");
    if (!file)
    {
        perror("Failed to open file for writing");
        return;
    }

    Node* current = head;
    while (current)
    {
        // Guardar los datos del objeto en el archivo
        fwrite(current->obj->position, sizeof(Point), 1, file);
        int title_len = strlen(current->obj->title) + 1;
        fwrite(&title_len, sizeof(int), 1, file);
        fwrite(current->obj->title, sizeof(char), title_len, file);

        // Guardar el diseño
        fwrite(&current->obj->model_size, sizeof(int), 1, file);
        for (int i = 0; i < current->obj->model_size; i++)
        {
            int design_len = strlen(current->obj->design[i]) + 1;
            fwrite(&design_len, sizeof(int), 1, file);
            fwrite(current->obj->design[i], sizeof(char), design_len, file);
        }

        fwrite(&current->obj->type, sizeof(enum object_type), 1, file);
        fwrite(&current->obj->life, sizeof(int), 1, file);
        fwrite(&current->obj->last_dir, sizeof(mov_dir), 1, file);
        fwrite(&current->obj->col_points_amount, sizeof(int), 1, file);
        fwrite(current->obj->colition_points, sizeof(Point), current->obj->col_points_amount, file);

        current = current->next;
    }
    fclose(file);
}

// Función para cargar la lista enlazada desde un archivo
Node* loadLinkedList(const char* filename)
{
    FILE* file = fopen(filename, "rb");
    if (!file)
    {
        perror("Failed to open file for reading");
        return NULL;
    }

    Node* head = NULL;
    Node* tail = NULL;

    while (!feof(file))
    {
        Object* obj = malloc(sizeof(Object));
        obj->position = (Point*)malloc(sizeof(Point));
        fread(obj->position, sizeof(Point), 1, file);

        int title_len;
        fread(&title_len, sizeof(int), 1, file);
        obj->title = (char*)malloc(title_len * sizeof(char));
        fread(obj->title, sizeof(char), title_len, file);

        fread(&obj->model_size, sizeof(int), 1, file);
        obj->design = (char**)malloc(obj->model_size * sizeof(char*));
        for (int i = 0; i < obj->model_size; i++)
        {
            int design_len;
            fread(&design_len, sizeof(int), 1, file);
            obj->design[i] = (char*)malloc(design_len * sizeof(char));
            fread(obj->design[i], sizeof(char), design_len, file);
        }

        fread(&obj->type, sizeof(enum object_type), 1, file);
        fread(&obj->life, sizeof(int), 1, file);
        fread(&obj->last_dir, sizeof(mov_dir), 1, file);

        fread(&obj->col_points_amount, sizeof(int), 1, file);
        obj->colition_points = (Point*)malloc(obj->col_points_amount * sizeof(Point));
        fread(obj->colition_points, sizeof(Point), obj->col_points_amount, file);

        Node* newNode = create_node(obj);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    fclose(file);
    return head;
}

void save_game(void)
{
    saveLinkedList(enemies_head, "enemies_save.bin");
    saveLinkedList(bullet_head, "bullets_head.bin");
    free_list(enemies_head);
    free_list(bullet_head);
    //FALTA SALVAR LA NAVE y ESTADISTICAS
}

void load_game(void)
{
    //CARGAR NAVE Y STATS
    enemies_head = loadLinkedList("enemies_save.bin");
    bullet_head = loadLinkedList("bullets_head.bin");
}
