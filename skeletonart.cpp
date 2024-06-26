#include <iostream>
#include "skeletonart.h"

using namespace std;

// const values that define the height and width of the original 2D text art
const int artHeight = 40;
const int artWidth = 70;

// 1D array that stores the original 2D text art line by line
char skeletonArt[artSize] = {
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '.', '-', '-', '"', '"', '-', '.', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '"', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '"', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', '/', ' ', '\\', ' ', ' ', ' ', ' ', ',', '^', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '(', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ')', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', '/', ' ', ' ', ' ', '\'', '-', '-', '-', '.', ' ', '|', '-', '-', '\'', '\\', ' ', ' ', ' ', ' ', '(', ' ', ' ', '\\', '_', '_', '.', '.', '\'', '-', '-', ' ', ' ', ' ', '-', ' ', ' ', ' ', '-', '-', ' ', '-', '\'', '"', '"', '-', '.', '-', '\'', ' ', ' ', ')', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', '|', ' ', ' ', ' ', ' ', '\'', '>', ' ', ' ', ' ', '\'', '.', ' ', ' ', ' ', ' ', ' ', 'l', '_', '.', '.', '-', '-', '-', '-', '-', '-', '-', '.', '.', '_', 'l', ' ', ' ', ' ', ' ', ' ', ' ', '.', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', 'l', ';', '_', '_', ' ', '.', '\'', ' ', ' ', ' ', ' ', ' ', ' ', '"', '-', '.', '_', '_', '.', '|', '|', '_', '.', '-', '\'', 'v', '\'', '-', '.', '_', '|', '|', '\'', '"', '-', '-', '-', '-', '"', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', ' ', ' ', '\\', ' ', ' ', '.', '-', '\'', ' ', '|', ' ', '|', ' ', ' ', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'l', '.', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '.', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', ' ', ' ', ' ', '\\', '/', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'l', '\'', '^', '^', '\'', '^', '^', '\'', 'j', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', '\\', '_', '_', '_', '_', '_', '/', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'j', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'l', ' ', '\'', '-', '-', '_', '_', ')', '-', '\'', '(', '_', '_', '.', '-', '-', '\'', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '/', '\'', '-', '-', '-', '\'', '\'', '-', '-', '-', '-', '-', '\'', '"', '1', ' ', '|', ' ', ' ', ',', '-', '-', '-', '-', '-', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ')', '/', ' ', ' ', '\'', '-', '-', '\'', ' ', '\'', '-', '-', '-', '\'', ' ', ' ', ' ', '\\', '\'', '-', '\'', ' ', ' ', '_', '_', '_', ' ', ' ', '\'', '-', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '/', ' ', ' ', '\'', '-', '\'', ' ', ' ', '\'', '\'', '-', '-', '-', '-', '\'', ' ', ' ', '/', ' ', ' ', ',', '-', '\'', ' ', ' ', ' ', 'I', '\'', '.', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', ' ', 'L', ' ', '|', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '/', ' ', ' ', '\'', '-', '.', '-', '.', '\'', '\'', '-', '-', '-', '-', '-', '\'', ' ', '/', ' ', ' ', '/', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', '\'', '.', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '.', '_', '\'', ' ', '/', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '/', '(', ' ', ' ', ' ', '\'', '/', ' ', ' ', ' ', ')', '-', ' ', '-', '-', '-', '\'', ' ', ';', ' ', ' ', '/', '_', '_', '.', 'J', ' ', ' ', ' ', 'L', '.', '_', '_', '.', '\\', ' ', ':', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '.', '_', ';', '/', '7', '(', '-', '.', '.', '.', '.', '.', '.', '.', '\'', ' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ')', ' ', '(', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '.', '_', ';', 'l', ' ', '_', '\'', '-', '-', '-', '-', '-', '-', '-', '-', '_', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ')', '-', '\'', '/', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '|', '_', '_', '_', '.', ' ', ' ', ' ', ' ', '_', '.', '_', '.', '/', ' ', ';', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '_', '_', ' ', ')', '-', '\'', '\\', ' ', ' ', '_', '_', ' ', ' ', '\\', ' ', ' ', '\\', ' ', ' ', 'I', ' ', ' ', ' ', '1', ' ', ' ', ' ', '/', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '-', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' ', ' ', ' ', '\'', '-', '\\', '-', '(', '-', '\'', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', '\'', '.', '|', ' ', ' ', ' ', '|', ' ', ',', '\'', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', '_', '_', ' ', ' ', '\'', '-', '\'', ' ', ' ', ' ', ' ', '_', '_', '/', ' ', ' ', '\'', '-', '.', ' ', '\'', '-', '-', '-', '\'', '\'', ',', '-', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ')', '-', '.', '_', '.', '-', '-', ' ', '(', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '-', '-', '-', '-', '-', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ')', '(', ' ', ' ', 'l', '\\', ' ', 'o', ' ', '(', '\'', '.', '.', '-', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '.', '.', '-', '-', '\'', ' ', '_', '\'', '-', '\'', ' ', '\'', '-', '-', '\'', '.', '-', '.', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', ',', ',', '-', '\'', '\'', ' ', '_', ',', ',', '-', '\'', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'f', '\'', '.', ' ', '_', ',', ',', '-', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '(', ')', '-', '-', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', '.', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '.', '_', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '(', ')', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ')', ' ', '\'', '-', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '/', ' ', '.', '_', '_', ')', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '.', '/', '/', '7', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '-', '-', '-', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'j', '_', '|', ' ', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '(', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', 'l', 'l', 'l', 'j', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|', '|', '|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
};


