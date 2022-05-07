// battle.h
#ifndef BATTLE_H
#define BATTLE_H

#include "skeletonart.h"
#include "inventory.h"

const int totalPlayerSkills = 5;
const int maxLengthOfSkillName = 20;

void battle(std::string playerActions[totalPlayerSkills][6], int playerDEF, int &playerHP, bool &enemyDefeated);

#endif