#include <stdlib.h>
#include "Creeps.h"

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