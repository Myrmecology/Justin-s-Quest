#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
public:
    std::string name;
    int health;
    int attackDamage;

    Enemy(std::string enemyName, int enemyHealth, int enemyDamage);
    void takeDamage(int damage);
    bool isAlive();
    int attack();
};

#endif
