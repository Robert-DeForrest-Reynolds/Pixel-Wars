#ifndef CREEP_H
#define CREEP_H

#include <string.h>
#include <raylib.h>

#include "Structures.h"

typedef struct Creep {
    int ID;
    int Health;
    char Name[20];
    char Type[20];
    int Direction; // -1 is left, 1 is right
    Color CurrentColor;
    Position OriginPosition;
    Position CurrentPosition;
    int Size;
    void (*Move)(struct Creep*);
} Creep;

void Move(Creep* _){ _->CurrentPosition.X += _->Direction; }

Creep* Spawn_Creep(SpawnPoint SP, int Direction){
    Creep* NewCreep = (Creep*)malloc(sizeof(Creep));
    if (!NewCreep) { return NULL; }
    NewCreep->ID = 0;
    NewCreep->Health = 50;
    strcpy(NewCreep->Name, "Basic Creep");
    strcpy(NewCreep->Type, "Basic");
    NewCreep->Direction = Direction;
    NewCreep->CurrentColor = (Color){ 155, 0, 85, 255 };
    NewCreep->OriginPosition = (Position){ SP.X, SP.Y };
    NewCreep->CurrentPosition = NewCreep->OriginPosition;
    NewCreep->Size = 10;
    NewCreep->Move = Move;
    return NewCreep;
}

#endif