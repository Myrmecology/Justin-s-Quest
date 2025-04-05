#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

class Player {
public:
    std::string name;
    int health;
    std::vector<std::string> inventory;
    int artifactsCollected;

    Player(std::string playerName);
    void showStats();
    void addItem(std::string item);
    void takeDamage(int damage);
    void collectArtifact();
    bool hasAllArtifacts();
};

#endif
