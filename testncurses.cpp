#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <ncurses.h>


#define BLOCK   "\xE2\x96\x88"
#define PLAYER  "\xEC\x9B\x83"
#define FOG     "\xF0\x9F\x8C\xAB"
#define SWORDS  "\xE2\x9A\x94"
#define EGREEN  "\xF0\x9F\x8C\xB2"
#define DECID   "\xF0\x9F\x8C\xB3"
#define PALM    "\xF0\x9F\x8C\xB4"

using namespace std;

const int artSize = 2800;



const double visibilityRadius = 20.0;
bool fogOn = false;



const int numRowsInArtI = 10;
const int numColsInArtI = 410;



const int maxLengthOfSkillName = 20;
const int totalPlayerSkills = 15;



const int mapHeight = 20;
const int mapLength = 100;
const int numMonsters = 19;



int playerHP = 100;
int playerDEF = 10;



// const int maxLengthOfSkillName = 20;
const int numOfMonsters = 10;
// const int totalPlayerSkills = 15;
const int totalBattleMessages = 7;
const int lucky_crit_number = 7;
const int battleMenuWidth = 100;

// bool enemy_defeated = false;

void printLine();
// void battleSkeleton();
// int main();



const int artHeight = 40;
const int artWidth = 70;

void printSkeleton();
void walk(char terrain[mapHeight][mapLength], int terrainHeight[mapLength], int monsterPositions[]);
void printTerrain(char terrain[mapHeight][mapLength], int playerCol, int playerRow);
void battle(char playerActions[totalPlayerSkills][maxLengthOfSkillName], int playerDEF, int &playerHP, bool &enemyDefeated);
int main();


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


// #include "battle.h"
// #include "walk.h"
// #include "printterrain.h"


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
        printw("Press an arrow key (<- or ->) and press ENTER to move:\n");
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
                printw("You pressed the right arrow key\r");
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
        cout << "\r" << endl;

        if (steps == 0){
            // cout << steps << endl;
            printw("When in Kalengard, it's wise to keep moving...\r");
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

    // clear();

    printTerrain(terrain, steps + currentPlayerCol, playerRow);
    

    if (battleInitiated){

        // clear();
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

        // clear();

        printTerrain(terrain, steps + currentPlayerCol, playerRow);
    }

    // endwin();

}




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
        monsterPositions[i] = (rand() % 5) + (5*(i+1));
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

    initscr();

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

    int test;

    cin >> test;

    // refresh();

    // usleep(5);

    bool walkOn = true; // static ??

    while (walkOn){
        walk(terrain, terrainHeight, monsterPositions);
    }

    endwin();

    return 0;
}




static string monsterdict[numOfMonsters] = {
    "skeleton",
    "goblin",
    "ogre",
    "demons",
    "dark elf",
    "wyvern",
    "dryad",
    "dragon",
    "elemental"
};

// char playerActions[totalPlayerSkills][maxLengthOfSkillName] = {
//     "blunt strike",
//     "sword slash",
//     "shield"
// };

// int atkStatForPlayerAction[totalPlayerSkills] = {
//     33
// };

string battleMessages[] = {
    "Stand strong on the battlefield!",
    "Unleash your wrath!",
    "Time to demonstrate your skills",
    "Awaken your power!",
    "Annihilate the pawns of the Demon King!",
    "",
    ""
};


