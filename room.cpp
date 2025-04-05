#include "room.h"
#include <iostream>

Room::Room(std::string roomDescription) : description(roomDescription), enemy(nullptr) {}

void Room::addOption(std::string option) {
    options.push_back(option);
}

void Room::showRoom() {
    std::cout << description << "\n";
    std::cout << "What do you want to do?\n";
    for (int i = 0; i < options.size(); i++) {
        std::cout << i + 1 << ". " << options[i] << "\n";
    }
}

void Room::setEnemy(Enemy* newEnemy) {
    enemy = newEnemy;
}
