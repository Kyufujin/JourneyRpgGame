#include "raylib.h"
#include "raymath.h"


int main(){

    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Kyufujiin Rpg Game");

    // var
    float speed =5;

    Texture2D map = LoadTexture("nature_tileset/WorldMap.png");
    Vector2 mapPos{0.0, 0.0};

    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knightPos{
        windowWidth/2.0f - 4.0f*(0.5f * (float)knight.width/6.0f),
        windowHeight/2.0f - 4.0f*(0.5f * (float)knight.height)
    };


    SetTargetFPS(60);

    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x -= 1.0;
        if(IsKeyDown(KEY_D)) direction.x += 1.0;
        if(IsKeyDown(KEY_W)) direction.y -= 1.0;
        if(IsKeyDown(KEY_S)) direction.y += 1.0;

        if(Vector2Length(direction) != 0.0)
        {
            // normalization of speed in diagonal direction
            mapPos = Vector2Subtract(mapPos,Vector2Scale(Vector2Normalize(direction), speed));
        }
        
        
        
        // draw a map
        DrawTextureEx(map, mapPos, 0.0, 3.0, WHITE);

        // draw a character
        Rectangle source{0.f, 0.f, (float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width/6.0f, 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);
        EndDrawing();
    }

    CloseWindow();

}