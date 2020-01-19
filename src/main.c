

/*******************************************************************************************
*
*   raylib [core] example - Initialize 3d camera mode
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;
    const int cardHeight = 290; // TODO: Check if we can get it via API from the loaded texture?
    const int cardWidth = 200; // TODO: Check if we can get it via API from the loaded texture?
    // Make the card go off the bottom of the screen
    // TODO: Make it go up/get bigger when the mouse is hovering over it.
    const int handPosition = screenHeight - cardHeight + 60;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera mode");
    
    // Load assets
    Texture2D cardTex = LoadTexture("../assets/placeholder_card.png");

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.type = CAMERA_PERSPECTIVE;                   // Camera mode type
 
    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    int cardsInHand = 5;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

                DrawGrid(10, 1.0f);

            EndMode3D();
            
            // Draw GUI
            // Draw card
            for (int i = 0; i < cardsInHand; i++) {
                float cardX = screenWidth/2 - ((cardWidth-80)*(cardsInHand-1)+cardWidth)/2 + (cardWidth-80)*i;
                DrawTextureEx(cardTex, (Vector2){cardX, handPosition}, 0.0f, 1.0f, WHITE);
            }

            DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(cardTex);

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

