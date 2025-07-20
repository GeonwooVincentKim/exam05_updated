# Exam05整理

このフォルダはexam05のすべての問題をレベル別に整理したものです。

## 構造

```
new_exam05/
├── Level_0/
│   └── vbc/
│       ├── vbc.c              # 式計算機（最初のバージョン）
│       ├── vbc_v2.c           # 式計算機（2番目のバージョン）
│       ├── vbc_refactored.c   # リファクタリングされた式計算機
│       └── subject.txt        # 問題説明
├── Level_1/
│   ├── bigint/
│   │   ├── bigint.hpp             # 大きな整数クラスヘッダー
│   │   ├── bigint.cpp             # 大きな整数クラス実装
│   │   ├── bigint_refactored.hpp  # リファクタリングされたヘッダー
│   │   └── main.cpp               # テストメイン
│   ├── string_bigint/
│   │   ├── bigint.hpp             # 文字列ベースの大きな整数クラスヘッダー
│   │   ├── bigint.cpp             # 文字列ベースの大きな整数クラス実装
│   │   ├── bigint_refactored.hpp  # リファクタリングされたヘッダー
│   │   ├── bigint_refactored.cpp  # リファクタリングされた実装
│   │   └── main.cpp               # テストメイン
│   ├── vect2/
│   │   ├── vect2.hpp      # 2次元ベクトルクラスヘッダー
│   │   ├── vect2.cpp      # 2次元ベクトルクラス実装
│   │   └── main.cpp       # テストメイン
│   └── polyset/
│       ├── bag.hpp                    # 基本bagインターフェース
│       ├── searchable_bag.hpp         # 検索可能なbagインターフェース
│       ├── array_bag.hpp              # 配列ベースbagヘッダー
│       ├── array_bag.cpp              # 配列ベースbag実装
│       ├── searchable_array_bag.hpp   # 検索可能な配列bag
│       ├── tree_bag.hpp               # ツリーベースbagヘッダー
│       ├── tree_bag.cpp               # ツリーベースbag実装
│       ├── searchable_tree_bag.hpp    # 検索可能なツリーbag
│       ├── set.hpp                    # Setクラス
│       └── main.cpp                   # テストメイン
└── Level_2/
    ├── bsq/
    │   ├── bsq.h          # 最大正方形検索ヘッダー
    │   ├── bsq.c          # 最大正方形検索実装
    │   ├── main.c         # メイン関数
    │   └── subject.txt    # 問題説明
    └── game_of_life/
        ├── life.h                 # ライフゲームヘッダー
        ├── life.c                 # ライフゲーム実装
        ├── main.c                 # メイン関数
        ├── life_refactored.h      # リファクタリングされたヘッダー
        ├── life_refactored.c      # リファクタリングされた実装
        ├── main_refactored.c      # リファクタリングされたメイン
        └── subject.txt            # 問題説明
```

## レベル別問題説明

### Level_0: vbc（式計算機）
- **目的**: 数学式を計算するプログラム
- **機能**: +、*、括弧をサポートする式パーサー
- **入力**: コマンドライン引数として式文字列
- **出力**: 計算結果

### Level_1: C++クラス実装

#### bigint（大きな整数）
- **目的**: 大きな整数を扱うクラスの実装
- **機能**: 
  - 算術演算子（+、+=、++）
  - 比較演算子（<、>、<=、>=、==、!=）
  - ビットシフト演算子（<<、>>、<<=、>>=）
- **特徴**: 文字列として大きな整数を保存

#### string_bigint（文字列ベースの大きな整数）
- **目的**: 文字列を使用した大きな整数クラスの実装
- **機能**:
  - 算術演算子（+、+=、++）
  - 比較演算子（<、>、<=、>=、==、!=）
  - ビットシフト演算子（<<、>>=）
- **特徴**: std::ostringstreamを使用した文字列変換

#### vect2（2次元ベクトル）
- **目的**: 2次元ベクトルクラスの実装
- **機能**:
  - 算術演算子（+、-、*、+=、-=、*=）
  - インクリメント/デクリメント演算子（++、--）
  - 比較演算子（==、!=）
  - スカラー乗算サポート

#### polyset（多態性Set）
- **目的**: 多態性を活用したSetデータ構造の実装
- **構造**:
  - `bag`: 基本インターフェース
  - `searchable_bag`: 検索機能を持つbag
  - `array_bag`: 配列ベースbag実装
  - `searchable_array_bag`: 検索可能な配列bag
  - `set`: 重複を許可しないSetクラス

### Level_2: アルゴリズム問題

#### bsq（最大正方形）
- **目的**: 地図上で障害物を避けて最大正方形を見つける
- **入力**: 地図ファイルまたは標準入力
- **出力**: 最大正方形が描かれた地図
- **アルゴリズム**: 動的プログラミング

#### game_of_life（ライフゲーム）
- **目的**: Conwayのライフゲームシミュレーション
- **入力**: 
  - コマンドライン: width、height、iterations
  - 標準入力: ペン操作コマンド（wasd: 移動、x: 描画）
- **出力**: シミュレーション結果ボード
- **ルール**: Conwayのライフゲームルール

## コンパイルと実行

各問題にはコメントでコンパイルコマンドが含まれています。

### 例:
```bash
# Level_0 vbc（オリジナル）
gcc -Wall -Wextra -Werror vbc.c -o vbc
./vbc "2+3*4"

# Level_0 vbc（リファクタリングされたバージョン）
gcc -Wall -Wextra -Werror vbc_refactored.c -o vbc_refactored
./vbc_refactored "2+3*4"

# Level_1 bigint
g++ -Wall -Wextra -Werror *.cpp -o bigint
./bigint

# Level_1 vect2
g++ -Wall -Wextra -Werror *.cpp -o vect2
./vect2

# Level_1 string_bigint
gcc -Wall -Wextra -Werror -lstdc++ *.cpp -o string_bigint
./string_bigint

# Level_1 polyset
g++ -Wall -Wextra -Werror *.cpp -o polyset
./polyset 1 2 3 4 5

# Level_2 bsq
gcc -Wall -Wextra -Werror *.c -o bsq
./bsq map_file.txt

# Level_2 game_of_life（オリジナル）
gcc -Wall -Wextra -Werror *.c -o life
./life 5 5 0

# Level_2 game_of_life（リファクタリングされたバージョン）
gcc -Wall -Wextra -Werror life_refactored.c main_refactored.c -o life_refactored
./life_refactored 5 5 0
```

## リファクタリング改善点

### Level_0: vbc
- **構造改善**: enumを使用してノードタイプを明確に定義
- **関数分離**: new_node関数をより柔軟に改善
- **コード可読性**: コメント追加と変数名改善
- **エラー処理**: より明確なエラー処理ロジック

### Level_1: bigint
- **ヘッダー整理**: 不要なコメント削除と構造改善
- **関数分離**: add_strings静的関数追加で加算ロジック分離
- **インラインコンストラクタ**: 簡単なコンストラクタをインラインで定義

### Level_2: game_of_life
- **モジュール化**: 機能別に関数を分離（create_board、count_neighborsなど）
- **可読性**: Conwayのライフゲームルールを明確な関数に分離
- **メモリ管理**: より安全なメモリ割り当てと解放
- **コード構造**: switch文を使用した入力処理改善

## 注意事項

- すべてのコードはメモリリーク検出のためvalgrindと一緒にテストできるように書かれています。
- 各問題のsubject.txtファイルで詳細な要件を確認できます。
- テストケースと例が含まれています。 