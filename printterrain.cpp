#include <iostream>
// #include <unistd.h>

#include "printterrain.h"

using namespace std;

#define BLOCK   "\xE2\x96\x88"
#define PLAYER  "\xEC\x9B\x83"
#define FOG     "\xF0\x9F\x8C\xAB"

// this bool variable fogOn is a switch to turn on FOG in any area
// FOG restricts the visibility to a specific radius around the player
// fogOn may be integrated into printTerrain later to allow for areas with and without fog
bool fogOn = false;

// the visiblitiy radius when FOG is active
const double visibilityRadius = 20.0;



// this function prints the 2D terrain of an area of the game
// the area is passed as a 2d array called terrain with height and length stored as const values
// the function also accepts two int values giving the column and row of the player at the current point in time
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
        cout << endl;
    }
    
    for (int times = 0; times < 1; times++){
        for (int i = 0; i < mapLength; i++){
            cout << "-";
        }
        cout << endl;
    }
    

}