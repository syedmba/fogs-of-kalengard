#include <iostream>
#include "printterrain.h"

using namespace std;

#define BLOCK   "\xE2\x96\x88"
#define PLAYER  "\xEC\x9B\x83"
#define FOG     "\xF0\x9F\x8C\xAB"

const double visibilityRadius = 20.0;
bool fogOn = false;

void printTerrain(char terrain[mapHeight][mapLength], int playerCol, int playerRow){

    for (int i = 0; i < mapHeight; i++){
        for (int j=0; j < mapLength; j++){
            if ((playerRow - i)*(playerRow - i) + (playerCol - j)*(playerCol - j) <= visibilityRadius || fogOn == false){
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
            else {
                cout << FOG;
            }
        }
        cout << "\r" << endl;
    }
    
    for (int times = 0; times < 1; times++){
        for (int i = 0; i < mapLength; i++){
            cout << "-";
        }
        cout << "\r" << endl;
    }
    

}