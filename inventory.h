// inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

const int inventorySize = 1000;
const int equipmentLimit = 10;
const int ItemsListSize = 100;

// tentative format: {item, health points effect, atk effect, def effect}
// convert numbers to double 
const std::string Items[ItemsListSize][4] = {
{"Water", "5", "0", "0"},
{"Pumpkin seeds", "5", "0", "0"},
{"Impure Healing Potion", "10", "0", "0"}, 
{"Regular Healing Potion", "30", "0", "0"},
{"Beans", "10", "0", "0"},
{"Soup", "15", "0", "0"},
{"Touch of Rejuvenation", "40", "0", "0"},
{"A Second Chance", "70", "0", "0"},
{"Queen Zelda's Healing Drought", "1000", "20", "100"},
{"Butterfly knife", "1", "5", "0"},
{"Rusted Shortsword", "5", "10", "0"},
{"Rusted Dagger", "5", "10", "0"},
{"Wooden Shield", "10", "5", "20"},
{"Wooden Sword", "5", "15", "5"},
{"Wooden Axe", "5", "10", "5"},
{"Shabby Armour", "50", "0", "20"},
{"Shabby Bow", "5","30", "10"},
{"Bow of Enchantment", "10", "100", "10"},
{"Armour of Pikaen Knights", "75", "0", "30"},
{"Blade of the Pikaen Knights", "75", "75", "0"},
{"Helmet of the Pikaen Knights", "50", "25", "75"},
{"Gauntlets of Pikaen Knights", "75", "5", "75"},
{"Boots of the Pikaen Knights", "35", "35", "15"},
{"Chestplate of Pikaen Knights", "150", "0", "250"},
{"Blade of the Ancient Knight", "150", "150", "0"},
{"Helmet of the Ancient Knight", "100", "50", "150"},
{"Gauntlets of the Ancient Knight", "150", "10", "150"},
{"Boots of the Ancient Knight", "70", "70", "30"},
{"Chestplate of the Ancient Knight", "300", "0", "500"},
{"Blade of the Ruined King", "300", "300", "50"},
{"Crown of the Ruined King", "300", "50", "200"},
{"Gauntlets of the Ruined King", "300", "20", "300"},
{"Boots of the Ruined King", "100", "100", "50"},
{"Chestplate of the Ruined King", "500", "0", "1000"},
{"Excalibur", "400", "400", "0"},
{""}

};

const bool Usable[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


void SwapItems(std::string playerInventory[inventorySize]);
void DeleteItem(std::string playerInventory[inventorySize]);
void UseItem(std::string playerInventory[inventorySize], double &playerHP, double &playerATK, double &playerDEF);
void EquipItem(std::string playerInventory[inventorySize], std::string playerEquipment[equipmentLimit], double &playerHP, double &playerATK, double &playerDEF);
void Inventory(std::string playerInventory[inventorySize], std::string playerEquipment[equipmentLimit], double &playerHP, double &playerATK, double &playerDEF);

#endif