#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "raylib.h"

typedef struct Background
{
    Vector2 pos;
    Vector2 size;
    Texture2D texture;
    float speed;
    float max_speed;
} Background;

Background* init_background(Vector2 pos, Vector2 size, Texture2D texture, float speed, float max_speed);
void update_background(Background* background);
void draw_background(Background* background);

#endif