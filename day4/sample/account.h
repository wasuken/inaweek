#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>

class Account {
private:
    std::string ownerName;        // 口座名義人
    int balance;                  // 残高
    static int totalAccounts;     // 静的メンバ変数（全口座数）
    static int nextAccountId;     // 次の口座ID
    int accountId;                // 口座ID

public:
    // コンストラクタ
    Account();                              // デフォルトコンストラクタ
    Account(const std::string& name, int initialBalance);  // パラメータ付きコンストラクタ
    Account(const Account& other);          // コピーコンストラクタ
    
    // デストラクタ
    ~Account();
    
    // メンバ関数
    void deposit(int amount);       // 入金
    bool withdraw(int amount);      // 出金
    void showBalance() const;       // 残高表示
    
    // ゲッター関数
    std::string getOwnerName() const { return ownerName; }
    int getBalance() const { return balance; }
    int getAccountId() const { return accountId; }
    
    // 静的メンバ関数
    static int getTotalAccounts();
    static void showBankInfo();
};

#endif // ACCOUNT_H_
