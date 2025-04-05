#include <iostream>
#include <vector>
#include "player.h"
#include "room.h"
#include "enemy.h"

int main() {
    // Create Player
    std::string name;
    std::cout << "Enter your character's name: ";
    std::cin >> name;
    Player player(name);

    // Create rooms and enemies
    Room room1("You wake up in a cold, damp dungeon. A guard stands near the door.");
    Enemy guard("Castle Guard", 30, 10);
    room1.setEnemy(&guard);
    room1.addOption("Fight the guard");
    room1.addOption("Search the room for an item");

    Room room2("You walk down a long corridor, filled with torches.");
    room2.addOption("Continue forward");
    room2.addOption("Look for a secret door");

    // Game loop
    bool gameRunning = true;
    Room* currentRoom = &room1;

    while (gameRunning) {
        currentRoom->showRoom();
        int choice;
        std::cout << "Enter choice (1 or 2): ";
        std::cin >> choice;

        if (choice == 1) {
            if (currentRoom->enemy != nullptr) {
                std::cout << "You engage in combat with the " << currentRoom->enemy->name << "!\n";
                while (currentRoom->enemy->isAlive() && player.health > 0) {
                    // Player turn
                    currentRoom->enemy->takeDamage(10);  // Simplified attack
                    // Enemy turn
                    player.takeDamage(currentRoom->enemy->attack());
                }
            } else {
                std::cout << "There is nothing to fight here.\n";
            }
        } else if (choice == 2) {
            if (currentRoom == &room1) {
                player.addItem("Shiny Key");
                std::cout << "You found a shiny key!\n";
            } else {
                std::cout << "Nothing useful here.\n";
            }
        }

        player.showStats();
        if (player.hasAllArtifacts()) {
            std::cout << "Congratulations! You've collected all the artifacts.\n";
            break;
        }
    }

    std::cout << "You've completed Justin's Quest! Now, enter the world of wonder and paradise!\n";
    return 0;
}
