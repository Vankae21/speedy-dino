#include "include/game.h"
#include "stdlib.h"
#include "stdio.h"


Dino* dino;
Platform* platform;
Background* sky;
Background* parallax;
Obstacle** cactuses;

unsigned short cactus_len = 4;

float score = 0;

float platform_speed = 5, sky_speed = 1, parallax_speed = 3;

bool lose = false;
bool begin = false;

void start()
{
    dino = init_dino((Vector2){ 50, -16 * SIZE_MULTIPLIER }, (Vector2){ 12, 16}, LoadTexture("assets/dino.png"), 0);
    platform = init_platform((Vector2){ 0, HEIGHT - 64 }, (Vector2){ 400, 16 }, LoadTexture("assets/platform.png"), platform_speed, 9);
    sky = init_background((Vector2){ 0, 0 }, (Vector2){ 400, 98 }, LoadTexture("assets/sky.png"), sky_speed, 5);
    parallax = init_background((Vector2){ 0, HEIGHT - 64 - 128 }, (Vector2){ 400, 32 }, LoadTexture("assets/parallax.png"), parallax_speed, 7);
    cactuses = init_obstacles((Vector2){ WIDTH, PLATFORM_HEIGHT}, (Vector2){ 7, 12}, LoadTexture("assets/cactus.png"), cactus_len);
}

void update()
{
    if(lose) return;
    if(begin)
    {
        for(unsigned short i = 0; i < cactus_len; i++)
        {
            if(is_colliding(dino->pos, dino->size, cactuses[i]->pos, cactuses[i]->size))
            {
                lose = true;
                return;
            }
        }
        score += GetFrameTime() * platform->speed;
        update_dino(dino);
        update_platform(platform);
        for(unsigned short i = 0; i < cactus_len; i++)
        {
            update_obstacle(cactuses[i], platform->speed);
        }
        update_background(sky);
        update_background(parallax);

    }
    else
    {
        update_dino(dino);
        update_platform(platform);
        update_background(sky);
        update_background(parallax);
    }
}

void late_update()
{
    draw_background(sky);
    draw_background(parallax);
    draw_platform(platform);
    for(unsigned short i = 0; i < cactus_len; i++)
    {
        draw_obstacle(cactuses[i]);
    }
    draw_dino(dino);
}

void finish()
{
    free(dino);
    free(platform);
    free(sky);
    free(parallax);
}

void replay()
{
    dino->vel_y = 0;
    dino->pos.y = -16 * SIZE_MULTIPLIER;
    score = 0;

    platform->speed = platform_speed;
    sky->speed = sky_speed;
    parallax->speed = parallax_speed;

    reset_obstacles(cactuses, cactus_len);
    
    lose = false;
}