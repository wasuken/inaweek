#!/bin/bash

mkdir -p rpg_project
cd rpg_project

# character.h
cat > character.h << 'EOF'
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
EOF

# warrior.h
cat > warrior.h << 'EOF'
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
EOF

# mage.h
cat > mage.h << 'EOF'
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
EOF

# paladin.h
cat > paladin.h << 'EOF'
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
EOF

# character.cpp
cat > character.cpp << 'EOF'
#include "character.h"
#include <iostream>
using namespace std;

Character::Character() : name("Unknown"), hp(100), mp(50), level(1) {
    cout << "Character デフォルトコンストラクタ" << endl;
}

Character::Character(const string& name, int hp, int mp) 
    : name(name), hp(hp), mp(mp), level(1) {
    cout << "Character コンストラクタ: " << name << " を作成" << endl;
}

Character::~Character() {
    cout << "Character デストラクタ: " << name << " を削除" << endl;
}

void Character::showStatus() const {
    cout << "名前: " << name << ", HP: " << hp << ", MP: " << mp 
         << ", Level: " << level << endl;
}

void Character::attack() {
    cout << name << " の基本攻撃！" << endl;
}

void Character::heal() {
    hp += 20;
    cout << name << " は20回復した（HP: " << hp << "）" << endl;
}

void Character::heal(int amount) {
    hp += amount;
    cout << name << " は" << amount << "回復した（HP: " << hp << "）" << endl;
}

void Character::heal(int amount, int cost) {
    if (mp >= cost) {
        hp += amount;
        mp -= cost;
        cout << name << " はMP" << cost << "を消費して" << amount 
             << "回復した（HP: " << hp << ", MP: " << mp << "）" << endl;
    } else {
        cout << name << " のMPが足りない！" << endl;
    }
}
EOF

# warrior.cpp
cat > warrior.cpp << 'EOF'
#include "warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior() : Character(), strength(15), defense(12) {
    cout << "Warrior デフォルトコンストラクタ" << endl;
}

Warrior::Warrior(const string& name, int hp, int mp, int str, int def) 
    : Character(name, hp, mp), strength(str), defense(def) {
    cout << "Warrior コンストラクタ: 戦士 " << name << " を作成" << endl;
}

Warrior::~Warrior() {
    cout << "Warrior デストラクタ: 戦士 " << name << " を削除" << endl;
}

void Warrior::attack() {
    cout << name << " は剣で斬りつけた！ダメージ: " << strength * 2 << endl;
}

void Warrior::useSkill() {
    powerAttack();
}

void Warrior::powerAttack() {
    if (mp >= 10) {
        mp -= 10;
        cout << name << " のパワーアタック！ダメージ: " << strength * 3 
             << "（MP: " << mp << "）" << endl;
    } else {
        cout << name << " のMPが足りない！" << endl;
    }
}

void Warrior::defend() {
    cout << name << " は防御した！防御力: " << defense << endl;
}
EOF

# mage.cpp
cat > mage.cpp << 'EOF'
#include "mage.h"
#include <iostream>
using namespace std;

Mage::Mage() : Character(), magic(12), wisdom(15) {
    cout << "Mage デフォルトコンストラクタ" << endl;
}

Mage::Mage(const string& name, int hp, int mp, int mag, int wis) 
    : Character(name, hp, mp), magic(mag), wisdom(wis) {
    cout << "Mage コンストラクタ: 魔法使い " << name << " を作成" << endl;
}

Mage::~Mage() {
    cout << "Mage デストラクタ: 魔法使い " << name << " を削除" << endl;
}

void Mage::attack() {
    cout << name << " は魔法弾を放った！ダメージ: " << magic * 2 << endl;
}

void Mage::useSkill() {
    castFireball();
}

void Mage::castFireball() {
    if (mp >= 15) {
        mp -= 15;
        cout << name << " のファイアボール！ダメージ: " << magic * 4 
             << "（MP: " << mp << "）" << endl;
    } else {
        cout << name << " のMPが足りない！" << endl;
    }
}

