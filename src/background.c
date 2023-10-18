#include "include/background.h"
#include "include/game.h"
#include "stdlib.h"

Background* init_background(Vector2 pos, Vector2 size, Texture2D texture, float speed, float max_speed)
{
    Background* background = calloc(1, sizeof(Background));

    background->pos = pos;
    background->size.x = size.x * SIZE_MULTIPLIER;
    background->size.y = size.y * SIZE_MULTIPLIER;
    background->texture = texture;
    background->speed = speed;
    background->max_speed = max_speed;

    return background;
}
void update_background(Background* background)
{
    if(begin && background->speed < background->max_speed)
        background->speed += SPEED_INCREASER * GetFrameTime();
    
    if(background->pos.x + WIDTH > 0)
    {
        background->pos.x -= background->speed;
    }
    else
    {
        background->pos.x = 0;
    }
}
void draw_background(Background* background)
{
    DrawTexturePro(background->texture, (Rectangle){ 0, 0, background->texture.width, background->texture.height}, (Rectangle){ background->pos.x, background->pos.y, background->size.x, background->size.y}, (Vector2){0, 0}, 0, WHITE);
}