#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <string>
#include "battle.h"
#include "walk.h"
#include "printterrain.h"

using namespace std;


const int numMonsters = 20;

int playerHP = 100;
int playerDEF = 10;

char playerActions[totalPlayerSkills][maxLengthOfSkillName] = {
    "blunt strike",
    "sword slash",
    "shield"
};

void walk(char terrain[mapHeight][mapLength], int terrainHeight[mapLength], int monsterPositions[]){

    bool battleInitiated = false;

    int currentPlayerRow = 0;
    int currentPlayerCol = 0;
    int nextMonsterPosition = 99;
    int nextMonsterIndex = 19;

    for (int i = 0; i < mapHeight; i++){
        for (int j=0; j < mapLength; j++){
            if (terrain[i][j] == 'p'){
                currentPlayerRow = i;
                currentPlayerCol = j;
                break;
            }
        }
    }

    for (int i = 0; i < numMonsters; i++){
        if (monsterPositions[i] > currentPlayerCol){
            nextMonsterPosition = monsterPositions[i];
            break;
        }
    }


    int steps = 0;
    while (steps == 0){
        cout << "Enter the number of steps you want to travel (negative to go back): ";
        cin >> steps;
        for (int i = 0; i < mapLength; i++){
            cout << "-";
        }
        cout << endl;
        if (steps == 0){
            cout << "When in Kalengard, it's wise to keep moving..." << endl;
        }
    }

    // check to see whether player encounters world border or monster when attempting the input number of steps
    if ((steps + currentPlayerCol >= nextMonsterPosition) && (terrain[(mapHeight - 1) - (terrainHeight[nextMonsterPosition] + 1)][nextMonsterPosition] == 'm')){
        steps = nextMonsterPosition - currentPlayerCol - 1;
        cout << "You encountered a monster at " << steps << " steps and cannot go any further." << endl;
        battleInitiated = true;
    }
    else if (steps + currentPlayerCol >= mapLength){
        steps = mapLength - currentPlayerCol - 1;
        cout << "You have reached the right world border at " << steps << " steps and cannot go any further." << endl;
    }
    else if (steps + currentPlayerCol < 0){
        steps = -currentPlayerCol;
        cout << "You have reached the left world border at " << -steps << " steps and cannot go any further." << endl;
    }
    

    terrain[currentPlayerRow][currentPlayerCol] = 's';
    terrain[(mapHeight - 1) - (terrainHeight[steps + currentPlayerCol] + 1)][steps + currentPlayerCol] = 'p';

    printTerrain(terrain);

    if (battleInitiated){

        bool enemyDefeated = false;
        battle(playerActions, playerDEF, playerHP, enemyDefeated);
        // cout << enemy_defeated;
        if (enemyDefeated){
            terrain[(mapHeight - 1) - (terrainHeight[nextMonsterPosition] + 1)][nextMonsterPosition] = 's';
        }
        printTerrain(terrain);
    }

}