void Mage::castHeal() {
    if (mp >= 8) {
        mp -= 8;
        int healAmount = wisdom * 2;
        hp += healAmount;
        cout << name << " の回復魔法！" << healAmount << "回復した（HP: " 
             << hp << ", MP: " << mp << "）" << endl;
    } else {
        cout << name << " のMPが足りない！" << endl;
    }
}
EOF

# paladin.cpp
cat > paladin.cpp << 'EOF'
#include "paladin.h"
#include <iostream>
using namespace std;

Paladin::Paladin(const string& name, int hp, int mp, int str, int def, int mag, int wis, int faith) 
    : Warrior(name, hp, mp, str, def), Mage(name, hp, mp, mag, wis), faith(faith) {
    cout << "Paladin コンストラクタ: 聖騎士 " << name << " を作成" << endl;
}

Paladin::~Paladin() {
    cout << "Paladin デストラクタ: 聖騎士を削除" << endl;
}

void Paladin::attack() {
    cout << getName() << " の聖なる一撃！物理+魔法ダメージ" << endl;
}

void Paladin::useSkill() {
    holyStrike();
}

void Paladin::holyStrike() {
    cout << getName() << " の聖撃！強力な一撃を放った！" << endl;
}

void Paladin::bless() {
    cout << getName() << " は祝福の光を放った！" << endl;
}

string Paladin::getName() const {
    return Warrior::getName();
}

void Paladin::showStatus() const {
    cout << "名前: " << getName() << ", HP: " << Warrior::getHp() << ", MP: " << Warrior::getMp() 
         << ", Level: " << 1 << endl;
}
EOF

# main.cpp
cat > main.cpp << 'EOF'
#include <iostream>
#include "character.h"
#include "warrior.h"
#include "mage.h"
#include "paladin.h"
using namespace std;

int main() {
    cout << "=== RPGキャラクター管理システム ===" << endl;
    
    cout << "\n--- 戦士と魔法使いの作成 ---" << endl;
    Warrior warrior("アーサー", 150, 30, 18, 15);
    Mage mage("マーリン", 80, 120, 20, 18);
    
    warrior.showStatus();
    mage.showStatus();
    
    cout << "\n--- 攻撃方法の違い ---" << endl;
    warrior.attack();
    mage.attack();
    
    cout << "\n--- スキル使用 ---" << endl;
    warrior.useSkill();
    mage.useSkill();
    
    cout << "\n--- 回復方法の違い ---" << endl;
    warrior.heal();
    warrior.heal(50);
    mage.heal(30, 15);
    
    cout << "\n--- クラス独自の能力 ---" << endl;
    warrior.defend();
    mage.castHeal();
    
    cout << "\n--- 仮想関数の威力 ---" << endl;
    Character* characters[2];
    characters[0] = new Warrior("騎士", 120, 40, 16, 14);
    characters[1] = new Mage("魔術師", 70, 100, 22, 20);
    
    for (int i = 0; i < 2; i++) {
        characters[i]->attack();
        characters[i]->useSkill();
    }
    
    delete characters[0];
    delete characters[1];
    
    cout << "\n--- 多重継承の例 ---" << endl;
    Paladin paladin("ガウェイン", 130, 80, 16, 13, 15, 16, 20);
    paladin.showStatus();
    paladin.attack();
    paladin.holyStrike();
    paladin.bless();
    
    cout << "\n=== プログラム終了 ===" << endl;
    
    return 0;
}
EOF

# Makefile
cat > Makefile << 'EOF'
CXX = g++
CXXFLAGS = -std=c++11 -Wall
OBJECTS = main.o character.o warrior.o mage.o paladin.o

rpg: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o rpg $(OBJECTS)

main.o: main.cpp character.h warrior.h mage.h paladin.h
character.o: character.cpp character.h
warrior.o: warrior.cpp warrior.h character.h
mage.o: mage.cpp mage.h character.h
paladin.o: paladin.cpp paladin.h warrior.h mage.h

clean:
	rm -f *.o rpg

.PHONY: clean
EOF

make
