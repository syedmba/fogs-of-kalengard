// battle.h
#ifndef BATTLE_H
#define BATTLE_H

#include "skeletonart.h"
#include "inventory.h"

const int totalPlayerSkills = 15;
const int maxLengthOfSkillName = 20;

void battle(char playerActions[totalPlayerSkills][maxLengthOfSkillName], int playerDEF, int &playerHP, bool &enemyDefeated);

#endif