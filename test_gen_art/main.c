#include <stdio.h>
#include "raylib.h"

#include <stdlib.h>  
#include <string.h>
#include "memory_region.h"

typedef struct _Tile {
    Vector2 centerPoint;
    int baseSize;

} Tile_t;

void DrawLine_rand(Vector2 point, int size) {
    //if(1) {
    if(rand()%2) {
        //printf("x %f ",point.y - size);
        //printf("y %f \n",point.y + size);
        Vector2 start_h = { .x=point.x , .y=point.y - size};
        Vector2 finish_h = { .x=point.x , .y=point.y + size};
        DrawLineBezier(start_h,finish_h, 2.0, RED);


    }
    else {
        Vector2 start_v = { .x=point.x  - size , .y=point.y};
        Vector2 finish_v = { .x=point.x  + size , .y=point.y};
        DrawLineBezier(start_v,finish_v, 2.0, RED);
    }
}

void TilingRecursive(Vector2 point, int size, int level){

    if (level ==0) {
        DrawCircleV(point,2, BLACK);
        //DrawLine_rand(point, size);
    }
    else{
        level -= 1;
        size /= 2;
        
        TilingRecursive( (Vector2) {point.x - size, point.y - size}, size, level);
        TilingRecursive( (Vector2) {point.x + size, point.y + size}, size, level);
        TilingRecursive( (Vector2) {point.x - size, point.y + size}, size, level);
        TilingRecursive( (Vector2) {point.x + size, point.y - size}, size, level);
        
    }
}

void TilingRecursive_v2(Vector2 point, int size, int level){

    if (level ==0) {
        Tile_t tile = {.centerPoint = point, .baseSize = size};
        void *tileMemory = MemoryAllocate(sizeof(Tile_t));
        memcpy(tileMemory, &tile, sizeof(Tile_t));
        
    }
    else{
        level -= 1;
        size /= 2;
        
        TilingRecursive_v2( (Vector2) {point.x - size, point.y - size}, size, level);
        TilingRecursive_v2( (Vector2) {point.x + size, point.y + size}, size, level);
        TilingRecursive_v2( (Vector2) {point.x - size, point.y + size}, size, level);
        TilingRecursive_v2( (Vector2) {point.x + size, point.y - size}, size, level);
        
    }
}


int main(void)
{
    const int size = 700;
    // Region *region;
    
    
    // region = MemoryRegion();
    // TilingRecursive_v2((Vector2){size/2, size/2}, size/2, 5);
    // PrintMemoryRegion();
    
    // for(size_t i =0; i<region->size; i+= sizeof(Tile_t)){
    //     Tile_t currentTile = *(Tile_t *) (region->data + i);

    //     printf("x: %f y: %f ",currentTile.centerPoint.x, currentTile.centerPoint.y);
    //     printf("size %d\n",currentTile.baseSize);
        
    // }
    
    InitWindow(size, size, "Tiling");
    SetTargetFPS(1);


    int count = 0;
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
            
            TilingRecursive((Vector2){size/2, size/2},size/2,6);
            //  for(size_t i =0; i<region->size; i+= sizeof(Tile_t)){
            //     Tile_t currentTile = *(Tile_t *) (region->data + i);
            //     DrawCircleV(currentTile.centerPoint, 2, RED);
            //     //DrawLine_rand(currentTile.centerPoint, currentTile.baseSize);
            //     //printf("x: %f y: %f ",currentTile.centerPoint.x, currentTile.centerPoint.y);
            //     //printf("size %d\n",currentTile.baseSize);
        
            // }
            
            ClearBackground(RAYWHITE);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
