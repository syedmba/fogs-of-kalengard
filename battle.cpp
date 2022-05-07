#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
// #include <ncurses.h>
// #include <unistd.h>
// #include <stdio.h>

#include "battle.h"
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
    {"Skeleton", "diagonal slash", "thrust", "vertical slash", "horizontal slash"},
    {"Goblin", "Punch", "Pillage", " Rob", "Dagger"},
    {"Ogre", "Punch", "Sword slash", "Charge", "Throw"},
    {"Demon", "Possession", "Magic spell", "Disillusionment", "Temptation"},
    {"Dark elf", "Dagger dash", "Claw attack", "Sword Slash", "Spear"},
    {"Wyvern", "Fire Breath", "Lighting Breath", "Toxic Gas", "Ice Breath"},
    {"Dryad","Dagger", "Knife", "Long Bow", "Club attack"},
    {"Dragon", "Fire Rain", "Aura burst", "Fire Breath", "Roar"},
    {"Elemental", "Water flood", "Firestorm", "Landslide", "Lightning strike"},
    {"Wolf", "Claw Strike", "Charge", "Side kick", "Bite"}
};


int monsterAtkDmg[numOfMonsters][numAttacks] = {
    {20, 40, 20, 25},
    {}
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
void battle(char playerActions[totalPlayerSkills][maxLengthOfSkillName], int playerDEF, int &playerHP, bool &enemyDefeated){

    srand(time(0));
    int whichMonster = rand() % 9;
    // add levels to monsters?? 

    string monsterName = monsterdict[whichMonster][0];

    printSkeleton();
    // printMonster(whichMonster);


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

    int enemyHP = thisMonster.stats.HP;
    int enemyDEF = thisMonster.stats.DEF;
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

    srand(time(0));

    while (enemyHP > 0 && playerHP > 0){
        int this_monster_atk = rand() % numAttacks;
        int crit_factor = 1;

        cout << "<< " << monsterName << " >> is about to do a " << thisMonster.MonsterAttacks[this_monster_atk] << "..." << endl;
        
        int this_message = rand() % totalBattleMessages; 
        cout << battleMessages[this_message] << endl;
        cout << "Available skills:" << endl;

        int skill_counter = 1;

        for (int i = 0; i < totalPlayerSkills; i++){
            if (playerActions[i]){
                cout << skill_counter << ". " << playerActions[i] << endl;
                skill_counter += 1;
            }
        }
        
        int response;
        cout << "Choose your response: " << endl;

        cin >> response;

        printLine();

        cout << "<< " << monsterName << " >> did a " << thisMonster.MonsterAttacks[this_monster_atk] << " and you did a " << playerActions[response - 1] << "." << endl;

        int crit_determiner = rand() % 10;
        if (crit_determiner == lucky_crit_number){
            crit_factor = 2;
        }

        thisDEF = playerDEF + playerActionDEF[response - 1];
        thisATK = crit_factor * playerActionATK[response - 1];

        int damageToPlayer = thisMonster.MonsterAttackDamages[this_monster_atk] + thisMonster.stats.ATK*0.05 - thisDEF;
        int damageToEnemy = thisATK - thisMonster.stats.DEF;

        if (damageToPlayer < 0){
            damageToPlayer = 0;
        }

        if (damageToEnemy < 0){
            damageToEnemy = 0;
        }

        if (crit_factor == 2 && damageToEnemy > 0){
            cout << "You dealt a critical hit !" << endl;
        }

        cout << "You inflicted " << damageToEnemy << " points of DMG to the << " << monsterName << " >> ";
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

