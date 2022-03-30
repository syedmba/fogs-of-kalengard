#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <ncurses.h>


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

    usleep(5);
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

    int enteredValue;
    int steps = 0;

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
        // cout << "Enter the number of steps you want to travel (negative to go back): ";
        cout << "Press an arrow key (<- or ->) and press ENTER to move: \r";
        // printw("Press an arrow key (<- or ->) and press ENTER to move: ");
        // refresh();
        if (getch() == '\033') { // if the first value is esc
            getch(); // skip the [
            // switch(getchar()) { // the real value
            //     // case 'A':
            //     //     // code for arrow up
            //     //     break;
            //     // case 'B':
            //     //     // code for arrow down
            //     case 'C':
            //         // code for arrow right
            //         steps = 1;
            //         cout << endl;
            //         break;
            //     case 'D':
            //         // code for arrow left
            //         steps = -1;
            //         cout << endl;
            //         break;
            // }
            enteredValue = getch();
            // getch(); // so that it doesn't take an extra empty input and print the terrain twice
            if (enteredValue == 'C'){
                cout << "You pressed the right arrow key\r" << endl;
                steps = 1;
            }
            else if (enteredValue == 'D'){
                cout << "You pressed the left arrow key\r" << endl;
                steps = -1;
            }
            else {
                cout << "Wrong input\r" << endl;
                steps = 0;
            }
        }
        
        for (int i = 0; i < mapLength; i++){
            cout << "-";
        }
        cout << endl;
        if (steps == 0){
            cout << steps << endl;
            cout << "When in Kalengard, it's wise to keep moving...\r" << endl;
        }
    }

    // check to see whether player encounters world border or monster when attempting the input number of steps
    if ((steps + currentPlayerCol >= nextMonsterPosition) && (terrain[(mapHeight - 1) - (terrainHeight[nextMonsterPosition] + 1)][nextMonsterPosition] == 'm')){
        steps = nextMonsterPosition - currentPlayerCol - 1;
        // system("clear");
        
        cout << "You encountered a monster at " << steps << " steps and cannot go any further.\r" << endl;
        battleInitiated = true;
    }
    else if (steps + currentPlayerCol >= mapLength){
        steps = mapLength - currentPlayerCol - 1;
        // system("clear");
        // refresh();
        
        cout << "You have reached the right world border at " << steps << " steps and cannot go any further.\r" << endl;
    }
    else if (steps + currentPlayerCol < 0){
        steps = -currentPlayerCol;
        // system("clear");
        // refresh();
        
        cout << "You have reached the left world border at " << -steps << " steps and cannot go any further.\r" << endl;
    }
    
    // endwin();
    // initscr();

    terrain[currentPlayerRow][currentPlayerCol] = 's';
    terrain[(mapHeight - 1) - (terrainHeight[steps + currentPlayerCol] + 1)][steps + currentPlayerCol] = 'p';

    int playerRow = (mapHeight - 1) - (terrainHeight[steps + currentPlayerCol] + 1);

    clear();

    printTerrain(terrain, steps + currentPlayerCol, playerRow);

    if (battleInitiated){

        clear();
        // refresh();

        // endwin();
        // initscr();

        bool enemyDefeated = false;
        battle(playerActions, playerDEF, playerHP, enemyDefeated);
        // cout << enemy_defeated;
        if (enemyDefeated){
            terrain[(mapHeight - 1) - (terrainHeight[nextMonsterPosition] + 1)][nextMonsterPosition] = 's';
        }
        // system("clear");
        // refresh();
        // endwin();
        // initscr();

        clear();

        printTerrain(terrain, steps + currentPlayerCol, playerRow);
    }

    // endwin();

}