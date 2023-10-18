#include "include/obstacle.h"
#include "include/game.h"
#include <stdlib.h>
#include <time.h>

Obstacle* init_obstacle(Vector2 pos, Vector2 size, Texture2D texture)
{
    srand(rand());

    Obstacle* obstacle = calloc(1, sizeof(Obstacle));

    obstacle->pos.x = pos.x;
    obstacle->pos.y = pos.y - size.y * SIZE_MULTIPLIER;
    obstacle->size.x = size.x * SIZE_MULTIPLIER;
    obstacle->size.y = size.y * SIZE_MULTIPLIER;
    obstacle->texture = texture;
    obstacle->elapsed_time = 0;
    obstacle->reveal_time = (rand() % 11 + 5) / 10;

    return obstacle;
}

Obstacle** init_obstacles(Vector2 pos, Vector2 size, Texture2D texture, unsigned short obstacle_len)
{
    srand(time(0) % rand());

    Obstacle** obstacles = calloc(obstacle_len, sizeof(Obstacle*));

    for(unsigned short i = 0; i < obstacle_len; i++)
    {
        obstacles[i] = calloc(1, sizeof(Obstacle));
        obstacles[i]->pos.x = pos.x + i * (rand() % (WIDTH/2 - 192) + 192);
        obstacles[i]->pos.y = pos.y - size.y * SIZE_MULTIPLIER;
        obstacles[i]->size.x = size.x * SIZE_MULTIPLIER;
        obstacles[i]->size.y = size.y * SIZE_MULTIPLIER;
        obstacles[i]->texture = texture;
        obstacles[i]->elapsed_time = 0;
        obstacles[i]->reveal_time = (rand() % 11 + 5) / 10;
    }
    
    return obstacles;
}

void update_obstacle(Obstacle* obstacle, float speed)
{
    if(obstacle->pos.x + obstacle->size.x > 0)
        obstacle->pos.x -= speed;
    else
    {
        if(obstacle->elapsed_time > obstacle->reveal_time)
        {
            srand(time(0) % rand());
            obstacle->elapsed_time = 0;
            obstacle->reveal_time = (rand() % 11 + 15) / 10;
            obstacle->pos.x = WIDTH;
        }
        else
        {
            obstacle->elapsed_time += GetFrameTime();
        }
    }
}

void draw_obstacle(Obstacle* obstacle)
{
    // DrawRectangle(obstacle->pos.x, obstacle->pos.y, obstacle->size.x, obstacle->size.y, PURPLE);
    DrawTexturePro(obstacle->texture, (Rectangle){ 0, 0, obstacle->texture.width, obstacle->texture.height}, (Rectangle){ obstacle->pos.x, obstacle->pos.y, obstacle->size.x, obstacle->size.y}, (Vector2){ 0, 0}, 0, WHITE);
}
void reset_obstacles(Obstacle** obstacles, unsigned short length)
{
    for(int i = 0; i < length; i++)
    {
        obstacles[i]->elapsed_time = 0;
        obstacles[i]->reveal_time = (rand() % 11 + 5) / 10;
        obstacles[i]->pos.x = WIDTH + i * (rand() % (WIDTH/2 - 192) + 192);
    }
}