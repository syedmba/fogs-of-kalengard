#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "battle.h"
// #include <stdio.h>


using namespace std;

// const int maxLengthOfSkillName = 20;
const int numOfMonsters = 10;
// const int totalPlayerSkills = 15;
const int totalBattleMessages = 7;
const int lucky_crit_number = 7;
const int battleMenuWidth = 100;

void printLine();
// void battleSkeleton();
// int main();

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


void battle(char playerActions[totalPlayerSkills][maxLengthOfSkillName], int playerDEF, int &playerHP){

    // add levels to monsters?? 

    cout << "You have encountered a << Skeleton >> monster !" << endl;
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

        cout << "<< Skeleton >> is about to do a " << attack[this_monster_atk] << "..." << endl;
        
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
        cout << "Choose your response: ";
        cin >> response;

        printLine();

        cout << "<< Skeleton >> did a " << attack[this_monster_atk] << " and you did a " << playerActions[response - 1] << "." << endl;

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
            cout << "You dealt a critical hit !" << endl;
        }

        cout << "You inflicted " << damageToEnemy << " points of DMG to the << Skeleton >> ";
        cout << "and received " << damageToPlayer << " points of damage." << endl;

        playerHP -= damageToPlayer;
        enemyHP -= damageToEnemy;

        if (playerHP < 0){
            playerHP = 0;
        }

        if (enemyHP < 0){
            enemyHP = 0;
        }

        cout << "Player HP: " << playerHP << " || << Skeleton >> HP: " << enemyHP << endl;
    }

    printLine();

    if (playerHP == 0 && enemyHP == 0){
        cout << "Double Kill !" << endl;
    }
    if (enemyHP == 0){
        cout << "You have defeated << Skeleton >>." << endl;
    }
    if (playerHP == 0){
        cout << "<< Skeleton >> has slain you." << endl;
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

