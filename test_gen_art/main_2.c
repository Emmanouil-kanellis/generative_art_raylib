#include <stdio.h>
#include "raylib.h"

#include <stdlib.h>  
#include <string.h>
#include "memory_region.h"

#define NUMBER_OF_POINTS 30

int main(void)
{
    const int dimentions = 600;
    InitWindow(dimentions, dimentions, "Tiling");
    SetTargetFPS(1);


    
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
            
            for(size_t width=0; width < dimentions; width += dimentions/NUMBER_OF_POINTS) {
                for (size_t height=0; height < dimentions; height += dimentions/NUMBER_OF_POINTS)
                {
                    DrawCircleV((Vector2) {.x= width, .y=height}, 2, BLACK);
                }
            }
            
            ClearBackground(RAYWHITE);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
