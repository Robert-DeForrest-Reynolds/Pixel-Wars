#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <string.h>

#include "Structures.h"
#include "SourceFileRead.h"

#define MAX_INSTRUCTIONS 1024
#define MAX_LINE_LENGTH 1024

typedef struct InstructionList{
    char Commands[MAX_INSTRUCTIONS][MAX_LINE_LENGTH];
    int Count;
} InstructionList;

Resolution WindowResolution;

void LoadInstructions(const char *FileName, InstructionList *List) {
    FILE *File = fopen(FileName, "r");
    if (!File) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    List->Count = 0;

    while (fgets(List->Commands[List->Count], MAX_LINE_LENGTH, File) != NULL) {
        List->Commands[List->Count][strcspn(List->Commands[List->Count], "\n")] = 0; // Remove newline
        List->Count++;
        if (List->Count >= MAX_INSTRUCTIONS) {
            break; // Prevent overflow
        }
    }

    fclose(File);
}
void Create_Window(const char *WindowTitle, int Width, int Height) {
    WindowResolution.Width = Width;
    WindowResolution.Height = Height;
    InitWindow(WindowResolution.Width, WindowResolution.Height, "Pixel Wars");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
}

int main() {
    InstructionList instructionList;
    printf("Welcome to the Thunderdome, bitches!\n");
    LoadInstructions("Example.papple", &instructionList);
    for (int Iteration = 0; Iteration < instructionList.Count; Iteration++){
        printf("%s\n", instructionList.Commands[Iteration]);
    }
    return 0;
}   