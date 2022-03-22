#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>

#define BLOCK   "\xE2\x96\x88"
#define PLAYER  "\xEC\x9B\x83"

using namespace std;


const int mapHeight = 20;
const int mapLength = 100;

void printTerrain(char terrain[mapHeight][mapLength]){
    for (int i = 0; i < mapHeight; i++){
        for (int j=0; j < mapLength; j++){
            if (terrain[i][j] == 'b'){
                cout << BLOCK;
            }
            else if(terrain[i][j] == 'p'){
                cout << PLAYER;
            }
            else if (terrain[i][j] == 's'){
                cout << " ";
            }
        }
        cout << endl;
    }
}


void updateArray(){

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

void walk(char terrain[mapHeight][mapLength], int terrainHeight[mapLength]){

    int currentPlayerRow = 0;
    int currentPlayerCol = 0;

    for (int i = 0; i < mapHeight; i++){
        for (int j=0; j < mapLength; j++){
            if (terrain[i][j] == 'p'){
                currentPlayerRow = i;
                currentPlayerCol = j;
                break;
            }
        }
    }


    int steps = 0;
    while (steps == 0){
        cout << "Enter the number of steps you want to travel (negative to go back): ";
        cin >> steps;
        if (steps == 0){
            cout << "When in Kalengard, it's wise to keep moving..." << endl;
        }
    }

    terrain[(mapHeight - 1) - (terrainHeight[steps + currentPlayerCol] + 1)][steps + currentPlayerCol] = 'p';
    terrain[currentPlayerRow][currentPlayerCol] = 's';

}


int dropLoot(){

    return 0;
}


int main(){


    char terrain[mapHeight][mapLength] = {};
    int terrainHeight[mapLength] = {};
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

    printTerrain(terrain);

    bool walkOn = true;

    while (walkOn){
        walk(terrain, terrainHeight);
        printTerrain(terrain);
    }

    

    return 0;
}

