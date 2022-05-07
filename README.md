# Fogs of Kalengard: Miasma of the Demon King - Chapter 1
# A Text-Based Adventure Game
Project for COMP2113/ENGG1340

## Team Members

BIN ASIF Syed Muhammad (3035767401)

HOSSAIN Fahim (3035929798)

## Game Description

The peaceful continent of Kalengard has suddenly been invaded/plagued by the monster army of the Demon King Zarquiea. Desperate to save their world, the Kalengardian people have summoned you, the foretold hero, from Earth to assist. Explore the cities and the wilderness of Kalengard and defeat the minions of Zarquiea ! Can you grow stronger and defeat the malicious Demon King where he sits within the enceinte of his dark castle ? 

_Fogs of Kalengard_ is an Open-World Action RPG (role playing game) where the player explores different areas of the world, interacts with NPCs (non-player characters), defeats many kinds of enemies, and gets stronger by leveling up and unlocking new skills. With a wide variety of world locations, uncountable player choices at each stage, and unpredictable plot progression, this is an experience built to immerse the player in a world of thrilling, spell-binding adventure.

Chapter 1 is a perpetual fighting experience where the game ends when you die. Take up your sword and fight!

## Features That We Implemented

### Player and Battle Stats

Player Skills and Skill Levels

Player & Monster Health Points

Player DEF and ATK Stats

Inventory and Equipped Items

### Story Progression

Spawn in wilderness

Subsequent areas can be unlocked by clearing previous areas

Areas vary in terrain

Monsters grow stronger as player levels up their skills

### Player Control

The player will be controlled using arrow keys input

### Monster Encounters

Monsters are generated randomly in each area

Monsters range in difficulty and type

Each monster has different stats

### World Features

Terrain generated randomly

## Coding Elements That Support The Game Features

### Generation of Random Game Sets or Events

Terrain for each level is generated randomly

In monster battles, enemies choose attacks randomly

During battles, we also randomly output messages to encourage the player to obliterate the enemy

### Data structures for storing the game status

Arrays will be used to manage player Inventory, player skill board, enemy skill boards, etc

Structs implemented for monsters and monster stats

### Dynamic Memory Management

Used to update inventory

Used to manage equipped items

### File Input and Output

Chapter 1 is perpetual fighting, therefore no rest is allowed

The player must fight from start til death ... there is no saving progress and taking breaks

### Program Codes in Multiple Files

Multiple files used to organize the code efficiently

Makefile used to link the code together

## Compilation and Execution Instructions

Run the following commands to compile the game:
```
make game
./game
```

The game begins with a print of the game name. Press [Enter] to start the game's introductory NPC interaction. Press [Enter] to print the next dialogue. After the dialogue ends, the player will find themselves on a randomly generated terrain. Press the left or right arrow key followed by [Enter] to move the character. Monsters on the map are marked by [?]. Upon reaching a monster's location, a battle is automatically triggered. Each monster has a set of possible attacks with different effects, and it uses one at random. The player has a given number of [Skills]. They can level up each [Skill] by reaching certain hidden usage milestones. It is recommended to invest in the defensive [Skill 3] to benefit from the [HP] gain. Stronger monsters start appearing as the player gets stronger. Beating a monster drops a random [Item], with buffs for the player's health, attack, and defense points, from the game's [Item] list. Items can be checked, used, and equipped by pressing [e] to open the [Inventory]. Beat all the monsters in one map to generate another map full of monsters. If a player dies, the game ends by printing the [GAME OVER] message.

We used the `academy11` server to test our program.
