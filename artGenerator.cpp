#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <string>

using namespace std;

const int artHeight = 10;
const int artWidth = 41;


void convertArtToAsciiArray(string data[artHeight], char array[artHeight][artWidth]){
    string entry;
    for (int i = 0; i < artHeight; i++){
        getline(cin, entry);
        data[i] = entry;
        for (int j = 0; j < artWidth; j++){
            array[i][j] = entry[j];
        }
    }
}


void print1DArray(string data[artHeight]){
    for (int i = 0; i < artHeight; i++){
        cout << data[i] << endl;
    }
}

void print2DArray(char array[artHeight][artWidth]){
    for (int i = 0; i < artHeight; i++){
        for (int j = 0; j < artWidth; j++){
            cout << array[i][j];
        }
        cout << endl;
    }
}


void initializeArray(string data[artHeight]){
    for (int i = 0; i < artHeight; i++){
        data[i] = "";
    }
}


int main(){
    
    string planetAndStars[artHeight] = {};
    char dataArray[artHeight][artWidth] = {};

    convertArtToAsciiArray(planetAndStars, dataArray);

    // print1DArray(planetAndStars);

    print2DArray(dataArray);


    return 0;
}