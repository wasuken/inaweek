#ifndef MAGE_H_
#define MAGE_H_

#include "character.h"

class Mage : public Character {
private:
    int magic;
    int wisdom;

public:
    Mage();
    Mage(const std::string& name, int hp, int mp, int mag, int wis);
    ~Mage();
    
    void attack() override;
    void useSkill() override;
    
    void castFireball();
    void castHeal();
};

#endif // MAGE_H_
