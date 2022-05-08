#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
// #include <ncurses.h>
// #include <unistd.h>
// #include <stdio.h>

#include "battle.h"
#include "inventory.h"
#include "skeletonart.h"

using namespace std;


// variable declarations

// const int maxLengthOfSkillName = 20;
const int numOfMonsters = 10;
// const int totalPlayerSkills = 15;
const int totalBattleMessages = 7;
const int lucky_crit_number = 7;
const int battleMenuWidth = 100;
const int numStats = 5;


const int numAttacks = 4;
// bool enemy_defeated = false;


// function prototype
void printLine();


int monsterStats[numOfMonsters][numStats] = {
    {80, 10, 1, 0, 0},          // skeleton HP, DEF, ATK, MAG ATK, MAG RES
    {70, 5, 2, 0, 0},           // goblin
    {200, 10, 3, 0, 0},         // ogre
    {99, 4, 5, 5, 5},           // demon
    {100, 7, 4, 2, 1},          // dark elf
    {1000, 30, 10, 20, 20},     // wyvern
    {100, 1, 4, 7, 0},          // dryad
    {10000, 200, 90, 0, 30},    // dragon
    {200, 1, 8, 10, 10},        // elemental
    {50, 1, 5, 0, 0}            // wolf
};

struct MonsterStats{
    int HP;
    int DEF;
    int ATK;
    int MAGATK;
    int MAGRES;
    MonsterStats(int stats[numStats]){
        this->HP = stats[0];
        this->DEF = stats[1];
        this->ATK = stats[2];
        this->MAGATK = stats[3];
        this->MAGRES = stats[4];
    }
};

// struct Ogre{
//     MonsterStats stats;
// };

// struct Skeleton{
//     MonsterStats stats;
//     string attack[numAttacks] = {
//         "diagonal slash", 
//         "thrust", 
//         "vertical slash", 
//         "horizontal slash"
//     };
//     int dmg[numAttacks] = {20, 40, 20, 25};
// };

struct Monster{
    MonsterStats stats;
    string MonsterAttacks[numAttacks];
    int MonsterAttackDamages[numAttacks];
    // Monster(MonsterStats stats){
    //     this->stats = stats;
    // }
};

// replicate for other monsters
// Monster Skeleton = {MonsterStats(monsterStats[0]), {"diagonal slash", "thrust", "vertical slash", "horizontal slash"}, {20, 40, 20, 25} };


// array that contains types of monsters discoverable
// hasn't been implemented yet
static string monsterdict[numOfMonsters][numAttacks + 1] = {
    {"Skeleton", "Diagonal Slash", "Thrust", "Vertical Slash", "Horizontal Slash"},
    {"Goblin", "Punch", "Pillage", "Sneak Attack", "Dagger Jump"},
    {"Dark Elf", "Dagger dash", "Rending Arrow", "Sword Slash", "Spear"},
    {"Wolf", "Claw Strike", "Charge", "Side Kick", "Bite"},
    {"Dryad", "Dagger Strike", "Wind Burst", "Longbow Shot", "Binding Attack"},
    {"Ogre", "Punch", "Club Smash", "Charge", "Throw"},
    {"Demon", "Possession", "Magic Rain", "Disillusionment", "Temptation"},
    {"Elemental", "Water Flood", "Firestorm", "Landslide", "Lightning Strike"},
    {"Wyvern", "Fire Breath", "Lighting Breath", "Toxic Gas", "Ice Breath"},
    {"Dragon", "Fire Rain", "Aura Burst", "Fire Breath", "Roar"},
};


int monsterAtkDmg[numOfMonsters][numAttacks] = {
    {20, 40, 20, 25},       // skeleton
    {15, 30, 20, 50},       // goblin
    {50, 40, 80, 90},       // dark elf
    {50, 20, 10, 70},       // wolf
    {30, 44, 40, 20},       // dryad
    {33, 70, 80, 20},       // ogre
    {60, 100, 50, 40},      // demon
    {100, 150, 90, 166},    // elemental
    {290, 333, 200, 275},   // wyvern
    {500, 300, 333, 200}    // dragon    
};

