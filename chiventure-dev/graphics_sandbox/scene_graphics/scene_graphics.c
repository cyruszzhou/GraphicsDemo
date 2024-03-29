#include "scene_graphics.h"
#include "raylib.h"

/* See scene_graphics.h*/
scene_graphics_t* new_scene_graphics(char* SceneName, char* ImagePath, Vector2 WindowPos,
                       Vector2 WindowSize, Vector2 SceneSize, Vector2 PlayerPosition)
{
    scene_graphics_t* s;
    s = malloc(sizeof(scene_graphics_t));
    s->SceneName=SceneName;
    s->ImagePath=ImagePath;
    s->WindowPos=WindowPos;
    s->WindowSize=WindowSize;
    s->SceneSize=SceneSize;
    s->PlayerPosition=PlayerPosition;

    return s;
    
}

/* See scene_graphics.h*/
int free_scene_graphics(scene_graphics_t* SceneGraphics)
{
    free(SceneGraphics);
    return SUCCESS;
}


/* See scene_graphics.h */
int draw_scene_graphics(scene_graphics_t* scene_graphics)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = scene_graphics->WindowSize.x;
    const int screenHeight = scene_graphics->WindowSize.y;

    InitWindow(screenWidth, screenHeight, "NSFW SCENE!!!");


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
           Texture2D scene = LoadTexture(scene_graphics->ImagePath);

        float ulxcoord = scene_graphics->PlayerPosition.x - (scene_graphics->SceneSize.x/2);
        float ulycoord = scene_graphics->PlayerPosition.y - (scene_graphics->SceneSize.y/2);
        Rectangle showScene = {ulxcoord, ulycoord, scene_graphics->SceneSize.x,scene_graphics->SceneSize.y};
        Vector2 drawPosition = {(screenWidth - scene_graphics->SceneSize.x)/2, (screenHeight - scene_graphics->SceneSize.y)/2};
        // Update
        //----------------------------------------------------------------------------------
        ulxcoord = scene_graphics->PlayerPosition.x - (scene_graphics->SceneSize.x/2);
        ulycoord = scene_graphics->PlayerPosition.y - (scene_graphics->SceneSize.y/2);
        Rectangle showScene = {ulxcoord, ulycoord, scene_graphics->SceneSize.x,scene_graphics->SceneSize.y};

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTextureRec(scene, showScene, drawPosition, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(scene);  // Unload scene texture

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return SUCCESS;
}
