#ifndef CREEP_H
#define CREEP_H

#include <raylib.h>

#include "Structures.h"

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

void Move(Creep* _){
    _->CurrentPosition.X += 1;
}

Creep Spawn_Creep(SpawnPoint SP){
    Color CreepColor = { 155, 0, 85, 255 };
    Position Origin = { SP.X, SP.Y };
    Position CurrentPosition = { Origin.X, Origin.Y };
    Creep NewCreep = { 0, 50, "Basic Creep", "Basic", CreepColor, Origin, CurrentPosition, Move};
    return NewCreep;
}

#endif