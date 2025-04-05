#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <string>
#include "enemy.h"

class Room {
public:
    std::string description;
    std::vector<std::string> options;
    Enemy* enemy; // Optional enemy in the room

    Room(std::string roomDescription);
    void addOption(std::string option);
    void showRoom();
    void setEnemy(Enemy* newEnemy);
};

#endif
