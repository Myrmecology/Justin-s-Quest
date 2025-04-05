#include <iostream>
#include <vector>
#include "player.h"
#include "room.h"
#include "enemy.h"

Room* createDungeon() {
    // Room 1 (Start room)
    Room* room1 = new Room("You wake up in a cold, damp dungeon. A guard stands near the door.");
    Enemy* guard = new Enemy("Castle Guard", 30, 10);
    room1->setEnemy(guard);
    room1->setArtifact(false);
    
    // Room 2 (north from Room 1)
    Room* room2 = new Room("You are in a dimly lit hallway, with torches lining the walls.");
    room2->setEnemy(nullptr);
    room2->setArtifact(true); // Room 2 contains an artifact.
    
    // Room 3 (south from Room 1)
    Room* room3 = new Room("You find a dark and quiet storage room.");
    Enemy* knight = new Enemy("Knight", 50, 15);
    room3->setEnemy(knight);
    room3->setArtifact(false);
    
    // Connect rooms (north, south, east, west)
    room1->north = room2;
    room1->south = room3;
    
    room2->south = room1;
    room3->north = room1;
    
    return room1; // Starting point of the dungeon.
}

int main() {
    // Create dungeon and player
    Room* startRoom = createDungeon();
    std::string name;
    std::cout << "Enter your character's name: ";
    std::cin >> name;
    Player player(name, startRoom);

    bool gameRunning = true;
    Room* currentRoom = player.currentRoom;

    // Game loop
    while (gameRunning) {
        currentRoom->showRoom();
        int choice;
        std::cout << "Enter choice (1 or 2): ";
        std::cin >> choice;

        if (choice == 1) {
            // Combat logic
            if (currentRoom->enemy != nullptr) {
                std::cout << "You engage in combat with the " << currentRoom->enemy->name << "!\n";
                while (currentRoom->enemy->isAlive() && player.health > 0) {
                    // Player's turn
                    currentRoom->enemy->takeDamage(10);  // Simplified attack
                    // Enemy's turn
                    player.takeDamage(currentRoom->enemy->attack());
                }
                if (currentRoom->enemy->isAlive() == false) {
                    std::cout << "You defeated the " << currentRoom->enemy->name << "!\n";
                }
            } else {
                std::cout << "There's no enemy here.\n";
            }
        } else if (choice == 2) {
            // Search for an artifact
            if (currentRoom->hasArtifact) {
                player.addItem("Ancient Artifact");
                player.collectArtifact();
                std::cout << "You found an ancient artifact!\n";
                currentRoom->hasArtifact = false;  // Artifact can only be collected once
            } else {
                std::cout << "There's nothing to find here.\n";
            }
        }

        // Show player stats
        player.showStats();

        // Check if player has all artifacts
        if (player.hasAllArtifacts()) {
            std::cout << "Congratulations! You've collected all the artifacts.\n";
            gameRunning = false;
        }

        // Ask for movement
        std::cout << "Where do you want to go? (north, south, east, west): ";
        std::string direction;
        std::cin >> direction;

        if (direction == "north" && currentRoom->north != nullptr) {
            player.move(currentRoom->north);
        } else if (direction == "south" && currentRoom->south != nullptr) {
            player.move(currentRoom->south);
        } else {
            std::cout << "You can't go that way.\n";
        }
    }

    std::cout << "The quest is complete! Justin has left the dungeon and entered the world of wonder!\n";

    return 0;
}

