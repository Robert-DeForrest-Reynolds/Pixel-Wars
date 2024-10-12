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

void Move(Creep* _);
Creep* Spawn_Creep(SpawnPoint SP, int Direction);

#endif