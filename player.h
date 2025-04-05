#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "room.h"

class Player {
public:
    std::string name;
    int health;
    std::vector<std::string> inventory;
    int artifactsCollected;
    Room* currentRoom;

    Player(std::string playerName, Room* startRoom);
    void showStats();
    void addItem(std::string item);
    void takeDamage(int damage);
    void collectArtifact();
    bool hasAllArtifacts();
    void move(Room* newRoom);
};

#endif
