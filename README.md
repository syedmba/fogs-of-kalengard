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

Inventory

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

### Program Codes in Multiple Files

Multiple files used to organize the code efficiently

Makefile used to link the code together

