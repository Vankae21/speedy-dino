#include "include/game.h"
#include "include/ui.h"

int main()
{
    InitWindow(WIDTH, HEIGHT, TITLE);

    SetTargetFPS(FPS);

    SetExitKey(KEY_NULL);

    start();
    ui_start();

    while(!WindowShouldClose())
    {
        update();
        ui_update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        late_update();
        ui_late_update();
        EndDrawing();
    }

    CloseWindow();
    
    finish();
    ui_finish();

    return 0;
}