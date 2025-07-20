# Exam05 정리

이 폴더는 exam05의 모든 문제들을 Level별로 정리한 것입니다.

## 구조

```
new_exam05/
├── Level_0/
│   └── vbc/
│       ├── vbc.c          # 수식 계산기 (첫 번째 버전)
│       ├── vbc_v2.c       # 수식 계산기 (두 번째 버전)
│       └── subject.txt    # 문제 설명
├── Level_1/
│   ├── bigint/
│   │   ├── bigint.hpp     # 큰 정수 클래스 헤더
│   │   ├── bigint.cpp     # 큰 정수 클래스 구현
│   │   └── main.cpp       # 테스트 메인
│   ├── vect2/
│   │   ├── vect2.hpp      # 2차원 벡터 클래스 헤더
│   │   ├── vect2.cpp      # 2차원 벡터 클래스 구현
│   │   └── main.cpp       # 테스트 메인
│   └── polyset/
│       ├── bag.hpp                    # 기본 bag 인터페이스
│       ├── searchable_bag.hpp         # 검색 가능한 bag 인터페이스
│       ├── array_bag.hpp              # 배열 기반 bag 헤더
│       ├── array_bag.cpp              # 배열 기반 bag 구현
│       ├── searchable_array_bag.hpp   # 검색 가능한 배열 bag
│       ├── set.hpp                    # Set 클래스
│       └── main.cpp                   # 테스트 메인
└── Level_2/
    ├── bsq/
    │   ├── bsq.h          # 최대 정사각형 찾기 헤더
    │   ├── bsq.c          # 최대 정사각형 찾기 구현
    │   ├── main.c         # 메인 함수
    │   └── subject.txt    # 문제 설명
    └── game_of_life/
        ├── life.h         # 생명 게임 헤더
        ├── life.c         # 생명 게임 구현
        ├── main.c         # 메인 함수
        └── subject.txt    # 문제 설명
```

## Level별 문제 설명

### Level_0: vbc (수식 계산기)
- **목적**: 수학 표현식을 계산하는 프로그램
- **기능**: +, *, 괄호를 지원하는 수식 파서
- **입력**: 명령행 인수로 수식 문자열
- **출력**: 계산 결과

### Level_1: C++ 클래스 구현

#### bigint (큰 정수)
- **목적**: 큰 정수를 다루는 클래스 구현
- **기능**: 
  - 산술 연산자 (+, +=, ++)
  - 비교 연산자 (<, >, <=, >=, ==, !=)
  - 비트 시프트 연산자 (<<, >>, <<=, >>=)
- **특징**: 문자열로 큰 정수를 저장

#### vect2 (2차원 벡터)
- **목적**: 2차원 벡터 클래스 구현
- **기능**:
  - 산술 연산자 (+, -, *, +=, -=, *=)
  - 증감 연산자 (++, --)
  - 비교 연산자 (==, !=)
  - 스칼라 곱셈 지원

#### polyset (다형성 Set)
- **목적**: 다형성을 활용한 Set 자료구조 구현
- **구조**:
  - `bag`: 기본 인터페이스
  - `searchable_bag`: 검색 기능이 있는 bag
  - `array_bag`: 배열 기반 bag 구현
  - `searchable_array_bag`: 검색 가능한 배열 bag
  - `set`: 중복을 허용하지 않는 Set 클래스

### Level_2: 알고리즘 문제

#### bsq (최대 정사각형)
- **목적**: 지도에서 장애물을 피해 최대 정사각형 찾기
- **입력**: 지도 파일 또는 표준 입력
- **출력**: 최대 정사각형이 그려진 지도
- **알고리즘**: 동적 프로그래밍

#### game_of_life (생명 게임)
- **목적**: Conway의 생명 게임 시뮬레이션
- **입력**: 
  - 명령행: width, height, iterations
  - 표준 입력: 펜 조작 명령 (wasd: 이동, x: 그리기)
- **출력**: 시뮬레이션 결과 보드
- **규칙**: Conway의 생명 게임 규칙 적용

## 컴파일 및 실행

각 문제별로 컴파일 명령어가 주석으로 포함되어 있습니다.

### 예시:
```bash
# Level_0 vbc
gcc vbc.c -o vbc
./vbc "2+3*4"

# Level_1 bigint
g++ -g main.cpp bigint.cpp -o bigint
./bigint

# Level_2 bsq
gcc -g main.c bsq.c -o bsq
./bsq map_file.txt
```

## 참고사항

- 모든 코드는 메모리 누수 검사를 위해 valgrind와 함께 테스트할 수 있도록 작성되었습니다.
- 각 문제의 subject.txt 파일에서 자세한 요구사항을 확인할 수 있습니다.
- 테스트 케이스와 예시가 포함되어 있습니다. 