// this function prints a text art of a skeleton armed for combat
// it uses a 1D array of size 2800 called skeletonArt declared above
// we generate this 1D array by writing a generator program called artGenerator.cpp
// then we use const values for the height and width of the actual art to print the art from the 1D array
void printSkeleton(){
    for (int i = 0; i < artHeight; i++){
        for (int j = 0; j < artWidth; j++){
            cout << skeletonArt[i*artWidth + j];
        }
        cout << endl;
    }
}

void printDragon(){
    cout << "                 __                  __ " << endl;
    cout << "            ( _)                ( _)    " << endl;
    cout << "           / / \\              / /\\_\\_  " << endl;
    cout << "          / /   \\            / / | \\ \\ " << endl;
    cout << "         / /     \\          / /  |\\ \\ \\ " << endl;
    cout << "        /  /   ,  \\ ,       / /   /|  \\ \\ " << endl;
    cout << "       /  /    |\\_ /|      / /   / \\   \\_\\ " << endl;
    cout << "      /  /  |\\/ _ '_| \\   / /   /   \\    \\ " << endl;
    cout << "     |  /   |/  0 \0\\    / |    |    \\    \\ " << endl;
    cout << "     |    |\\|      \\_\\_ /  /    |     \\    \\ " << endl;
    cout << "     |  | |/    \\.\\ o\\o)  /      \\     |    \\ " << endl;
    cout << "     \\    |     /\\`v-v  /        |    |     \\ " << endl;
    cout << "      | \\/    /_| \\_|  /         |    | \\    \\ " << endl;
    cout << "      | |    /__/_ `-` /   _____  |    |  \\    \\ " << endl;
    cout << "      \\|    [__]  \\_/  |_________  \\   |   \\    () " << endl;
    cout << "       /    [___] (    \\         \\  |\\ |   |   // " << endl;
    cout << "      |    [___]                  |\\| \\|   /  |/ " << endl;
    cout << "     /|    [____]                  \\  |/\\ / / || " << endl;
    cout << "       \\   [____ /     ) _\\      \\  \\    \\| | || " << endl;
    cout << "     \\  \\  [_____|    / /     __/    \\   / / // " << endl;
    cout << "     |   \\ [_____/   / /        \\    |   \\/ // " << endl;
    cout << "     |   /  '----|   /=\\____   _/    |   / // " << endl;
    cout << "  __ /  /        |  /   ___/  _/\\    \\  | || " << endl;
    cout << " (/-(/-\\)       /   \\  (/\\/\\)/  |    /  | / " << endl;
    cout << "               (/\\/\\)           /   /   // " << endl;
    cout << "                      _________/   /    / " << endl;
    cout << "                     \\____________/    ( " << endl;

}

void printDemon(){
    cout << "     (_(  " << endl;
    cout << "    ('')  " << endl;
    cout << "  _  \"\\ )>,_     .-->   \\ " << endl;
    cout << "  _>--w/((_ >,_.'    " << endl;
    cout << "         ///   " << endl;
    cout << "         \"`\"     \\ " << endl;
    }

void printGoblin(){
    cout << "             ,      ,  " << endl;    
    cout << "           /(.-""-.)\\  " << endl;
    cout << "       |\\  \\/      \\/  /|  " << endl;
    cout << "       | \\ / =.  .= \\ / |  " << endl;
    cout << "       \\( \\   o\\/o   / )/  " << endl;
    cout << "        \\_, '-/  \\-' ,_/   " << endl;
    cout << "          /   \\__/   \\ " << endl;
    cout << "          \\,___/\\___,/ " << endl;
    cout << "        ___\\ \\|uu|/ /___   " << endl;
    cout << "      /`    \\ .--. /    `\\ " << endl;
    cout << "     /       '----'       \\    " << endl;

}

void printOgre(){
    cout << "   . +.  |  * . ' " << endl;
    cout << "  .* \\\\_/|\\_// +  " << endl;
    cout << " ___/(o)|(o)\\___   " << endl;
    cout << " ####\"\"\"\"\"\"\"####   " << endl;

}

void printWolf(){
    cout << "                     . " << endl;
    cout << "                    / V\\   " << endl;
    cout << "                  / `  /   " << endl;
    cout << "                 <<   |    " << endl;
    cout << "                 /    |    " << endl;
    cout << "               /      |    " << endl;
    cout << "             /        |    " << endl;
    cout << "           /    \\  \\ /  " << endl;
    cout << "          (      ) | | " << endl;
    cout << "  ________|   _/_  | | " << endl;
    cout << "<__________\\______)\\__)    " << endl;

}

void printDarkElf(){
    cout << "*<|:-(" <<endl;
}

void printElemental(){
    cout << "               (  .      )   "<< endl;
    cout << "           )           (              )    "<< endl;
    cout << "                 .  '   .   '  .  '  . "<< endl;
    cout << "        (    , )       (.   )  (   ',    ) "<< endl;
    cout << "         .' ) ( . )    ,  ( ,     )   ( .  "<< endl;
    cout << "      ). , ( .   (  ) ( , ')  .' (  ,    ) "<< endl;
    cout << "     (_,) . ), ) _) _,')  (, ) '. )  ,. (' ) "<< endl;
    cout << "    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ "<< endl;


}

void printWyvern(){
    cout << "          .    "<< endl; 
    cout << "     .>   )\\;`a__    "<< endl;
    cout << "    (  _ _)/ /-.\" ~~    "<< endl;
    cout << "     `( )_ )/    "<< endl;
    cout << "      <_  <_    "<< endl;
}

void printDryad(){
cout << "       |}.'}    "<< endl;
cout << "    \\()/%(    "<< endl;
cout << "     _>\\_{    "<< endl;
cout << "      /|    "<< endl;
cout << "      \\    "<< endl;

}
