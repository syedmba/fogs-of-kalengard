#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

#include "inventory.h"

using namespace std;


// function to open the player's inventory
// the player can choose to:
// reorder the items
// delete items
// use items such as health potions (or permanent buffs?)
// equip and unequip items (weapons and armor etc)
// close the inventory
void Inventory(string playerInventory[inventorySize], string playerEquipment[equipmentLimit]){
    bool foreverFlag = true;
    while (foreverFlag){
        cout << "--------------------------------" << endl;
        cout << "P L A Y E R    I N V E N T O R Y" << endl;
        cout << "--------------------------------" << endl;
        cout << "Available Items:" << endl;
        for (int i = 0; i < inventorySize; i++){
            if (i == 0 && playerInventory[i] == ""){
                cout << "No items in inventory" << endl;
            }
            if (playerInventory[i].length() > 0){
                cout << i << ". " << playerInventory[i] << endl;
            }
        }
        cout << "--------------------------------" << endl;
        cout << endl;
        cout << "Actions" << endl;
        cout << "1. Swap Positions" << endl;
        cout << "2. Delete Item (be careful what you do...)" << endl;
        cout << "3. Use Item" << endl;
        cout << "4. Equip/Unequip Item" << endl;
        cout << "e. Close Inventory" << endl;

        cout << "--------------------------------" << endl;
        cout << "Choose an action" << endl;

        string response;
        cin >> response;

        while (response != "1" && response != "2" && response != "3" && response != "4" && response != "e"){
            cout << "Invalid action" << endl;
            cout << "--------------------------------" << endl;
            cout << "Choose an action" << endl;
            cin >> response;
        }

        if (response == "e"){
            getchar();
            return;
        } else if (response == "1"){
            SwapItems(playerInventory);
        } else if (response == "2"){
            DeleteItem(playerInventory);
        } else if (response == "3"){
            UseItem(playerInventory);
        } else if (response == "4"){
            EquipItem(playerInventory, playerEquipment);
        }
    }
}

void SwapItems(std::string playerInventory[inventorySize]){
    cout << "Items Swapped" << endl;
    return;
}
void DeleteItem(std::string playerInventory[inventorySize]){
    cout << "Item Deleted" << endl;
    return;
}
void UseItem(std::string playerInventory[inventorySize]){
    cout << "Item Used" << endl;
}
void EquipItem(std::string playerInventory[inventorySize], std::string playerEquipment[equipmentLimit]){
    cout << "Item Equipped/Unequipped" << endl;
}