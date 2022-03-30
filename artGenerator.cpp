#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <string>

using namespace std;

const int artHeight = 40;
const int artWidth = 70;


void convertArtToAsciiArray(string data[artHeight], char array[artHeight][artWidth]){
    string entry;
    for (int i = 0; i < artHeight; i++){
        getline(cin, entry);
        data[i] = entry;
        for (int j = 0; j < entry.length(); j++){
            if (entry[j]){
                array[i][j] = entry[j];
            }
        }
    }
}


void print1DArray(string data[artHeight]){
    for (int i = 0; i < artHeight; i++){
        cout << data[i] << endl;
    }
}

void print2DArray(char array[artHeight][artWidth]){
    int count = 0;
    cout << "{";
    for (int i = 0; i < artHeight; i++){
        for (int j = 0; j < artWidth; j++){
            if (array[i][j] == '\''){
                cout << "\'" << "\\" << "\'" << "\'" << ", ";
            }
            else if (array[i][j] == '`'){
                cout << "\'" << "\\" << "\'" << "\'" << ", ";
            }
            else if (array[i][j] == '\\'){
                cout << "\'" << "\\" << "\\" << "\'" << ", ";
            }
            else{
                cout << "\'" << array[i][j] << "\'" << ", ";
                count += 1;
            }
        }
    }
    cout << "};" << endl;
    cout << count;
}


void initializeArray(string data[artHeight]){
    for (int i = 0; i < artHeight; i++){
        data[i] = "";
    }
}

void initializeCharArray(char array[artHeight][artWidth]){
    for (int i = 0; i < artHeight; i++){
        for (int j = 0; j < artWidth; j++){
            array[i][j] = ' ';
        }
    }
}


int main(){
    
    string planetAndStars[artHeight] = {};
    char dataArray[artHeight][artWidth] = {};

    initializeCharArray(dataArray);

    convertArtToAsciiArray(planetAndStars, dataArray);

    // print1DArray(planetAndStars);

    print2DArray(dataArray);


    return 0;
}