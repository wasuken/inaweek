#include "account.h"
#include <iostream>
using namespace std;

// 静的メンバ変数の初期化（クラス外で行う）
int Account::totalAccounts = 0;
int Account::nextAccountId = 1001;

// デフォルトコンストラクタ
Account::Account() : ownerName("Unknown"), balance(0) {
    accountId = nextAccountId++;
    totalAccounts++;
    cout << "デフォルトコンストラクタ: 口座 " << accountId << " を作成" << endl;
}

// パラメータ付きコンストラクタ（初期化リスト使用）
Account::Account(const string& name, int initialBalance) 
    : ownerName(name), balance(initialBalance) {
    
    accountId = nextAccountId++;
    totalAccounts++;
    cout << "パラメータ付きコンストラクタ: " << ownerName 
         << " の口座 " << accountId << " を作成（残高: " << balance << "円）" << endl;
}

// コピーコンストラクタ
Account::Account(const Account& other) 
    : ownerName(other.ownerName + "_copy"), balance(other.balance) {
    
    accountId = nextAccountId++;
    totalAccounts++;
    cout << "コピーコンストラクタ: " << ownerName 
         << " の口座 " << accountId << " をコピー作成" << endl;
}

// デストラクタ
Account::~Account() {
    totalAccounts--;
    cout << "デストラクタ: 口座 " << accountId << "（" << ownerName 
         << "）を削除" << endl;
}

// 入金処理
void Account::deposit(int amount) {
    if (amount > 0) {
        balance += amount;
        cout << ownerName << " が " << amount << "円入金。残高: " 
             << balance << "円" << endl;
    } else {
        cout << "入金額は正の値である必要があります" << endl;
    }
}

// 出金処理
bool Account::withdraw(int amount) {
    if (amount <= 0) {
        cout << "出金額は正の値である必要があります" << endl;
        return false;
    }
    
    if (balance >= amount) {
        balance -= amount;
        cout << ownerName << " が " << amount << "円出金。残高: " 
             << balance << "円" << endl;
        return true;
    } else {
        cout << ownerName << " の出金失敗: 残高不足（残高: " 
             << balance << "円）" << endl;
        return false;
    }
}

// 残高表示
void Account::showBalance() const {
    cout << "口座 " << accountId << "（" << ownerName 
         << "）の残高: " << balance << "円" << endl;
}

// 静的メンバ関数：総口座数を取得
int Account::getTotalAccounts() {
    return totalAccounts;
}

// 静的メンバ関数：銀行情報表示
void Account::showBankInfo() {
    cout << "=== 銀行情報 ===" << endl;
    cout << "現在の口座総数: " << totalAccounts << "口座" << endl;
    cout << "次の口座ID: " << nextAccountId << endl;
}
