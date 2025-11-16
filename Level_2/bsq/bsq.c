#include "bsq.h"

static void cleanup_map_partial(Map *map, int lines_allocated) {
	if (!map) return;
	if (map->map)
	{
		for (int i = 0; i < lines_allocated; i++)
			free(map->map[i]); 
		free(map->map);
	}
	free(map);
}

static void cleanup_dp(int **dp, int lines) {
	if (!dp) return;
	for (int i = 0; i < lines; i++) free(dp[i]);
	free(dp);
}

static int min3(int a, int b, int c) { return (a <= b && a <= c) ? a : (b <= c) ? b : c; }

static Map* cleanup_and_return(Map *map, FILE *file, char *filename) {
	if (map) cleanup_map_partial(map, 0);
	if (filename) fclose(file);
	return NULL;
}

Map* read_map(char *filename) {
	FILE *file = filename ? fopen(filename, "r") : stdin;
	if (!file) return NULL;
	Map *map = malloc(sizeof(Map));
	if (!map) return cleanup_and_return(NULL, file, filename);
	if (fscanf(file, "%d %c %c %c\n", &map->l, &map->e, &map->o, &map->f) != 4 ||
		map->e == map->o || map->e == map->f || map->o == map->f || map->l <= 0) {
		return cleanup_and_return(map, file, filename);
	}
	map->map = malloc(map->l * sizeof(char*));
	if (!map->map) return cleanup_and_return(map, file, filename);
	for (int i = 0; i < map->l; i++) {
		char *line = NULL;
		size_t len = 0;
		ssize_t read = getline(&line, &len, file);
		if (read == -1) {
			cleanup_map_partial(map, i); 
			return cleanup_and_return(NULL, file, filename);
		}
		if (read > 0) {
			if (line[read - 1] == '\n') { line[read - 1] = '\0'; read--; }
			if (read > 0 && line[read - 1] == '\r') { line[read - 1] = '\0'; read--; }
		}
		if (i == 0) map->w = read;
		else if (read != map->w)
		{
			free(line); 
			cleanup_map_partial(map, i); 
			return cleanup_and_return(NULL, file, filename);
		}
		map->map[i] = line;
	}
	if (filename) fclose(file);
	return map;
}

int validate_map(Map *map) {
	if (!map || map->l <= 0 || map->w <= 0) return 0;
	for (int i = 0; i < map->l; i++)
		for (int j = 0; j < map->w; j++)
			if (map->map[i][j] != map->e && map->map[i][j] != map->o) return 0;
	return 1;
}

void solve_bsq(Map *map) {
	int **dp = malloc(map->l * sizeof(int*));
	if (!dp) return;
	for (int i = 0; i < map->l; i++) {
		dp[i] = calloc(map->w, sizeof(int));
		if (!dp[i]) { cleanup_dp(dp, i); return; }
	}
	int max_size = 0, best_i = 0, best_j = 0;
	for (int i = 0; i < map->l; i++) {
		for (int j = 0; j < map->w; j++) {
			if (map->map[i][j] == map->o) dp[i][j] = 0;
			else if (i == 0 || j == 0) dp[i][j] = 1;
			else dp[i][j] = min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
			if (dp[i][j] > max_size) { max_size = dp[i][j]; best_i = i; best_j = j; }
		}
	}
	if (max_size > 0) {
		int start_i = best_i - max_size + 1, start_j = best_j - max_size + 1;
		for (int i = start_i; i <= best_i; i++)
			for (int j = start_j; j <= best_j; j++)
				map->map[i][j] = map->f;
	}
	cleanup_dp(dp, map->l);
}

void print_map(Map *map) { for (int i = 0; i < map->l; i++) printf("%s\n", map->map[i]); }
void free_map(Map *map) { if (!map) return; cleanup_map_partial(map, map->l); }

void process_file(char *filename) {
	Map *map = read_map(filename);
	if (!map || !validate_map(map)) { fprintf(stderr, "map error\n"); if (map) free_map(map); return; }
	solve_bsq(map); print_map(map); free_map(map);
}

int main(int argc, char **argv) {
	if (argc == 1) process_file(NULL);
	else for (int i = 1; i < argc; i++) process_file(argv[i]);
	return 0;
}
