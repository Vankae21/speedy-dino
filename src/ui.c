#include "include/ui.h"
#include "include/game.h"
#include "include/button.h"
#include <stdio.h>
#include <stdlib.h>

Font font;
char score_text[32];

Button* start_button;
Button* replay_button;

void ui_start()
{
    font = LoadFontEx("assets/fonts/Pixelify.ttf", 32, NULL, 95);

    start_button = init_button((Vector2){ 32, 16}, (Vector2){ WIDTH/2 - 16 * SIZE_MULTIPLIER, HEIGHT/2 - 8 * SIZE_MULTIPLIER }, LoadTexture("assets/play_button.png"));
    replay_button = init_button((Vector2){ 32, 16}, (Vector2){ WIDTH/2 - 16 * SIZE_MULTIPLIER, HEIGHT/2 - 8 * SIZE_MULTIPLIER }, LoadTexture("assets/replay_button.png"));
}

void ui_update()
{
    if(!begin)
    {
        if(is_button_pressed(start_button))
        {
            begin = true;
        }
    }
    else if(begin && !lose)
    {
        sprintf(score_text, "Score: %.0f", score);
    }
    else if(lose)
    {
        if(is_button_pressed(replay_button))
        {
            replay();
        }
    }

}

void ui_late_update()
{
    if(!begin)
        draw_button(start_button);
    else if(begin && !lose)
    {
        DrawTextEx(font, score_text, (Vector2){20, 20} , 32, 0, BLACK);
    }
    else if(lose)
    {
        draw_button(replay_button);
    }
}

void ui_finish()
{
    free(start_button);
    UnloadFont(font);
}