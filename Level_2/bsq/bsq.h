#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Map structure
typedef struct {
	int lines, width;
	char empty, obstacle, full;
	char **map;
} Map;

// Function declarations
Map* read_map(char *filename);
int validate_map(Map *map);
void solve_bsq(Map *map);
void print_map(Map *map);
void free_map(Map *map);
void process_file(char *filename);
int min3(int a, int b, int c);

#endif // BSQ_H 