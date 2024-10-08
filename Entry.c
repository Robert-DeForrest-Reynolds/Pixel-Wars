#include <stdio.h>
#include <raylib.h>

#include "Structures.h"
#include "Creeps.h"

Resolution WindowResolution = { 800, 600 };
SpawnPoint SP = { 10, 10 };

void Initialize() {
    InitWindow(WindowResolution.Width, WindowResolution.Height, "Pixel Wars");
    SetTargetFPS(60);
}

int main() {
    printf("Welcome to the Thunderdome, bitches!");
    Initialize();
    Creep InitialCreep = Spawn_Creep(SP);
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircle(InitialCreep.CurrentPosition.X, InitialCreep.CurrentPosition.Y, 10, InitialCreep.CurrentColor);
            InitialCreep.Move(&InitialCreep);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}