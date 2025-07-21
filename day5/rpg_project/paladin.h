#ifndef PALADIN_H_
#define PALADIN_H_

#include "warrior.h"
#include "mage.h"

class Paladin : public Warrior, public Mage {
private:
    int faith;

public:
    Paladin(const std::string& name, int hp, int mp, int str, int def, int mag, int wis, int faith);
    ~Paladin();
    
    void attack() override;
    void useSkill() override;
    
    void holyStrike();
    void bless();
    
    std::string getName() const;
    void showStatus() const;
};

#endif // PALADIN_H_
