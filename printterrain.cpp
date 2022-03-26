#include <iostream>
#include "printterrain.h"

using namespace std;

#define BLOCK   "\xE2\x96\x88"
#define PLAYER  "\xEC\x9B\x83"
#define FOG     "\xF0\x9F\x8C\xAB"

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
            else if (terrain[i][j] == 'm'){
                cout << "?";
            }
        }
        cout << endl;
    }
    
    for (int times = 0; times < 1; times++){
        for (int i = 0; i < mapLength; i++){
            cout << "-";
        }
        cout << endl;
    }
    

}