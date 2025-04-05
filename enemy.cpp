#include "enemy.h"
#include <iostream>

Enemy::Enemy(std::string enemyName, int enemyHealth, int enemyDamage)
    : name(enemyName), health(enemyHealth), attackDamage(enemyDamage) {}

void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        std::cout << name << " has been defeated!\n";
    }
}

bool Enemy::isAlive() {
    return health > 0;
}

int Enemy::attack() {
    return attackDamage;
}
