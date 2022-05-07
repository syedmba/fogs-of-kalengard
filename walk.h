// walk.h


#ifndef WALK_H
#define WALK_H

#include "battle.h"
#include "printterrain.h"
#include "inventory.h"

// number of monsters on the terrain
const int numMonsters = 19;

void walk(char terrain[mapHeight][mapLength], int terrainHeight[mapLength], int monsterPositions[], bool &walkOn);
void giveRandomItem(std::string playerInventory[inventorySize]);
void generateMonsters(char terrain[mapHeight][mapLength], int terrainHeight[mapLength], int monsterPositions[numMonsters]);
void generateTerrain(char terrain[mapHeight][mapLength], int terrainHeight[mapLength]);

#endif
