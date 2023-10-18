#include "include/logic.h"

bool is_colliding(Vector2 a_pos, Vector2 a_size, Vector2 b_pos, Vector2 b_size)
{
    if(a_pos.x + a_size.x < b_pos.x ||
    a_pos.x > b_pos.x + b_size.x ||
    a_pos.y + a_size.y < b_pos.y ||
    a_pos.y > b_pos.y + b_size.y
    ) return false;
    return true;
}