void battle(char playerActions[totalPlayerSkills][maxLengthOfSkillName], int playerDEF, int &playerHP, bool &enemyDefeated){

    // add levels to monsters?? 

    // clear();

    printSkeleton();

    // refresh();

    printw("You have encountered a << Skeleton >> monster !\n");

    // refresh();
    const int numAttacks = 4;

    int enemyHP = 100;
    int enemyDEF = 10;
    // int enemyATK = 30;
    // int enemySTR = 5;

    int thisDEF;
    int thisATK;

    int playerActionATK[totalPlayerSkills] = {
        45,
        3,
        0
    };

    int playerActionDEF[totalPlayerSkills] = {
        0,
        0,
        30
    };

    string attack[numAttacks] = {
        "diagonal slash", 
        "thrust", 
        "vertical slash", 
        "horizontal slash"
    };

    int dmg[numAttacks] = {20, 40, 20, 25};

    srand(time(0));

    while (enemyHP > 0 && playerHP > 0){
        int this_monster_atk = rand() % numAttacks;
        int crit_factor = 1;

        cout << "<< Skeleton >> is about to do a " << attack[this_monster_atk] << "...\r" << endl;
        
        int this_message = rand() % totalBattleMessages; 
        cout << battleMessages[this_message] << "\r" << endl;
        cout << "Available skills:\r" << endl;

        int skill_counter = 1;

        for (int i = 0; i < totalPlayerSkills; i++){
            if (playerActions[i]){
                cout << skill_counter << ". " << playerActions[i] << "\r" << endl;
                skill_counter += 1;
            }
        }
        
        int response;
        cout << "Choose your response: \r" << endl;

        // refresh();

        // cin >> response;
        response = getch();

        printLine();

        cout << "<< Skeleton >> did a " << attack[this_monster_atk] << " and you did a " << playerActions[response - 1] << ".\r" << endl;

        int crit_determiner = rand() % 10;
        if (crit_determiner == lucky_crit_number){
            crit_factor = 2;
        }

        thisDEF = playerDEF + playerActionDEF[response - 1];
        thisATK = crit_factor * playerActionATK[response - 1];

        int damageToPlayer = dmg[this_monster_atk] - thisDEF;
        int damageToEnemy = thisATK - enemyDEF;

        if (damageToPlayer < 0){
            damageToPlayer = 0;
        }

        if (damageToEnemy < 0){
            damageToEnemy = 0;
        }

        if (crit_factor == 2 && damageToEnemy > 0){
            cout << "You dealt a critical hit !\r" << endl;
        }

        cout << "You inflicted " << damageToEnemy << " points of DMG to the << Skeleton >> ";
        cout << "and received " << damageToPlayer << " points of damage.\r" << endl;

        playerHP -= damageToPlayer;
        enemyHP -= damageToEnemy;

        if (playerHP < 0){
            playerHP = 0;
        }

        if (enemyHP < 0){
            enemyHP = 0;
        }

        cout << "Player HP: " << playerHP << " || << Skeleton >> HP: " << enemyHP << "\r" << endl;
    }

    printLine();

    if (playerHP == 0 && enemyHP == 0){
        cout << "Double Kill !\r" << endl;
        enemyDefeated = true;
    }
    if (enemyHP == 0){
        cout << "You have defeated << Skeleton >>.\r" << endl;
        enemyDefeated = true;
        // cout << enemy_defeated;
    }
    if (playerHP == 0){
        cout << "<< Skeleton >> has slain you.\r" << endl;
    }

    printLine();
    
}

void printLine(){
    for (int i = 0; i < battleMenuWidth; i++){
        cout << "-";
    }
    cout << "\r" << endl;
}

// int main(){

//     int playerDEF = 10;
//     int playerHP = 100;
//     // for (int i = 0; i < numOfMonsters; i++){
//     //     cout << monsterdict[i] << endl;
//     // }

//     // battleSkeleton(playerActions, playerDEF, playerHP);



//     return 0;
// }

void printTerrain(char terrain[mapHeight][mapLength], int playerCol, int playerRow){

    for (int i = 0; i < mapHeight; i++){
        for (int j=0; j < mapLength; j++){
            if ((playerRow - i)*(playerRow - i) + (playerCol - j)*(playerCol - j) <= visibilityRadius || fogOn == false){
                if (terrain[i][j] == 'b'){
                    mvprintw(i, j, BLOCK);
                }
                else if(terrain[i][j] == 'p'){
                    mvprintw(i, j, PLAYER);
                }
                else if (terrain[i][j] == 's'){
                    mvprintw(i, j, " ");
                }
                else if (terrain[i][j] == 'm'){
                    mvprintw(i, j, "?");
                }
            }
            else {
                mvprintw(i, j, FOG);
            }
        }
        // cout << "\r" << endl;
    }
    
    for (int times = 0; times < 1; times++){
        for (int i = 0; i < mapLength; i++){
            printw("-");
        }
        // cout << "\r" << endl;
    }
    

}



