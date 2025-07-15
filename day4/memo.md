# ４日目

# コンストラクタ

```cpp
Hoge::constructor(): mem1(1), mem2(2)...
```

定義方法がこれまでやってきたJavaやRuby、Pythonなどとも異なり新鮮。

# デストラクタ

他言語にあるにはあるけど、勝手にメモリ解放してくれるから対して使ったことない。

クラス名の戦闘にチルダをつけるとデストラクタになる。

```cpp
Hoge::~Hoge(){
...
}
```

みたいになる。

# new,delete

- new:ヒープ領域にメモリを確保する
- delete: ヒープ領域で確保したメモリを削除する

```cpp
instance = new Constructor()
delete instance
array = new int[30];
// 配列の場合、delete[]をつける
delete[] array;
```


deleteを忘れるとメモリリークとなる。
メモリリークが長時間発生するといずれメモリは枯渇する。


# 静的メンバ

```cpp
static int hoge;
```

インスタンス関係なく、存在可能。
