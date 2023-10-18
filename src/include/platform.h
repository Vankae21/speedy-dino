#ifndef PLATFORM_H
#define PLATFORM_H
#include "raylib.h"

typedef struct Platform
{
    Vector2 pos;
    Vector2 size;
    Texture2D texture;
    float speed;
    float max_speed;
} Platform;

Platform* init_platform(Vector2 pos, Vector2 size, Texture2D texture, float speed, float max_speed);
void update_platform(Platform* platform);
void draw_platform(Platform* platform);

#endif