// walk.h


#ifndef WALK_H
#define WALK_H

#include "battle.h"
#include "printterrain.h"
#include "inventory.h"

void walk(char terrain[mapHeight][mapLength], int terrainHeight[mapLength], int monsterPositions[]);
void giveRandomItem(std::string playerInventory[inventorySize]);

#endif
