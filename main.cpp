#include <iostream>
#include <string>    // string型を使うために必要
#include <cstdlib>   // malloc/freeを使うために必要
using namespace std;

// 名前空間の定義（関連する機能をまとめる）
namespace GameSystem {
    string playerName = "勇者";           // string型（C++の文字列クラス）
    int* healthPoints = nullptr;          // int型のポインタ（初期化はnullptr）
                                               // nullptr = 「何も指していない」という意味の特別な値
    bool isGameRunning = true;            // bool型（true/false）
    
    // 体力を動的に確保する関数
    void initializeHealth(int maxHP) {
        cout << "=== 体力システム初期化 ===" << endl;
        
        // 動的メモリ確保（ヒープ領域に確保）
        healthPoints = (int*)malloc(sizeof(int));
        
        // ポインタが有効かチェック（メモリ確保に失敗した場合のエラーハンドリング）
        // nullptr = 「何も指していない」状態。メモリ確保に失敗するとnullptrが返される
        if (healthPoints == nullptr) {
            cout << "メモリ確保に失敗しました！" << endl;
            isGameRunning = false;
            return;
        }
        
        // ポインタを使って値を設定（*演算子でポインタの指す先にアクセス）
        *healthPoints = maxHP;
        
        cout << "体力を動的に確保: " << *healthPoints << " HP" << endl;
        cout << "メモリアドレス: " << healthPoints << endl;    // ポインタが指すアドレスを表示
    }
    
    // 体力を減らす関数
    void takeDamage(int damage) {
        // ポインタが有効かチェック
        if (healthPoints == nullptr) {
            cout << "体力システムが初期化されていません！" << endl;
            return;
        }
        
        // ポインタを使って値を変更
        *healthPoints -= damage;
        cout << playerName << "は " << damage << " のダメージを受けた！" << endl;
        cout << "残りHP: " << *healthPoints << endl;
        
        // bool値を使った条件分岐
        if (*healthPoints <= 0) {
            cout << "ゲームオーバー！" << endl;
            isGameRunning = false;
        }
    }
    
    // メモリを解放する関数
    void cleanup() {
        cout << "=== メモリ解放処理 ===" << endl;
        
        // 動的に確保したメモリを解放（重要！メモリリークを防ぐ）
        // free()でメモリを返すが、ポインタはまだ古いアドレスを覚えている
        if (healthPoints != nullptr) {
            free(healthPoints);
            healthPoints = nullptr;  // ダングリングポインタを防ぐ
                                    // ダングリングポインタ = 解放済みメモリを指すポインタ（超危険）
                                    // nullptrを代入することで「何も指していない」状態に戻す
            cout << "メモリを解放しました" << endl;
        }
    }
}

// 文字列操作の名前空間
namespace StringUtils {
    // 文字列の長さをチェックする関数
    void checkStringLength(const string& str) {
        cout << "=== 文字列解析 ===" << endl;
        cout << "文字列: \"" << str << "\"" << endl;
        cout << "長さ: " << str.length() << " 文字" << endl;
        
        // bool値を使った条件分岐
        bool isLongString = (str.length() > 10);
        if (isLongString) {
            cout << "これは長い文字列です" << endl;
        } else {
            cout << "これは短い文字列です" << endl;
        }
    }
    
    // C言語風の文字列（char*）とC++のstring型の比較
    void compareStringTypes() {
        cout << "=== C言語風 vs C++風 文字列 ===" << endl;
        
        // C言語風（char*ポインタ）
        const char* cStyleString = "Hello";
        cout << "C言語風文字列: " << cStyleString << endl;
        cout << "アドレス: " << (void*)cStyleString << endl;  // ポインタのアドレスを表示
        
        // C++風（string型）
        string cppString = "Hello";
        cout << "C++風文字列: " << cppString << endl;
        cout << "内部データのアドレス: " << (void*)cppString.c_str() << endl;
        
        // 比較
        bool areEqual = (cppString == cStyleString);  // C++では自動変換される
        cout << "両方とも同じ内容？ " << (areEqual ? "はい" : "いいえ") << endl;
    }
}

int main() {
    cout << "=== C++総まとめプログラム ===" << endl;
    
    // 1. 名前空間を使った文字列操作
    StringUtils::checkStringLength("プログラミング学習中");
    StringUtils::compareStringTypes();
    
    // 2. 動的メモリ管理とポインタ
    GameSystem::initializeHealth(100);
    
    // 3. whileループとbool値を使ったゲームループ
    int turn = 1;
    while (GameSystem::isGameRunning && turn <= 3) {  // bool値で継続条件を判定
        cout << "\n--- ターン " << turn << " ---" << endl;
        
        // ダメージ計算（ランダムっぽく）
        int damage = 20 + (turn * 10);
        GameSystem::takeDamage(damage);
        
        // if文でゲーム継続をチェック
        if (!GameSystem::isGameRunning) {
            cout << "ゲームが終了しました..." << endl;
            break;  // whileループを抜ける
        }
        
        turn++;
    }
    
    // 4. メモリ解放（重要！）
    GameSystem::cleanup();
    
    // 5. 追加のポインタ学習（基本から丁寧に）
    cout << "\n=== ポインタ学習コーナー ===" << endl;
    
    // ポインタとは何か？
    // ポインタ = 「メモリのアドレス（住所）を入れる箱」
    // 普通の変数 = 「値を入れる箱」
    // ポインタ = 「その箱がどこにあるかの住所を入れる箱」
    
    int normalVar = 42;                    // 通常の変数（スタック領域）
    int* ptr = &normalVar;                 // ポインタ（normalVarのアドレスを格納）
                                          // &演算子 = 「～のアドレス」を取得
                                          // * = 「ポインタ型」を表す記号
    
    cout << "通常の変数 normalVar: " << normalVar << endl;
    cout << "変数のアドレス &normalVar: " << &normalVar << endl;        // 住所を表示
    cout << "ポインタ ptr: " << ptr << endl;                          // ポインタが持つ住所を表示
    cout << "ポインタの指す値 *ptr: " << *ptr << endl;                // その住所の中身を表示
    cout << "ポインタ自体のアドレス &ptr: " << &ptr << endl;          // ポインタという箱の住所
    
    // ポインタを使って値を変更
    // *ptr = 「ポインタが指す先の値」を操作
    *ptr = 100;
    cout << "ポインタ経由で変更後の normalVar: " << normalVar << endl;
    
    // 重要ポイント：nullptrとは何か？
    cout << "\n--- nullptrの説明 ---" << endl;
    int* emptyPtr = nullptr;              // 何も指していないポインタ
    cout << "空のポインタ emptyPtr: " << emptyPtr << endl;
    // cout << *emptyPtr;  // これをやるとクラッシュ！nullptr を * で見ようとするのは危険
    
    // 安全なポインタの使い方
    if (emptyPtr != nullptr) {
        cout << "ポインタは有効です: " << *emptyPtr << endl;
    } else {
        cout << "ポインタは無効です（nullptr）" << endl;
    }
    
    // 6. 最終的な状態表示
    cout << "\n=== 最終状態 ===" << endl;
    cout << "プレイヤー名: " << GameSystem::playerName << endl;
    cout << "ゲーム実行中？ " << (GameSystem::isGameRunning ? "はい" : "いいえ") << endl;
    
    return 0;  // プログラム正常終了
}
