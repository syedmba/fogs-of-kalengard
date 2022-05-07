#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
// #include <ncurses.h>


#include "battle.h"
#include "walk.h"
#include "printterrain.h"
#include "inventory.h"

using namespace std;

// added to header file inventory.h
// void Inventory();

// create inventory
string playerInventory[inventorySize] = {};
string playerEquipment[equipmentLimit] = {};

// number of monsters on the terrain
const int numMonsters = 20;

// player stats
int playerHP = 100;
int playerDEF = 10;
int playerATK = 10;

// array that contains the skills a player currently has
char playerActions[totalPlayerSkills][maxLengthOfSkillName] = {
    "blunt strike",
    "sword slash",
    "shield"
};


void giveRandomItem(string playerInventory[inventorySize]){
    srand(time(0));
    int itemIndex = rand() % ItemsListSize;
    for (int i = 0; i < inventorySize; i++){
        if (playerInventory[i] != ""){
            playerInventory[i] = Items[itemIndex][0];
            cout << "The defeated enemy dropped " << playerInventory[i] << ". The item has been added to slot " << i+1 << " of your inventory." << endl;
            return;
        }
    }
}


// this function allows the player to move across the terrain of any area in the game
// the area is passed as a 2d array called terrain with height and length stored as const values
// the function also accepts a 1D array that contains the terrain altitude at each column
// as well as a 1D array that contains the positions of monsters in the terrain
// this function takes input (arrow keys?) from the player
// then moves the player correspondingly
// and then updates the player position in the 2d array
void walk(char terrain[mapHeight][mapLength], int terrainHeight[mapLength], int monsterPositions[]){

    // usleep(5);
    // initscr();

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

    int enteredValue = 0;
    int steps = 0;
    char response;

    // cout << "Enter the number of steps you want to travel (negative to go back): ";
    
    // enteredValue = getch();
    // if (getchar() == '\033') { // if the first value is esc
    //     getchar(); // skip the [
    //     switch(getchar()) { // the real value
    //         case 'A':
    //             // code for arrow up
    //             break;
    //         case 'B':
    //             // code for arrow down
    //             break;
    //         case 'C':
    //             // code for arrow right
    //             steps = 1;
    //             break;
    //         case 'D':
    //             // code for arrow left
    //             steps = -1;
    //             break;
    //     }
    // }

    
    while (steps == 0){
        bool inventoryOpened = false;
        // cout << "Enter the number of steps you want to travel (negative to go back): ";
        cout << "Press an arrow key (<- or ->) and press ENTER to move: " << endl;
        
        enteredValue = getchar();
        if (enteredValue == '\033') { // if the first value is esc
            getchar(); 
            enteredValue = getchar();
            getchar();
            if (enteredValue == 'C'){
                cout << "You pressed the right arrow key" << endl;
                steps = 1;
            }
            else if (enteredValue == 'D'){
                cout << "You pressed the left arrow key" << endl;
                steps = -1;
            }
        } else if (enteredValue == 'e'){
            Inventory(playerInventory, playerEquipment, playerHP, playerATK, playerDEF);
            inventoryOpened = true;
        } else if (enteredValue == 'm'){
            // Map();
        } else {
            cout << "Wrong input" << endl;
            steps = 0;
        }
        
        for (int i = 0; i < mapLength; i++){
            cout << "-";
        }
        cout << endl;

        if (steps == 0 && !inventoryOpened){
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

    int playerRow = (mapHeight - 1) - (terrainHeight[steps + currentPlayerCol] + 1);


    printTerrain(terrain, steps + currentPlayerCol, playerRow);
    

    if (battleInitiated){

        bool enemyDefeated = false;
        battle(playerActions, playerDEF, playerHP, enemyDefeated);

        if (enemyDefeated){
            giveRandomItem(playerInventory);
            terrain[(mapHeight - 1) - (terrainHeight[nextMonsterPosition] + 1)][nextMonsterPosition] = 's';
        }

        printTerrain(terrain, steps + currentPlayerCol, playerRow);
    }


}