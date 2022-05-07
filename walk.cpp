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


// player stats
double playerHP = 100.0;
double playerDEF = 10.0;
double playerATK = 10.0;

// array that contains the skills a player currently has
string playerActions[totalPlayerSkills][7] = {
    {"1", "Punch", "Blunt Strike", "Concuss", "Ultimate Smash", "Downfall of Judgement", "0"},
    {"1", "Sword Slash", "Two-Point Strike", "Flurry of Blades", "Titan's Crisscross", "Atomic Strike", "0"},
    {"1", "Protect", "Shield", "Sturdy Tank", "Unmoving Fortress", "Might of the Untouchable", "0"},
    {"1", "Kick", "Roundhouse Kick", "Triple Kick", "Devil's Anomalous Barrage", "Phaser Kick", "0"},
    {"1", "Rock Throw", "Flying Dagger", "Arrow Rain", "Twin Shuriken Dance", "Eclipsing Storm", "0"}
};

// stored as {LifeSteal, ATK, DEF}
double playerActionStats[totalPlayerSkills][6][3] = {
        {{0, 10, 0}, {0, 30, 0}, {0.001, 100, 10}, {0.005, 300, 50}, {0.01, 430, 60}},
        {{0, 30, 0}, {0, 90, 0}, {0.001, 250, 5}, {0.008, 460, 6}, {0.03, 530, 9}},
        {{0.001, 0, 30}, {0.005, 0, 60}, {0.01, 0, 150}, {0.04, 0, 300}, {0.06, 0, 400}},
        {{0, 15, 0}, {0, 40, 0}, {0, 120, 0}, {0, 370, 0}, {0.005, 470, 20}},
        {{0, 20, 0}, {0, 50, 0}, {0.002, 150, 0}, {0.009, 400, 0}, {0.01, 500, 0}}
};

// int playerActionDEF[totalPlayerSkills] = {
//     0,
//     0,
//     30
// };


