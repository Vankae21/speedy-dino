#include "include/platform.h"
#include "include/game.h"
#include "stdlib.h"

Platform* init_platform(Vector2 pos, Vector2 size, Texture2D texture, float speed, float max_speed)
{
    Platform* platform = calloc(1, sizeof(Platform));

    platform->pos = pos;
    platform->size.x = size.x * SIZE_MULTIPLIER;
    platform->size.y = size.y * SIZE_MULTIPLIER;
    platform->texture = texture;
    platform->speed = speed;
    platform->max_speed = max_speed;

    return platform;
}
void update_platform(Platform* platform)
{
    if(begin && platform->speed < platform->max_speed)
        platform->speed += SPEED_INCREASER * GetFrameTime();
        
    if(platform->pos.x + WIDTH > 0)
    {
        platform->pos.x -= platform->speed;
    }
    else
    {
        platform->pos.x = 0;
    }
}
void draw_platform(Platform* platform)
{
    DrawTexturePro(platform->texture, (Rectangle){ 0, 0, platform->texture.width, platform->texture.height}, (Rectangle){ platform->pos.x, platform->pos.y, platform->size.x, platform->size.y}, (Vector2){0, 0}, 0, WHITE);
}