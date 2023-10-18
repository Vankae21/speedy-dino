#ifndef DINO_H
#define DINO_H
#include "raylib.h"

typedef struct Dino
{
    enum
    {
        RUNNING,
        AIR
    } state;
    Vector2 pos;
    Vector2 size;
    Texture2D texture;
    float jump_force;
    float vel_y;
    unsigned short frame;
    float frame_time;
    float elapsed_frame_time;
} Dino;

Dino* init_dino(Vector2 pos, Vector2 size, Texture2D texture, float jump_force);
void update_dino(Dino* dino);
void draw_dino(Dino* dino);

#endif