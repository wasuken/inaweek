#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>

class Character {
protected:
    std::string name;
    int hp;
    int mp;
    int level;

public:
    Character();
    Character(const std::string& name, int hp, int mp);
    virtual ~Character();
    
    void showStatus() const;
    virtual void attack();
    virtual void useSkill() = 0;
    
    void heal();
    void heal(int amount);
    void heal(int amount, int cost);
    
    std::string getName() const { return name; }
    int getHp() const { return hp; }
    int getMp() const { return mp; }
};

#endif // CHARACTER_H_
