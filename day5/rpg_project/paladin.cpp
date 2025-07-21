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
