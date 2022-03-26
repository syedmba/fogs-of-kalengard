// walk.h


#ifndef WALK_H
#define WALK_H

#include "battle.h"

const int mapHeight = 20;
const int mapLength = 100;

void walk(char terrain[mapHeight][mapLength], int terrainHeight[mapLength], int monsterPositions[]);

#endif
