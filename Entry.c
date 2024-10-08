#include <stdio.h>
#include <raylib.h>

typedef struct Resolution { int Width; int Height; } Resolution;
typedef struct Position { int X; int Y; } Position;
typedef struct SpawnPoint { int X; int Y; } SpawnPoint;

Resolution WindowResolution = { 800, 600 };
SpawnPoint SP = { 10, 10 };

typedef struct Creep {
    int ID;
    int Health;
    char Name[20];
    char Type[20];
    Color CurrentColor;
    Position OriginPosition;
    Position CurrentPosition;
    void (*Move)(struct Creep*);
} Creep;

void Move(Creep* self){
    printf("I'm fucking moving");
}

Creep Spawn_Creep(SpawnPoint SP){
    Color CreepColor = { 155, 0, 85, 255 };
    Position Origin = { SP.X, SP.Y };
    Position CurrentPosition = { Origin.X, Origin.Y };
    Creep NewCreep = { 0, 50, "Basic Creep", "Basic", CreepColor, Origin, CurrentPosition, Move};
    return NewCreep;
}

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