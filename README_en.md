# Exam05 Organization

This folder contains all exam05 problems organized by levels.

## Structure

```
new_exam05/
├── Level_0/
│   └── vbc/
│       ├── vbc.c              # Expression calculator (first version)
│       ├── vbc_v2.c           # Expression calculator (second version)
│       ├── vbc_refactored.c   # Refactored expression calculator
│       └── subject.txt        # Problem description
├── Level_1/
│   ├── bigint/
│   │   ├── bigint.hpp             # Big integer class header
│   │   ├── bigint.cpp             # Big integer class implementation
│   │   ├── bigint_refactored.hpp  # Refactored header
│   │   └── main.cpp               # Test main
│   ├── string_bigint/
│   │   ├── bigint.hpp             # String-based big integer class header
│   │   ├── bigint.cpp             # String-based big integer class implementation
│   │   ├── bigint_refactored.hpp  # Refactored header
│   │   ├── bigint_refactored.cpp  # Refactored implementation
│   │   └── main.cpp               # Test main
│   ├── vect2/
│   │   ├── vect2.hpp      # 2D vector class header
│   │   ├── vect2.cpp      # 2D vector class implementation
│   │   └── main.cpp       # Test main
│   └── polyset/
│       ├── bag.hpp                    # Basic bag interface
│       ├── searchable_bag.hpp         # Searchable bag interface
│       ├── array_bag.hpp              # Array-based bag header
│       ├── array_bag.cpp              # Array-based bag implementation
│       ├── searchable_array_bag.hpp   # Searchable array bag
│       ├── tree_bag.hpp               # Tree-based bag header
│       ├── tree_bag.cpp               # Tree-based bag implementation
│       ├── searchable_tree_bag.hpp    # Searchable tree bag
│       ├── set.hpp                    # Set class
│       └── main.cpp                   # Test main
└── Level_2/
    ├── bsq/
    │   ├── bsq.h          # Maximum square finder header
    │   ├── bsq.c          # Maximum square finder implementation
    │   ├── main.c         # Main function
    │   └── subject.txt    # Problem description
    └── game_of_life/
        ├── life.h                 # Game of Life header
        ├── life.c                 # Game of Life implementation
        ├── main.c                 # Main function
        ├── life_refactored.h      # Refactored header
        ├── life_refactored.c      # Refactored implementation
        ├── main_refactored.c      # Refactored main
        └── subject.txt            # Problem description
```

## Level Descriptions

### Level_0: vbc (Expression Calculator)
- **Purpose**: Program to calculate mathematical expressions
- **Features**: Supports +, *, and parentheses in expressions
- **Input**: Expression string as command line argument
- **Output**: Calculation result

### Level_1: C++ Class Implementations

#### bigint (Big Integer)
- **Purpose**: Implementation of a class to handle large integers
- **Features**: 
  - Arithmetic operators (+, +=, ++)
  - Comparison operators (<, >, <=, >=, ==, !=)
  - Bit shift operators (<<, >>, <<=, >>=)
- **Characteristics**: Stores large integers as strings

#### string_bigint (String-based Big Integer)
- **Purpose**: Implementation of a big integer class using strings
- **Features**:
  - Arithmetic operators (+, +=, ++)
  - Comparison operators (<, >, <=, >=, ==, !=)
  - Bit shift operators (<<, >>=)
- **Characteristics**: Uses std::ostringstream for string conversion

#### vect2 (2D Vector)
- **Purpose**: Implementation of a 2D vector class
- **Features**:
  - Arithmetic operators (+, -, *, +=, -=, *=)
  - Increment/decrement operators (++, --)
  - Comparison operators (==, !=)
  - Scalar multiplication support

#### polyset (Polymorphic Set)
- **Purpose**: Implementation of a Set data structure using polymorphism
- **Structure**:
  - `bag`: Basic interface
  - `searchable_bag`: Bag with search functionality
  - `array_bag`: Array-based bag implementation
  - `searchable_array_bag`: Searchable array bag
  - `set`: Set class that doesn't allow duplicates

### Level_2: Algorithm Problems

#### bsq (Maximum Square)
- **Purpose**: Find the maximum square avoiding obstacles on a map
- **Input**: Map file or standard input
- **Output**: Map with the maximum square drawn
- **Algorithm**: Dynamic programming

#### game_of_life (Game of Life)
- **Purpose**: Conway's Game of Life simulation
- **Input**: 
  - Command line: width, height, iterations
  - Standard input: Pen control commands (wasd: move, x: draw)
- **Output**: Simulation result board
- **Rules**: Conway's Game of Life rules

## Compilation and Execution

Each problem includes compilation commands in comments.

### Examples:
```bash
# Level_0 vbc (original)
gcc -Wall -Wextra -Werror vbc.c -o vbc
./vbc "2+3*4"

# Level_0 vbc (refactored version)
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

# Level_2 game_of_life (original)
gcc -Wall -Wextra -Werror *.c -o life
./life 5 5 0

# Level_2 game_of_life (refactored version)
gcc -Wall -Wextra -Werror life_refactored.c main_refactored.c -o life_refactored
./life_refactored 5 5 0
```

## Refactoring Improvements

### Level_0: vbc
- **Structure improvement**: Used enums to clearly define node types
- **Function separation**: Improved new_node function for more flexibility
- **Code readability**: Added comments and improved variable names
- **Error handling**: Clearer error handling logic

### Level_1: bigint
- **Header cleanup**: Removed unnecessary comments and improved structure
- **Function separation**: Added add_strings static function to separate addition logic
- **Inline constructors**: Defined simple constructors inline

### Level_2: game_of_life
- **Modularization**: Separated functions by functionality (create_board, count_neighbors, etc.)
- **Readability**: Separated Conway's Game of Life rules into clear functions
- **Memory management**: Safer memory allocation and deallocation
- **Code structure**: Improved input processing using switch statements

## Notes

- All code is written to be testable with valgrind for memory leak detection.
- Detailed requirements can be found in each problem's subject.txt file.
- Test cases and examples are included. 