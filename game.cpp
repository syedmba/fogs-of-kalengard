#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <string>
// #include <ncurses.h>
#include <stdlib.h>
// #include <unistd.h>

#include "walk.h"
#include "battle.h"
#include "printterrain.h"
#include "inventory.h"
#include "npcdialogueone.h"

#define BLOCK   "\xE2\x96\x88"
#define PLAYER  "\xEC\x9B\x83"
#define FOG     "\xF0\x9F\x8C\xAB"
#define SWORDS  "\xE2\x9A\x94"
#define EGREEN  "\xF0\x9F\x8C\xB2"
#define DECID   "\xF0\x9F\x8C\xB3"
#define PALM    "\xF0\x9F\x8C\xB4"

using namespace std;


struct Player{
    
};


// variable declarations

const int numRowsInArtI = 10;
const int numColsInArtI = 410;

// const int maxLengthOfSkillName = 20;
// const int totalPlayerSkills = 15;

// const int mapHeight = 20;
// const int mapLength = 100;
// const int numMonsters = 19;

// int playerHP = 100;
// int playerDEF = 10;



// function prototypes

// void PrintTerrain(char terrain[mapHeight][mapLength]);
// void walk(char terrain[mapHeight][mapLength], int terrainHeight[mapLength], int monsterPositions[]);
void createPlanetAndStars(char array[]);


// char playerActions[totalPlayerSkills][maxLengthOfSkillName] = {
//     "blunt strike",
//     "sword slash",
//     "shield"
// };


// unused
void createPlanetAndStars(char array[numRowsInArtI][numColsInArtI]){

    string planet[numRowsInArtI] = {
    "        ~+                               ", 
    "                 *       +               ",
    "           '                  |          ",
    "       ()    .-.,=\"\'\'\"=.    - o -        ",
    "             '=/_       \\     |          ",
    "          *   |  '=._    |               ",
    "               \\     `=./`,        '     ",
    "            .   '=.__.=' `='      *      ",
    "   +                         +           ",
    "        O      *        '       .        "
    };

    char planetAndStars[numRowsInArtI][numColsInArtI] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '~', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', '(', ')', ' ', ' ', ' ', ' ', '.', '-', '.', ',', '=', '"', '`', '`', '"', '=', '.', ' ', ' ', ' ', ' ', '-', ' ', 'o', ' ', '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '=', '/', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '|', ' ', ' ', '\'', '=', '.', '_', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', '`', '=', '.', '/', '`', ',', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', ' ', ' ', ' ', '\'', '=', '.', '_', '_', '.', '=', '\'', ' ', '`', '=', '\'', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    for (int i = 0; i < numRowsInArtI; i++){
        for (int j = 0; j < numColsInArtI; j++){
            array[i][j] = planetAndStars[i][j];
        }
    }
}


// void printTerrain(char terrain[mapHeight][mapLength]){

//     for (int i = 0; i < mapHeight; i++){
//         for (int j=0; j < mapLength; j++){
//             if (terrain[i][j] == 'b'){
//                 cout << BLOCK;
//             }
//             else if(terrain[i][j] == 'p'){
//                 cout << PLAYER;
//             }
//             else if (terrain[i][j] == 's'){
//                 cout << " ";
//             }
//             else if (terrain[i][j] == 'm'){
//                 cout << "?";
//             }
//         }
//         cout << endl;
//     }
    
//     for (int times = 0; times < 1; times++){
//         for (int i = 0; i < mapLength; i++){
//             cout << "-";
//         }
//         cout << endl;
//     }
    

// }




// the main() function of the game
// this function contains the main framework of the game
int main(){

    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "                               F O G S    O F    K A L E N G A R D" << endl;
    cout << "                       M I A S M A    O F    T H E    D E M O N    K I N G" << endl;
    cout << "                C H A P T E R    1    :    T H E    E T E R N A L    B A T T L E S" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;

    getchar();

    initiateDialogue("Knight Commander Drakyn", 0);

    // initscr();

    char terrain[mapHeight][mapLength] = {};
    int terrainHeight[mapLength] = {};
    int monsterPositions[numMonsters] = {};

    // space = 's'
    // player = 'p
    // block = 'b'
    // water? monster? collectible?


    // cout << terrain[0]<< endl;

    for (int i = 0; i < mapHeight; i++){
        for (int j=0; j < mapLength; j++){
            terrain[i][j] = 's';
        }
    }

    generateTerrain(terrain, terrainHeight);
    generateMonsters(terrain, terrainHeight, monsterPositions);

    // clear();
    // refresh();

    printTerrain(terrain, 0, mapHeight - terrainHeight[0] - 2);

    // int test;

    // cin >> test;

    // refresh();

    // usleep(5);

    static bool walkOn = true; // static ??

    while (walkOn){
        walk(terrain, terrainHeight, monsterPositions, walkOn);
    }

    // endwin();

    return 0;
}

