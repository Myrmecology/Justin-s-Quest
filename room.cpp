#include "room.h"
#include <iostream>

Room::Room(std::string roomDescription) : description(roomDescription), enemy(nullptr), hasArtifact(false), north(nullptr), south(nullptr), east(nullptr), west(nullptr) {}

void Room::addOption(std::string option) {
    options.push_back(option);
}

void Room::showRoom() {
    std::cout << description << "\n";
    std::cout << "What do you want to do?\n";
    for (int i = 0; i < options.size(); i++) {
        std::cout << i + 1 << ". " << options[i] << "\n";
    }
    std::cout << "You can also move north, south, east, or west.\n";
}

void Room::setEnemy(Enemy* newEnemy) {
    enemy = newEnemy;
}

void Room::setArtifact(bool artifact) {
    hasArtifact = artifact;
}