// string monsterAttacks[numOfMonsters] = {

// };
// discarded


// char playerActions[totalPlayerSkills][maxLengthOfSkillName] = {
//     "blunt strike",
//     "sword slash",
//     "shield"
// };

// int atkStatForPlayerAction[totalPlayerSkills] = {
//     33
// };



// array that contains messages printed at random during battles with monsters
string battleMessages[] = {
    "Stand strong on the battlefield!",
    "Unleash your wrath!",
    "Time to demonstrate your skills",
    "Awaken your power!",
    "Annihilate the pawns of the Demon King!",
    "",
    ""
};


// this function implements a battle between the player and an enemy (only skeleton at the moment)
// the first argument passed is an array containing skills the player can currently use
// the second argument passed is the player DEFENSE stat
// the third argument passed is the player HEALTH POINTS stat and is passed by reference to update it after the battle
// the fourth argument passed is a bool value that determines the outcome of the battle and is passed by reference
// that bool value is then used by the outer function calling battle() to update the monster positions on the terrain
void battle(string playerActions[totalPlayerSkills][7], double &playerATK, double &playerDEF, double &playerHP, bool &enemyDefeated, std::string playerInventory[inventorySize], std::string playerEquipment[equipmentLimit], double playerActionStats[totalPlayerSkills][6][3]){

    srand(time(0));

    // determine difficulty of monsters according to player skill level
    int modInt;
    double avg = 0;
    for (int i = 0; i < totalPlayerSkills; i++){
        avg += stoi(playerActions[i][0]);
    }
    avg = avg * 2 / 5;
    modInt = (int) avg;
    if (avg > 9){
        modInt = 9;
    }

    int whichMonster = rand() % modInt;

    string monsterName = monsterdict[whichMonster][0];

    // printSkeleton();
    // printMonster(whichMonster);

    if (monsterName == "Skeleton"){
        printSkeleton();
    } else if (monsterName == "Goblin"){
        printGoblin();
    } else if (monsterName == "Ogre"){
        printOgre();
    } else if (monsterName == "Dark Elf"){
        printDarkElf();
    } else if (monsterName == "Dragon"){
        printDragon();
    } else if (monsterName == "Wyvern"){
        printWyvern();
    } else if (monsterName == "Dryad"){
        printDryad();
    } else if (monsterName == "Wolf"){
        printWolf();
    } else if (monsterName == "Demon"){
        printDemon();
    }


    // cout << "You have encountered a << Skeleton >> monster !" << endl;
    cout << "You have encountered a << " << monsterName << " >> monster !" << endl;

    string attack[numAttacks] = {
        monsterdict[whichMonster][1], 
        monsterdict[whichMonster][2], 
        monsterdict[whichMonster][3], 
        monsterdict[whichMonster][4]
    };

    int dmg[numAttacks] = {
        monsterAtkDmg[whichMonster][0],
        monsterAtkDmg[whichMonster][1],
        monsterAtkDmg[whichMonster][2],
        monsterAtkDmg[whichMonster][3]
    };

    Monster thisMonster = {
        MonsterStats(monsterStats[whichMonster]), 
        {monsterdict[whichMonster][1], monsterdict[whichMonster][2], monsterdict[whichMonster][3], monsterdict[whichMonster][4]}, 
        {monsterAtkDmg[whichMonster][0],monsterAtkDmg[whichMonster][1],monsterAtkDmg[whichMonster][2],monsterAtkDmg[whichMonster][3]}
    }; // create struct for this monster

    double enemyHP = thisMonster.stats.HP;
    double enemyDEF = thisMonster.stats.DEF;
    // int enemyATK = 30;
    // int enemySTR = 5;

    double thisDEF;
    double thisATK;

    srand(time(0));

    while (enemyHP > 0 && playerHP > 0){
        int this_monster_atk = rand() % numAttacks;
        int crit_factor = 1;

        cout << "<< " << monsterName << " >> is about to do a " << thisMonster.MonsterAttacks[this_monster_atk] << "..." << endl;
        cout << endl;

        int this_message = rand() % totalBattleMessages; 
        cout << battleMessages[this_message] << endl;
        cout << "Available skills:" << endl;

        for (int i = 0; i < totalPlayerSkills; i++){
            cout << i+1 << ". " << playerActions[i][stoi(playerActions[i][0])] << endl;
        }
        
        string response;
        cout << "Choose your response (e for inventory): " << endl;

        cin >> response;

        while (response != "1" && response != "2" && response != "3" && response != "4" && response != "5"){
            // take valid input
            // open inventory if e
            if (response == "e"){
                Inventory(playerInventory, playerEquipment, playerHP, playerATK, playerDEF);
            }
            printLine();
            cout << "Choose your battle response (e for inventory): " << endl;

            cin >> response;
        }

        printLine();

        cout << "<< " << monsterName << " >> did a " << thisMonster.MonsterAttacks[this_monster_atk] << " and you did a " << playerActions[stoi(response) - 1][stoi(playerActions[stoi(response) - 1][0])] << "." << endl;
        playerActions[stoi(response) - 1][6] = to_string(stoi(playerActions[stoi(response) - 1][6]) + 1);
        

        int crit_determiner = rand() % 10;
        if (crit_determiner == lucky_crit_number){
            crit_factor = 2;
        }
        
        thisDEF = playerDEF + playerActionStats[stoi(response)-1][stoi(playerActions[stoi(response)-1][0])-1][2];
        thisATK = playerATK + crit_factor * playerActionStats[stoi(response) - 1][stoi(playerActions[stoi(response)-1][0])-1][1];
        playerHP += enemyHP * playerActionStats[stoi(response) - 1][stoi(playerActions[stoi(response)-1][0])-1][0];

        double damageToPlayer = thisMonster.MonsterAttackDamages[this_monster_atk] + thisMonster.stats.ATK - thisDEF;
        double damageToEnemy = thisATK - thisMonster.stats.DEF;

        if (damageToPlayer < 0){
            damageToPlayer = 0;
        }

        if (damageToEnemy < 0){
            damageToEnemy = 0;
        }

        if (crit_factor == 2 && damageToEnemy > 0){
            cout << "You dealt a critical hit !" << endl;
        }

        cout << "You inflicted " << damageToEnemy << " points of damage to the << " << monsterName << " >> ";
        cout << "and received " << damageToPlayer << " points of damage." << endl;

        playerHP -= damageToPlayer;
        enemyHP -= damageToEnemy;

        if (playerHP < 0){
            playerHP = 0;
        }

        if (enemyHP < 0){
            enemyHP = 0;
        }

        cout << "Player HP: " << playerHP << " || << " << monsterName << " >> HP: " << enemyHP << endl;

        // upgrade level of skill upon reaching usage milestones
        // milestones: 3, 10, 30, 80
        int usage = stoi(playerActions[stoi(response) - 1][6]);
        if (usage == 3 || usage == 10 || usage == 30 || usage == 80){
            playerActions[stoi(response) - 1][0] = to_string(stoi(playerActions[stoi(response) - 1][0]) + 1);
            cout << endl;
            cout << " *** Skill " << playerActions[stoi(response) - 1][stoi(playerActions[stoi(response) - 1][0]) - 1];
            cout << " has been upgraded to " << playerActions[stoi(response) - 1][stoi(playerActions[stoi(response) - 1][0])] << " ***" << endl;
            cout << endl;
        }
    }

    printLine();

    if (playerHP == 0 && enemyHP == 0){
        cout << "Double Kill !" << endl;
        enemyDefeated = true;
    }
    if (enemyHP == 0){
        cout << "You have defeated << " << monsterName << " >>." << endl;
        enemyDefeated = true;
        // cout << enemy_defeated;
    }
    if (playerHP == 0){
        cout << "<< " << monsterName << " >> has slain you." << endl;
    }

    printLine();

    getchar();
    
}

void printLine(){
    for (int i = 0; i < battleMenuWidth; i++){
        cout << "-";
    }
    cout << endl;
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

