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

#define BLOCK   "\xE2\x96\x88"
#define PLAYER  "\xEC\x9B\x83"
#define FOG     "\xF0\x9F\x8C\xAB"
#define SWORDS  "\xE2\x9A\x94"
#define EGREEN  "\xF0\x9F\x8C\xB2"
#define DECID   "\xF0\x9F\x8C\xB3"
#define PALM    "\xF0\x9F\x8C\xB4"

using namespace std;



struct MonsterStats{
    int HP;
    int DEF;
    int ATK;
};

struct Ogre{
    MonsterStats stats;
};

struct Skeleton{
    MonsterStats stats;
};


// variable declarations

const int numRowsInArtI = 10;
const int numColsInArtI = 410;

// const int maxLengthOfSkillName = 20;
// const int totalPlayerSkills = 15;

// const int mapHeight = 20;
// const int mapLength = 100;
const int numMonsters = 19;

// int playerHP = 100;
// int playerDEF = 10;



// function prototypes

// void PrintTerrain(char terrain[mapHeight][mapLength]);
void generateMonsters(char terrain[mapHeight][mapLength], int terrainHeight[mapLength], int monsterPositions[numMonsters]);
void generateTerrain(char terrain[mapHeight][mapLength], int terrainHeight[mapLength]);
// void walk(char terrain[mapHeight][mapLength], int terrainHeight[mapLength], int monsterPositions[]);
void createPlanetAndStars(char array[]);


// char playerActions[totalPlayerSkills][maxLengthOfSkillName] = {
//     "blunt strike",
//     "sword slash",
//     "shield"
// };



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


void updateArray(){

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


void monsterEncounter(){

}


void collectiblePicked(){

}


// this function generateTerrain() initializes a random 2D terrain
// the first argument passed is a 2D array called terrain, which will contain the terrain generated randomly in this function
// the second argument passed is a 1D array called terrainHeight, which will contain the height of the terrain at each column
void generateTerrain(char terrain[mapHeight][mapLength], int terrainHeight[mapLength]){
    
    srand(time(0));
    const int maxHeight = 8;
    
    int startHeight = rand() % 5;
    cout << startHeight << endl;
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

void monsterfight(){

}




int dropLoot(){

    return 0;
}


// the main() function of the game
// this function contains the main framework of the game
int main(){

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

    bool walkOn = true; // static ??

    while (walkOn){
        walk(terrain, terrainHeight, monsterPositions);
    }

    // endwin();

    return 0;
}