void giveRandomItem(string playerInventory[inventorySize]){
    srand(time(0));
    int itemIndex = rand() % 35;
    for (int i = 0; i < inventorySize; i++){
        if (playerInventory[i] == ""){
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
void walk(char terrain[mapHeight][mapLength], int terrainHeight[mapLength], int monsterPositions[], bool &walkOn){

    if (walkOn == false){
        return;
    }

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
        cout << "Press an arrow key (<- or ->) and then press ENTER to move (e for INVENTORY): " << endl;
        
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
        
        cout << "You encountered a monster and cannot go any further." << endl;
        battleInitiated = true;
    }
    else if (steps + currentPlayerCol >= mapLength){
        steps = mapLength - currentPlayerCol - 1;
        
        cout << "You have reached the right world border and cannot go any further." << endl;
    }
    else if (steps + currentPlayerCol < 0){
        steps = -currentPlayerCol;
        
        cout << "You have reached the left world border and cannot go any further." << endl;
    }
    
    terrain[currentPlayerRow][currentPlayerCol] = 's';
    terrain[(mapHeight - 1) - (terrainHeight[steps + currentPlayerCol] + 1)][steps + currentPlayerCol] = 'p';

    int playerRow = (mapHeight - 1) - (terrainHeight[steps + currentPlayerCol] + 1);


    printTerrain(terrain, steps + currentPlayerCol, playerRow);
    cout << " | Player HP: " << playerHP << " | Player ATK: " << playerATK << " | Player DEF: " << playerDEF  << " | " << endl;
    

    if (battleInitiated){

        bool enemyDefeated = false;
        battle(playerActions, playerATK, playerDEF, playerHP, enemyDefeated, playerInventory, playerEquipment, playerActionStats);

        if (enemyDefeated){
            giveRandomItem(playerInventory);
            terrain[(mapHeight - 1) - (terrainHeight[nextMonsterPosition] + 1)][nextMonsterPosition] = 's';
        }

        printTerrain(terrain, steps + currentPlayerCol, playerRow);
        cout << " | Player HP: " << playerHP << " | Player ATK: " << playerATK << " | Player DEF: " << playerDEF  << " | " << endl;
    }

    if (playerHP <= 0){
        cout << endl;
        cout << "You have died in adventure and will be revived and sent back in time to the beginning. Do not lose hope..." << endl;
        cout << "G A M E    O V E R" << endl;
        walkOn = false;
        return;
    }


    if (terrain[(mapHeight - 1) - (terrainHeight[monsterPositions[0]] + 1)][monsterPositions[0]] != 'm' && terrain[(mapHeight - 1) - (terrainHeight[monsterPositions[numMonsters-1]] + 1)][monsterPositions[numMonsters-1]] != 'm'){

        generateTerrain(terrain, terrainHeight);
        generateMonsters(terrain, terrainHeight, monsterPositions);

        printTerrain(terrain, 0, mapHeight - terrainHeight[0] - 2);

        walkOn = true;

        while (walkOn){
            walk(terrain, terrainHeight, monsterPositions, walkOn);
        }
    }


}


// this function generates a set number of monsters at random positions on the terrain of a game area
// the area is passed as a 2d array called terrain with height and length stored as const values
// the function also accepts a 1D array that contains the terrain altitude at each column
// as well as an empty 1D array called monsterPositions
// the function generates random column values for specific intervals
// the function then adds the symbol for monsters (?) to the terrain array at those columns
// monsterPositions will then be updated to contain the positions of monsters in the terrain
void generateMonsters(char terrain[mapHeight][mapLength], int terrainHeight[mapLength], int monsterPositions[numMonsters]){
    // monster classification: literal or ranked?
    // skeletons, ogres, demons, dark elves, wyverns, goblins, dryad?, dragon!, elemental beings

    // number of monsters = one every 6 steps

    // monster loot/drops may be affected by the type and difficulty of monster
   

    // int intervals[numMonsters] = {};

    // for (int i = 0; i < 20; i++){
    //     intervals[i] = 5*i;
    // }

    srand(time(0));

    for (int i = 0; i < numMonsters; i++){
        monsterPositions[i] = (rand() % 5) + (5*(i+1));
        terrain[(mapHeight - 1) - (terrainHeight[monsterPositions[i]] + 1)][monsterPositions[i]] = 'm';
    }

}


// this function generateTerrain() initializes a random 2D terrain
// the first argument passed is a 2D array called terrain, which will contain the terrain generated randomly in this function
// the second argument passed is a 1D array called terrainHeight, which will contain the height of the terrain at each column
void generateTerrain(char terrain[mapHeight][mapLength], int terrainHeight[mapLength]){
    
    srand(time(0));
    const int maxHeight = 8;
    
    int startHeight = rand() % 5;
    terrain[(mapHeight - 1) - startHeight][0] = 'b';

    int prevHeight = startHeight;
    int this_increment = 0;
    int random_increment_generator = 0;
    int i = 0;
    bool prevIncremented = true;

    while (i < mapLength){
        if (prevIncremented == false){
            random_increment_generator = rand() % 3;
            // random_increment_generator -= int(random_increment_generator);
            if (random_increment_generator >= 0 && random_increment_generator < 1){
                this_increment = -1;
            }
            else if (random_increment_generator >= 1 && random_increment_generator < 2){
                this_increment = 0;
            }
            else if (random_increment_generator >= 2 && random_increment_generator < 3){
                this_increment = 1;
            }

            if (prevHeight + this_increment <= maxHeight && prevHeight + this_increment >= 0){
                terrain[(mapHeight - 1) - (prevHeight + this_increment)][i] = 'b';
                prevHeight += this_increment;
            }
            else {
                terrain[(mapHeight - 1) - prevHeight][i] = 'b';
            }

            prevIncremented = true;
        }
        
        else if (prevIncremented == true){
            terrain[(mapHeight -1) - prevHeight][i] = 'b';
            prevIncremented = false;
        }

        terrainHeight[i] = prevHeight;

        for (int j = 0; j < prevHeight; j++){
            terrain[19 - j][i] = 'b';
        }

        i += 1;
    }

    terrain[mapHeight - startHeight - 2][0] = 'p';


}
