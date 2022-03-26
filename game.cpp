#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <string>

#include "walk.h"
#include "battle.h"
#include "printterrain.h"

#define BLOCK   "\xE2\x96\x88"
#define PLAYER  "\xEC\x9B\x83"
#define FOG     "\xF0\x9F\x8C\xAB"

using namespace std;

const int numRowsInArtI = 10;
const int numColsInArtI = 410;

// const int maxLengthOfSkillName = 20;
// const int totalPlayerSkills = 15;


// const int mapHeight = 20;
// const int mapLength = 100;
const int numMonsters = 20;


// int playerHP = 100;
// int playerDEF = 10;


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
        monsterPositions[i] = (rand() % 5) + (5*i);
        terrain[(mapHeight - 1) - (terrainHeight[monsterPositions[i]] + 1)][monsterPositions[i]] = 'm';
    }

}


void monsterEncounter(){

}


void collectiblePicked(){

}


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


int main(){


    char terrain[mapHeight][mapLength] = {};
    int terrainHeight[mapLength] = {};
    int monsterPositions[numMonsters] = {};

    // space = 's'
    // player = 'p
    // block = 'b'
    // water? monster? collectible?


    cout << terrain[0]<< endl;

    for (int i = 0; i < mapHeight; i++){
        for (int j=0; j < mapLength; j++){
            terrain[i][j] = 's';
        }
    }

    generateTerrain(terrain, terrainHeight);
    generateMonsters(terrain, terrainHeight, monsterPositions);

    printTerrain(terrain);

    bool walkOn = true; // static ??

    while (walkOn){
        walk(terrain, terrainHeight, monsterPositions);
    }

    

    return 0;
}

