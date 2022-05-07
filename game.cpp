#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <string>
// #include <ncurses.h>
#include <stdlib.h>
#include <fstream>
// #include <unistd.h>

#include "walk.h"
#include "battle.h"
#include "printterrain.h"
#include "inventory.h"
#include "npcdialogueone.h"
#include "nextarea.h"

#define BLOCK   "\xE2\x96\x88"
#define PLAYER  "\xEC\x9B\x83"
#define FOG     "\xF0\x9F\x8C\xAB"
#define SWORDS  "\xE2\x9A\x94"
#define EGREEN  "\xF0\x9F\x8C\xB2"
#define DECID   "\xF0\x9F\x8C\xB3"
#define PALM    "\xF0\x9F\x8C\xB4"

using namespace std;




// variable declarations

const int numRowsInArtI = 10;
const int numColsInArtI = 410;

// unused function prototype
void createPlanetAndStars(char array[]);
inline bool file_exists(const string &name);

inline bool file_exists(const string &name) {
    ifstream f(name.c_str());
    return f.good();
}


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



// the main() function of the game
// this function contains the main framework of the game
int main(){

    // player stats
    double playerHP = 100.0;
    double playerDEF = 10.0;
    double playerATK = 10.0;

    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "                               F O G S    O F    K A L E N G A R D" << endl;
    cout << "                       M I A S M A    O F    T H E    D E M O N    K I N G" << endl;
    cout << "                C H A P T E R    1    :    T H E    E T E R N A L    B A T T L E S" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;

    cout << "Welcome, warrior! Please tell your name: ";
    string playerName;
    cin >> playerName;

    string filename = playerName + ".txt";
    string inventory[inventorySize] = {};
    string equipment[equipmentLimit] = {};
    if (file_exists(filename)){
        // load game data
        ifstream fin(filename);
        if (fin.fail()){
            cout << "Error in opening file!" << endl;
            exit(1);
        }

        string line;
        getline(fin, line);
        if (line.length() == 0){
            cout << "Save files are incomplete! Load game again..." << endl;
            exit(1);
        }
        int playerHP = stoi(line);
        getline(fin, line);
        if (line.length() == 0){
            cout << "Save files are incomplete! Load game again..." << endl;
            exit(1);
        }
        int playerATK = stoi(line);
        getline(fin, line);
        if (line.length() == 0){
            cout << "Save files are incomplete! Load game again..." << endl;
            exit(1);
        }
        int playerDEF = stoi(line);
        bool equipmentReached = false;

        
        int inventoryIndex = 0;
        int equipmentIndex = 0;
        while (getline(fin, line)){
            if (line == "Equipment"){
                equipmentReached = true;
            } else if (equipmentReached){
                equipment[equipmentIndex] = line;
                equipmentIndex++;
            } else {
                inventory[inventoryIndex] = line;
                inventoryIndex++;
            }
        }

        fin.close();

    } else {
        cout << "Save files do not exist... Press Enter to begin new game" << endl;
        getchar();

        getchar();

        initiateDialogue("Knight Commander Drakyn", 0);
    }

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
        walk(terrain, terrainHeight, monsterPositions, walkOn, playerHP, playerATK, playerDEF, inventory, equipment);
    }

    // endwin();

    return 0;
}

