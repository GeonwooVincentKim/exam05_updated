#ifndef LIFE_H
#define LIFE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define LIVE_CELL '0'
#define DEAD_CELL ' '

// Board management
char **create_board(int width, int height);
void free_board(char **board, int height);
void print_board(char **board, int width, int height);

// Game logic
char **initialize_board(int width, int height);
char **update_board(char **board, int width, int height);
int count_neighbors(char **board, int x, int y, int width, int height);
bool should_live(bool is_alive, int neighbors);

// Main game function
void game_of_life(int width, int height, int iterations);

#endif // LIFE_H 