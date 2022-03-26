# Fogs of Kalengard: Miasma of the Demon King 
# A Text-Based Adventure Game
Project for COMP2113/ENGG1340

## Team Members

BIN ASIF Syed Muhammad (3035767401)

HOSSAIN Fahim (3035929798)

## Game Description

The peaceful continent of Kalengard has suddenly been invaded/plagued by the monster army of the Demon King Zarquiea. Desperate to save their world, the Kalengardian people have summoned you, the foretold hero, from Earth to assist. Explore the cities and the wilderness of Kalengard and defeat the minions of Zarquiea ! Can you grow stronger and defeat the malicious Demon King where he sits within the enceinte of his dark castle ? 

_Fogs of Kalengard_ is an Open-World Action RPG (role playing game) where the player explores different areas of the world, interacts with NPCs (non-player characters), defeats many kinds of enemies, and gets stronger by leveling up and unlocking new skills. With a wide variety of world locations, uncountable player choices at each stage, and unpredictable plot progression, this is an experience built to immerse the player in a world of thrilling, spell-binding adventure.

## Features That We Plan To Implement

### Menu User Interface

Start Menu and Pause Menu

Player Avatar

Can press ESC at any time during gameplay to open Pause Menu

**Possible Menu Format:**

RESUME

START GAME

RESTART GAME

OPTIONS

QUIT

### Player and Battle Stats

Player class (tank?, warrior?, thief? bandit? etc)

Player level and EXP bar

Monster fury/anger meter

Player & monster health bar (updated constantly)

Inventory (menu + hotbar?)

Status effects

### Story Progression

Intro Scene followed by timeskip

Demon King tower is in the final area

Subsequent areas can be unlocked by clearing previous areas

Areas may vary between cities and wilderness

### Player Control

The player will be controlled using either arrow keys (if viable) or manually entered steps

### Travel System

Teleport waypoint at ends of areas to go to previous and next areas respectively

Or we could implement fast travel to previously unlocked teleport waypoints

### Monster Encounters

Monsters are generated randomly in each area

Monster respawns after fixed amount of time

### NPC interactions

Dialogue depending on player's choice of replies

The overall route taken would still remain same

### World Features

Terrain generated randomly

Traps

Lava/Water?

Collectibles

Bonfire-type system to rest and regenerate HP and save progress

## Coding Elements That Support The Game Features

### Generation of Random Game Sets or Events

Terrain for each level is generated randomly

In monster battles, enemies choose attacks randomly

During battles, we also randomly output messages to encourage the player to obliterate the enemy

### Data structures for storing the game status

Arrays will be used to manage player Inventory, player skill board, enemy skill boards, etc

Vectors and other structures may also be implemented later

### Dynamic Memory Management

Dynamic memory management using "new" and "delete"

May be used to update status effects on player and enemies

May be used to update inventory

### File Input and Output

File I/O will be implemented to save and load progress for each user

User IDs will be assigned

### Program Codes in Multiple Files

Multiple files will be used to organize the code efficiently

Makefile will be used to link the code together

