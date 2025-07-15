#include <iostream>
#include "account.h"
using namespace std;

int main() {
    cout << "=== 銀行口座管理システム ===" << endl;
    
    // 通常のオブジェクト作成（スタック領域）
    Account account1("田中太郎", 10000);
    Account account2("佐藤花子", 50000);
    
    // 静的メンバの確認
    cout << "現在の口座総数: " << Account::getTotalAccounts() << endl;
    
    // 動的メモリ確保（ヒープ領域）
    Account* account3 = new Account("鈴木一郎", 30000);
    Account* account4 = new Account("山田美咲", 25000);
    
    cout << "動的確保後の口座総数: " << Account::getTotalAccounts() << endl;
    
    // 各口座の操作
    account1.deposit(5000);
    account2.withdraw(10000);
    account3->deposit(15000);
    account4->withdraw(5000);
    
    // 残高確認
    account1.showBalance();
    account2.showBalance();
    account3->showBalance();
    account4->showBalance();
    
    // 動的メモリの解放（重要！）
    delete account3;
    delete account4;
    
    cout << "メモリ解放後の口座総数: " << Account::getTotalAccounts() << endl;
    
    // 配列の動的確保例
    cout << "\n=== 複数口座の一括管理 ===" << endl;
    Account* accounts = new Account[3]{
        Account("顧客A", 1000),
        Account("顧客B", 2000),
        Account("顧客C", 3000)
    };
    
    for(int i = 0; i < 3; i++) {
        accounts[i].showBalance();
    }
    
    // 配列の場合はdelete[]を使用
    delete[] accounts;
    
    cout << "全ての動的メモリ解放完了" << endl;
    cout << "最終的な口座総数: " << Account::getTotalAccounts() << endl;
    
    return 0;
}