char skeletonArt[artSize] = {
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '.', '-', '-', '"', '"', '-', '.', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '"', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '"', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', '/', ' ', '\\', ' ', ' ', ' ', ' ', ',', '^', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '(', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ')', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', '/', ' ', ' ', ' ', '\'', '-', '-', '-', '.', ' ', '|', '-', '-', '\'', '\\', ' ', ' ', ' ', ' ', '(', ' ', ' ', '\\', '_', '_', '.', '.', '\'', '-', '-', ' ', ' ', ' ', '-', ' ', ' ', ' ', '-', '-', ' ', '-', '\'', '"', '"', '-', '.', '-', '\'', ' ', ' ', ')', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', '|', ' ', ' ', ' ', ' ', '\'', '>', ' ', ' ', ' ', '\'', '.', ' ', ' ', ' ', ' ', ' ', 'l', '_', '.', '.', '-', '-', '-', '-', '-', '-', '-', '.', '.', '_', 'l', ' ', ' ', ' ', ' ', ' ', ' ', '.', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', 'l', ';', '_', '_', ' ', '.', '\'', ' ', ' ', ' ', ' ', ' ', ' ', '"', '-', '.', '_', '_', '.', '|', '|', '_', '.', '-', '\'', 'v', '\'', '-', '.', '_', '|', '|', '\'', '"', '-', '-', '-', '-', '"', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', ' ', ' ', '\\', ' ', ' ', '.', '-', '\'', ' ', '|', ' ', '|', ' ', ' ', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'l', '.', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '.', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', ' ', ' ', ' ', '\\', '/', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'l', '\'', '^', '^', '\'', '^', '^', '\'', 'j', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', '\\', '_', '_', '_', '_', '_', '/', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'j', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'l', ' ', '\'', '-', '-', '_', '_', ')', '-', '\'', '(', '_', '_', '.', '-', '-', '\'', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '/', '\'', '-', '-', '-', '\'', '\'', '-', '-', '-', '-', '-', '\'', '"', '1', ' ', '|', ' ', ' ', ',', '-', '-', '-', '-', '-', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ')', '/', ' ', ' ', '\'', '-', '-', '\'', ' ', '\'', '-', '-', '-', '\'', ' ', ' ', ' ', '\\', '\'', '-', '\'', ' ', ' ', '_', '_', '_', ' ', ' ', '\'', '-', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '/', ' ', ' ', '\'', '-', '\'', ' ', ' ', '\'', '\'', '-', '-', '-', '-', '\'', ' ', ' ', '/', ' ', ' ', ',', '-', '\'', ' ', ' ', ' ', 'I', '\'', '.', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', ' ', 'L', ' ', '|', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '/', ' ', ' ', '\'', '-', '.', '-', '.', '\'', '\'', '-', '-', '-', '-', '-', '\'', ' ', '/', ' ', ' ', '/', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', '\'', '.', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '.', '_', '\'', ' ', '/', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '/', '(', ' ', ' ', ' ', '\'', '/', ' ', ' ', ' ', ')', '-', ' ', '-', '-', '-', '\'', ' ', ';', ' ', ' ', '/', '_', '_', '.', 'J', ' ', ' ', ' ', 'L', '.', '_', '_', '.', '\\', ' ', ':', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '.', '_', ';', '/', '7', '(', '-', '.', '.', '.', '.', '.', '.', '.', '\'', ' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ')', ' ', '(', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '.', '_', ';', 'l', ' ', '_', '\'', '-', '-', '-', '-', '-', '-', '-', '-', '_', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ')', '-', '\'', '/', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '|', '_', '_', '_', '.', ' ', ' ', ' ', ' ', '_', '.', '_', '.', '/', ' ', ';', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '_', '_', ' ', ')', '-', '\'', '\\', ' ', ' ', '_', '_', ' ', ' ', '\\', ' ', ' ', '\\', ' ', ' ', 'I', ' ', ' ', ' ', '1', ' ', ' ', ' ', '/', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '-', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' ', ' ', ' ', '\'', '-', '\\', '-', '(', '-', '\'', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', '\'', '.', '|', ' ', ' ', ' ', '|', ' ', ',', '\'', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', '_', '_', ' ', ' ', '\'', '-', '\'', ' ', ' ', ' ', ' ', '_', '_', '/', ' ', ' ', '\'', '-', '.', ' ', '\'', '-', '-', '-', '\'', '\'', ',', '-', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ')', '-', '.', '_', '.', '-', '-', ' ', '(', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '-', '-', '-', '-', '-', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ')', '(', ' ', ' ', 'l', '\\', ' ', 'o', ' ', '(', '\'', '.', '.', '-', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '.', '.', '-', '-', '\'', ' ', '_', '\'', '-', '\'', ' ', '\'', '-', '-', '\'', '.', '-', '.', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', ',', ',', '-', '\'', '\'', ' ', '_', ',', ',', '-', '\'', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'f', '\'', '.', ' ', '_', ',', ',', '-', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '(', ')', '-', '-', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', '.', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '.', '_', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '(', ')', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ')', ' ', '\'', '-', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '/', ' ', '.', '_', '_', ')', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '.', '/', '/', '7', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '-', '-', '-', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'j', '_', '|', ' ', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '(', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', 'l', 'l', 'l', 'j', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|', '|', '|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void printSkeleton(){
    for (int i = 0; i < artHeight; i++){
        for (int j = 0; j < artWidth; j++){
            cout << skeletonArt[i*artWidth + j];
        }
        cout << "\r" << endl;
    }
}
