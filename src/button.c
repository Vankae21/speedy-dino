#include "include/button.h"
#include <stdlib.h>

Button* init_button(Vector2 size, Vector2 pos, Texture2D texture)
{
    Button* button = calloc(1, sizeof(Button));

    button->size.x = size.x * SIZE_MULTIPLIER;
    button->size.y = size.y * SIZE_MULTIPLIER;
    button->pos = pos;
    button->texture = texture;

    return button;
}

bool is_button_pressed(Button* button)
{
    if(GetMousePosition().x < button->pos.x ||
    GetMousePosition().x > button->pos.x + button->size.x ||
    GetMousePosition().y < button->pos.y ||
    GetMousePosition().y > button->pos.y + button->size.y
    )
    {
        if(button->state == HOLD) button->state = STILL;
        return false;
    }
    if(IsMouseButtonPressed(0) && button->state == STILL)
    {
        button->state = HOLD;
    }
    else if(IsMouseButtonReleased(0) && button->state == HOLD)
    {
        button->state = STILL;
        return true;
    }
    return false;
}

void draw_button(Button* button)
{
    DrawTexturePro(button->texture, (Rectangle){ button->state * 32, 0 , 32, 16}, (Rectangle){ button->pos.x, button->pos.y, button->size.x, button->size.y}, (Vector2){ 0, 0}, 0, WHITE);
}