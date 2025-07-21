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
