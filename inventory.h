// inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

const int inventorySize = 1000;
const int equipmentLimit = 10;
const int ItemsListSize = 100;

// tentative format: {item, health points effect, atk effect, def effect}
// convert numbers to double 
string Items[ItemsListSize][4] = {
{"Impure Health Potion", "10", "0", "0"}, 
{"Queen Zelda's Healing Drought", "1000", "20", "100"},
{"Rusted Shortsword", "0", "10", "0"},
{"Blade of the Ruined King", "200", "200", "0"},
{"Crown of the Ruined King", "300", "50", "200"},
{"Gauntlets of the Ruined King", "300", "20", "300"},
{"Boots of the Ruined King", "100", "100", "50"},
{"Chestplate of the Ruined King", "500", "0", "1000"},
{"Rusted Dagger", "0", "10", "0"},
{"Butterfly knife", "0", "5", "0"},
{"Water", "5", "0", "0"},
{"Pumkin seeds", "5", "0", "0"},
{"Blade of the Ancient Knight", "150", "150", "0"},
{"Helmet of the Ancient Knight", "100", "50", "150"},
{"Gauntlets of the Ancient Knight", "150", "10", "150"},
{"Boots of the Ancient Knight", "70", "70", "30"},
{"Chestplate of the Ancient Knight", "300", "0", "500"},
{"Wooden Shield", "0", "5", "30"},
{"Wooden Sword", "0", "15", "5"},
{"Wooden Axe", "0", "10", "5"},
{"Excalibur Blade", "400", "400", "0"},
{"Basic Armour", "50", "0", "20"},
{"Armour of Pikaen Knights", "75", "0", "30"},
{"Blade of the Pikaen Knights", "75", "75", "0"},
{"Helmet of the Pikaen Knights", "50", "25", "75"},
{"Gauntlets of Pikaen Knights", "75", "5", "75"},
{"Boots of the Pikaen Knights", "35", "35", "15"},
{"Chestplate of Pikaen Knights", "150", "0", "250"},
{"Bow of Enchantment", "0", "100", "10"},

};

bool Usable[] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


void SwapItems(std::string playerInventory[inventorySize]);
void DeleteItem(std::string playerInventory[inventorySize]);
void UseItem(std::string playerInventory[inventorySize], int &playerHP, int &playerATK, int&playerDEF);
void EquipItem(std::string playerInventory[inventorySize], std::string playerEquipment[equipmentLimit]);
void Inventory(std::string playerInventory[inventorySize], std::string playerEquipment[equipmentLimit], int &playerHP, int &playerATK, int &playerDEF);

#endif