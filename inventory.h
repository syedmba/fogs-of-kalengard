// inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

const int inventorySize = 1000;
const int equipmentLimit = 10;
const int ItemsListSize = 100;


void SwapItems(std::string playerInventory[inventorySize]);
void DeleteItem(std::string playerInventory[inventorySize]);
void UseItem(std::string playerInventory[inventorySize], int &playerHP, int &playerATK, int&playerDEF);
void EquipItem(std::string playerInventory[inventorySize], std::string playerEquipment[equipmentLimit]);
void Inventory(std::string playerInventory[inventorySize], std::string playerEquipment[equipmentLimit], int &playerHP, int &playerATK, int &playerDEF);

#endif