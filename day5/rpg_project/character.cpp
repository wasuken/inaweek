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
