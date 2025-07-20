# Exam05整理

此文件夹包含按级别组织的所有exam05问题。

## 结构

```
new_exam05/
├── Level_0/
│   └── vbc/
│       ├── vbc.c              # 表达式计算器（第一个版本）
│       ├── vbc_v2.c           # 表达式计算器（第二个版本）
│       ├── vbc_refactored.c   # 重构后的表达式计算器
│       └── subject.txt        # 问题描述
├── Level_1/
│   ├── bigint/
│   │   ├── bigint.hpp             # 大整数类头文件
│   │   ├── bigint.cpp             # 大整数类实现
│   │   ├── bigint_refactored.hpp  # 重构后的头文件
│   │   └── main.cpp               # 测试主函数
│   ├── string_bigint/
│   │   ├── bigint.hpp             # 基于字符串的大整数类头文件
│   │   ├── bigint.cpp             # 基于字符串的大整数类实现
│   │   ├── bigint_refactored.hpp  # 重构后的头文件
│   │   ├── bigint_refactored.cpp  # 重构后的实现
│   │   └── main.cpp               # 测试主函数
│   ├── vect2/
│   │   ├── vect2.hpp      # 二维向量类头文件
│   │   ├── vect2.cpp      # 二维向量类实现
│   │   └── main.cpp       # 测试主函数
│   └── polyset/
│       ├── bag.hpp                    # 基本bag接口
│       ├── searchable_bag.hpp         # 可搜索bag接口
│       ├── array_bag.hpp              # 基于数组的bag头文件
│       ├── array_bag.cpp              # 基于数组的bag实现
│       ├── searchable_array_bag.hpp   # 可搜索数组bag
│       ├── tree_bag.hpp               # 基于树的bag头文件
│       ├── tree_bag.cpp               # 基于树的bag实现
│       ├── searchable_tree_bag.hpp    # 可搜索树bag
│       ├── set.hpp                    # Set类
│       └── main.cpp                   # 测试主函数
└── Level_2/
    ├── bsq/
    │   ├── bsq.h          # 最大正方形查找头文件
    │   ├── bsq.c          # 最大正方形查找实现
    │   ├── main.c         # 主函数
    │   └── subject.txt    # 问题描述
    └── game_of_life/
        ├── life.h                 # 生命游戏头文件
        ├── life.c                 # 生命游戏实现
        ├── main.c                 # 主函数
        ├── life_refactored.h      # 重构后的头文件
        ├── life_refactored.c      # 重构后的实现
        ├── main_refactored.c      # 重构后的主函数
        └── subject.txt            # 问题描述
```

## 级别问题描述

### Level_0: vbc（表达式计算器）
- **目的**: 计算数学表达式的程序
- **功能**: 支持+、*、括号的表达式解析器
- **输入**: 命令行参数作为表达式字符串
- **输出**: 计算结果

### Level_1: C++类实现

#### bigint（大整数）
- **目的**: 处理大整数的类实现
- **功能**: 
  - 算术运算符（+、+=、++）
  - 比较运算符（<、>、<=、>=、==、!=）
  - 位移运算符（<<、>>、<<=、>>=）
- **特点**: 以字符串形式存储大整数

#### string_bigint（基于字符串的大整数）
- **目的**: 使用字符串的大整数类实现
- **功能**:
  - 算术运算符（+、+=、++）
  - 比较运算符（<、>、<=、>=、==、!=）
  - 位移运算符（<<、>>=）
- **特点**: 使用std::ostringstream进行字符串转换

#### vect2（二维向量）
- **目的**: 二维向量类实现
- **功能**:
  - 算术运算符（+、-、*、+=、-=、*=）
  - 递增/递减运算符（++、--）
  - 比较运算符（==、!=）
  - 标量乘法支持

#### polyset（多态Set）
- **目的**: 利用多态性的Set数据结构实现
- **结构**:
  - `bag`: 基本接口
  - `searchable_bag`: 具有搜索功能的bag
  - `array_bag`: 基于数组的bag实现
  - `searchable_array_bag`: 可搜索数组bag
  - `set`: 不允许重复的Set类

### Level_2: 算法问题

#### bsq（最大正方形）
- **目的**: 在地图上避开障碍物找到最大正方形
- **输入**: 地图文件或标准输入
- **输出**: 绘制了最大正方形的地图
- **算法**: 动态规划

#### game_of_life（生命游戏）
- **目的**: Conway生命游戏模拟
- **输入**: 
  - 命令行: width、height、iterations
  - 标准输入: 画笔控制命令（wasd: 移动、x: 绘制）
- **输出**: 模拟结果板
- **规则**: Conway生命游戏规则

## 编译和执行

每个问题都包含注释中的编译命令。

### 示例:
```bash
# Level_0 vbc（原始版本）
gcc -Wall -Wextra -Werror vbc.c -o vbc
./vbc "2+3*4"

# Level_0 vbc（重构版本）
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

# Level_2 game_of_life（原始版本）
gcc -Wall -Wextra -Werror *.c -o life
./life 5 5 0

# Level_2 game_of_life（重构版本）
gcc -Wall -Wextra -Werror life_refactored.c main_refactored.c -o life_refactored
./life_refactored 5 5 0
```

## 重构改进

### Level_0: vbc
- **结构改进**: 使用枚举明确定义节点类型
- **函数分离**: 改进new_node函数以提高灵活性
- **代码可读性**: 添加注释和改进变量名
- **错误处理**: 更清晰的错误处理逻辑

### Level_1: bigint
- **头文件清理**: 删除不必要的注释并改进结构
- **函数分离**: 添加add_strings静态函数以分离加法逻辑
- **内联构造函数**: 内联定义简单构造函数

### Level_2: game_of_life
- **模块化**: 按功能分离函数（create_board、count_neighbors等）
- **可读性**: 将Conway生命游戏规则分离为清晰函数
- **内存管理**: 更安全的内存分配和释放
- **代码结构**: 使用switch语句改进输入处理

## 注意事项

- 所有代码都编写为可与valgrind一起测试以检测内存泄漏。
- 可以在每个问题的subject.txt文件中找到详细要求。
- 包含测试用例和示例。 