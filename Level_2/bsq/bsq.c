#include "bsq.h"

int min3(int a, int b, int c) {
	if (a <= b && a <= c) return a;
	if (b <= a && b <= c) return b;
	return c;
}

Map* read_map(char *filename) {
	FILE *file = filename ? fopen(filename, "r") : stdin;
	if (!file) return NULL;
	
	Map *map = malloc(sizeof(Map));
	if (!map) {
		if (filename) fclose(file);
		return NULL;
	}
	
	// Read first line: number of lines, empty char, obstacle char, full char
	if (fscanf(file, "%d %c %c %c\n", &map->lines, &map->empty, 
				&map->obstacle, &map->full) != 4) {
		free(map);
		if (filename) fclose(file);
		return NULL;
	}
	
	// Validate characters are different
	if (map->empty == map->obstacle || map->empty == map->full || 
		map->obstacle == map->full) {
		free(map);
		if (filename) fclose(file);
		return NULL;
	}
	
	// Validate number of lines
	if (map->lines <= 0) {
		free(map);
		if (filename) fclose(file);
		return NULL;
	}
	
	// Allocate map array
	map->map = malloc(map->lines * sizeof(char*));
	if (!map->map) {
		free(map);
		if (filename) fclose(file);
		return NULL;
	}
	
	// Read map lines (skip the first line which contains parameters)
	for (int i = 0; i < map->lines; i++) {
		char *line = NULL;
		size_t len = 0;
		ssize_t read = getline(&line, &len, file);
		
		if (read == -1) {
			// Cleanup on error
			for (int j = 0; j < i; j++) {
				free(map->map[j]);
			}
			free(map->map);
			free(map);
			if (filename) fclose(file);
			return NULL;
		}
		
		// Remove newline and carriage return
		if (read > 0) {
			if (line[read - 1] == '\n') {
				line[read - 1] = '\0';
				read--;
			}
			if (read > 0 && line[read - 1] == '\r') {
				line[read - 1] = '\0';
				read--;
			}
		}
		
		// Set width from first line
		if (i == 0) {
			map->width = read;
		} else if (read != map->width) {
			// All lines must have same length
			for (int j = 0; j < i; j++) {
				free(map->map[j]);
			}
			free(line);
			free(map->map);
			free(map);
			if (filename) fclose(file);
			return NULL;
		}
		
		map->map[i] = line;
	}
	
	if (filename) fclose(file);
	return map;
}

int validate_map(Map *map) {
	if (!map || map->lines <= 0 || map->width <= 0) return 0;
	
	// Check all characters are valid
	for (int i = 0; i < map->lines; i++) {
		for (int j = 0; j < map->width; j++) {
			char c = map->map[i][j];
			if (c != map->empty && c != map->obstacle) {
				return 0;
			}
		}
	}
	return 1;
}

void solve_bsq(Map *map) {
	// Create DP table
	int **dp = malloc(map->lines * sizeof(int*));
	if (!dp) return;
	
	for (int i = 0; i < map->lines; i++) {
		dp[i] = calloc(map->width, sizeof(int));
		if (!dp[i]) {
			for (int j = 0; j < i; j++) {
				free(dp[j]);
			}
			free(dp);
			return;
		}
	}
	
	int max_size = 0, best_i = 0, best_j = 0;
	
	// Fill DP table
	for (int i = 0; i < map->lines; i++) {
		for (int j = 0; j < map->width; j++) {
			if (map->map[i][j] == map->obstacle) {
				dp[i][j] = 0;
			} else if (i == 0 || j == 0) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
			}
			
			if (dp[i][j] > max_size) {
				max_size = dp[i][j];
				best_i = i;
				best_j = j;
			}
		}
	}
	
	// Fill the square
	if (max_size > 0) {
		int start_i = best_i - max_size + 1;
		int start_j = best_j - max_size + 1;
		
		for (int i = start_i; i <= best_i; i++) {
			for (int j = start_j; j <= best_j; j++) {
				map->map[i][j] = map->full;
			}
		}
	}
	
	// Free DP table
	for (int i = 0; i < map->lines; i++) {
		free(dp[i]);
	}
	free(dp);
}

void print_map(Map *map) {
	for (int i = 0; i < map->lines; i++) {
		printf("%s\n", map->map[i]);
	}
}

void free_map(Map *map) {
	if (!map) return;
	if (map->map) {
		for (int i = 0; i < map->lines; i++) {
			if (map->map[i]) {
				free(map->map[i]);
			}
		}
		free(map->map);
	}
	free(map);
}

void process_file(char *filename) {
	Map *map = read_map(filename);
	if (!map || !validate_map(map)) {
		fprintf(stderr, "map error\n");
		if (map) free_map(map);
		return;
	}
	
	solve_bsq(map);
	print_map(map);
	free_map(map);
}

int main(int argc, char **argv) {
	if (argc == 1) {
		process_file(NULL);  // Read from stdin
	} else {
		for (int i = 1; i < argc; i++) {
			process_file(argv[i]);
		}
	}
	return 0;
}
