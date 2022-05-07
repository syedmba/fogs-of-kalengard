// inventory.cpp

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
void Inventory(std::string playerInventory[inventorySize], std::string playerEquipment[equipmentLimit], double &playerHP, double &playerATK, double &playerDEF){
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
            string effectHP, effectATK, effectDEF, type;
            for (int k = 0; k < ItemsListSize; k++){
                if (Items[k][0] == playerInventory[i]){
                    effectHP = Items[k][1];
                    effectATK = Items[k][2];
                    effectDEF = Items[k][3];
                    if (Usable[k]){
                        type = "Usable";
                    } else {
                        type = "Equippable";
                    }
                }
            }
            if (playerInventory[i].length() > 0){
                cout << i+1 << ". " << playerInventory[i] << " | HP Effect:" << effectHP << " | ATK Effect:" << effectATK << " | DEF Effect:" << effectDEF << " | Type: " << type << " | "<< endl;
            }
        }
        cout << "--------------------------------" << endl;
        cout << endl;
        cout << "Actions" << endl;
        //cout << "1. Swap Positions" << endl;
        //cout << "2. Delete Item (be careful what you do...)" << endl;
        cout << "1. Use Item" << endl;
        cout << "2. Equip/Unequip Item" << endl;
        cout << "e. Close Inventory" << endl;

        cout << "--------------------------------" << endl;
        cout << "Choose an action" << endl;

        string response;
        cin >> response;

        while (response != "1" && response != "2" && response != "e"){
            cout << "Invalid action" << endl;
            cout << "--------------------------------" << endl;
            cout << "Choose an action" << endl;
            cin >> response;
        }

        if (response == "e"){
            getchar();
            return;
        } else if (response == "1"){
            UseItem(playerInventory, playerHP, playerATK, playerDEF);
        } else if (response == "2"){
            EquipItem(playerInventory, playerEquipment, playerHP, playerATK, playerDEF);
        }
    }
}

/* void SwapItems(std::string playerInventory[inventorySize]){
    for()
    cout << "Items Swapped" << endl;
    return;
}
void DeleteItem(std::string playerInventory[inventorySize]){
    
    cout << "Item Deleted" << endl;
    return;
}
*/



void UseItem(std::string playerInventory[inventorySize], double &playerHP, double &playerATK, double &playerDEF){


    // to find num of items in inventory
    int itemsInInventoryRightNow = 0;
    int usableItemsInInventoryRightNow = 0;
    for (int i = 0; i < inventorySize; i++){
        if (playerInventory[i] != ""){
            itemsInInventoryRightNow++;
        }
    }

    // important: if items in inventory  = 0 print message and return
    if(itemsInInventoryRightNow==0){
        cout << "Your inventory is empty." << endl;
        return;
    }

    // print list of usable items in inventory
    int indexInItemsList;
    for (int j = 0; j < inventorySize; j++){
        if (playerInventory[j] != ""){
            for (int i = 0; i < ItemsListSize; i++){
                if (Items[i][0] == playerInventory[j]){
                    indexInItemsList = i;
                    break;
                }
            }

            if (Usable[indexInItemsList]){
                if (usableItemsInInventoryRightNow == 0){
                    cout << "Usable items in inventory:" << endl;
                }
                usableItemsInInventoryRightNow++;
                cout << j+1 << ". " << playerInventory[j] << endl;
            }
        }
    }

    // if no usable items in inventory then print message and return
    if(usableItemsInInventoryRightNow == 0){
        cout << "There are no usable items in the inventory";
        return;
    }

    string selectedItem;
    int selectedItemIndex;
    cout << "Enter the slot number of the item you wish to use:";
    cin >> selectedItemIndex;

    // do a while loop til valid input
    while (playerInventory[selectedItemIndex] == ""){
        cout << "No item in slot " << selectedItemIndex << ", enter a valid slot number: ";
        cin >> selectedItemIndex;
    }

    selectedItem = playerInventory[selectedItemIndex];

    for (int i = 0; i < ItemsListSize; i++){
        if (Items[i][0] == selectedItem){
            indexInItemsList = i;
            break;
        }
    }

    if (!Usable[indexInItemsList]){
        // print message and return
        cout << "The item you have chosen is not usable.";
        return;
        
    } else {
        // apply item effects to player's stats
        playerHP += stoi(Items[indexInItemsList][1]);
        playerATK += stoi(Items[indexInItemsList][2]);
        playerDEF += stoi(Items[indexInItemsList][3]);

        // remove item from inventory after it is used
        playerInventory[selectedItemIndex] = "";
    }

    cout << "Item Used" << endl;
}
void EquipItem(std::string playerInventory[inventorySize], std::string playerEquipment[equipmentLimit], double &playerHP, double &playerATK, double &playerDEF){
    int equipmentCount = 0;
    cout << "Current equipment: " << endl;
    for (int i = 0; i < equipmentLimit; i++){
        if (playerEquipment[i] != ""){
            equipmentCount += 1;
            cout << "Equipment Slot " << i+1 << ": " << playerEquipment[i] << endl;
        }
    }

    
    
    cout << "1. Equip Item" << endl;
    cout << "2. Unequip Item" << endl;
    cout << "3. Go Back" << endl;
    int response;
    cin >> response;

    while (response != 1 && response != 2){
        if (response == 3){
            return;
        }
        cout << "Invalid Choice..." << endl;
        cout << "1. Equip Item" << endl;
        cout << "2. Unequip Item" << endl;
        cout << "3. Go Back" << endl;
        cin >> response;
    }
    if (response == 1){
        if (equipmentCount == equipmentLimit){
            cout << "Max number of items already equipped, unequip some to equip more..." << endl;
            return;
        }
        int itemSlot;
        cout << "Enter inventory slot of item you wish to equip: ";
        cin >> itemSlot;
        if (playerInventory[itemSlot - 1] == ""){
            cout << "No item in this inventory slot" << endl;
            return;
        } else {
            for (int i = 0; i < ItemsListSize; i++){
                if (Items[i][0] == playerInventory[itemSlot - 1]){
                    if (Usable[i]){
                        cout << "Usable item cannot be equipped" << endl;
                        return;
                    } else {
                        // equip item
                        for (int j = 0; j < equipmentLimit; j++){
                            if (playerEquipment[j] == ""){
                                playerEquipment[j] = playerInventory[itemSlot - 1];
                                playerInventory[itemSlot - 1] = "";
                                playerHP += stoi(Items[i][1]);
                                playerATK += stoi(Items[i][2]);
                                playerDEF += stoi(Items[i][3]);

                                return;
                            }
                        }
                        
                    }
                }
            }
        }
    } else {
        int equipmentSlot;
        cout << "Enter equipment slot of item you wish to unequip: ";
        cin >> equipmentSlot;
        if (playerEquipment[equipmentSlot-1] == ""){
            cout << "No equipment in this slot" << endl;
            return;
        } else {
            for (int j = 0; j < inventorySize; j++){
                if (playerInventory[j] == ""){
                    playerInventory[j] = playerEquipment[equipmentSlot-1];
                    playerEquipment[equipmentSlot-1] = "";

                    for (int i = 0; i < ItemsListSize; i++){
                        if (Items[i][0] == playerInventory[j]){
                            playerHP -= stoi(Items[i][1]);
                            playerATK -= stoi(Items[i][2]);
                            playerDEF -= stoi(Items[i][3]);
                            break;
                        }
                    }
                    
                    return;
                }
            }
        }
    }
    
    cout << "Item Equipped/Unequipped" << endl;
}



