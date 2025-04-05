#include "player.h"
#include <iostream>

Player::Player(std::string playerName, Room* startRoom) : name(playerName), health(100), artifactsCollected(0), currentRoom(startRoom) {}

void Player::showStats() {
    std::cout << "Player: " << name << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Artifacts Collected: " << artifactsCollected << "/10\n";
    std::cout << "Inventory: ";
    for (auto &item : inventory) {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

void Player::addItem(std::string item) {
    // Check if the item is already in the inventory
    for (const auto& invItem : inventory) {
        if (invItem == item) {
            std::cout << "You already have a " << item << " in your inventory.\n";
            return;
        }
    }
    inventory.push_back(item);
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        std::cout << "You have died. Game Over!\n";
    }
}

void Player::collectArtifact() {
    artifactsCollected++;
}

bool Player::hasAllArtifacts() {
    return artifactsCollected == 10;
}

void Player::move(Room* newRoom) {
    currentRoom = newRoom;
}

