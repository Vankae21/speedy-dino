#include "include/dino.h"
#include "include/logic.h"
#include "include/game.h"
#include "stdlib.h"
#include "stdio.h"

Dino* init_dino(Vector2 pos, Vector2 size, Texture2D texture, float jump_force)
{
    Dino* dino = calloc(1, sizeof(Dino));

    dino->pos = pos;
    dino->size.x = size.x * SIZE_MULTIPLIER;
    dino->size.y = size.y * SIZE_MULTIPLIER;
    dino->jump_force = jump_force;
    dino->vel_y = 0.0f;
    dino->texture = texture;
    dino->frame = 0;
    dino->frame_time = 0.2f;
    dino->elapsed_frame_time = 0;
    dino->state = AIR;

    return dino;
}

void update_dino(Dino* dino)
{
    dino->pos.y += dino->vel_y;
    if(dino->pos.y + dino->size.y < PLATFORM_HEIGHT)
    {
        dino->vel_y += 30 * GetFrameTime();
        dino->state = AIR;
    }
    else
    {
        dino->pos.y = PLATFORM_HEIGHT - dino->size.y;
        dino->vel_y = 0;
        dino->state = RUNNING;

        if(begin && (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(0)))
        {
            dino->vel_y = -13;
        }
    }

    if(dino->state == AIR)
    {
        dino->frame = 0;
        dino->elapsed_frame_time = 0;
    }
    else if(dino->state == RUNNING)
    {
        if(dino->frame == 0)
            dino->frame = 1;
        if(dino->elapsed_frame_time < dino->frame_time) dino->elapsed_frame_time += GetFrameTime();
        else
        {
            dino->frame = dino->frame > 1 ? 1 : 2;
            dino->elapsed_frame_time = 0;
        }
    }
}
void draw_dino(Dino* dino)
{
    // DrawRectangle(dino->pos.x, dino->pos.y, dino->size.x, dino->size.y, RED);
    DrawTexturePro(dino->texture, (Rectangle){ dino->frame * 12 , 0, 12, 16}, (Rectangle){ dino->pos.x, dino->pos.y, dino->size.x, dino->size.y}, (Vector2){ 0, 0 }, 0, WHITE); 
}