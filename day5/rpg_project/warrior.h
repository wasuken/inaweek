#ifndef WARRIOR_H_
#define WARRIOR_H_

#include "character.h"

class Warrior : public Character {
private:
    int strength;
    int defense;

public:
    Warrior();
    Warrior(const std::string& name, int hp, int mp, int str, int def);
    ~Warrior();
    
    void attack() override;
    void useSkill() override;
    
    void powerAttack();
    void defend();
};

#endif // WARRIOR_H_
