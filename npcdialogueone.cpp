#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>

#include "npcdialogueone.h"

using namespace std;

void printMessage(string npcName, string message);
void printMessageLine();
void initiateDialogue(string npcName);


const int textBoxWidth = 100;
const int maxMessageLines = 7;
const int dummyTextInLine = 18;
const int numberOfNPCs = 5;
const int conversationLength[numberOfNPCs] = {8, 5, 7, 4, 3};


static int conversationNumber[numberOfNPCs] = {0, 0, 0, 0, 0};

// int * conversationLengthPtr = & conversationLength[0];
const int conversationLengthDrakyn = 6;
const int conversationLengthChild = 5;
const int conversationLengthWOM = 7;
const int conversationLengthFairMaiden = 4;
const int conversationLengthVillager = 3;

//conversations with NPCs
string Drakyn[conversationLengthDrakyn] = {
    "Greetings, foreign traveler! Where go you?",
    "You seem new around these parts... Ah! You must be our honoured Hero!",
    "Pleased to meet you. Knight Commander Drakyn of the Pikaen Knights Corps at your service.",
    "I have been assigned by Her Majesty to guide you around this area and help you get acquainted with fighting monsters. One of the most fundamental requirements for fighting monsters is a weapon. To start off, here's a common sword we Knights regularly use - it can be handy in many situations.",
    "Try to test different weapons and find the type that is most suitable for your fighting style.",
    // "Once that is done, I can provide you higher grade equipment fitting your choice.",
    // "I can also provide you with information regarding nearby towns, common monsters, and dungeons.",
    "Ad fines longinquos valeamus!"
};


string UnknownChild[conversationLengthChild] = {
    "ahhhhhhh, help me~",
    "There is a big monster up ahead",
    "I can't outrun it",
    "It is very scary",
    "Can you help me?"
};


string WiseOldMan[conversationLengthWOM] = {
    "Hello there",
    "I see you have come far in the prophecy",
    "Ahead lies your final challenge in your story of the chosen one",
    "Fear you shall, finch you shall not",
    "For the future of Kalengrad in your hands",
    "Take this and use it",
    "Sine sacrificio victoria esse nequit"
};


string FairMaiden[conversationLengthFairMaiden] = {
    "Thank you for saving me, brave soul",
    "Your chilvalry is outstanding",
    "May you have success on your journey",
    "Farewell, till we meet again."
};


string Villager[conversationLengthVillager] = {
    "You are in uncharted territory",
    "The monsters have ravaged this world for eternities",
    "How will you write history?"
};


// function to carry out the main dialogue
// uses printMessage()
void initiateDialogue(string npcName, int conversationNumber){
    for (int i = 0; i < conversationLengthDrakyn; i++){
        printMessage(npcName, Drakyn[i]);
        getchar();
    }
}


// function to print npc dialogue in a retro-style message box at the bottom of the game window
// first argument passed is a string containing the name of the NPC
// second argument passed is the message said by the NPC
void printMessage(string npcName, string message){
    string messagePartitions[maxMessageLines] = {};
    // float numLines = message.length() / (textBoxWidth);

    // bool inWord = false;
    int index = 0;
    // int lineNumber = 0;
    // int thisLineLength = 0;
    // string thisWord = "";
    bool endReached = false;

    while (!endReached){
        bool spaceAtStart = true;
        while (spaceAtStart){
            if (message.substr(0,1) == " "){
                message.erase(0,1);
            }
            else {
                spaceAtStart = false;
            }
        }
        if (message.length() <= 100){
            messagePartitions[index] = message;
            endReached = true;
        }
        else {
            int lastSpaceInLine = message.rfind(" ", 99);
            messagePartitions[index] = message.substr(0, lastSpaceInLine);
            message.erase(0, lastSpaceInLine);
            index += 1;
        }
    }
    


    // while (index < message.length()){
    //     if (message.substr(index, 1) != " "){
    //         inWord = true;
    //         thisWord = thisWord + message.substr(index, 1);
    //     }
    //     else {
    //         inWord = false;
            
    //     }
    //     if (thisLineLength > textBoxWidth){
    //         if inWord
    //     }
        
    // }

    // for (int i = 0; i < numLines; i++){
    //     messagePartitions[i] = message.substr(textBoxWidth*i, textBoxWidth));
    // }

    printMessageLine();
    cout << "<---> || " << npcName << " || <--->" << endl;
    for (int i = 0; i <= maxMessageLines; i++){
        if (messagePartitions[i].length() > 0){
            cout << messagePartitions[i] << endl;
        }
    }
    printMessageLine();
}


// this function prints a line of dashes
void printMessageLine(){
    for (int i = 0; i < textBoxWidth; i++){
        cout << "-";
    }
    cout << endl;
}


// dummy func
// int main(){
//     initiateDialogue("Knight Commander Drakyn");
// }