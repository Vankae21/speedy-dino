#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "raylib.h"

typedef struct Obstacle
{
    Vector2 pos;
    Vector2 size;
    Texture2D texture;
    float elapsed_time;
    float reveal_time;
} Obstacle;

Obstacle* init_obstacle(Vector2 pos, Vector2 size, Texture2D texture);
Obstacle** init_obstacles(Vector2 pos, Vector2 size, Texture2D texture, unsigned short obstacle_len);
void update_obstacle(Obstacle* obstacle, float speed);
void draw_obstacle(Obstacle* obstacle);
void reset_obstacles(Obstacle** obstacles, unsigned short length);

#endif