#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>

using namespace std;

const int artHeight = 10;
const int artWidth = 41;


void convertArtToAsciiArray(char data[artHeight][artWidth]){
    char entry;
    for (int i = 0; i < artHeight; i++){
        for (int j = 0; j < artWidth; j++){
            cin >> entry;
            if (entry){
                data[i][j] = entry;
            }
        }
    }
}


void printArray(char data[artHeight][artWidth]){
    for (int i = 0; i < artHeight; i++){
        for (int j = 0; j < artWidth; j++){
            cout << data[i][j];
        }
    }
}


void initializeArray(char data[artHeight][artWidth]){
    for (int i = 0; i < artHeight; i++){
        for (int j = 0; j < artWidth; j++){
            data[i][j] = ' ';
        }
    }
}


int main(){
    
    char planetAndStars[artHeight][artWidth] = {};

    convertArtToAsciiArray(planetAndStars);

    printArray(planetAndStars);

    return 0;
}