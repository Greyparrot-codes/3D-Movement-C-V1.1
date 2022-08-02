#include <iostream>
#include <math.h>
#include <string>
#include "raylib.h"

using namespace std;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 650;

    float CX = 15.00;
    float CY = 30.00;
    float CZ = -10.00;

    float hyporadius = 50.00;
    float distval = 1.00;
    float angle = 0.001;

    float X = 0.0f;
    float Z = 0.0f;

    float Xmove;
    float Zmove;

    float COLOR = 0;
    float Time = 0;

    InitWindow(screenWidth, screenHeight, "Movement Testing By[GreyParrotCodes]");

    SetTargetFPS(60);                       // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Texture2D BoardTexture = LoadTexture("Textures/Board.png");
    // Main game loop
    while (!WindowShouldClose())            // Detect window close button or ESC key
    {
        Camera camera = { { CX, CY, CZ }, { (CX+0.00000001f)+X, (CY), (CZ)+Z }, { 0.0f, 1.0f, 0.0f }, 80.0f, 0 };
        SetCameraMode(camera, CAMERA_FREE);
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);              // Update camera
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        if(angle >= 360.0f){
            angle == 0.01f;
        }
        if(angle <= 0.0f){
            angle == 360.0f;
        }
        if(IsKeyDown(KEY_RIGHT)){
            angle -= 0.05f;
        }
        if(IsKeyDown(KEY_LEFT)){
            angle += 0.05f;
        }
        if(IsKeyDown(KEY_W)){
            CX += Xmove;
            CZ += Zmove;
        }
        if(IsKeyDown(KEY_S)){
            CX -= Xmove;
            CZ -= Zmove;
        }
        if(IsKeyDown(KEY_D)){
            CX -= Zmove;
            CZ += Xmove;
        }
        if(IsKeyDown(KEY_A)){
            CX += Zmove;
            CZ -= Xmove;
        }
        if(IsKeyDown(KEY_UP)){
            CY += 1.5f;
        }
        if(IsKeyDown(KEY_DOWN)){
            CY -= 1.5f;
        }
        X = ((sin(angle)*distval) * hyporadius);
        Z = ((cos(angle)*distval) * hyporadius);
        Xmove = ((sin(angle))*(hyporadius/20));
        Zmove = ((cos(angle))*(hyporadius/20));
        COLOR = abs(sin(Time) * 255);
        Time += 0.01f;
        if(Time > 360.0f){
            Time = 0.0f;
        }
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawGrid(10,10.0f);
                DrawCubeTexture(BoardTexture,(Vector3){ 0.0f, 0.0f, 0.0f }, 100.0f, 3.0f, 100.0f, Color{255,255,255,255});
                DrawCube(Vector3{ 34.0f, 17.0f, 35.0f }, 30.0f, 30.0f, 30.0f, Color{COLOR,COLOR,COLOR,255});
            EndMode3D();


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
