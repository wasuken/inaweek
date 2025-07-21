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
