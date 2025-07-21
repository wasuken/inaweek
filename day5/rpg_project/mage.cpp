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
